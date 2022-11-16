#include "hfile.h"
#include <math.h>
#include <limits.h>

int compare(char a[], char b[])
{
    int flag = 0, i = 0;
    while (a[i] != '\0' && b[i] != '\0')
    {
        if (a[i] != b[i])
        {
            flag = 1;
            break;
        }
        i++;
    }
    if (flag == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int strToInt(char *str)
{
    int res = 0;

    for (int i = 0; str[i] != '\0'; ++i)
    {
        if (str[i] > '9' || str[i] < '0')
            return -1;
        res = res * 10 + str[i] - '0';
    }
    return res;
}

void moveDisksBetweenTwoPoles(Stack *src, Stack *dest, char s, char d, int printText)
{
    info_t pole1TopDisk = pop(src);
    info_t pole2TopDisk = pop(dest);

    if (pole1TopDisk == INT_MIN)
    {
        push(src, pole2TopDisk);
        moveDisk(d, s, pole2TopDisk, printText);
    }

    else if (pole2TopDisk == INT_MIN)
    {
        push(dest, pole1TopDisk);
        moveDisk(s, d, pole1TopDisk, printText);
    }

    else if (pole1TopDisk > pole2TopDisk)
    {
        push(src, pole1TopDisk);
        push(src, pole2TopDisk);
        moveDisk(d, s, pole2TopDisk, printText);
    }

    else
    {
        push(dest, pole2TopDisk);
        push(dest, pole1TopDisk);
        moveDisk(s, d, pole1TopDisk, printText);
    }
}

void tohIterative(int num_of_disks, Stack *src, Stack *aux, Stack *dest, int printText)
{
    unsigned int i, total_num_of_moves;
    char s = 'A', d = 'C', a = 'B';

    if (num_of_disks % 2 == 0)
    {
        char temp = d;
        d = a;
        a = temp;
    }
    total_num_of_moves = pow(2, num_of_disks) - 1;

    if (printText == 0)
    {
        printAllStacks(src, aux, dest, num_of_disks);
    }

    for (i = 1; i <= total_num_of_moves; i++)
    {
        if (i % 3 == 1)
            moveDisksBetweenTwoPoles(src, dest, s, d, printText);

        else if (i % 3 == 2)
            moveDisksBetweenTwoPoles(src, aux, s, a, printText);

        else if (i % 3 == 0)
            moveDisksBetweenTwoPoles(aux, dest, a, d, printText);
    }
}

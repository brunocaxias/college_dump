def main():
    nb3 = str(input)
    decimal = int(0)
    i = int(0)
    n = int(0)
    dec = int(0)
    while nb3 != 0:
        dec = nb3 % 10
        decimal = decimal + dec * (3 ** i)
        nb3 = nb3 // 10
        i += 1
    print (decimal)

if __name__ == "__main__":
    main()
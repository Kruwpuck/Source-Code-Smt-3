A = int(input("Input N: "))
B = int(input("Input K: "))


while A < 1 or B > 10**5:
    print("Masukkan invalid")
    A = int(input("Input N: "))
    B = int(input("Input K: "))

C = int(input("Input A: "))
D = int(input("Input B: "))


while C < 1 or D > 10**5:
    print("Masukkan invalid")
    C = int(input("Input A: "))
    D = int(input("Input B: "))


if A <= B:
    print("0,0")
else:
    total1 = B
    total2 = B
    i = 0
    j = 0
    while total1 < A:
        total1 += D
        i += 1

    while total2 < A:
        total2 += C
        j += 1
    print(i,j)


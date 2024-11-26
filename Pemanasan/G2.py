def minX(N, K):
    def hitungAngka(number):
        return len(set(str(number)))
    X = 0
    while hitungAngka(N + X) > K:
        X += 1
    return X

N, K = map(int, input().split())
while N < 1 or K > 10**8:
    N, K = map(int, input().split())
result = minX(N, K)
print(result)
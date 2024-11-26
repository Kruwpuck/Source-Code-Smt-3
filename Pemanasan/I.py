def maxBitset(N, K):
    if N == 1:
        return bin(K).count('1')
    A = [0] * N
    for i in range(N):
        if K == 0:
            break
        A[i] = min(K, (1 << (K.bit_length() - 1)))
        K -= A[i]
    maxBit = sum(bin(x).count('1') for x in A)
    return maxBit
if __name__ == "__main__":
    N, K = map(int, input().split())
    while N < 1 or K > 10**9:
        N, K = map(int, input().split())
    hasil = maxBitset(N, K)
    print(hasil)
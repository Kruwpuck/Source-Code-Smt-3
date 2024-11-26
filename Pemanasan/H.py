def H(N, K, S):
    total = 0
    for char in S:
        total ^= int(char)
    if total == 0 and K > 1:
        return "Ya"
    hasil = total // K if total % K == 0 else 0
    if total != 0 and K == 1:
        return "Ya"
    now = 0
    subs = 0
    for char in S:
        now ^= int(char)
        if now == hasil:
            subs += 1
            now = 0
    return "Ya" if subs == K else "Tidak"

N, K = map(int, input().split())
S = input().strip()
while N < 1 or K > 10**6:
    N, K = map(int, input().split())
    S = input().strip()
print(H(N, K, S))

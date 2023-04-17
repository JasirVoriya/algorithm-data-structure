a, b, p = map(int, input().split())
base = a % p
ans = 1
while b != 0:
    if b & 1 == 1:
        ans = (ans * base) % p
    base = (base << 1) % p
    b = b >> 1
print(ans)

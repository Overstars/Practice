import sys
def isprime(n):
    if n <= 1: return False
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:return False
    return True
t=int(input())
for i in range(0,t):
    n, k = list(map(int, input().split()))
    ans=1
    for j in range(1,(n//k)+1):
        if isprime(j):
            ans*=j
    print(ans*k)
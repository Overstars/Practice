# import numba as nb
# import numpy as np
# @nb.jit(nopython=True)s
h,n=map(int,input().split())
# H<=45000
w=[0]*10005
dp=[0]*45005
for i in range(1,n+1):
    w[i]=int(input())
for i in range(1,n+1):
    for j in range(h,w[i]-1,-1): #从最大容量h开始逆序到w[i]
        dp[j]=max(dp[j],dp[j-w[i]]+w[i])
# print("h=",h,",","n=",n)
print(dp[h])

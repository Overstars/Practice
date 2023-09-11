from sys import stdin,stdout  #加速
from collections import defaultdict
t=int(input())
for case in range(t):
    n=int(input())
##    s=[0]*100005
##    a=[0]*100005
    a=[int(x) for x in input().split()]    
    # a=list(map(int,input().split()))
##    a[1:n]=map(int,input().split())
##    for i in range(1,n+1):
##        s[i]=s[i-1]+a[i]
    mi,maxsum,tot,pre=0,0,0,0
    for i in range(0,n-1):
        tot+=a[i]
        pre=max(0,pre+a[i])
        maxsum=max(maxsum,pre)#最大区间和
##        mi=min(mi,s[i])
    tot+=a[n-1]
    pre=0
    for i in range(0,n):
        pre+=a[i]
        maxsum=max(maxsum,tot-pre)
##    for i in range(2,n+1):
##        maxsum=max(maxsum,s[n]-s[i])
    if tot>maxsum:
        print('YES')
    else:
        print('NO')

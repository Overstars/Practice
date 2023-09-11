n,m=map(int,input().split())
## 矩阵
##a=[[0 for col in range(105)] for row in range(105)]
ans=0
for t in range(n):
    a=[0 for i in range(105)]
    a[1:]=[int(x) for x in input().split()] #一行输入的数组
    a.append(0) ##防止越界
    dp=[[0 for col in range(105)] for row in range(105)]
    for l in range(m-1,0,-1):##长度
        for i in range(1,m-l+2):##左端点
            j=i+l-1##右端点
            dp[i][j]=max(dp[i-1][j]+a[i-1]*(1<<(m-l)),dp[i][j+1]+a[j+1]*(1<<(m-l)))
##            print("dp[",i,"][",j,"]=",dp[i][j])
    now=0
    for i in range(1,m+1):
        now=max(now,dp[i][i]+a[i]*(1<<m))
    ans+=now
print(ans)

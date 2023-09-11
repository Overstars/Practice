n=int(input())
w=[0]*1005
dp=[0]*1005 #存储到当前最大分组数目
for i in range(1,n+1):
    w[i]=int(input())
    w[i]+=w[i-1] #前缀和
    if(w[i]>0):
        dp[i]=1 #至少有一组
for i in range(2,n+1): #从j到i
    for j in range(1,i):
        if(dp[j]>0 and w[i]-w[j]>=0): #j前面可以分组
            dp[i]=max(dp[j]+1,dp[i]) #从j到i这里再分一组
if(dp[n]==0):
    print("Impossible")
else:
    print(dp[n])

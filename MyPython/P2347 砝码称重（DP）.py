import  sys
# str=input()
num=list(map(int, input().split())) # 读入每种砝码的数量
w=[1,2,3,5,10,20]
dp=[0]*1080
# print(num)
dp[0]=1
for i in range(0,6): # 枚举砝码种类
    for j in range(1,num[i]+1): # 枚举每种数量
        for k in range(1000,-1,-1):
            if dp[k]>0:
                dp[k+w[i]]=1
cnt=0
for i in range(1,1001):
    if(dp[i]>0):
        cnt+=1
print('Total={}'.format(cnt))

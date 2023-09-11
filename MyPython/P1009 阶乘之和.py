import sys
def fac(x):
    sum=1
    for i in range(2,x+1,1):
        sum*=i
    return (sum)
n=int(input())
ans=0
for i in range(1,n+1,1):
    ans+=fac(i)
print(ans)
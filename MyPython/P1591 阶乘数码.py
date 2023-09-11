def fact(x): #计算阶乘
    ret=1
    for i in range(2,x+1,1):
        ret*=i
    return (ret)
t=int(input())
while t>0:
    print("我选择狗带")
    n,a=map(int,input().split())
    ans=0
    tem=fact(n)
    while tem>0:
        if (tem%10==a):
            ans+=1
        tem//=10
    t-=1

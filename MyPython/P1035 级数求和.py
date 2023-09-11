
# 读取k
k=int(input())
# 定义列表，赋初值为0
# arr= [0 for x in range(0, 1005)]
sum=0.0
var=0
while sum<=k:
    var += 1
    sum+=float(1/var)
print(var)

import sys
sys.setrecursionlimit(1000000) #扩栈
from math import gcd
for i in range(int(input())):
    x,y=map(int,input().split())
    print('Case {:d}: {:d}'.format(int(i+1),int(x*y/gcd(x,y))))

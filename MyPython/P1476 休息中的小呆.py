import math
G=[[0]*105 for i in range(0,105)]
inf=9999999999999
while True:#不定组输入
    try:
        n=int(input())
        m=int(input())
        for i in range(n+2):
            for j in range(n+2):
                G[i][j]=0
        for i in range(0,m):#出发点是1，结束点是n+1
            u,v,w=map(int,input().split())
            G[u][v]=w;
        for k in range(1,n+2):
            for i in range(1,n+2):
                for j in range(1,n+2):
                    if(i!=j and j!=k and G[i][k]>0 and G[k][j]>0):
                        G[i][j]=max(G[i][j],G[i][k]+G[k][j]);
        print(G[1][n+1])
        print(1,end=' ')
        for i in range(2,n+2):
            if(G[1][i]+G[i][n+1]==G[1][n+1]):
                print(i,end=' ')
    except EOFError:
        break;
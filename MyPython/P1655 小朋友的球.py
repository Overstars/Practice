while True:
    try:#本题求出斯特林数s[n][m]
        n,m=list(map(int,input().split()))
        s=[[0 for col in range(105)] for row in range(105)]
        s[0][1]=1
        for i in range(1,n+1):
            for j in range(1,i+1):
                s[i][j]=s[i-1][j-1]+s[i-1][j]*j
        if(m>n):
            print(0)
        else:
            print(s[n][m])
    except EOFError:
        break
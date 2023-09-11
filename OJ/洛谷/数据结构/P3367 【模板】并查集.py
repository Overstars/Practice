N,m=map(int,input().split())
#fa=[int(i) for i in range(N+1)]
siz=[1]*(N+1)
def findfa(x):
    if fa[x]!=x:
        fa[x]=findfa(fa[x])
    return fa[x]
def Merge(x,y):
    xx,yy=findfa(x),findfa(y)
    if xx == yy:
        return False
    if siz[xx] > siz[yy]: #按秩合并
        fa[yy]=xx
        siz[xx]+=siz[yy]
    else:
        fa[xx]=yy
        siz[yy]+=siz[xx]
    return True
for i in range(m):
    z,x,y=map(int,input().split())
    if z==1:
        Merge(x,y)
    else:
        print('Y' if findfa(x)==findfa(y)else 'N')

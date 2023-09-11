//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int ll
typedef pair<int,int>pii;
#define ff first
#define ss second
#define debug(x) std:: cerr << #x << " = " << x << std::endl;
const int maxn=2e5+10,inf=0x3f3f3f3f,mod=1000000007;
const ll INF=0x3f3f3f3f3f3f3f3f;
const double eps=1e-9;
//#define DEBUG//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
int parent[maxn];
long long counter = 0;

int find(int x) {
    while (x != parent[x]) {
        if (x < parent[x]) {
            // Merge-by-rank and Path-compression
            parent[x] = parent[parent[x]];
        }
        x = parent[x];
        counter++;
        printf("%d->%d,cnt=%lld\n",x,parent[x],counter);
    }

    return x;
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);
    parent[a] = b;
}

signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,t;
	cin>>n>>t;
	for(int i=n-1;i>=1;i--)
		cout<<n<<' '<<i<<endl;
	cout<<n<<' '<<n<<endl;
//	int n, A, B, ans = 0;
//    cin >> n;
//
//    for (int i = 1; i <= n; i++)
//        parent[i] = i;
//
//    for (int i = 1; i <= n; i++) {
//        cin >> A >> B;
//        merge(A, B);//p[a]=b
//    }//x比p[x]大
//
////    for (int i = 1; i <= n; i++)
////        if (i == find(i))
////            ans++;
//
//    cout << ans << endl;
	return 0;
}
/*
10
10 9
10 8
10 7
10 6
10 5
10 4
10 3
10 2
10 1
10 10

10
10 9
9 8
8 7
7 6
6 5
5 4
4 3
3 2
2 1
10 1
*/
/*
 * 2021-05-30-11.14.48
 * C:\Users\dell\Desktop\C++\OJ\未解决\2021年5月30日The 16th Heilongjiang Provincial Collegiate Programming Contest\H.cpp
 *
*/


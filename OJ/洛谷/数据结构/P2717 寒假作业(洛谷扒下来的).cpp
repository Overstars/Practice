#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll> b;
const int N=4e5+10;
ll All,k,a[N],Ans;
int n;
int main() {
	scanf("%d%lld",&n,&k);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]),a[i]-=k;
	for(int i=1;i<=n;i++) {
		b.insert(lower_bound(b.begin(),b.end(),-All),-All);
		All+=a[i];
		int p=b.end()-lower_bound(b.begin(),b.end(),-All);
		Ans+=p;
	}
	printf("%lld\n",Ans);
	return 0;
}

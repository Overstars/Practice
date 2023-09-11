#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+5,inf=0x3f3f3f3f,mod=1000000007;
//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
template<class T>inline void read(T &x) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	string s;
	cin>>s;
	bool flag=1;
	stack<char>QAQ;
	for(char &ch:s)
	{
		if(ch==')'||ch==']'||ch=='}')
		{
			if(ch==')')
			{
				if(QAQ.top()=='(')
					QAQ.pop();
				else{
					flag=0;
					break;
				}
			}
			else if(ch==']')
			{
				if(QAQ.top()=='[')
					QAQ.pop();
				else{
					flag=0;
					break;
				}
			}
			else if(ch=='}')
			{
				if(QAQ.top()=='{')
					QAQ.pop();
				else{
					flag=0;
					break;
				}
			}
		}
		else
			QAQ.push(ch);
	}
	if(!QAQ.empty())
		flag=0;
	cout<<(flag?"Yes":"No")<<endl;
	return 0;
}



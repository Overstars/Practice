#include<bits/stdc++.h>
using namespace std;
char a[105],ans[105];
int main()
{
	scanf("%s",a);
	int l1=strlen(a);
	sort(a,a+l1);
	bool flag=1;
	scanf("%s",ans);
	int l2=strlen(ans),loc=0;
	char ch='9'+1,*pc=ans;
	if(a[0]!='0')
		goto here;
	for(int i=0;i<l1;i++)
	{
		if(a[i]<ch&&a[i]!='0')
		{
			loc=i;
			ch=a[i];
		}
		if(ch=='1')
			break;
	}
	if(loc)
		swap(a[0],a[loc]);
	here:
	for(int i=0;i<l2;i++)
	{
		if(ans[i]!='0')
		{
			pc=&ans[i];
			break;
		}
	}
	//	cout<<a<<endl<<ans<<endl;
	if(ans[0]=='0'&&a[0]=='0'&&l1==1&&l2==1)
		cout<<"OK"<<endl;
	else if(ans[0]=='0')
		cout<<"WRONG_ANSWER"<<endl;
	else
		cout<<(!strcmp(a,pc)?"OK":"WRONG_ANSWER")<<endl;
	return 0;
}

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char s[1000005];
int nex[1000005],extend[1000005];//ex[i]存储母串的子串S[i:n-1]与T的公共前缀长度
void GetNext(char T[],int m,int nex[])//先计算模式串的next数组
{//之前匹配过程中所达到的最远位置为p(匹配串最后一个字符为T[p-1]),并且以T[a]为起始
    int a=0,p=0;//边界情况,此时不能令p=m,避免T[0]与T[0]对齐
    nex[0]=m;//与自身完全匹配
    //T[i]串和T[i-a]串对齐,来求nex[i]
    for(int i=1;i<m;i++)//计算子串T[i]...T[m-1]的匹配长
	{
        if(i>=p||i+nex[i-a]>=p)//最右匹配串需要更新
		{
			if(i>=p)
				p=i;//i<p时T[i]~T[p-1]与T[0]~T[p-i-1]相同
            while(p<m&&T[p]==T[p-i])
                p++;//更新最右值,T[p]与T[p-i]匹配失败则跳出
            nex[i]=p-i;//最大匹配长T[0]~T[p-i-1]
            a=i;//更新最右匹配串起始位置
        }
        else//在之前的最长匹配串中,所以T[i]==T[i-a],T[i+nex[i-a]]==T[i-a+nex[i-a]],且T[i-a]串在T[nex[i-a]]处截断(相当于T[0+nex[i-a]]!=T[i-a+nex[i-a]])
			nex[i]=nex[i-a];//所以T[i]也在T[nex[i-a]]处截断(T[i+nex[i-a]]!=T[0+nex[i-a]]),即为匹配串长度
    }
}
void GetExtend(char S[],int n,char T[],int m,int extend[],int next[])
{//注意:比较过程中T[0]始终与S[a]对齐
	int a=0,p=0;//a,p为母串S上的标记,p为之前匹配过程中所达到的最远位置
	GetNext(T,m,next);
	for(int i=0;i<n;i++)//计算子串S[i]...S[n-1]与T的匹配长
    {//i一定≥a,所以要求p尽量在最右,而不必特别关注a
        if(i>=p||i+next[i-a]>=p)//a和p都要更新
        {
            if(i>=p)//i>=p的作用:举个典型例子,S和T无一字符相同
                p=i;//i>=p时更新最右值p,i<p时S[i]~S[p-1]与T[0]~T[p-i-1]匹配
            while(p<n&&p-i<m&&S[p]==T[p-i])//
                p++;
            extend[i]=p-i;//S[i]~S[p-1],共p-i个字符匹配
            a=i;//更新最右匹配串起始位置,当i超出了p时,以i开头重新计算p
        }//但当p<i&&i+next[i-a]>=p时,a更不更新不影响
        else//未超出最右匹配串,即S[i]~S[i+nex[i-a]]==T[i-a]~T[i-a+nex[i-a]],T[0+nex[i-a]]!=T[i-a+nex[i-a]]
            extend[i]=next[i-a];//所以S[i+nex[i-a]]!=T[0+nex[i-a]],nex[i-a]即为匹配串长度
    }
}
int main()
{
	int t;
	cin>>t;
	while(t--){
		scanf("%s",s);
		int len=strlen(s);
		long long cnt=0;//果然是卡int...
		memset(nex,0,sizeof(nex));
//		memset(extend,0,sizeof(extend));
		GetNext(s,len,nex);
//		GetExtend(s,len,s,len,extend,nex);
//		{
//			 cout << "next:   ";
//			for (int i = 0; i < len; i++)
//				cout << nex[i] << " ";
//
//			// 打印 extend
//			cout << "\nextend: ";
//			for (int i = 0; i < len; i++)
//				cout << extend[i] << " ";
//
//			cout << endl << endl;
//		}
		for(int i=1;i<=len-1;i++){
			cnt+=nex[i];
			if(i+nex[i]<len)
				cnt++;
		}
//		for(int i=1;i<=len-1;i++){
//			cnt+=extend[i];
//			if(i+extend[i]<len)
//				cnt++;
//		}
//		printf("cnt=%d,cnt2=%d\n",cnt,cnt2);
//		cnt++;//最后一个字符
		cout<<cnt<<endl;
	}
	return 0;
}

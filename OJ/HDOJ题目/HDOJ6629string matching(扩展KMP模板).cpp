#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char s[1000005];
int nex[1000005],extend[1000005];//ex[i]�洢ĸ�����Ӵ�S[i:n-1]��T�Ĺ���ǰ׺����
void GetNext(char T[],int m,int nex[])//�ȼ���ģʽ����next����
{//֮ǰƥ����������ﵽ����Զλ��Ϊp(ƥ�䴮���һ���ַ�ΪT[p-1]),������T[a]Ϊ��ʼ
    int a=0,p=0;//�߽����,��ʱ������p=m,����T[0]��T[0]����
    nex[0]=m;//��������ȫƥ��
    //T[i]����T[i-a]������,����nex[i]
    for(int i=1;i<m;i++)//�����Ӵ�T[i]...T[m-1]��ƥ�䳤
	{
        if(i>=p||i+nex[i-a]>=p)//����ƥ�䴮��Ҫ����
		{
			if(i>=p)
				p=i;//i<pʱT[i]~T[p-1]��T[0]~T[p-i-1]��ͬ
            while(p<m&&T[p]==T[p-i])
                p++;//��������ֵ,T[p]��T[p-i]ƥ��ʧ��������
            nex[i]=p-i;//���ƥ�䳤T[0]~T[p-i-1]
            a=i;//��������ƥ�䴮��ʼλ��
        }
        else//��֮ǰ���ƥ�䴮��,����T[i]==T[i-a],T[i+nex[i-a]]==T[i-a+nex[i-a]],��T[i-a]����T[nex[i-a]]���ض�(�൱��T[0+nex[i-a]]!=T[i-a+nex[i-a]])
			nex[i]=nex[i-a];//����T[i]Ҳ��T[nex[i-a]]���ض�(T[i+nex[i-a]]!=T[0+nex[i-a]]),��Ϊƥ�䴮����
    }
}
void GetExtend(char S[],int n,char T[],int m,int extend[],int next[])
{//ע��:�ȽϹ�����T[0]ʼ����S[a]����
	int a=0,p=0;//a,pΪĸ��S�ϵı��,pΪ֮ǰƥ����������ﵽ����Զλ��
	GetNext(T,m,next);
	for(int i=0;i<n;i++)//�����Ӵ�S[i]...S[n-1]��T��ƥ�䳤
    {//iһ����a,����Ҫ��p����������,�������ر��עa
        if(i>=p||i+next[i-a]>=p)//a��p��Ҫ����
        {
            if(i>=p)//i>=p������:�ٸ���������,S��T��һ�ַ���ͬ
                p=i;//i>=pʱ��������ֵp,i<pʱS[i]~S[p-1]��T[0]~T[p-i-1]ƥ��
            while(p<n&&p-i<m&&S[p]==T[p-i])//
                p++;
            extend[i]=p-i;//S[i]~S[p-1],��p-i���ַ�ƥ��
            a=i;//��������ƥ�䴮��ʼλ��,��i������pʱ,��i��ͷ���¼���p
        }//����p<i&&i+next[i-a]>=pʱ,a�������²�Ӱ��
        else//δ��������ƥ�䴮,��S[i]~S[i+nex[i-a]]==T[i-a]~T[i-a+nex[i-a]],T[0+nex[i-a]]!=T[i-a+nex[i-a]]
            extend[i]=next[i-a];//����S[i+nex[i-a]]!=T[0+nex[i-a]],nex[i-a]��Ϊƥ�䴮����
    }
}
int main()
{
	int t;
	cin>>t;
	while(t--){
		scanf("%s",s);
		int len=strlen(s);
		long long cnt=0;//��Ȼ�ǿ�int...
		memset(nex,0,sizeof(nex));
//		memset(extend,0,sizeof(extend));
		GetNext(s,len,nex);
//		GetExtend(s,len,s,len,extend,nex);
//		{
//			 cout << "next:   ";
//			for (int i = 0; i < len; i++)
//				cout << nex[i] << " ";
//
//			// ��ӡ extend
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
//		cnt++;//���һ���ַ�
		cout<<cnt<<endl;
	}
	return 0;
}

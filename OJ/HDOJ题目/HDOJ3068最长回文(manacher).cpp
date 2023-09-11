#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<map>
using namespace std;
#define PI 3.14159265358979323846
#define e  2.7182818284590452354
#define ln_2 0.69314718055994530942
#define ln_10 2.30258509299404568402
const int inf=0x3f3f3f3f;
/*
 *String:��'#'�����Ļ��Ĵ�
 *MaxR:����İ뾶��Ӧ���Ҷ��ַ�MaxRight
 *flag:����İ뾶��Ӧ�����ĵ��±�
 *cnt[i]:��iΪ���Ķ�Ӧ�Ļ��İ뾶
 *l:String����
*/
const int maxlen=110005;
char str[maxlen],String[maxlen<<1];
int cnt[maxlen<<1];//��¼������ַ���i�������İ뾶
int Manacher(char s[],int len)//ԭ�ַ����ʹ���
{
    int l=0;
    String[l++] = '$'; // 0�±�洢Ϊ�����ַ�,��ֹԽ��
    String[l++] = '#';
    for(int i=0;i<len;i++)
	{
        String[l++]=s[i];
        String[l++]='#';
    }
    String[l]='\0'; // ���ַ�
    int MaxR=0;//����İ뾶��Ӧ���Ҷ��ַ�MaxRight
    int flag=0;//����İ뾶��Ӧ�����ĵ��±�
    int ans=0;
    for(int i=0;i<l;i++)
	{
		if(i<MaxR)//iһ������flag(��һ��ʼ��i��ֵ��flagʱi==flag)
			cnt[i]=min(cnt[(flag<<1)-i],MaxR-i);//2*flag-i��i�����flag�ĶԳƵ�,��Ϊi'
		else//��Ϊ����flag�Գ�,��i+cnt[i']<=MaxRʱ,i����cnt[i']���ַ�����i�Գ�,���Ա����ظ�ƥ�䡣ȡmin����Ϊi+cnt[i']�п��ܳ���MaxR
			cnt[i]=1;//��ͷ��ʼƥ��
		while(String[i+cnt[i]]==String[i-cnt[i]])
			cnt[i]++;
		if(i+cnt[i]>MaxR)//�¼���Ļ��Ĵ��Ҷ˵�λ�ô���MaxR
		{
			MaxR=i+cnt[i];//���µ������Ҷ˵�
			flag=i;
		}
		ans=max(ans,cnt[i]);
	}
	return ans-1;
}
int main()
{
	while(scanf("%s",str)==1)
		cout<<Manacher(str,strlen(str))<<endl;
	return 0;
}

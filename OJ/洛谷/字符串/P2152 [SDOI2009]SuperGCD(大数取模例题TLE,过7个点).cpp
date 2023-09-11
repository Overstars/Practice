#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
const int Length=10005;
string add(const string &a,const string &b)//��
{
    string ans;
    int na[Length]={0},nb[Length]={0};
    int la=a.size(),lb=b.size();
    for(int i=0;i<la;i++) na[la-1-i]=a[i]-'0';
    for(int i=0;i<lb;i++) nb[lb-1-i]=b[i]-'0';
    int lmax=la>lb?la:lb;
    for(int i=0;i<lmax;i++) na[i]+=nb[i],na[i+1]+=na[i]/10,na[i]%=10;
    if(na[lmax]) lmax++;
    for(int i=lmax-1;i>=0;i--) ans+=na[i]+'0';
    return ans;
}
string mul(const string &a,const string &b)//��
{
    string s;
    int na[Length],nb[Length],nc[Length],La=a.size(),Lb=b.size();//na�洢��������nb�洢������nc�洢��
    fill(na,na+Length,0);fill(nb,nb+Length,0);fill(nc,nc+Length,0);//��na,nb,nc����Ϊ0
    for(int i=La-1;i>=0;i--) na[La-i]=a[i]-'0';//���ַ�����ʾ�Ĵ�������ת��i���������ʾ�Ĵ�������
    for(int i=Lb-1;i>=0;i--) nb[Lb-i]=b[i]-'0';
    for(int i=1;i<=La;i++)
        for(int j=1;j<=Lb;j++)
        nc[i+j-1]+=na[i]*nb[j];//a�ĵ�iλ����b�ĵ�jλΪ���ĵ�i+j-1λ���Ȳ����ǽ�λ��
    for(int i=1;i<=La+Lb;i++)
        nc[i+1]+=nc[i]/10,nc[i]%=10;//ͳһ�����λ
    if(nc[La+Lb]) s+=nc[La+Lb]+'0';//�жϵ�i+jλ�ϵ������ǲ���0
    for(int i=La+Lb-1;i>=1;i--)
        s+=nc[i]+'0';//����������ת���ַ���
    return s;
}
int sub(int *a,int *b,int La,int Lb)//��
{
    if(La<Lb)
        return -1;//���aС��b���򷵻�-1
    if(La==Lb)
    {
        for(int i=La-1;i>=0;i--)
            if(a[i]>b[i])
                break;
            else if(a[i]<b[i])
                return -1;//���aС��b���򷵻�-1
    }
    for(int i=0;i<La;i++)//�߾��ȼ���
    {
        a[i]-=b[i];
        if(a[i]<0)
            a[i]+=10,a[i+1]--;
    }
    for(int i=La-1;i>=0;i--)
        if(a[i])
            return i+1;//���ز��λ��
    return 0;//���ز��λ��
}
string div(const string &n1,const string &n2,int nn)//n1,n2���ַ�����ʾ�ı�����������,nn��ѡ�񷵻��̻�������
{
    string s,v;//s����,v������
    int a[Length],b[Length],r[Length],La=n1.size(),Lb=n2.size(),i,tp=La;//a��b�����������ʾ��������������tp���汻�����ĳ���
    fill(a,a+Length,0);fill(b,b+Length,0);fill(r,r+Length,0);//����Ԫ�ض���Ϊ0
    for(i=La-1;i>=0;i--) a[La-1-i]=n1[i]-'0';
    for(i=Lb-1;i>=0;i--) b[Lb-1-i]=n2[i]-'0';
    if(La<Lb || (La==Lb && n1<n2))
    {
        //cout<<0<<endl;
        return n1;
    }//���a<b,����Ϊ0������Ϊ������
    int t=La-Lb;//�������ͳ�����λ��֮��
    for(int i=La-1;i>=0;i--)//����������10^t��
        if(i>=t)
            b[i]=b[i-t];
        else b[i]=0;
     Lb=La;
     for(int j=0;j<=t;j++)
     {
         int temp;
         while((temp=sub(a,b+j,La,Lb-j))>=0)//����������ȳ����������
         {
             La=temp;
             r[t-j]++;
         }
     }
     for(i=0;i<Length-10;i++)
        r[i+1]+=r[i]/10,r[i]%=10;//ͳһ�����λ
     while(!r[i]) i--;//�����������ʾ����ת�����ַ�����ʾ��
     while(i>=0) s+=r[i--]+'0';
     //cout<<s<<endl;
     i=tp;
     while(!a[i]) i--;//�����������ʾ������ת�����ַ�����ʾ��</span>
     while(i>=0) v+=a[i--]+'0';
     if(v.empty()) v="0";
     //cout<<v<<endl;
     if(nn==1)
        return s;
     if(nn==2)
        return v;
}
bool judge(const string &s)//�ж�s�Ƿ�Ϊȫ0��
{
    for(int i=0;i<s.size();i++)
        if(s[i]!='0')
            return false;
    return true;
}
string gcd(string a,string b)//�����Լ��
{
    if(a.length()<b.length())
		swap(a,b);
	else if(a<b)
		swap(a,b);
    string t;
    while(!judge(b))//���������Ϊ0��������
    {
        t=a;//���汻������ֵ
        a=b;//�ó����滻������
        b=div(t,b,2);//�������滻����
    }
    return a;
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	string a,b;
	cin>>a>>b;
	cout<<gcd(a,b)<<endl;
	return 0;
}

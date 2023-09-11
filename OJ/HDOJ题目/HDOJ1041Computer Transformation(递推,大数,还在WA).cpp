#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
#define BASE 10    //ȷ������
#define N 90001    //ȷ�� ���λ��+1
int l = 0;                      //ÿ�μ�¼���������˶೤����ԭʱ��ʡʱ��
char res[N] = { '\0' };  //������
char a[1005][300]={"00\0","00\0","00\0","01\0"},b[1005][300]={"00\0","00\0","00\0","01\0"};

//������Լ�������f[n]=f[n-1]+2^n-2
//F[n]=F[n-1]+2*F[n-2]


void ini(char * x ,int l)
{
    int i;

    if(l < N)
        l++;

    for(i = 0 ; i < l ;i++)
        x[i] = '\0';
}

void Clean(char * x,int l)
{
    for(l--; x[l] == '0';l--)
        x[l] = '\0';
}
void rev(char * x)
{
    int right = strlen(x)-1;
    int left = 0;
    char temp;

    while(left < right)
    {
        temp = x[left];
        x[left++] = x[right];
        x[right--] = temp;
    }
}
int BigCmp(char * a, char * b)  //  ����a < ����b ����1 ����ȷ���0 ��a>b����-1
{
    int i,j,k;
    int la = strlen(a),lb = strlen(b);
    char * temp;

    if(a[0] == '-' && b[0] != '-')
        return 1;
    else if(a[0] != '-' && b[0] == '-')
        return -1;
    else if(a[0] == '-' && b[0] == '-')
    {
        a++;
        b++;

        temp = a;
        a = b;
        b = temp;

        la--;
        lb--;

        k = la;
        la =lb;
        lb = k;
    }

    if(la < lb)
        return 1;
    if(la > lb)
        return -1;

    if(la == lb)
    {
        for(i = 0 ; i < la ; i++)
        {
            if(a[i] < b[i])
                return 1;
            else if(a[i] > b[i])
                return -1;
        }
    }

    return 0;
}
char *  BigAdd( char * a, char * b)
{
    int i,j,k;
    int sum,la,lb,carry,flag,cmp;
    char *ans,*temp;
    carry = 0;
    flag = 0;
    ans = &res[1];
    ini(res,l);
    la=strlen(a);
    lb=strlen(b);

    if(b[0] == '0' && lb == 1)     //�ж�0
    {
        strcpy(ans,a);
        l = strlen(ans);
        return ans;
    }
    else if(a[0] == '0' && la ==1)
    {
        strcpy(ans,b);
        l = strlen(ans);
        return ans;
    }

    rev(a);
    rev(b);

    if(BigCmp(a,b) == 1)     //���ִ���a>����b
    {
        temp = a;
        a = b;
        b =temp;

        k = la;
        la = lb;
        lb = k;
    }

    for(i = lb ; i < la ; i++)  //��λ��0
        b[i] = '0';

    for(i = 0 ; i < la ; i++)
    {
        sum = (a[i]-48) + (b[i]-48) + carry;

        if( sum < BASE )
        {
            ans[i] = sum + 48;
            carry = 0;
        }
        else
        {
            ans[i] = sum  - BASE  + 48;
            carry = 1;
        }
    }

    if(carry)   //�������λ
    {
        ans[i] = carry + 48;
        i++;
    }

    Clean(ans,i);

    for(i = lb ; i < la ; i++)//ɾ�����ϵ�0
        b[i] = '\0';

    rev(ans);
    rev(a);
    rev(b);

    l = strlen(ans);
    return ans;
}
int main()
{
	int i,n;
	char one[100]="00";
	for(i=4;i<1001;i++){
		BigAdd(a[i-1],b[i-1]);
		strcpy(a[i],res);
		if((i+1)%2){
			BigAdd(a[i-1],b[i-1]);
			BigAdd(res,one);
		}
		else{
			BigAdd(a[i-1],b[i-1]);
		}
		strcpy(b[i],res);
	}
	while(cin>>n)
		cout<<b[n]+1<<endl;
	return 0;
}

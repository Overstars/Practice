#include<iostream>
#include<ostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<climits>
#include<cmath>
#include<iomanip>//控制输出,<<setiosflags(ios::fixed)<<setprecision(9)
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
#define MAXN 9999		//MAXN控制每个a[i]内大小
#define DLEN 4		//DLEN控制a[i]中有几位
#define MAXSIZE 10010	//控制数字位数

class BigNum
{
private:
	int a[MAXSIZE];
	int len;
public:
	BigNum() {
		len = 1;
		memset(a, 0, sizeof(a));
	}
	BigNum(const int);
	BigNum(const char*);
	BigNum(const BigNum &);
	BigNum &operator=(const BigNum &);
	friend istream& operator>>(istream&, BigNum&);
	friend ostream& operator<<(ostream&, BigNum&);
	BigNum operator +(const BigNum &)const;
	BigNum operator -(const BigNum &)const;
	BigNum operator *(const BigNum &)const;
	BigNum operator /(const int &)const;
	BigNum operator ^(const int &)const;
	long long operator %(const long long &)const;
	BigNum operator %(const BigNum &i_T)const;
	bool operator >(const BigNum&i_T)const;
	bool operator >(const int &i_T)const;
	void print();
};

//int->BigNum
BigNum::BigNum(const int i_b)
{
	int c, d = i_b;
	len = 0;
	memset(a, 0, sizeof(a));
	while (d > MAXN) {
		c = d - (d / (MAXN + 1))*(MAXN + 1);
		d = d / (MAXN + 1);
		a[len++] = c;
	}
	a[len++] = d;
}
//char->BigNum
BigNum::BigNum(const char *i_s)
{
	int t, k, index, L;
	memset(a, 0, sizeof(a));
	L = strlen(i_s);
	len = L / DLEN;
	if (L%DLEN)
		len++;
	index = 0;
	for (int i = L - 1; i >= 0; i -= DLEN) {
		t = 0;
		k = i - DLEN + 1;
		if (k < 0)
			k = 0;
		for (int j = k; j <= i; j++)
			t = t * 10 + i_s[j] - '0';
		a[index++] = t;
	}
}
//copy
BigNum::BigNum(const BigNum &i_T) :len(i_T.len)
{
	memset(a, 0, sizeof(a));
	for (int i = 0; i < len; i++)
		a[i] = i_T.a[i];
}
//BigNum复制BigNum
BigNum&BigNum::operator =(const BigNum&i_n)
{
	len = i_n.len;
	memset(a, 0, sizeof(a));
	for (int i = 0; i < len; i++)
		a[i] = i_n.a[i];
	return *this;
}
//cin>> BigNum
istream& operator >>(istream &in, BigNum &i_b)
{
	char ch[MAXSIZE * DLEN];
	in >> ch;
	int L = strlen(ch), count = 0, sum = 0;
	for (int i = L - 1; i >= 0;) {
		sum = 0;
		int t = 1;
		for (int j = 0; j < DLEN && i >= 0; j++, i--, t *= 10)
			sum += (ch[i] - '0')*t;
		i_b.a[count] = sum;
		count++;
	}
	i_b.len = count++;
	return in;
}
//cout<<BigNum
ostream& operator <<(ostream& out, BigNum& i_b)
{
	cout << i_b.a[i_b.len - 1];
	for (int i = i_b.len - 2; i >= 0; i--)
		printf("%04d", i_b.a[i]);
	return out;
}
//高精度除低精度
BigNum BigNum::operator /(const int &i_b)const
{
	BigNum ret;
	int down = 0;
	for (int i = len - 1; i >= 0; i--) {
		ret.a[i] = (a[i] + down * (MAXN + 1)) / i_b;
		down = a[i] + down * (MAXN + 1) - ret.a[i] * i_b;
	}
	ret.len = len;
	while (ret.a[ret.len - 1] == 0 && ret.len > 1)
		ret.len--;
	return ret;
}
//高精度%低精度
long long BigNum::operator %(const long long &i_b)const
{
	long long d = 0;
	for (int i = len - 1; i >= 0; i--)
		d = ((d*MAXN + 1) % i_b + a[i] * 1LL) % i_b;
	return d;
}

//高精度求幂
BigNum BigNum::operator ^(const int &n)const
{
	int i;
	BigNum t, ret(1);
	if (n < 0)
		exit(-1);
	if (n == 0)
		return 1;
	if (n == 1)
		return *this;
	int m = n;
	while (m > 1) {
		t = *this;
		for (i = 1; (i << 1) <= m; i <<= 1)
			t = t * t;
		m -= i;
		ret = ret * t;
		if (m == 1)
			ret = ret * (*this);
	}
	return ret;
}
//高精与高精比较
bool BigNum::operator >(const BigNum &i_T)const
{
	int ln;
	if (len > i_T.len)
		return true;
	else if (len < i_T.len)
		return false;
	else {
		ln = len - 1;
		while (a[ln] == i_T.a[ln] && ln > 0)
			ln--;
		return (ln >= 0 && a[ln] > i_T.a[ln]);
	}
}
//高精与低精度
bool BigNum::operator >(const int &i_T)const
{
	BigNum b(i_T);
	return *this > b;
}
//打印高精度
void BigNum::print()
{
	printf("%d", a[len - 1]);
	for (int i = len - 2; i >= 0; i--)
		printf("%04d", a[i]);
	printf("\n");
}
//高精度相乘
BigNum BigNum::operator *(const BigNum &i_T)const
{
	BigNum ret;
	int up, i=0, j=0, temp, temp1;
	for (i = 0; i < len; i++) {
		up = 0;
		for (j = 0; j < i_T.len; j++) {
			temp = a[i] * i_T.a[j] + ret.a[i + j] + up;
			if (temp > MAXN) {
				temp1 = temp - temp / (MAXN + 1)*(MAXN + 1);
				up = temp / (MAXN + 1);
				ret.a[i + j] = temp1;
			}
			else {
				up = 0;
				ret.a[i + j] = temp;
			}
		}
		if (up != 0)
			ret.a[i + j] = up;
	}
	ret.len = i + j;
	while (ret.a[ret.len - 1] == 0 && ret.len > 1)
		ret.len--;
	return ret;
}

BigNum BigNum::operator +(const BigNum &i_T)const	//BigNum+BigNum
{
	BigNum t(*this);
	int big;
	big = i_T.len > len ? i_T.len : len;
	for (int i = 0; i < big; i++) {
		t.a[i] += i_T.a[i];
		if (t.a[i] > MAXN) {
			t.a[i + 1]++;
			t.a[i] -= MAXN + 1;
		}
	}
	t.len = (t.a[big] != 0) ? big + 1 : big;
	return t;
}

BigNum BigNum::operator -(const BigNum &i_T)const //num - num
{
	int big, j;
	bool flag;
	BigNum t1, t2;
	if (*this > i_T) {
		t1 = *this;
		t2 = i_T;
		flag = 0;
	}
	else {
		t1 = i_T;
		t2 = *this;
		flag = 1;
	}
	big = t1.len;
	for (int i = 0; i < big; i++) {
		if (t1. a[i] < t2.a[i]) {
			j = i + 1;
			while (t1.a[j] == 0)
				j++;
			t1.a[j--]--;
			while (j > i)
				t1.a[j--] += MAXN;
			t1.a[i] += MAXN + 1 - t2.a[i];
		}
		else
			t1.a[i] -= t2.a[i];
	}
	t1.len = big;
	while (t1.a[t1.len - 1] == 0 && t1.len > 1) {
		t1.len--;
		big--;
	}
	if (flag)
		t1.a[big - 1] = 0 - t1.a[big - 1];
	return t1;
}

//自己手写高精度取模
BigNum BigNum::operator %(const BigNum &i_T)const
{
	BigNum r = *this / i_T;
	r = *this - r*i_T;
	return r;
}
BigNum gcd(BigNum a,BigNum b)//求最大公约数
{
    BigNum r;
    if(b>a)
	{
		r=a;
		a=b;
		b=r;
	}
    while((r=a%b)>0)//如果余数不为0，继续除
    {
        a=b;
        b=r;
    }
    return b;
}
//#define DEBUG
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	#ifdef DEBUG
		freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	#endif
	BigNum a,b;
	cin>>a>>b;
	a=gcd(a,b);
	cout<<a<<endl;
	return 0;
}

#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#define N 9989899+1 //���Ľ��Ϊ9989899
bool prime[N + 1]; //= { 0 }; //�����������N��Ԫ�أ���ֻ������ǰ1��Ԫ�ظ��˳�ֵ����n-1��Ԫ�س�ֵΪ0��
int hwzs[1000];
//void is_prime()
//{
//	memset(prime, true,sizeof(prime));
//	//int j,k;
//	prime[0] =0 ;
//	prime[1] =0;
//	for (int j = 2; j < N; j++)
//	{
//		/*if (prime[j] == 0) 
//			continue;*/
//		if (prime[j])
//		{
//			for (int k = j*j; k < N; k = k + j)
//			{
//				prime[k] = false;
//			}
//		}
//	}
//}
void is_prime()
{
	memset(prime, true, sizeof(prime));
	prime[0] = false;
	prime[1] = false;
	for (int j = 2; j<N; j++)
	{
		if (prime[j])
		{
			//cout<<i<<endl;
			for (int k = j+j; k<N; k += j) //�����ﲻ����������������k=j*j���������� Խ��
			{
				prime[k] = false;
			}
		}
	}
}
bool huiwen(int n)
{
	int zx = n;
	int sum=0;
	while (n)
	{
		sum = sum * 10 + n % 10;
		n = n / 10;
	}
	return (sum == zx);
}
int main()
{
	
	is_prime();
	int i,m=0;
	for (i = 2; i < N; i++)
	{
		if (prime[i] && huiwen(i))
		{
			hwzs[m++] = i;
		}
	}
	int a, b;
	cin >> a>>b;
	for (i = 0; i <= m; i++)
	{
		if (hwzs[i] >= a && hwzs[i] <= b)
		{
			cout << hwzs[i] << endl;
		}
	}
	system("pause");
	return 0;
}
/*
#include <iostream>
#include <cstring>
using namespace std;
#define maxn 9989899+1//���Ľ��Ϊ9989899
bool isPrime[maxn + 1];
int ans[800];//��̵��������������ֹ�781��
void getPrime()
{
	memset(isPrime, true, sizeof(isPrime));
	for (int i = 2; i<maxn; i++)
	{
		if (isPrime[i])
		{
			//cout<<i<<endl;
			for (int j = i + i; j<maxn; j += i)
			{
				isPrime[j] = false;
			}
		}
	}
}
bool isHuiwen(int n)
{
	int sum = 0, nn = n;
	while (n)
	{
		sum = sum * 10 + n % 10;
		n /= 10;
	}
	return sum == nn;
}
int main()
{
	int a, b;
	getPrime();
	int k = 0;
	for (int i = 2; i<maxn; i++)
	{
		if (isPrime[i] && isHuiwen(i))
			ans[k++] = i;
	}
	//cout<<k<<endl;
	while (cin >> a >> b)
	{
		for (int i = 0; i <= k; i++)
		{
			if (ans[i]<a)
				continue;
			else if (ans[i]>b)
				break;
			else
				cout << ans[i] << endl;
		}
		cout << endl;
	}

	return 0;
}
*/

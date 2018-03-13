#define _CRT_SECURE_NO_WARNINGS
/***************************************************************************************************/
/*װ������
ʱ�ޣ�1000ms �ڴ����ƣ�10000K  ��ʱ�ޣ�3000ms
����
�����Ҵ����������ֱ���c1�� c2.  n����װ�䣬������wi(i = 1��n)�������м�װ���������������c1 + c2��ȷ���Ƿ��п��ܽ����м�װ��ȫ��װ�����Ҵ���

����
���������ÿ������������ռ���С���һ��һ����c1��c2��n��n <= 10�����ڶ���n��������ʾwi(i = 1��n)��n����0��־���������

���
����ÿ�������ڵ�����һ�������Yes��No��

��������
7 8 2
8 7
7 9 2
8 8
0 0 0

�������
Yes
No

��ʾ
���������c1�����ֵmax������������max < c2����װ�뵽���Ҵ���
/***************************************************************************************************/
#include<iostream>
#include<cstdio>
#include<fstream>
using namespace std;
 //��װ����
	int weight[11];//��װ������


int dp[100][100];


int max(int a, int b)
{
	return a>b ? a : b;
}
int search(int n, int w)
{
	if (n<0)
		return 0;
	if (dp[n][w] >= 0)
		return dp[n][w];
	if (w >= weight[n])
	{
		dp[n][w] = max(search(n - 1, w - weight[n]) + weight[n], search(n - 1, w));
	}
	else
		dp[n][w] = search(n - 1, w);
	return dp[n][w];
}

int main()
{

	int c1, c2, n;
	while (cin >> c1 >> c2 >> n)
	{

		if (n == 0)
			return 0;

		for (int ii = 0; ii<100; ii++)
			for (int jj = 0; jj<100; jj++)
				dp[ii][jj] = -1;

		for (int i = 0; i<n; i++)
		{
			cin >> weight[i];
		}

		int sum = 0;
		for (int j = 0; j<n; j++)
		{
			sum += weight[j];
		}


		int w1 = search(n - 1, c1);//����װ��1����װ�¶�������
		int w2 = search(n - 1, c2);//����װ��2����װ�¶���O

		if ((sum - w1) <= c2)
		{
			cout << "YES" << endl;
		}
		else if ((sum - w2) <= c1)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}

	}
	return 0;
}



















//struct N
//{
//	int num;  //��װ����
//	int weight;//��װ������
//}st[11];
//
//int b[100][100];
//
//
//int max(int a, int b)
//{
//	return a>b ? a : b;
//}
//int search(int n, int w)
//{
//	if (n<0)
//		return 0;
//	if (b[n][w] >= 0)
//		return b[n][w];
//	if (w >= st[n].weight)
//	{
//		b[n][w] = max(search(n - 1, w - st[n].weight) + st[n].weight, search(n - 1, w));
//	}
//	else
//		b[n][w] = search(n - 1, w);
//	return b[n][w];
//}
//
//int main()
//{
//
//	int c1, c2, n;
//	while (cin >> c1 >> c2 >> n)
//	{
//
//		if (n == 0)
//			return 0;
//
//		for (int ii = 0; ii<100; ii++)
//			for (int jj = 0; jj<100; jj++)
//				b[ii][jj] = -1;
//
//		for (int i = 0; i<n; i++)
//		{
//			st[i].num = i;
//			cin >> st[i].weight;
//		}
//
//		int sum = 0;
//		for (int j = 0; j<n; j++)
//		{
//			sum += st[j].weight;
//		}
//
//
//		int w1 = search(n - 1, c1);//����װ��1����װ�¶�������
//		int w2 = search(n - 1, c2);//����װ��2����װ�¶���O
//
//		if ((sum - w1) <= c2)
//		{
//			cout << "YES" << endl;
//		}
//		else if ((sum - w2) <= c1)
//		{
//			cout << "YES" << endl;
//		}
//		else
//		{
//			cout << "NO" << endl;
//		}
//
//	}
//	return 0;
//}
#include <cstdio>
#include <iostream>
#include<cmath>
using namespace std;

q(int l,int  r,int  m,int  n,int i,int j) {
	return j ? i ? q(l, r, m, n, i&i - 1, 1) + q((l | i & -i) * 2, (r | i & -i) / 2, m | i & -i, n, 0, 0) : 0 : m == n ? 1 : q(l, r, m, n, ~(l | r | m)&n, 1);
}main(n) {
	for (n = 0; n++<15;)
		printf("%d ", q(0, 0, 0, (1 << n) - 1, 0, 0));
}

//int queenPos[100];
//void NQueen(int n, int N);
//int main()
//{
//	int N;
//	cout << "������N��ֵ��";
//	cin >> N;
//	NQueen(0, N);
//	return 0;
//}
//void NQueen(int n, int N)
//{
//	if (n == N)//ִ����ϣ�������
//	{
//		for (int i = 0; i<N; i++)
//		{
//			cout << queenPos[i] + 1 << "   ";
//		}
//		cout << endl;
//		return;
//	}
//	for (int i = 0; i<N; i++)//һ��һ�г���
//	{
//		int j;
//		for (j = 0; j<n; j++)
//		{
//			if (queenPos[j] == i || abs(queenPos[j] - i) == abs(n - j))//����ͬ�����߶Խ�
//				break;
//		}
//		if (j == n)
//		{
//			queenPos[n] = i;
//			NQueen(n + 1, N);
//		}
//	}
//}
int queen(int l, int r, int m, int k) {
	int ans = 0;
	for (int i = (~(l | r | m)) & 0xff; i; i -= i & -i)
		ans += queen((l | (i & -i)) << 1, (r | (i & -i)) >> 1, m | (i & -i), k + 1);
	return k == 8 ? 1 : ans;
}
int main() {
	printf("%d\n", queen(0, 0, 0, 0));
}


//int count=0;
////����row:��ʾ��ʼ��
////����n:��ʾ����
////����(*chess)[8]����ʾָ������ÿһ�е�ָ��
//bool notdanger(int row, int j, int(*chess)[8])
//{
//	int i,k, flag1 = 0; int flag2 = 0; int flag3 = 0; int flag4 = 0;
//	//pan duan lie fx
//	for (i = 0; i < 8; i++)
//	{
//		if (*(*(chess + i) + j) != 0)
//		{
//			flag1 = 1;
//			break;
//		}
//	}
//	//�ж����Ϸ�
//	for (i = row, k = j; i >= 0 && k >= 0; i--, k--)
//	{
//		if (*(*(chess + i) + k) != 0)
//		{
//			flag2 = 1;
//			break;
//		}
//	}
//	//�ж����·�
//	for (i = row, k = j; i<8 && k<8; i++, k++)
//	{
//		if (*(*(chess + i) + k) != 0)
//		{
//			flag3= 1;
//			break;
//		}
//	}
//	//�ж����Ϸ�
//	for (i = row, k = j; i>=0 && k<8; i--, k++)
//	{
//		if (*(*(chess + i) + k) != 0)
//		{
//			flag4 = 1;
//			break;
//		}
//	}
//	//�ж����Ϸ�
//	for (i = row, k = j; i >= 8 && k<8; i--, k++)
//	{
//		if (*(*(chess + i) + k) != 0)
//		{
//			flag4 = 1;
//			break;
//		}
//	}
//}
//void eightqueen(int row,int n,int (*chess)[8])//ָ������ÿһ�е�ָ��
//{
//	int chess2[8][8],i,j;
//	for (i = 0; i < 8; i++)
//	{
//		for (j = 0; j < 8; j++)
//		{
//			chess2[i][j] = chess[i][j];
//		}
//		if (8 == row)
//		{
//			printf("�� %d ��",count + 1);
//			for (i = 0; i < 8; i++)
//			{
//				for (j = 0; j < 8; j++)
//				{
//					printf("%d", *(*chess2 + i) + j);
//				}
//				printf("\n");
//			}
//		printf("\n");
//		count++;
//		}
//			else
//		{
//				//�ж����λ���Ƿ���Σ�ա����û��Σ�գ���������
//				for (j = 0; j < n; j++)
//				{
//					if (notdanger(row,j.chess))//�ж��Ƿ���Σ��
//					{
//						for (i = 0; i < 8; i++)
//						{
//							*(*(chess2 + row) + i) = 0;
//						}
//						*(*(chess2 + row) + j) = 1;
//						eightqueen(row + 1, n, chess2);
//					}
//				}
//		}
//	}
//}             
//int main()
//{
//	int chess[8][8], i, j;
//	for (i = 0; i < 8; i++)    //���̳�ʼ��
//	{
//		for (j = 0; j < 8; j++)
//		{
//			chess[i][j] = 0;
//		}
//	}
//	eightqueen();
//	return 0;
//}
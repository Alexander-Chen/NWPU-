#define _CRT_SECURE_NO_WARNINGS
/*http://blog.csdn.net/theonegis/article/details/45787955 */
#include <cstdio>
#include <cstring>
#include<iostream>
using namespace std;

#include <iostream>

using namespace std;

//const int N = 5;//�ʺ�ĸ���
int N;
int positon[12];//��Żʺ��λ��
int cont = 0;//��¼�ж����ְڷ�

			  /*�жϵ�row�з��õ�λ���Ƿ�����Ҫ��*/
bool valid(int row)
{
	for (int i = 0; i < row; ++i)
	{
		// �����ǰ��ź�λ�õĲ���ͬһ�У�Ҳ���ڶԽ����ϣ��򷵻�true�����򷵻�false
		if (positon[i] == positon[row] || abs(positon[i] - positon[row]) == abs(i - row))
			return false;
	}
	return true;
}

/*����ڷŽ��*/
void print()
{
	cout << "���ǵ�" << ++cont << "�ְڷ���" << '\n';
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (positon[i] == j)
				cout << "�� ";
			else
				cout << "�� ";
		}
		cout << '\n';
	}
	cout << endl;
}

/*���ݷ������ڷ�λ��*/
void trail(int row = 0)
{
	// ���������N�У���������
	if (N == row)
	{
		print();
		return;
	}
	for (int column = 0; column < N; ++column)
	{
		positon[row] = column;// �����ڵ�row�е�column��
							  // ��������������������һ��
		if (valid(row)) trail(row + 1);
		// ����������������������һ��ѭ���������ݻ�ȥ�ڵ�row������Ѱ�Ұڷŵ�λ��
	}
}

int main()
{
	cin >> N;
	trail();
	system("pause");
	return 0;
}
//#include <iostream>  
//#include <cmath>  
//#include <cstring>  
//using namespace std;
//
//int queen[9];
//
////�����ʼ��  
//void init()
//{
//	memset(queen, 0, 9 * sizeof(int));
//}
//
////������  
//void print()
//{
//	for (int i = 1; i<9; i++) cout << queen[i] << "  ";
//	cout << endl;
//}
//
////��֦����  
//bool canPlaceQueen(int k)
//{
//	for (int i = 1; i < k; i++)
//	{
//		//�ж��Ƿ���ͬһ�л�ͬһб��  
//		if (queen[i] == queen[k] || abs(k - i) == abs(queen[k] - queen[i])) return false;
//	}
//	return true;
//}
////�����������˻ʺ����  
//void eightQueen_1()
//{
//	int k = 1;
//	while (k >= 1)
//	{
//		while (queen[k] <= 7)
//		{
//			queen[k] += 1;
//			if (k == 8 && canPlaceQueen(k))
//			{
//				print();
//			}
//			else if (canPlaceQueen(k))
//			{
//				k++;
//			}
//		}
//		queen[k] = 0;
//		k--;
//	}
//}
//
////�ݹ鷽�����˻ʺ����  
//void eightQueen_2(int k)
//{
//	for (int i = 1; i<9; i++)
//	{
//		queen[k] = i;
//		if (k == 8 && canPlaceQueen(k))
//		{
//			print();
//			return;
//		}
//		else if (canPlaceQueen(k))
//		{
//			eightQueen_2(k + 1);
//		}
//	}
//}
//int main()
//{
//	init();
//	//eightQueen_1();
//	    eightQueen_2(1);  
//	system("pause");
//	return 0;
//}


//
//int a[15] = { 0 }, b[2][15] = { 0 }, st[9], pzl[9][9], ttl = 0;
//
//void print(void)
//{
//	memset(pzl, 0, sizeof(pzl));
//	for (int i = 1; i <= 8; ++i)
//		pzl[i][st[i]] = 1;
//
//	printf("%i:\n", ++ttl);
//	for (int i = 1; i <= 8; ++i) {
//		for (int j = 1; j <= 8; ++j)
//			printf("%c ", pzl[i][j] == 1 ? 'X' : 'O');
//		puts("");
//	}
//}
//
//void sch(int n) // ������
//{
//	for (int i = 1; i <= 8; ++i) { // ������
//		int x = n + i - 2, y = n - i + 7;
//
//		if (!a[i] && !b[0][x] && !b[1][y]) { // ������Ľ�
//			st[n] = i;
//			a[i] = b[0][x] = b[1][y] = 1; // ����λ��
//
//			n == 8 ? print() : sch(n + 1); // ����������ж�
//
//			a[i] = b[0][x] = b[1][y] = 0; // ����λ��
//		}
//	}
//}
//
//int main(void)
//{
//	sch(1);
//	system("pause");
//	return 0;
//}

#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<stdio.h>  
#include <iostream>  
using namespace std;
#include <iostream>  
using namespace std;
int fun(int n, int k)//nΪ�У�kΪ��  
{
	if (k == 1 || n == k)//ÿ�е�һ��||���һ�У�ÿ�ж˵����β  
		return 1;
	else
		return fun(n - 1, k - 1) + fun(n - 1, k);//���㹫ʽ  
}
int main()
{
	int n;
	while (1)
	{
		cout << "������n��";
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			for (int k = 1; k<n - i + 1; k++)
				cout << "  ";
			for (int j = 1; j <= i; j++)
				//cout << fun(i, j) << " ";
				printf("%4d", fun(i,j));
			cout << endl;
		}
	}
	return 0;
}
/*��������n������m.�õ����и��е�ֵ****************************************************/
//int fun(int n, int k)//nΪ�У�kΪ��  
//{
//	if (k == 1 || n == k)//ÿ�е�һ��||���һ�У�ÿ�ж˵����β  
//		return 1;
//	else
//		return fun(n - 1, k - 1) + fun(n - 1, k);//���㹫ʽ  
//}
//int main()
//{
//	int n,m;
//	while (1)
//	{
//		//cout << "�������У�";
//		cin >> n>>m;
//			cout << fun(n, m)<<endl;
//		
//	}
//	return 0;
//}
/************************************************************************************/

/**********************************************************************/
//ͨ����Ϲ�ʽ�Ƶ����ɵõ�Ч�ĵ������dwTriVal = dwTriVal * (dwRow - dwCol) / (dwCol + 1)��
void BinomialYangHui(void)
{
	int dwRow = 0, dwCol = 0, dwTriVal;

	for (dwRow = 0; dwRow < MAX_ROW; dwRow++)
	{   //����ֱ�����1�������ɶ���ʽϵ�����ƹ�ʽ������ֵ
		dwTriVal = 1;
		for (dwCol = 0; dwCol <= dwRow; dwCol++)
		{
			printf("%5d", dwTriVal);
			dwTriVal = dwTriVal * (dwRow - dwCol) / (dwCol + 1);
		}
		printf("\n");
	}
}
void printYangHui()//��������ӡ�������  
{
	int rows, coef = 1, space, i, j;
	printf("����: ");
	scanf("%d", &rows);
	for (i = 0; i<rows; i++)
	{
		coef = 1;
		for (space = 1; space <= rows - i; space++)
			printf("  ");
		for (j = 0; j <= i; j++)//��n�е�������n�����j<=i  
		{
			printf("%5d", coef);
			coef = coef * (i - j) / (j + 1);
		}
		printf("\n");
	}

}
/**********************************************************************/
//void printYangHui();
//int main()
//{
//	printYangHui();//  
//	system("pause");
//	return 0;
//}
//void printYangHui()//��������ӡ�������  
//{
//	int rows, coef = 1, space, i, j;
//	printf("����: ");
//	scanf("%d", &rows);
//
//	//��������  
//	for (i = 0; i<rows; i++)
//	{
//		//��ӡ�ո�  
//		for (space = 1; space <= rows - i; space++)
//			printf("  ");
//		//  
//		for (j = 0; j <= i; j++)//��n�е�������n�����j<=i  
//		{
//			//��һ��Ϊ1����һ��Ϊ1  
//			if (j == 0 || i == 0)
//				coef = 1;
//			else
//				coef = coef * (i - j + 1) / j;//���һ��ÿһ��i=j,�����ڶ��У�coef=j������������  
//			printf("%4d", coef);
//		}
//		printf("\n");
//	}
//
//}
//int main()
//{
//	int a[100][200], i, j, n;
//	printf("������nֵ��\n");
//	scanf("%d", &n);
//
//	for (i = 0; i<100; i++)
//		for (j = 0; j<200; j++)
//			a[i][j] = 0;
//
//	for (i = 0; i<n; i++)
//	{
//		for (j = n - 1 - i; j <= i + 5; j = j + 2)
//		{
//			if (j<n - i)
//				a[i][j] = 1;
//			else
//				a[i][j] = a[i - 1][j - 1] + a[i - 1][j + 1];
//		}
//	}
//
//	for (i = 0; i<n; i++)
//	{
//		for (j = 0; j <= i + 5; j++)
//		{
//			if (a[i][j] == 0)
//				printf("    ");
//			else
//				printf("%3d ", a[i][j]);
//		}
//		
//		printf("\n");
//	}
//
//	system("pause");
//}
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<stdio.h>  
void printYangHui();
int main()
{
	printYangHui();//  
	system("pause");
	return 0;
}
void printYangHui()//��������ӡ�������  
{
	int rows, coef = 1, space, i, j;
	printf("����: ");
	scanf("%d", &rows);

	//��������  
	for (i = 0; i<rows; i++)
	{
		//��ӡ�ո�  
		for (space = 1; space <= rows - i; space++)
			printf("  ");
		//  
		for (j = 0; j <= i; j++)//��n�е�������n�����j<=i  
		{
			//��һ��Ϊ1����һ��Ϊ1  
			if (j == 0 || i == 0)
				coef = 1;
			else
				coef = coef * (i - j + 1) / j;//���һ��ÿһ��i=j,�����ڶ��У�coef=j������������  
			printf("%4d", coef);
		}
		printf("\n");
	}

}
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
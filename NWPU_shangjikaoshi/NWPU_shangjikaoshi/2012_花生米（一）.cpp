#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
using namespace std;
#include <stdio.h>
int n;
int main()
{
	int i, j, k;
	int a[2000];
	for (i = 0; i<2000; i++)
		a[i] = 0;
	for (i = 2; i <= 1000; i++)
	{
		for (j = 1; j<10; j++)//ע�⣺�Ǵ���0��С��10 
		{
			if (i - j>0)
			{
				if (a[i - j] == 0) //�ҵ���һ����9�������ڡ���Ϊ0�������Ȼ�󽫴˴ε�ȡ��ת��Ϊ�ϴε������
					a[i] = j;
			}
			else { break; }
		}
	}
	scanf("%d", &n);

	while (n != 0)
	{
		printf("%d\n", a[n]);
		scanf("%d", &n);
	}
	return 0;
}
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
using namespace std;
int max[101][101];                 //ÿ�����ܻ��е�������
int r, c;
int xue[101][101];                 //ѩ�ظ߶�ֵ
int dirx[] = { -1,1,0,0 };            //��x,y����
int diry[] = { 0,0,1,-1 };
bool edge(int x, int y)
{
	if ((x < 0) || (y < 0) || (x > r) || (y > c))
		return false;
	else return true;
	/*return  ((x > 0) && (y > 0) && (x <=r) && (y <=c));*/
}
int dp(int i, int j)
{
	int tmp;
	if (max[i][j]) return max[i][j];        //����Ѿ�������ˣ�ֱ�ӷ���
	for (int k = 0; k < 4; k++)
	{
		if (edge(i+dirx[k], j+diry[k]))     //�ж�Խ��
		{
			if (xue[i][j] > xue[i + dirx[k]][j + diry[k]])            //���˳�Ÿò���Ի�
			{
				tmp = dp(i + dirx[k], j + diry[k]);                 //�ݹ���dp(i + dirx[k], j + diry[k])����������ʱ����temp
				max[i][j] = max[i][j] > tmp ? max[i][j] : tmp +1;
			}
		}
	}
	return max[i][j];
}
int main()
{
	scanf("%d %d", &r, &c);
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			scanf("%d", xue[i] + j);
			max[i][j] = 0;
		}
		
	}

	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			cout << xue[i][j]<<' ';
		}
		cout << endl;
	}
	int temp = 0;
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			cout<<dp(i,j)<<' ';
			if (dp(i, j) > temp)
				temp = dp(i, j);
		}
		cout << endl;
	}
	cout << temp << endl;
	system("pause");
	return 0;
}
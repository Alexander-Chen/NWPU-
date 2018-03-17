#include <iostream>
using namespace std;
char map[10][10];
struct
{
	int h;
	int l;

}cor[90];
int cont;
bool fit(char number, int x, int y)//�ж��Ƿ������������
{
	int i, j;
	for (i = 0; i < 9; i++)
	{
		if (map[x][i] == number || map[i][y] == number)
			return false;
	}
	int kh = x - x % 3;
	int kl = y - y % 3;
	for (i = kh; i < kh + 3; i++)
	{
		for (j = kl; j < kl + 3; j++)
		{
			if (map[i][j] == number)
				return false;
		}
		return true;
	}
}
void search(int x)
{
	int i, j;
	if (x>cont)//�����ɹ����ӡ
	{
		for (i = 0; i<9; i++)
		{
			for (j = 0; j < 8; j++)
		
				cout << map[i][j] << " ";
			
				cout << map[i][8] << endl;
		}
		return;
	}
	for (i = 1; i <= 9; i++)
	{
		char number = i + '0';
		if (fit(number, cor[x].h, cor[x].l))
		{
			map[cor[x].h][cor[x].l] = number;
			search(x + 1);//������һ������������
			map[cor[x].h][cor[x].l] = '0';//��Ҫ�ı䵽ǰһ��״̬
		}
	}
}
int main()
{
	int i, j;
	while (true)
	{
		cont = -1;
		for (i = 0; i < 9; i++)
		{
			for (j = 0; j < 9; j++)
			{
				cin >> map[i][j];//��0����û���������ֵĿո�
				if (map[i][j] == '0')
				{
					++cont;//��¼�ո������
					cor[cont].h = i;//��¼�ո����
					cor[cont].l = j;//��¼�ո����
				}
			}
		}
		search(0);//��ʼ����
		cout << endl;
	}
	return 0;
}
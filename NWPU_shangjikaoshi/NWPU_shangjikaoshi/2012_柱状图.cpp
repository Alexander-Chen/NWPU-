//#include "stdafx.h"
#include <string>
#include <iostream>
#include <ctype.h>
#include <cstdio>
using namespace std;
int main(int argc, char* argv[])
{
	//�����д�Ÿ�����ĸ���ֵĴ���
	unsigned short statistic[26] = { 0 };
	//���ֵ�������
	unsigned short max = 0;
	int i, j;
	/**����������ݲ�ͳ��ÿ����ĸ���ֵĴ���
	*/

	for (i = 0; i < 4; i++)
	{
		string s;
		getline(cin, s);
		for (j = 0; j < s.size(); j++) {
			if (toupper(s[j]) && isalpha(s[j]))
				statistic[s[j] - 'A']++;
		}
	}
	//�ҳ���ĸ���ֵ�������
	for (i = 0; i < 26; i++) {
		if (statistic[i] >max)
			max = statistic[i];
	}
	//��ͳ��ͼ����ߵ����ӳ������������ϲ� ��ĸ���ִ���������һ�㣬�Զ����¼���
	for (i = max; i > 0; i--)
	{
		for (j = 0; j < 25; j++)
		{
			//Ѱ�ҵ�ǰ������ĸ���ִ�����С�ڵ�ǰ�е�����ֵʱ
			if (statistic[j] >= i)
				cout << "* ";  //��� һ�� *  ��һ���ո�
			else
				cout << "  "; //����������������Ŀո�
		}
		if (j == 25)
		{
			if (statistic[j] >= i)
				cout << "*";  //��� һ�� *  ��һ���ո�
			else
				cout << " "; //����������������Ŀո�
		}
		cout << endl;
	}
	//���������һ�е�A-Z��ĸ
	for (i = 0; i < 25; i++)
	{
		printf("%c ", 'A' + i);
	}
	if (i == 25)cout << 'Z';
	//cout << endl;
	system("pause");
	return 0;
}
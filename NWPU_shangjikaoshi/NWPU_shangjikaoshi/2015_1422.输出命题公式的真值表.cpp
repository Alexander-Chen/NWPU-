/*1422.������⹫ʽ����ֵ��
ʱ�ޣ�1000ms �ڴ����ƣ�10000K  ��ʱ�ޣ�3000ms
����
������һ��������n��nС�ڵ���10������ʾ����n�������Ԫ��������һ���������沨�����ʽ���ַ�����ʾһ�����⹫ʽ��Լ���ڸ��ַ�������һλ��ʮ��������ʾһ�������Ԫ����a��o��n��i��e�ֱ��ʾ�ҡ��򡢷ǡ��̺�����ֵ�����������沨�����ʽ��ʽ���ַ�����ʾ�����⹫ʽ����ֵ�������ʽ������Ԫ���㣬������������ǰ��������ں�һԪ���㣬һ����������ǰ��������ں󣩡�
 
����
������һ��С�ڵ���10��������n��������һ���ַ�����
 
���
������ַ�����ʾ�����⹫ʽ����ֵ��
��ʾ��
�����P��Q��R�ֱ��ʾ�����������Ԫ�Ļ���
��������01a2i��ʾ�����⹫ʽ�ǣ�((P��Q)��R)
��������012ia��ʾ�����⹫ʽ�ǣ�(P��(Q��R))
��������0n��ʾ�����⹫ʽ�ǣ���P
 
��������
3
01a2i
 
�������
0 0 0 1
0 0 1 1
0 1 0 1
0 1 1 1
1 0 0 1
1 0 1 1
1 1 0 0
1 1 1 1
 */
/*�ο����룺https://www.cnblogs.com/codeyuan/p/4374999.html */
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
using namespace std; int m = 0; int v = 0; int p = 0;
stack<int> s;
int n, l;
char str[100];
int ans[20];
void slove()
{
	v++;
	int top = 1;
	while (!s.empty()) s.pop();
	char s1, s2;
	//cout << ans[0];
	for (int i = 0; i<l; i++)
	{
		if (str[i] == 'a')
		{
			s2 = s.top(); s.pop();
			s1 = s.top(); s.pop();
			if (s1 == '0' || s2 == '0') s.push('0');
			else s.push('1');
		}
		else if (str[i] == 'o')
		{
			s2 = s.top(); s.pop();
			s1 = s.top(); s.pop();
			if (s1 == '0'&&s2 == '0') s.push('0');
			else s.push('1');
		}
		else if (str[i] == 'i')
		{
			s2 = s.top(); s.pop();
			s1 = s.top(); s.pop();
			if (s1 == '1'&&s2 == '0') s.push('0');
			else s.push('1');
		}
		else if (str[i] == 'e')
		{
			s2 = s.top(); s.pop();
			s1 = s.top(); s.pop();
			if (s1 == s2) s.push('1');
			else s.push('0');
		}
		else if (str[i] == 'n')
		{
			s1 = s.top(); s.pop();
			if (s1 == '0') s.push('1');
			else s.push('0');
		}
		else {
			//cout << ans[top]<<' ';
			char c = ans[top++] + '0'; //cout<<ans[top]<<' '<<c<<' ';
			s.push(c);
		}
	}
}
void print()
{
	p++;
	for (int i = 1; i <= n; i++)
		printf("%d ", ans[i]);
	printf("%c\n", s.top());
}
void dfs(int point)
{
	m++;
	if (point>n) 
	{
		slove(); 
		print(); 
		return; 
	}
	for (int i = 0; i<2; i++)
	{
		ans[point] = i; //cout << point;
		dfs(point + 1);
	}
}

int main()
{
	scanf("%d", &n);
	scanf("%s", str);
	l = strlen(str);
	dfs(1);
	//cout << m << ' ' << v << ' ' << p;;
	system("pause");
	return 0;
}
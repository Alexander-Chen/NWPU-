#include<iostream>
#include<stack>
#include<string>
#include<cstring>
#include<stdlib.h>
#include<cstdio>
#include<vector>
using namespace std; 

bool paren(const std::string &str)
{
	std::stack<char> s;
	for (auto i = 0; i < str.size(); i++)
	{
		switch (str[i])
		{
		case '(':s.push(str[i]); break;
		case '[':s.push(str[i]); break;
		case '{':s.push(str[i]); break;
		case ')':
			if (s.top() != '(')
				return false;
			else
				s.pop(); break;
		case ']':
			if (s.top() != '[')
				return false;
			else
				s.pop(); break;
		case '}':
			if (s.top() != '{')
				return false;
			else
				s.pop(); break;

		default:
			break;
		}
	}
	return s.empty();
}

int main()
{
	int n;
	cin >> n;
	int m = n;
	vector<string>result(n+1);
	while (n>0)
	{
		std::string strBuf;
		cin >> strBuf;
		//std::cout << "The string is : " << strBuf << " ";
		if (paren(strBuf))
		{
			//std::cout << "yes";
			result[n] = "yes";
		}
		else
		{	//std::cout << "no";
			result[n] = "no";
		}
		n--;
	}
	for (int i = m; i >0; i--)
	{
		cout << result[i] << endl;
	}
	//std::cout << std::endl;
	return 0;
}


/*����ƥ����ջ����͵�Ӧ���ˡ�
˼·�ܼ򵥣���������һ�������ž�ѹջ������һ�������ž͵�ջ�����Ƿ�ƥ��ͺ��ˡ��������ջ�Ƿ�Ϊ�վ����ˡ�*/
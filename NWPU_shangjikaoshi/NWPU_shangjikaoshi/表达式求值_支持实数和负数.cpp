//��ν���ʽ��ֵ������дһ��΢�ͼ��������������룺��1 + 9�� * 2 / 2 - 1����������� 9���������������⣬����һ������ջ��ģ����ѧ��������ɡ�
//Ϊ�˼����⣬�ڼ�������ķ���֮ǰ�����ڴ�����Լ��������ֻ���� + -*/ ()�������������㣬���ⲻ��������ֵķ��ţ����� ^���Ͳ����Ϲ淶����ѧ���ʽ
//������ 2 * -1�����쳣����

//����˼·������
//������һ���ַ����飨��char s[1000]�����洢��ѧ���ʽ������һ��ȫ�ֱ��� g_pos ��ʾ s[] ���±꣬�±�� 0 ��ʼ���������Ƕ�������ջ��optr �� opnd��
//�ֱ�洢�������������������������ֱ�ӷŽ� opnd������������������������
//��1�����������ţ�
//��2�������������ţ�
//��3�������������ţ�
//��4�������� + -*/ ��
//
//ǰ�������������⣬�����̸�µ�������������Ƕ�֪��������������ѭ�ȳ˳��ټӼ��ģ���˶���ÿ������������Ƕ�Ҫ�� optr ��ջ�����ŵȼ��Ƚϣ����
//������ŵĵȼ��� optr ջ�����ŵȼ��ߣ�ʲôҲ������ֱ�ӷŽ�ջ�����С�ڵ��ڣ�����Ҫ�� opnd ��ջ���������ֳ���������м��㡣�����и����⣬������
//��һ�������ʱ����ʱ optr Ϊ�գ�����������Ҫ�� optr ջ��������Ƚϵȼ�����ʱ����ô�죿Ϊ�˽��������⣬�����ڳ�ʼ�� optr ��ʱ�򣬷Ž�һ�� #��������ȼ�Ϊ��͡�
//
//������������ܻ�����һ�����ʣ�����ж����� - �Ǹ��Ż��Ǽ��ţ����� - 1 + 2 �� 5 - 1 + 2���������֣����ָ���ֻ�����������
//��1��������������ţ����磨 - 1 + 5 * 3����
//��2�����ַ����ĵ�һ���ַ������� - 5 * 6 - 1��
//
//Ϊ�˷��������д�������ָ��ţ�����������ջ����һ������ 0����Ҳ���������������� bool ֵ is_minus ��ԭ�򣩣���ת��һ�±��ʽ������ - 1 + 2 ת��Ϊ 0 - 1 + 2��*/
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>
#include <cmath>
using namespace std;

char s[1000];
int  g_pos;  // �ַ�������±�

			 /* �ַ�ת���� */
double Translation(int & pos)
{
	double integer = 0.0;    // ��������
	double remainder = 0.0;  // ��������

	while (s[pos] >= '0' && s[pos] <= '9')
	{
		integer *= 10;
		integer += (s[pos] - '0');
		pos++;
	}

	if (s[pos] == '.')
	{
		pos++;
		int c = 1;
		while (s[pos] >= '0' && s[pos] <= '9')
		{
			double t = s[pos] - '0';
			t *= pow(0.1, c);
			c++;
			remainder += t;
			pos++;
		}
	}

	return integer + remainder;
}

/* ������������� */
int GetLevel(char ch)
{
	switch (ch)
	{
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	case '(':
		return 0;
	case '#':
		return -1;
	};
}

/* ���������������� */
double Operate(double a1, char op, double a2)
{
	switch (op)
	{
	case '+':
		return a1 + a2;
	case '-':
		return a1 - a2;
	case '*':
		return a1 * a2;
	case '/':
		return a1 / a2;
	};
}

/* ��������ջ����ģ����� */
double Compute()
{
	stack<char> optr;    // ������ջ
	stack<double> opnd;  // ������ջ

	optr.push('#');
	int len = strlen(s);
	bool is_minus = true;  // �ж�'-'�Ǽ��Ż��Ǹ���

	for (g_pos = 0; g_pos < len;)
	{
		//1. ����  
		if (s[g_pos] == '-' && is_minus)  // �Ǹ���
		{
			opnd.push(0);
			optr.push('-');
			g_pos++;
		}
		//2. �������� ) 
		else if (s[g_pos] == ')')
		{
			is_minus = false;
			g_pos++;

			while (optr.top() != '(')
			{
				double a2 = opnd.top();
				opnd.pop();
				double a1 = opnd.top();
				opnd.pop();
				char op = optr.top();
				optr.pop();

				double result = Operate(a1, op, a2);
				opnd.push(result);
			}

			optr.pop();  // ɾ��'('  
		}
		//3. ����  
		else if (s[g_pos] >= '0' && s[g_pos] <= '9')
		{
			is_minus = false;
			opnd.push(Translation(g_pos));
		}
		//4. ( ������  
		else if (s[g_pos] == '(')
		{
			is_minus = true;
			optr.push(s[g_pos]);
			g_pos++;
		}
		//5. + - * / ����  
		else
		{
			while (GetLevel(s[g_pos]) <= GetLevel(optr.top()))
			{
				double a2 = opnd.top();
				opnd.pop();
				double a1 = opnd.top();
				opnd.pop();
				char op = optr.top();
				optr.pop();

				double result = Operate(a1, op, a2);
				opnd.push(result);
			}

			optr.push(s[g_pos]);
			g_pos++;
		}
	}

	while (optr.top() != '#')
	{
		double a2 = opnd.top();
		opnd.pop();
		double a1 = opnd.top();
		opnd.pop();
		char op = optr.top();
		optr.pop();

		double result = Operate(a1, op, a2);
		opnd.push(result);
	}

	return opnd.top();
}

int main()
{
	while (cin >> s)
		cout << "���Ϊ��" << Compute() << endl << endl;

	return 0;
}

//char s[1000];
//int  g_pos;  // �ַ�������±�
//
//			 /* �ַ�ת���� */
//double Translation(int & pos)
//{
//	double integer = 0.0;    // ��������
//	double remainder = 0.0;  // ��������
//
//	while (s[pos] >= '0' && s[pos] <= '9')
//	{
//		integer *= 10;
//		integer += (s[pos] - '0');
//		//integer = atof(&s[pos]);
//		pos++;
//	}
//
//	if (s[pos] == '.')
//	{
//		pos++;
//		int c = 1;
//		while (s[pos] >= '0' && s[pos] <= '9')
//		{
//			double t = s[pos] - '0';
//			t =t* pow(0.1, c);
//			c++;
//			remainder += t;
//			pos++;
//		}
//	}
//
//	return integer + remainder;
//}
//
///* ������������� */
//int GetLevel(char ch)
//{
//	switch (ch)
//	{
//	case '+':
//	case '-':
//		return 1;
//	case '*':
//	case '/':
//		return 2;
//	case '(':
//		return 0;
//	case '#':
//		return -1;
//	};
//}
//
///* ���������������� */
//double Operate(double a1, char op, double a2)
//{
//	switch (op)
//	{
//	case '+':
//		return a1 + a2;
//	case '-':
//		return a1 - a2;
//	case '*':
//		return a1 * a2;
//	case '/':
//		return a1 / a2;
//	};
//}
//
///* ��������ջ����ģ����� */
//double Compute(char *s)
//{
//	stack<char> optr;    // ������ջ
//	stack<double> opnd;  // ������ջ
//
//	optr.push('#');
//	int len = strlen(s);
//	bool is_minus = true;  // �ж�'-'�Ǽ��Ż��Ǹ���
//
//	for (g_pos = 0; g_pos < len;)
//	{
//		//1. ����  
//		if (s[g_pos] == '-' && is_minus)  // �Ǹ���
//		{
//			opnd.push(0);
//			optr.push('-');
//			g_pos++;
//		}
//		//2. �������� ) 
//		else if (s[g_pos] == ')')
//		{
//			is_minus = false;
//			g_pos++;
//
//			while (optr.top() != '(')
//			{
//				double a2 = opnd.top();
//				opnd.pop();
//				double a1 = opnd.top();
//				opnd.pop();
//				char op = optr.top();
//				optr.pop();
//
//				double result = Operate(a1, op, a2);
//				opnd.push(result);
//			}
//
//			optr.pop();  // ɾ��'('  
//		}
//		//3. ����  
//		else if (s[g_pos] >= '0' && s[g_pos] <= '9')
//		{
//			is_minus = false;
//			opnd.push(Translation(g_pos));
//		}
//		//4. ( ������  
//		else if (s[g_pos] == '(')
//		{
//			is_minus = true;
//			optr.push(s[g_pos]);
//			g_pos++;
//		}
//		//5. + - * / ����  
//		else
//		{
//			while (GetLevel(s[g_pos]) <= GetLevel(optr.top()))
//			{
//				double a2 = opnd.top();
//				opnd.pop();
//				double a1 = opnd.top();
//				opnd.pop();
//				char op = optr.top();
//				optr.pop();
//
//				double result = Operate(a1, op, a2);
//				opnd.push(result);
//			}
//
//			optr.push(s[g_pos]);
//			g_pos++;
//		}
//	}
//
//	while (optr.top() != '#')
//	{
//		double a2 = opnd.top();
//		opnd.pop();
//		double a1 = opnd.top();
//		opnd.pop();
//		char op = optr.top();
//		optr.pop();
//
//		double result = Operate(a1, op, a2);
//		opnd.push(result);
//	}
//
//	return opnd.top();
//}
//
//int main()
//{
//	//while (cin >> s)
//	int n;
//	cin >> n;
//	while (n--)
//	{		
//		cin >> s;	
//		cout << "���Ϊ��" << Compute(s) << endl;
//	}
//	system("pause");
//	return 0;
//}
//char str[50];
//const char * p = "+-*/";
//int i;
//using namespace std;
//int cmp(char c)
//{
//	if (c == '+' || c == '-') return 1;
//	if (c == '*' || c == '/') return 2;
//	if (c == '(') return 0;
//	if (c == '#') return -1;
//
//}
//double run(double x, double y, char c)
//{
//	switch (c)
//	{
//	case '+':return x + y;
//	case '-':return x - y;
//	case '*':return x * y;
//	case '/':return x / y;
//	};
//
//}
//double trs(int i)
//{
//	double integer = 0.0;
//	double remainder = 0.0;
//	while (str[i] >= '0'&&str[i] <= '9')
//	{
//		integer = integer * 10;
//		integer += (str[i] - '0');
//		i++;
//	}
//	if (str[i] == '.')
//	{
//		i++;
//		int s = 1;
//		while (str[i] >= '0'&&str[i] <= '9')
//		{
//			double t = str[i] - '0';
//			t = t * pow(0.1, s);
//			s++;
//			remainder += t;
//			i++;
//		}
//	}
//	return integer + remainder;
//}
//double calc()
//{
//	stack<char> sgn;
//	stack<double> num;
//	sgn.push('#');
//	bool is_f = true;
//	int t = strlen(str);
//	for (i = 0; i<t;)
//	{
//		if (str[i] == '-'&&is_f)
//		{
//			num.push(0);
//			sgn.push('-');
//			i++;
//		}
//		else if (str[i] == '(')
//		{
//			is_f = true;
//			sgn.push(str[i]);
//			i++;
//		}
//		else if (str[i] >= '0'&&str[i] <= '9')
//		{
//			is_f = false;
//			num.push(trs(i));
//			cout << trs(i);
//		}
//		else if (str[i] == ')')
//		{
//			is_f = false;
//			i++;
//			while (sgn.top() != '(')
//			{
//				double a2 = num.top();
//				num.pop();
//				double a1 = num.top();
//				num.pop();
//				char op = sgn.top();
//				sgn.pop();
//				num.push(run(a1, a2, op));
//			}
//			sgn.pop();
//		}
//		else //if(str[i]==*p)
//		{
//			is_f = false;
//			while (cmp(str[i]) <= cmp(sgn.top()))
//				//		sgn.push(str[i]);
//				//	else {
//			{
//				double a2 = num.top();
//				num.pop();
//				double a1 = num.top();
//				num.pop();
//				char op = sgn.top();
//				sgn.pop();
//				num.push(run(a1, a2, op));
//				sgn.push(str[i]);
//			}
//			sgn.push(str[i]);
//			i++;
//
//		}
//
//		while (sgn.top() != '#')
//		{
//			double a2 = num.top();
//			num.pop();
//			double a1 = num.top();
//			num.pop();
//			char op = sgn.top();
//			sgn.pop();
//			num.push(run(a1, a2, op));
//		}
//
//	}
//	return num.top();
//}
//int main()
//{
//	//scanf("%s",str);
//	cin >> str;
//	cout << calc();
//	system("pause");
//	return 0;
//}
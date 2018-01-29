#include <iostream>
#include <stack>
#include<vector>
#include<string>


using namespace std;
/*ʹ��vector��ʵ��string����������*/
/*
int main()
{
	vector<string>str;
	string s;
	int a{0};
	while (cin >> s)
	{
		str.push_back(s);
		cout << str[a] << endl;
		++a;
	}
	
	return 0;
}
*/

/*��C++ ģ���STL��stackջ�ĳ��ò�������ϰ*/
/*
int main()
{
	stack<string> a;
	cout << "��ջ���̣�"<<endl;
	for (int i = 0; i < 5; i++)
	{ 
		string s;
		cin >> s;
		a.push(s);
		cout <<"������ջ��Ԫ��Ϊ��"<< a.top()<<endl;
		cout << "ջ��Ԫ�ظ���Ϊ��" << a.size() << endl;
	}
	cout << "��ջ����:"<<endl;
	while (!a.empty())
	{
		cout << "���γ�ջ��ջ��Ԫ��Ϊ��" << a.top() << endl;;
		a.pop();
		cout << "ջ��Ԫ�ظ���Ϊ��" << a.size() << endl;
	}
	
	return  0;
}
*/

#include<iostream>  
#include<stack>  
#include<string>  
using namespace std;

/*�жϷ��ż�����ȹ�ϵ����
*1��ʾ>,0��ʾ=,-1��ʾ<
*c1ջ�ڵ������c2ջ������
*/
int Judge(char c1, char c2)
{
	int a1, a2;
	if ('+' == c1 || '-' == c1) a1 = 3;
	if ('*' == c1 || '/' == c1)a1 = 5;
	if ('(' == c1) a1 = 1;
	if (')' == c1) a1 = 7;
	if ('#' == c1) a1 = 0;

	if ('+' == c2 || '-' == c2)a2 = 2;
	if ('*' == c2 || '/' == c2)a2 = 4;
	if ('(' == c2) a2 = 6;
	if (')' == c2) a2 = 1;
	if ('#' == c2) a2 = 0;
	if (a1>a2) return 1;
	if (a1 == a2) return 0;
	if (a1<a2) return -1;
}
//�������㺯��  
double run(char c, double d1, double d2)
{
	switch (c)
	{
	case '+':
		return d1 + d2;
		break;
	case '-':
		return d1 - d2;
		break;
	case'*':
		return d1 * d2;
		break;
	case '/':
		return d1 / d2;
		break;
	default:
		return 0.0;
		break;
	}
}

double calculate(string str)
{
	const char * op = "+-*/()#";
	//string str;
	//cin >> str;
	//�����ʽ�ַ���str���'#'������ʶ��  
	str.append(1, '#');
	stack<char> OPTR;//�����ջ  
	stack<double> OPND;//������ջ  
	int a = -1;
	//�Ƚ�#������ջ  
	OPTR.push('#');
	while (true)
	{
		int b = a + 1;
		a = str.find_first_of(op, a + 1);
		if (a == string::npos) break;
		if (a != b)
		{
			string ss(str, b, a - b);
			double d = atof(ss.c_str());
			//��������ջ  
			OPND.push(d);
		}
		//��������ȼ��Ƚ�  
		int ju = Judge(OPTR.top(), str[a]);
		if (-1 == ju)//ջ�����ȼ���ֱ����ջ  
		{
			OPTR.push(str[a]);
		}
		if (0 == ju)//ջ�������ȼ�������ջ  
		{
			OPTR.pop();
		}
		if (1 == ju)//ջ�����ȼ���,��ջ��������  
		{
			double d1 = OPND.top();
			OPND.pop();
			double d2 = OPND.top();
			OPND.pop();
			d1 = run(OPTR.top(), d2, d1);
			//��������ջ  
			OPND.push(d1);
			OPTR.pop();
			a--;
		}
	}
	//ɾ�����ʽ����'#'������ʶ��  
	str.erase(str.length() - 1, 1);
	return OPND.top();
}
int main()
{
	int n;	
	cin >> n;
	const int m = n;
	vector <double> display(n+1);
	//vector <string> biaodashi(n+1);
	while (n > 0)
	{
		string str;
		cin >> str;
		//biaodashi[n] = str;
		double result = calculate(str);
		display[n] = result;
		n--;
	};
	for(int j=m;j>0;j--)
	cout /*<< biaodashi[j] << " = "*/ << display[j] << endl;
	return 0;
}





















/*�����㷨-�������ʽ��ֵ
˼����Ҫ���õ���ջ�Ƚ���������ݽṹ���ڸó����н�������ջ��һ�����ڴ洢���������һ�����ڴ洢��������������������
�����ǣ�

��1�����������ò�����ջΪ��ջ�����������ջ�ԡ�#��Ϊջ��Ԫ�أ������ȼ���ͣ���

��2����ͨ��Ϊջ��ջ�����������ֵ���Ƚ������ȼ�

��3��������ȥ�ҵ����ʽ�е�����������Ͳ����������ڲ�����ֱ����ջ���������������ջ��

ջ��������бȽ����ȼ�����ջ�����ȼ����������Ӧ��������������ջ�����������ջ�������ȼ����ֻ��

ջ���������ջ����������һ����������ɣ���ջ�����ȼ�����ջ���������ջ������ѭ��֪����������ʽ��

������������Ͳ��������ɡ�

��4��������ڲ�����ջ�н�ֻ��ʣ��Ψһ��һ��Ԫ�أ�����Ԫ��Ҳ���ͻ���������ʽ��ֵ��

2 ��׺���ʽ�ͺ�׺���ʽ

��׺���ʽ����ͨ����˵���������ʽ������(1+2)*3-4��

��׺���ʽ��ָͨ���������������������֮��ı��ʽ��������ʽ�����ɺ�׺���ʽ����12+3*4-�����ֱ��ʽ����ֱ������ջ����⡣

3 ����������ȼ�

���ȼ� �����
1 ����()
2 ����-
3 �˷�**
4 ��*����/������%
5 ��+����-
6 С��<��С�ڵ���<=������>�����ڵ���>=
7 ����==��������!=
8 �߼���&&
9 �߼���||
���µĹ����ǣ�һԪ����� > ��Ԫ����� > ��Ԫ�������
*/

//����׺���ʽ�����ɺ�׺���ʽ
/*
��׺���ʽ����ɺ�׺���ʽ�ķ������£�
��1��������������ȡ������ch��
��2�����ch�ǲ�������ֱ�������
��3�����ch������������������ţ�����
a�����ch = '('�������ջ��
b�����ch = ')'�����������ջ�е��������ֱ������'('Ϊֹ��
c�����ch����')'����'('����ô�ͺͶ�ջ����λ�õ������top�����ȼ��Ƚϡ�
1�����ch���ȼ���top�ߣ���ô��ch�����ջ��
2�����ch���ȼ����ڻ��ߵ���top����ô���top��Ȼ��ch�����ջ��
��4��������ʽ�Ѿ���ȡ��ɣ�����ջ�л��������ʱ�������ɶ��������
��������б��ʽ(A-B)*C+D-E/F��Ҫ����ɺ�׺���ʽ�����ҰѺ�׺���ʽ�洢��һ������output���ַ����У�����������Ĳ��衣

��1����ȡ'('��ѹ���ջ��outputΪ��
��2����ȡA������������ֱ�������output�ַ�����output = A
��3����ȡ'-'����ʱջ����ֻ��һ��'('����˽�'-'ѹ��ջ��output = A
��4����ȡB������������ֱ�������output�ַ�����output = AB
��5����ȡ')'����ʱ���������ջ����������'-'��Ȼ�����'('��ֱ�ӵ�����output = AB-
��6����ȡ'*'��������������ڴ�ʱջΪ�գ����ֱ��ѹ��ջ��output = AB-
��7����ȡC������������ֱ�������output�ַ�����output = AB-C
��8����ȡ'+'������������������ȼ���'*'�ͣ���ô����'*'��ѹ��'+"��output = AB-C*
��9����ȡD������������ֱ�������output�ַ�����output = AB-C*D
��10����ȡ'-'�������������'+'�����ȼ�һ������˵���'+'��Ȼ��ѹ��'-'��output = AB-C*D+
��11����ȡE������������ֱ�������output�ַ�����output = AB-C*D+E
��12����ȡ'/'�������������'-'�����ȼ��ߣ����ѹ��ջ��output = AB-C*D+E
��13����ȡF������������ֱ�������output�ַ�����output = AB-C*D+EF
��14��ԭʼ�ַ����Ѿ���ȡ��ϣ���ջ����ʣ�����������ε�����output = AB-C*D+EF/-
*/
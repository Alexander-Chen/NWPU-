/*�����㷨-�������ʽ��ֵ
���ö�ջ�����������ʽ�Ļ���������������ʾ�������ܽ����κΰ���+��-��*��/��()��0��9������ɵ��������ʽ��

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
#include<iostream>
#include<string.h> 
#include<stdlib.h>
using namespace std;
template <class T>
class stack
{
public:
	stack() { top = -1; SIZE = 2; buffer = new T[SIZE]; }; //SIZE=2����С�����ڲ���PUSH���� 
	~stack() { if (buffer) delete[]buffer; };//��������
	bool push(T element); //��ջ
	T& pop();//��ջ
	int size() { return top + 1; };//ȡԪ�ظ���
	bool isempty() { return top == -1; }
	void clear() { top = -1; }
private:
	T * buffer;
	int top;
	int SIZE;
};
template <class T>
bool stack<T>::push(T element)
{
	top++;
	if (top>SIZE - 1)
	{
		SIZE += 10;
		T* temp = new T[SIZE];
		//  for(int i=0;i<SIZE-10;i++)
		// temp[i]=buffer[i];//������ COPY 
		memcpy((void*)temp, (void*)buffer, (SIZE - 10) * sizeof(T));//���ַ������� 
		delete buffer;
		buffer = temp;
	}//��
	buffer[top] = element;
	return true;
}
template <class T>
T& stack<T>::pop()
{
	return buffer[top--];
}
bool IsOperand(char ch)
{
	char operators[] = { '+', '-', '*', '/', '(', ')' };
	for (int i = 0; i<6; i++)
		if (ch == operators[i])
			return false;
	return true;
}
int Priority(char ch)
{
	int priority;
	switch (ch)
	{
	case '+':
		priority = 1;
		break;
	case '-':
		priority = 1;
		break;
	case '*':
		priority = 2;
		break;
	case '/':
		priority = 2;
		break;
	default:
		priority = 0;
		break;
	}
	return priority;
}
double GetValue(char op, double ch1, double ch2)
{
	switch (op)
	{
	case '+':
		return ch2 + ch1;
	case '-':
		return ch2 - ch1;
	case '*':
		return ch2 * ch1;
	case '/':
		return ch2 / ch1;
	default:
		return 0;
	}
}
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
char* Parse(const char *expr)
{
	//  const char *exp = expr;
	int i, j = 0;
	char ch, ch1;
	const char* A = expr;
	char *B = new char[strlen(expr) + 1]; //������ɵĺ�׺���ʽ
	stack<char>  myStack;
	for (i = 0; ch = A[i]; i++)//A[I]='
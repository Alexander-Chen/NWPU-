/*********************************************************************************
1.������

�Ѷ�������ת����ʮ��������

���룺
������һ��8λ�Ķ���������
�����
���������ת��Ϊʮ�����������
����������
10000001
���������
129
/*********************************************************************************/

#include <iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
	int n;
	int a[8];  //ֻ��0-7
	int i;
	int sjz = 0;
	cin >> n;
	for (i = 0; i<8; i++)
	{
		a[i] = n % 10;
		//   cout<<a[i]<<endl;
		n = n / 10;

	}
	for (i = 0; i<8; i++)
	{
		sjz = sjz + a[i] * pow(2, i);
	}
	cout << sjz << endl;;
	system("pause");
	return 0;
}
//int main()
//{
//    int n=0b10000001;
//    cout << n<< endl;
//    return 0;
//}
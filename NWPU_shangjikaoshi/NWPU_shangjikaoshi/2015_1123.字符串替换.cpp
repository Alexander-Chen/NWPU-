/*ʾ������1*/
//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//	string a, b, c,d;
//	cin >> a;
//	cin >> b;
//	cin >> c;
//	int n=a.find_first_of(b);
//	if (a.find_first_of(b) < size(a))
//	{
//		if (n != string::npos)
//			//ɾ��ָ�������_ʼ��ָ�����ȵ��ַ�
//			 a.erase(n, b.length()) ;
//		a.insert(n, c);
//	}
//	//int index = a.find(b);
//	cout << a;
//	system("pause");
//	return 0;
//}

/*ʾ������2*/
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string a, b, c, d;
	cin >> a;
	cin >> b;
	cin >> c;
	int n = a.find_first_of(b);
	if (a.find_first_of(b) < size(a))
	{
		a.replace(n, size(b), c);
	}
	cout << a;
	system("pause");
	return 0;
}

/*Stringʹ�÷���*/
//#include <iostream>  
//#include <string>  
//using std::cout;
//using std::endl;
//using std::string;
//int main(void) {
//	string str1 = "We can insert a string";
//	string str2 = "a str into ";
	////���ַ���ָ��λ��ǰ�����ָ���ַ���  
	//cout << str1.insert(14, str2) << endl;
	////���ַ���ָ��λ��ǰ�����ָ���ַ������Ӵ�����ָ��������ʼ��ָ���������ַ���  
	//cout << str1.insert(14, str2, 2, 9) << endl;
	////����ָ���ַ�����ǰn���ַ�  
	//cout << str1.insert(14, "test hello", 5) << endl;
	////����n����ͬ�ַ����ַ�����  
	//cout << str1.insert(14, 6, '*') << endl;

	////�滻ָ��������ʼ��ָ�����ȵ��Ӵ�  
	//cout << str1.replace(3, 3, "may") << endl;
	//�ø����ַ�����ָ���Ӵ��������滻  
	//���£�ʵ����ʹ�õ���could�������滻  
//	cout << str1.replace(3, 3, "can could", 4, 5) << endl;
//	//ʹ�ø����ַ�����ǰn���ַ��������滻��can  
//	cout << str1.replace(3, 5, "can could", 3) << endl;
//	//ʹ��ָ���������ظ��ַ��������滻  
//	cout << str1.replace(3, 3, 5, '*') << endl;
//
//	string word = "We";
//	size_t index = str1.find(word);
//	if (index != string::npos)
//		//ɾ��ָ��������ʼ��ָ�����ȵ��ַ�  
//		cout << str1.erase(index, word.length()) << endl;
//	system("pause");
//	return 0;
//
//}


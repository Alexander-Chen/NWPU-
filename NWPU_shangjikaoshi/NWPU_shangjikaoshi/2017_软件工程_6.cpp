#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<string>
#include <cctype> 
using namespace std;
int main()
{
	fstream danci;
	danci.open("D:\\Github\\NWPU-shangjikaoshi\\NWPU_shangjikaoshi\\NWPU_shangjikaoshi\\�������2017_6.txt");
	string s1,s2,s,s3;
	int num=0;
	cin>>s3;
	transform(s3.begin(), s3.end(), back_inserter(s1), ::toupper);
	transform(s3.begin(), s3.end(), back_inserter(s2), ::tolower);
	//cout << s1 <<"  "<< s2<<endl;
	while (danci >> s)
	{
		if (s == s1 || s == s2)
			num++;
	}
	cout << num<<endl;
	danci.close();
	system("pause");
	return 0;
}

/************************************************************/
/*
char*strupr(char *string)

���ܣ����ַ���string�е�Сд��ĸת��Ϊ��д��������ָ��string��ָ�롣

char*strlwr(char *string)

���ܣ����ַ���string�еĴ�д��ĸת��ΪСд��������ָ��string��ָ�롣





#include<iostream>  
#include<string.h>  
#include <string>  
using namespace std;
void main(void)
{
	char *p;
	std::string  m("Design and implementation of the remote location robot and control system ");
	p = strupr((char *)m.c_str());
	cout << p << "      " << m << endl;
	std::string n("DFGRADGHHEVGV");
	p = strlwr((char*)n.c_str());
	cout << p << "    " << n << endl;
	getchar();
}
/********************************************************************************/
#include<iostream>
using namespace std;
//��������: ����Catalan���еĵ�n��  
//��������: ����n  
//����ֵ:   ��n��Catalan��  
//long Catalan(int n)
//{
//	if (n <= 1)
//		return 1;
//	long *h = new long[n + 1]; //������ʱ���  
//	h[0] = h[1] = 1;        //h(0)��h(1)  
//	for (int i = 2; i <= n; i++)    //���μ���h(2),h(3)...h(n)  
//	{
//		h[i] = 0;
//		for (int j = 0; j < i; j++) //���ݵݹ�ʽ���� h(i)= h(0)*h(i-1)+h(1)*h(i-2) + ... + h(i-1)h(0)  
//			h[i] += (h[j] * h[i - 1 - j]);
//	}
//	long result = h[n]; //������  
//	delete[] h;       //ע���ͷſռ�  
//	return result;
//}
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		cout << Catalan(n)<<endl;
//	}
//	return 0;
//}
#include <iostream>
using namespace std;
//����������ԭ��Ӧ��
int catalan(int n) {

	if (n == 1)return 1;
	if (n == 2)return 1;
	int res = 0;
	for (int i = 1; i <= n - 1; i++) {
		res =res+ catalan(i)*catalan(n - i);
	}
	return res;

}
//���Ժ���
int main() {
	int n;
	while (cin >> n) {

		cout << catalan(n) << endl;
	}
	return 0;
}
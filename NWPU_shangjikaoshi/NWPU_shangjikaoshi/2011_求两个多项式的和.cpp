/******************************************************************/
/*��Ŀ1472������������ʽ�ĺ�
ʱ�����ƣ�1 ���ڴ����ƣ�128 ���������⣺���ύ��40�����9
��Ŀ������
������������ʽ���������ǵĺ͡�
ÿ������ʽ�����ɶ�������ʾ��ÿ�������У���һ��������ʾϵ������0�����ڶ���������ʾ����Ĵ�����
����3 3 5 - 2 1 4 0��ʾ3x ^ 5 - 2 * x + 4���е�һ��3��ʾ�ö���ʽ�����������Ա�ʾ��

���룺
����Ϊ���У��ֱ��ʾ��������ʽ����ʾÿ�������
�԰��մ�����С���������(��������ֵС��1000��ϵ������ֵС��10000)

�����
���ս���˳�������ʾ�Ͷ���ʽ�������ԣ�ϵ��Ϊ0�������Բ���������������ɿո�ָ������һ�������Ժ���ӿո�

�������룺
3 3 5 - 2 1 4 0
4 2 3 - 1 2 1 1 3 0
���������
3 5 2 3 - 1 2 - 1 1 7 0
��Դ��2011��������ҵ��ѧ������о�����������
/**************************************************************************/
#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>  
#include<string.h>  
#include<iostream>
using namespace std;
int mici[22];
int main()
{
	FILE * p = fopen("D:\\Github\\NWPU-shangjikaoshi\\NWPU_shangjikaoshi\\test data\\polyn.txt", "r+");
	int n1, n2;
	while (fscanf(p, "%d", &n1))
	{
		memset(mici, 0, sizeof(mici));

		//cin>>n1;
		for (int i = 0; i<n1; i++)
		{
			int xishu;
			int mi;
			fscanf(p, "%d", &xishu);//cin>>xishu;
			fscanf(p, "%d", &mi);//cin>>mi;
			mici[mi] = xishu;
		}
		fscanf(p, "%d", &n2);
		if (n1 == 0 && n2 == 0) break;//cin>>n2;
		for (int i = 0; i<n2; i++)
		{
			int xishu;
			int mi;
			fscanf(p, "%d", &xishu);//cin>>xishu;
			fscanf(p, "%d", &mi);//cin>>mi;
			mici[mi] = mici[mi] + xishu;
		}
		for (int i = 20; i >= 0; i--)
		{
			if (mici[i] == 0)
			{
				continue;
			}
			cout << mici[i] << ' ' << i << ' ';
		}
		cout << endl;
	}
}

//int arr[2001] = { 0 };
//
//int main() {
//	int n, m, i, a, b, first;
//	//int array[2001];
//	while (scanf("%d", &n) != EOF) {
//		first = 1;
//		memset(arr, 0, sizeof(arr));
//		//����ʽһ  
//		for (i = 0; i < n; i++) {
//			scanf("%d %d", &a, &b);
//			arr[b + 1000] = a;
//		}
//		//����ʽ��  
//		scanf("%d", &m);
//		for (i = 0; i < m; i++) {
//			scanf("%d %d", &a, &b);
//			//��ͬ����ϵ�����  
//			arr[b + 1000] += a;
//		}
//		//���  
//		for (i = 2001; i >= 0; i--) {
//			//ϵ��Ϊ0�������Բ������  
//			if (arr[i] == 0) {
//				continue;
//			}
//			//���Ƹ�ʽ  
//			/*if (first) {
//				first = 0;
//			}
//			else {
//				printf(" ");
//			}*/
//			//printf("%d %d", array[i], i - 1000);
//			cout << arr[i] << ' ' << i - 1000 << ' ';
//		}
//		printf("\n");
//	}
//	return 0;
//}
/*
����������
ʱ�ޣ�1000ms �ڴ����ƣ�10000K  ��ʱ�ޣ�3000ms
����
����һ�������еı�����£�

A B C
D E F

��1��2��3��4��5��6�������ֱַ�����A��B��C��D��E��F�����У�ÿ������һ�������Ҹ�����ͬ��ÿ�ֲ�ͬ�����Ϊһ�ֲ��֡����£�

1 3 5
2 4 6
����1

2 5 6
4 3 1
����2

������任���£���A���е����ַ���B�񣬰�B���е����ַ���E�񣬰�E���е����ַ���D�񣬰�D���е����ַ���A��
����±任���£���B���е����ַ���C�񣬰�C���е����ַ���F�񣬰�F���е����ַ���E�񣬰�E���е����ַ���B��

�ʣ����ڸ����Ĳ��֣��ɷ�ͨ�����޴εĦ��任�ͦ±任��������Ŀ�겼�֣�

1 2 3
4 5 6

����
�����ж����������һ��Ϊ��������ĸ���n��������n�в�����ÿ��������������1��6���������ֵ�һ�����У��ո��������ʾ��ʼ����ABCDEF����������������֡�

���
ÿ�����ռһ�С����ת����Ŀ������Ҫ�任�����ٴ�������������ת������� - 1��

��������
2
2 5 3 1 4 6
2 3 6 1 5 4

�������
1
2

*/


#include<iostream>
#include<queue>
#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;
queue<int> Q;
bool mark[666666] = { false };

int yezi=0;
int n;

vector<int>show;
vector<int>::iterator pd;

int aerfa(int tmp)
{
	int tr[6];
	int k; int tmp2; int res = 0;
	/*if (tmp == 0) tr[6] = { 0 };
	while (tmp != 0)
	{
	tr[k++] = tmp % 10;
	tmp /= 10;
	}*/
	for (k = 5; k >= 0; k--)
	{
		tr[k] = tmp % 10;
		tmp = tmp / 10;
	}
	tmp2 = tr[3];
	tr[3] = tr[4];
	tr[4] = tr[1];
	tr[1] = tr[0];
	tr[0] = tmp2;
	for (int m = 0; m < 6; m++)
	{
		res = res * 10 + tr[m];
	}
	return(res);
}
int beita(int tmp)
{
	int tr[6];
	int k; int tmp2; int res = 0;
	/*if (tmp == 0) tr[6] = { 0 };
	while (tmp != 0)
	{
	tr[k++] = tmp % 10;
	tmp /= 10;
	}*/
	for (k = 5; k >= 0; k--)
	{
		tr[k] = tmp % 10;
		tmp = tmp / 10;
	}
	tmp2 = tr[4];
	tr[4] = tr[5];
	tr[5] = tr[2];
	tr[2] = tr[1];
	tr[1] = tmp2;
	for (int m = 0; m < 6; m++)
	{
		res = res * 10 + tr[m];
	}
	return(res);
}
int bfs()
{
	int next, tmp, l;
	while (!Q.empty())
	{
		tmp = Q.front();
		Q.pop();
		yezi++;
		if (tmp == 123456) { /*if (tmp = zuozishu) cishu = 1;*/ return 1; }

		for (l = 0; l < 2; l++)
		{

			if (l == 0) { next = aerfa(tmp);      /*cout << next << ' ';*/ }
			else if (l == 1) { next = beita(tmp); /*cout << next << " ";*/ }
			//cout << mark[next] << " ";

			if (mark[next] == 0)
			{
				/*cout << Q.front()<<" ";
				cout << endl;*/

				Q.push(next);
				/*cout << Q.size() << " ";
				cout << endl;*/
				mark[next] = 1;
			}
		}

		//}
	}
	return -1;

}
int main()
{
	cin >> n;
	while (n--)
	{
		int input[6];
		int combine = 0;
		for (int i = 0; i < 6; i++)
		{
			scanf_s("%d", input + i);
		};
		for (int j = 0; j < 6; j++)
		{
			combine = combine * 10 + input[j];
		};

		//cout << combine;
		Q.push(combine);
		mark[combine] = 1;
		if (bfs() == 1) /*cout <<*/show.push_back(int(log(yezi) / log(2)));
		else if (bfs() == -1) /*cout <<*/ show.push_back(-1);
		//printf("\n");
		//cout << int(log(yezi)/log(2)) << ' ';
		/*if (int((log(cishu + 1) / log(2)) + 1) == 2)cout << 1;*/
		while (!Q.empty())
		{
			Q.pop();
		}
		//int mark[1000000] = { false };
		for (int s = 10000; s < 654321; s++)
		{
			
				mark[s] = false;

		};

		 yezi = 0;
		//cout << Q.size()<<"   "<<mark[253146]<<endl;
	}
	for (pd = show.begin(); pd != show.end(); pd++)
	{
		cout << *pd << endl;
	}
		system("pause");
		return 0;
	
}

//#include <iostream>
//#include <queue>
//#define N 5
//using namespace std;
//int maze[N][N] = {
//	{ 0, 1, 1, 0, 0 },
//{ 0, 0, 1, 1, 0 },
//{ 0, 1, 1, 1, 0 },
//{ 1, 0, 0, 0, 0 },
//{ 0, 0, 1, 1, 0 }
//};
//int visited[N + 1] = { 0, };
//void BFS(int start)
//{
//	queue<int> Q;
//	Q.push(start);
//	visited[start] = 1;
//	while (!Q.empty())
//	{
//		int front = Q.front();
//		cout << front << " ";
//		Q.pop();
//		for (int i = 1; i <= N; i++)
//		{
//			if (!visited[i] && maze[front - 1][i - 1] == 1)
//			{
//				visited[i] = 1;
//				Q.push(i);
//			}
//		}
//	}
//}
//int main()
//{
//	for (int i = 1; i <= N; i++)
//	{
//		if (visited[i] == 1)
//			continue;
//		BFS(i);
//	}
//	system("pause");
//	return 0;
//}
//
//
//#include<iostream>
//#include<algorithm>
//#include<cstdio>
//#include<cstring>
//using namespace std;
//struct node
//{
//	int a[6], num;
//};
//int top, base;
//node q[10000];
//int n, aa[6];
//int ans;
//bool ff;
//bool flag[666666];
//bool judge(int point)
//{
//	return !flag[point];
//}
//int get_num(int aa[])
//{
//	return aa[0] + aa[1] * 10 + aa[2] * 100 + aa[3] * 1000 + aa[4] * 10000 + aa[5] * 100000;
//}
//void get1()
//{
//	aa[1] = q[base].a[0];
//	aa[4] = q[base].a[1];
//	aa[3] = q[base].a[4];
//	aa[0] = q[base].a[3];
//	aa[2] = q[base].a[2];
//	aa[5] = q[base].a[5];
//}
//void get2()
//{
//	aa[0] = q[base].a[0];
//	aa[3] = q[base].a[3];
//	aa[1] = q[base].a[4];
//	aa[2] = q[base].a[1];
//	aa[5] = q[base].a[2];
//	aa[4] = q[base].a[5];
//}
//bool can()
//{
//	for (int i = 0; i<6; i++)
//		if (q[base].a[i] != i + 1) return 0;
//	return 1;
//}
//void paste(int a1[], int a2[])
//{
//	for (int i = 0; i<6; i++) a1[i] = a2[i];
//}
//void bfs()
//{
//	while (base<top) {
//		if (can()) { ans = q[base].num; ff = 1; return; }
//		get1();
//		int point = get_num(aa);
//		if (judge(point)) {
//			flag[point] = 1;
//			q[top].num = q[base].num + 1;
//			paste(q[top++].a, aa);
//		}
//		get2();
//		point = get_num(aa);
//		if (judge(point)) {
//			flag[point] = 1;
//			q[top].num = q[base].num + 1;
//			paste(q[top++].a, aa);
//		}
//		base++;
//	}
//}
//int main()
//{
//	node n1;
//	scanf_s("%d", &n);
//	while (n--) {
//		for (int i = 0; i<6; i++) scanf_s("%d", &q[0].a[i]);
//		ff = 0;
//		top = base = 0; q[0].num = 0; top = 1;
//		memset(flag, 0, sizeof(flag));
//		int point = get_num(q[0].a);
//		flag[point] = 1;
//		bfs();
//		if (!ff) printf("-1\n");
//		else printf("%d\n", ans);
//	}
//	return 0;
//}




//#include<stdio.h>
//#include<iostream>
//#include<queue>
//using namespace std;
//
//queue<int>q1;
//
//int sum = 0, t, use[1000000];
//void init();
//int bfs();
//int change1(int n);
//int change2(int n);
//
//int main()
//{
//	int a[6], i, j;
//	while (scanf_s("%d", &a[0]) != EOF)
//	{
//		sum = 0;
//		for (int k = 100000; k <= 654321; k++)
//		{
//			use[k] = 0;
//		}
//		for (i = 1; i<6; i++)
//		{
//			scanf_s("%d", &a[i]);
//		}
//		for (j = 0; j<6; j++)//������ת��Ϊһ����λ���������ȽϷ���
//		{
//			sum = sum * 10 + a[j];
//		}
//		init();
//		if (bfs() == 1)printf("Yes\n");
//		else if (bfs() == -1)printf("No\n");
//		while (!q1.empty())
//		{
//			q1.pop();//ÿ���������ݵó����ۺ�Ҫ�������е�Ԫ����գ�����Ӱ��
//		}
//
//	}
//	return 0;
//}
//void init()//��ʼ������һ����������
//{
//	q1.push(sum);
//	use[sum] = 1;//��Ǵ��������ù�
//}
//int bfs()
//{
//	int u, v, i;
//	while (!q1.empty())
//	{
//		u = q1.front();
//		q1.pop();
//		if (u == 654321)
//		{
//			return 1;
//		}
//		for (i = 0; i<2; i++)
//		{
//			if (i == 0)v = change1(u);
//			else if (i == 1)v = change2(u);
//			if (use[v] != 1)
//			{
//				q1.push(v);//v�������
//				use[v] = 1;//���v�ѱ��ù�
//			}
//		}
//	}
//	return -1;
//}
//int change1(int n)//����λ��ת���������ڰ��չ涨ת���õ���һ����λ������
//{
//	int a[6], y[6];
//	int i, s = 0;
//	for (i = 5; i >= 0; i--)
//	{
//		a[i] = n % 10;
//		n = n / 10;
//	}
//	y[2] = a[1];
//	y[5] = a[2];
//	y[4] = a[5];
//	y[1] = a[4];
//	y[3] = a[3];
//	y[0] = a[0];
//	for (i = 0; i<6; i++)
//	{
//		s = s * 10 + y[i];
//	}
//	return s;
//
//}
//int change2(int n)
//{
//	int a[6], y[6];
//	int i, s = 0;
//	for (i = 5; i >= 0; i--)
//	{
//		a[i] = n % 10;
//		n = n / 10;
//	}
//	y[1] = a[0];
//	y[3] = a[4];
//	y[4] = a[1];
//	y[0] = a[3];
//	y[2] = a[2];
//	y[5] = a[5];
//	for (i = 0; i<6; i++)
//	{
//		s = s * 10 + y[i];
//	}
//	return s;
//}



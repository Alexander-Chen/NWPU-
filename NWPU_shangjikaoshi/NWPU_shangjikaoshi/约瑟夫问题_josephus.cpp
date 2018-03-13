#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
#include<stdlib.h>
using namespace std;
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

typedef struct node
{
	int data;
	struct node *next;
}node, *node_pointer;

/* nΪ������,kΪ��һ����ʼ�������˵ı��,��1��ʼ,����m���˳��� */
void JOSEPHUS(int n, int k, int m)
{
	/* pΪ��ǰ�ڵ㣬qΪ�����ڵ㣬ָ��p��ǰ���ڵ�*/
	node_pointer p = NULL, q = NULL, pd = NULL;

	/* ����ѭ������ */
	p = (node_pointer)malloc(sizeof(node));
	p->data = 0;
	p->next = p; //һ���ڵ��ѭ������
	pd = p;//pָ����Ϊ0�Ľڵ�
	for (int i = 1; i<n; i++)
	{
		node_pointer t = (node_pointer)malloc(sizeof(node));
		t->data = i;
		t->next = pd->next;
		pd->next = t;
		pd = t; //ѭ��������pdָ����0�Ľڵ㣬tָ����n-1�Ľڵ㡣
	}

	q = pd; //�ѵ�ǰָ���Ƶ���һ����������
	while (k--) //��һ�δӱ��Ϊk���˿�ʼ����������Ҫ����ǰk-1���ˡ�
	{
		q = p;
		p = p->next;
	}
	while (n--) //ֱ��Բ����Χ��n����ȫ������
	{
		for (int s = m - 1; s--; q = p, p = p->next); //��1��ʼ����������m���˳���,��Ӧs��m-1��0�ı仯��
		q->next = p->next; //������Ϊm�Ľڵ��޳�����
		printf("%d->", p->data);//�����������
		free(p);
		p = q->next;
	}
}

int main()
{
	JOSEPHUS(7, 0, 3);
	system("pause");
}
//#include<cstdio>  
//int main() {
//	int n, m;
//	while (scanf("%d %d", &n, &m) == 2 && n&&m) {
//		int ans = 0;
//		for (int i = 1; i <= n; ++i) {
//			ans = (ans + m) % i;
//		}
//		printf("������:%d ÿ�γ��е��˺��ĺ���:%d ���һ�����е��˵����:%d\n", n, m, ans + 1);
//	}
//	return 0;
//}
//int winner(int m, int n)
//{
//	int i;
//	int number;
//	if (m <= 0 || n <= 0) {
//		return -1;
//	}
//	number = 0;                        /* ��ֻ��һ����ʱ�����Ϊ0�ĳ�Ȧ */
//	for (i = 2; i <= m; i++) {           /* ѭ��m-1�ν�ʣ��һ����         */
//		number = (number + n % i) % i; /* ����д����⣬��(number+n)%i  */
//	}
//	return number + 1;                 /* �����0��ţ�����ʱӦ+1       */
//}
//
//int main()
//{
//	cout << winner(6, 3);
//	system("pause");
//}
typedef struct node
{
	int data;
	struct node *next;
}node;
node *create(int n)
{
	node *p = NULL, *head;
	head = (node*)malloc(sizeof(node));
	p = head;
	node *s;
	int i = 1;
	if (0 != n)
	{
		while (i <= n)
		{
			s = (node*)malloc(sizeof(node));
			s->data = i++;
			head->next = s;
			p = s;
		}
		s->next = head->next;
	}
	free(head);
	return s->next;

}
int main()
{
	int n = 41;
	int m = 3;
	int i;
	node *p = create(n);
	node *temp;
	m %= n;

	while (p != p->next)
	{
		for (i = 1; i < m - 1; i++)
		{
			p = p->next;
		}
		printf("%d->", p->next->data);

		temp = p->next;
		p->next = temp->next;
		free(temp);
		p = p->next;
	}
	printf("%d\n", p->data);
	return 0;

}
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

/* �������Ķ���������ṹ���� */
typedef  struct BiTNode    /* ���ṹ */
{
	int data;    /* ������� */
	struct BiTNode *lchild, *rchild; /* ���Һ���ָ�� */
} BiTNode, *BiTree;

/*�ڶ�Ԫ������b�в���x�Ĺ���Ϊ��
1.��b�ǿ�����������ʧ�ܣ�����
2.��x����b�ĸ��ڵ��������ֵ֮������ҳɹ�������
3.��xС��b�ĸ��ڵ��������ֵ֮��������������������
4.������������

/*�ݹ���Ҷ���������T���Ƿ����key, */
/* ָ��fָ��T��˫�ף����ʼ����ֵΪNULL */
/* �����ҳɹ�����ָ��pָ�������Ԫ�ؽ�㣬������TRUE */
/* ����ָ��pָ�����·���Ϸ��ʵ����һ����㲢����FALSE */
bool Delete(BiTree *p);
bool SearchBST(BiTree T, int key, BiTree f, BiTree *p)
{
	if (!T)    /*  ���Ҳ��ɹ� */
	{
		*p = f;
		return false;
	}
	else if (key == T->data) /*  ���ҳɹ� */
	{
		*p = T;
		return true;
	}
	else if (key<T->data)
		return SearchBST(T->lchild, key, T, p);  /*  ���������м������� */
	else
		return SearchBST(T->rchild, key, T, p);  /*  ���������м������� */
}

/*  ������������T�в����ڹؼ��ֵ���key������Ԫ��ʱ�� */
/*  ����key������TRUE�����򷵻�FALSE */
bool InsertBST(BiTree *T, int key)
{
	BiTree p, s;
	if (!SearchBST(*T, key, NULL, &p)) /* ���Ҳ��ɹ� */
	{
		s = (BiTree)malloc(sizeof(BiTNode));
		s->data = key;
		s->lchild = s->rchild = NULL;
		if (!p)
			*T = s;            /*  ����sΪ�µĸ���� */
		else if (key<p->data)
			p->lchild = s;    /*  ����sΪ���� */
		else
			p->rchild = s;  /*  ����sΪ�Һ��� */
		return true;
	}
	else
		return false;  /*  �������йؼ�����ͬ�Ľ�㣬���ٲ��� */
}

void zhongxu(BiTree T)
{
	if (T)
	{
		zhongxu(T->lchild);
		cout << T->data<<' ';
		zhongxu(T->rchild);
	}
}
int main()
{
	int i=0;
	int a[100];
	/*for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}*/
	do
	{
		scanf("%d",&a[i++]);
	} while (getchar()!='\n');
	BiTree T = NULL;
	for (int j = 0; j <i ; j++)
	{
		//cout << a[j]<<' ';
		InsertBST(&T, a[j]);
	}
	zhongxu(T);
	system("pause");
	return 0;
}
//int main()
//{
//	int i=0;
//	int a[10] = {9,8,7,6,5,4,3,2,1,0};
//	/*do
//	{
//		cin >> a[i++];
//	} while (getchar() != '\n');*/
//	BiTree T = NULL;
//	for (int j = 0; j < 9; i++)
//	{
//		InsertBST(&T, a[j]);
//	}
//	zhongxu(T);
//	system("pause");
//	return 0;
//}

/* ������������T�д��ڹؼ��ֵ���key������Ԫ��ʱ����ɾ��������Ԫ�ؽ��, */
/* ������TRUE�����򷵻�FALSE�� */
bool DeleteBST(BiTree *T, int key)
{
	if (!*T) /* �����ڹؼ��ֵ���key������Ԫ�� */
		return false;
	else
	{
		if (key == (*T)->data) /* �ҵ��ؼ��ֵ���key������Ԫ�� */
			return Delete(T);
		else if (key<(*T)->data)
			return DeleteBST(&(*T)->lchild, key);
		else
			return DeleteBST(&(*T)->rchild, key);

	}
}

/* �Ӷ�����������ɾ�����p�����ؽ���������������� */
bool Delete(BiTree *p)
{
	BiTree q, s;
	if ((*p)->rchild == NULL) /* ����������ֻ���ؽ���������������ɾ�����Ҷ��Ҳ�ߴ˷�֧) */
	{
		q = *p; *p = (*p)->lchild; free(q);
	}
	else if ((*p)->lchild == NULL) /* ֻ���ؽ����������� */
	{
		q = *p; *p = (*p)->rchild; free(q);
	}
	else /* �������������� */
	{
		q = *p; s = (*p)->lchild;
		while (s->rchild) /* ת��Ȼ�����ҵ���ͷ���Ҵ�ɾ����ǰ���� */
		{
			q = s;
			s = s->rchild;
		}
		(*p)->data = s->data; /*  sָ��ɾ����ֱ��ǰ��������ɾ���ǰ����ֵȡ����ɾ����ֵ�� */
		if (q != *p)
			q->rchild = s->lchild; /*  �ؽ�q�������� */
		else
			q->lchild = s->lchild; /*  �ؽ�q�������� */
		free(s);
	}
	return true;
}

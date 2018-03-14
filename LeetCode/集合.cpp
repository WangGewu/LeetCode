#include<stdio.h>
#include<stdlib.h>
#define ElementType int
typedef struct Lnode* List;
struct Lnode
{
	ElementType Data;
	List Next;
};
void Insert(List L,ElementType x);//ͷ�巨
List CreatList();//��ʼ��
List Build();//��������
void PrintList(List L);//�������
List Bing(List L1, List L2);//����
List Jiao(List L1, List L2);//����
List Cha(List L1, List L2);//���L1-L2��
bool Find(List L, ElementType x);//�ڼ���L�в����Ƿ���ֵ��x�����û�ҵ�������true
int main()
{
	List L1, L2, L;
	printf("�������һ������(����0����):\n");
	L1 = Build();
	printf("������ڶ�������(����0����):\n");
	L2 = Build();
	printf("���ϵĲ�����:\n");
	L = Bing(L1, L2);
	PrintList(L);
	printf("���ϵĽ�����:\n");
	L = Jiao(L1, L2);
	PrintList(L);
	printf("���ϵĲ��:\n");
	L = Cha(L1, L2);
	PrintList(L);
	return 0;
}
List CreatList()
{
	List L;
	L = (List)malloc(sizeof(struct Lnode));
	L->Next = NULL;
	return L;
}
void Insert(List L, ElementType x)//ͷ�巨
{
	List p = (List)malloc(sizeof(struct Lnode));
	p->Data = x;
	p->Next = L->Next;
	L->Next = p;
}
List Build()
{
	List p, L;
	L = CreatList();
	int data;
	scanf("%d", &data);
	while (data != 0)//����0����,ͷ�巨
	{
		if (Find(L, data))//��������֮ǰ�����ظ�������˵�
		{
			Insert(L, data);
		}
		scanf("%d", &data);
	}
	return L;
}
void PrintList(List L)
{
	List p;
	if (!L->Next)//LΪ��
	{
		printf("��\n");
		return;
	}
	else
	{
		p = L->Next;
		while (p)
		{
			printf("%d ", p->Data);
			p = p->Next;
		}
	}
	printf("\n");
}
bool Find(List L, ElementType x)
{
	List p;
	for (p = L->Next; p && (p->Data != x); p = p->Next);
	if (!p)return true;//û�ҵ�
	else return false;
}
List Bing(List L1, List L2)
{
	List L, p1, p2, p;
	p1 = L1->Next;
	p2 = L2->Next;
	if (!p1)
		L = L2;
	else if (!p2)
		L = L1;
	else {
		L = CreatList();
		while (p1)//�ȿ���L1��L��
		{
			Insert(L, p1->Data);
			p1 = p1->Next;
		}
		while (p2)
		{
			if (Find(L, p2->Data))//��L1�в���L2�е�ÿ��Ԫ�أ����û�ҵ��Ļ����򽫽ڵ㿽����L��
				Insert(L, p2->Data);
			p2 = p2->Next;
		}
	}
	return L;
}
List Jiao(List L1, List L2)
{
	List L, p1, p2, p;
	p1 = L1->Next;
	p2 = L1->Next;
	L = CreatList();
	if (!L1)//���L1λ�գ�����Ϊ��
		return L;
	else if (!L2)//���L2λ�գ�����Ϊ��
		return L;
	else {
		while (p1)//��L2�в���L1��ÿһ��Ԫ�أ�����ҵ��ˣ��򿽱���L��
		{
			if (!Find(L2, p1->Data))
				Insert(L, p1->Data);
			p1 = p1->Next;
		}
	}
	return L;
}
List Cha(List L1, List L2)
{
	List L, p1, p2, p;
	p1 = L1->Next;
	p2 = L1->Next;
	L = CreatList();
	if (!L1)//���L1Ϊ�գ��Ϊ��
		return L;
	else if (!L2)//���L2Ϊ�գ��ΪL1
		return L1;
	else {
		while (p1)//��L2�в���L1��ÿһ��Ԫ�أ����û�ҵ����򿽱���L��
		{
			if (Find(L2, p1->Data))
				Insert(L, p1->Data);
			p1 = p1->Next;
		}
	}
	return L;
}
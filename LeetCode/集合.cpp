#include<stdio.h>
#include<stdlib.h>
#define ElementType int
typedef struct Lnode* List;
struct Lnode
{
	ElementType Data;
	List Next;
};
void Insert(List L,ElementType x);//头插法
List CreatList();//初始化
List Build();//建立集合
void PrintList(List L);//输出链表
List Bing(List L1, List L2);//并集
List Jiao(List L1, List L2);//交集
List Cha(List L1, List L2);//差集（L1-L2）
bool Find(List L, ElementType x);//在集合L中查找是否有值域x，如果没找到，返回true
int main()
{
	List L1, L2, L;
	printf("请输入第一个集合(输入0结束):\n");
	L1 = Build();
	printf("请输入第二个集合(输入0结束):\n");
	L2 = Build();
	printf("集合的并集是:\n");
	L = Bing(L1, L2);
	PrintList(L);
	printf("集合的交集是:\n");
	L = Jiao(L1, L2);
	PrintList(L);
	printf("集合的差集是:\n");
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
void Insert(List L, ElementType x)//头插法
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
	while (data != 0)//输入0结束,头插法
	{
		if (Find(L, data))//如果输入和之前输入重复，则过滤掉
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
	if (!L->Next)//L为空
	{
		printf("空\n");
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
	if (!p)return true;//没找到
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
		while (p1)//先拷贝L1到L中
		{
			Insert(L, p1->Data);
			p1 = p1->Next;
		}
		while (p2)
		{
			if (Find(L, p2->Data))//在L1中查找L2中的每个元素，如果没找到的话，则将节点拷贝到L中
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
	if (!L1)//如果L1位空，交集为空
		return L;
	else if (!L2)//如果L2位空，交集为空
		return L;
	else {
		while (p1)//在L2中查找L1的每一个元素，如果找到了，则拷贝到L中
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
	if (!L1)//如果L1为空，差集为空
		return L;
	else if (!L2)//如果L2为空，差集为L1
		return L1;
	else {
		while (p1)//在L2中查找L1的每一个元素，如果没找到，则拷贝到L中
		{
			if (Find(L2, p1->Data))
				Insert(L, p1->Data);
			p1 = p1->Next;
		}
	}
	return L;
}
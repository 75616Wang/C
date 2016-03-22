#include<stdlib.h>
#include<stdio.h>
#define OK 1
#define NULL 0
typedef struct LNode {	//单链表节点结构
	char	 data;
	struct LNode	 *next;
}LNode, *LinkList;

int PrintLinkList(LinkList &L) {//输出单链表
	int i = 0;
	LinkList p;
	printf("序号\t地址\tdata\tnext\n", i, p, p->data, p->next);
	while (p) {
		printf("%d\t%X\t%c\t%X\n", i, p, p->data, p->next);
		p = p->next;
		i++;
	}
	return OK;
}//PrintLinkList
int CreatLinkList(LinkList &L, char data[], int n) {	//创建带头单链表,P30
	L = (LinkList)malloc(sizeof(LNode));
	L->data = '?';
	L->next = NULL;
	LinkList p;
	for (int i = 0; i < n; i++) {
		p = (LinkList)malloc(sizeof(LNode));
		p->data = data[i];
		p->next = L->next;
		L->next = p;
	}
	return OK;
}
int LinkListLength(LinkList &L) {	//求单链表长度
	int len;
	LinkList p;
	for (len = 0, p = L; p->next; p = p->next, len++);
	return len;

}//LinkListLength
int RevrseLinkList(LinkList &L) {//单链表的就地转置
								 //依次把每一个节点插入到新表的前面
	LinkList p, q, s;
	p = L->next; q = p->next; s = q->next; p->next = NULL;
	while (s->next) {
		q->next = p; p = q;
		q = s; s = s->next; //把L的元素逐个插入新表表头
	}
	q->next = p; s->next = q; L->next = s;

	return OK;
}//LinkList_reverse


int main()
{
	char *data = "asdfghjkiuvuadususausah";
	LinkList L;
	int n = 10;
	CreatLinkList(L, data, n);

	printf("初始化后的单链表：\n");
	PrintLinkList(L);	//输出

	printf("length = %d\n", LinkListLength(L));	//输出长度

	RevrseLinkList(L);	//就地转置
	
	printf("就地转置后的单链表：\n");
	PrintLinkList(L);
	return 0;


}
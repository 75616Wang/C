#include<stdlib.h>
#include<stdio.h>
#define OK 1
#define NULL 0
typedef struct LNode {	//������ڵ�ṹ
	char	 data;
	struct LNode	 *next;
}LNode, *LinkList;

int PrintLinkList(LinkList &L) {//���������
	int i = 0;
	LinkList p;
	printf("���\t��ַ\tdata\tnext\n", i, p, p->data, p->next);
	while (p) {
		printf("%d\t%X\t%c\t%X\n", i, p, p->data, p->next);
		p = p->next;
		i++;
	}
	return OK;
}//PrintLinkList
int CreatLinkList(LinkList &L, char data[], int n) {	//������ͷ������,P30
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
int LinkListLength(LinkList &L) {	//��������
	int len;
	LinkList p;
	for (len = 0, p = L; p->next; p = p->next, len++);
	return len;

}//LinkListLength
int RevrseLinkList(LinkList &L) {//������ľ͵�ת��
								 //���ΰ�ÿһ���ڵ���뵽�±��ǰ��
	LinkList p, q, s;
	p = L->next; q = p->next; s = q->next; p->next = NULL;
	while (s->next) {
		q->next = p; p = q;
		q = s; s = s->next; //��L��Ԫ����������±��ͷ
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

	printf("��ʼ����ĵ�����\n");
	PrintLinkList(L);	//���

	printf("length = %d\n", LinkListLength(L));	//�������

	RevrseLinkList(L);	//�͵�ת��
	
	printf("�͵�ת�ú�ĵ�����\n");
	PrintLinkList(L);
	return 0;


}
#include <stdio.h>
#include <malloc.h>

typedef struct LNode {
	int data;
	struct LNode* next;
}LNode, * LinkList;


void displayLinkList(LinkList linkList);

void createLinkByHead(LinkList& linkList);

void createLinkByTail(LinkList& linkList);

LinkList queryByIndex(LinkList linkList, int index);

LinkList insertByIndex(LinkList linkList, int index, int data);

LinkList deleteByIndex(LinkList linkList, int index);



void create() {
	LinkList L1;
	createLinkByHead(L1);
	displayLinkList(L1);
	displayLinkList(L1);

	LinkList L2;
	createLinkByTail(L2);
	displayLinkList(L2);
	displayLinkList(L2);
}



void query() {
	LinkList L;
	createLinkByTail(L);
	displayLinkList(L);

	
	int positionQuery = 3;
	LinkList p = queryByIndex(L, positionQuery - 1);
	printf("\n\t第 %d 个元素的值是 %d\n", positionQuery, p->data);
}


void deleteI() {
	LinkList L;
	createLinkByTail(L);
	displayLinkList(L);



	int positionDel1 = 3;
	printf("\n\t删除第 %d 个元素的值\n", positionDel1);
	LinkList LDel1 = deleteByIndex(L, positionDel1 - 1);
	displayLinkList(LDel1);

	int positionDel2 = 1;
	printf("\n\t删除第 %d 个元素的值\n", positionDel2);
	LinkList LDel2 = deleteByIndex(LDel1, positionDel2 - 1);
	displayLinkList(LDel2);

	int positionDel3 = 4;
	printf("\n\t删除第 %d 个元素的值\n", positionDel3);
	LinkList LDel3 = deleteByIndex(LDel2, positionDel3 - 1);
	displayLinkList(LDel3);
}


void insert() {
	LinkList L;
	createLinkByTail(L);
	displayLinkList(L);


	int positionInsert1 = 3;
	printf("\n\t在第 %d 个位置插入\n", positionInsert1);
	LinkList LInsert1 = insertByIndex(L, positionInsert1 - 1, 333);
	displayLinkList(LInsert1);

	int positionInsert2 = 1;
	printf("\n\t在第 %d 个位置插入\n", positionInsert2);
	LinkList LInsert2 = insertByIndex(LInsert1, positionInsert2 - 1, 111);
	displayLinkList(LInsert2);


	int positionInsert3 = 8;
	printf("\n\t在第 %d 个位置插入\n", positionInsert3);
	LinkList LInsert3 = insertByIndex(LInsert2, positionInsert3 - 1, 888);
	displayLinkList(LInsert3);


	int positionInsert4 = 10;
	printf("\n\t在第 %d 个位置插入\n", positionInsert4);
	LinkList LInsert4 = insertByIndex(LInsert3, positionInsert4 - 1, 101010);
	displayLinkList(LInsert4);
}


int main() {
	//create();
	//query();
	//deleteI();

	insert();

	return 0;
}

//通过序号插入
LinkList insertByIndex(LinkList linkList, int index, int data) {

	LinkList pEle = (LinkList)malloc(sizeof(LNode));
	pEle->data = data;
	pEle->next = NULL;

	LinkList pre = linkList;
	LinkList p = pre;
	if (index == 0){
		pEle->next = pre;
		linkList = pEle;
	}
	else {
		for (int i = 0; i < index; i++) {
			pre = p;
			p = p->next;
		}
		pre->next = pEle;
		pEle->next = p;
	}
	return linkList;
}


//通过序号删除
LinkList deleteByIndex(LinkList linkList, int index) {

	LinkList pre = linkList;

	if (index == 0) {
		linkList = linkList->next;
		pre->next = NULL;
		free(pre);
	}
	else {
		LinkList p = pre;
		for (int i = 0; i < index; i++) {
			pre = p;
			p = p->next;
		}
		pre->next = p->next;
		p->next = NULL;
		free(p);

	}
	return linkList;
}



//通过序号查找
LinkList queryByIndex(LinkList linkList, int index) {
	LinkList p = linkList;
	int i = 0;
	while (i < index) {
		p = p->next;
		i++;
	}
	return p;
}



//尾插法
void createLinkByTail(LinkList& linkList) {

	linkList = (LinkList)malloc(sizeof(LNode));
	linkList->data = 100;
	linkList->next = NULL;
	LinkList pre = linkList;
	for (int i = 0; i < 5; i++) {
		LinkList p = (LinkList)malloc(sizeof(LNode));
		p->data = (i + 2) * 100;
		pre->next = p;
		p->next = NULL;
		pre = p;
	}
}


//头插法
void createLinkByHead(LinkList& linkList) {

	linkList = (LinkList)malloc(sizeof(LNode));
	linkList->data = 100;
	linkList->next = NULL;

	for (int i = 0; i < 5; i++) {
		LinkList p = (LinkList)malloc(sizeof(LNode));
		p->data = (i + 2) * 100;
		p->next = linkList->next;
		linkList->next = p;
	}
}


//遍历链表
void displayLinkList(LinkList p) {
	printf("\n");
	while (p != NULL) {
		printf("\t%d", p->data);
		p = p->next;
	}
	printf("\n");
}
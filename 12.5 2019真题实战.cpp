#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;
typedef struct LNode{
	ElemType data;
	struct LNode* next;
}LNode,*LinkList;

void list_foot_insert(LNode* &L){
	LNode* r;//指向要插入元素的前一个节点 （尾结点） 
	LNode* s1; //待插入节点 
	L = (LinkList)malloc(sizeof(LNode));
	r=L; 
	ElemType e;
    scanf("%d",&e);
	while(e!=99){
	s1 = (LinkList)malloc(sizeof(LNode));//为新节点分配空间 
	s1->data=e;
	r->next=s1;
	r=s1;//指向待插入前的节点 
	scanf("%d",&e);
	}
	r->next=NULL;//最后一个节点的next始终保持null 
}

void print_list(LinkList &L){
   LNode* l;
   l=L;
  while(l->next!=NULL){
  	l=l->next;
  	printf("%3d",l->data);
  }	
}

void find_middle(LinkList &L,LinkList &L2){
		L2 = (LinkList)malloc(sizeof(LNode));
		LNode *r1,*r2;
		r1=L->next;
		r2=L->next;
		while(r2){
			r2=r2->next;
			if(r2==NULL){
				break;
			}
			r2=r2->next;
			r1=r1->next;
		}
		L2->next=r1->next;
		r1->next=NULL;
}

bool list_reserve(LinkList &L2){
	LNode *m,*p,*q;
	p=L2->next;
	if(NULL==p){
		return false;
	}
	m=p->next;
	if(NULL==m){
		return false;
	}
	q=m->next;
	while(q){
	m->next=p;
	p=m;
	m=q;
	q=q->next;
	}
	m->next=p;
	L2->next->next=NULL;
	L2->next=m;
	return true;
}

void list_merge(LinkList &L,LinkList &L2){
	LinkList pcur,p,q;
	pcur=L->next;//始终指向组合链表的链表尾 
	p=pcur->next;
	q=L2->next;
	while(p!=NULL&&q!=NULL){
		pcur->next = q;
		q=q->next;
		pcur=pcur->next;
		pcur->next=p;
		p=p->next;
		pcur=pcur->next; 
	} 
	 if(p!=NULL){
	 	pcur->next=p;
	 }
	 if(q!=NULL){
	 	pcur->next=q;
	 }	 
}

int main(){
	LinkList L,L2;
	list_foot_insert(L);
	print_list(L);
	find_middle(L,L2);
	print_list(L2);
	list_reserve(L2);
	print_list(L2);
	list_merge(L,L2);
	print_list(L);
	return 0;
}

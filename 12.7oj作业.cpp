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
	r = (LinkList)malloc(sizeof(LNode));
	r=L; 
	ElemType e;
    scanf("%d",&e);
	while(e!=9999){
	s1 = (LinkList)malloc(sizeof(LNode));//为新节点分配空间 
	s1->data=e;
	r->next=s1;
	r=s1;//指向待插入前的节点 
	scanf("%d",&e);
	}
	r->next=NULL;//最后一个节点的next始终保持null 
}

 int list_queryby_position(LinkList &L,int p){
	ElemType p1=0;//位置 
	ElemType x=0;//记录链表长度 
	LNode *L1,*L2;
	L1=L2=L;
	while(L1->next!=NULL){
  	 L1=L1->next;
  	 x++; 
  }	
  if(p<=0||p>x){
  	return 0;
  }else{
  	  while(p1!=p){
  	  	if(p1==p)
			break;
			L2=L2->next;
			p1++;
  }
}
  return L2->data;
}
//获得查找到的位置的指针 
LinkList GetElem(LinkList L,int SearchPos){
	LNode *l=L;
	int j=0;
	if(SearchPos<0){
		return NULL;
	}
	
	while(l&&j<SearchPos){
		l=l->next;
		j++;
	}
	return l;
}

bool ListFrontInsert(LinkList L,int i,ElemType e){
	LinkList p = GetElem(L,i-1);
	if(NULL==p){
		return false;
	}
    LNode *s;	
    s = (LinkList)malloc(sizeof(LNode));
    s->data=e;
    s->next=p->next;
    p->next=s;
    return true; 
}

bool List_delete(LNode* &L,int SearchPos){
	LNode *l;
	l=GetElem(L,SearchPos-1);
	if(l==NULL){
		return false;
	}
	LNode *q;
	q=l->next;
	l->next=q->next;
	free(q);
	return true;
}

void print_list(LinkList &L){
	LNode *l=L;
  while(l->next!=NULL){
  	l=l->next;
  	printf("%3d",l->data);
  }	
  	printf("\n");
}

int main(){
    LinkList L;
	list_foot_insert(L);
	int e = list_queryby_position(L,2);
    printf("%d\n",e);	
	ListFrontInsert(L,2,99);
	print_list(L);	
	List_delete(L,4);
	print_list(L);
	return 0;
}

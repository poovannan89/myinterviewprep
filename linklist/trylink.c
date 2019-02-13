#include<stdio.h>
struct node {
	int a;
	struct node* next;
};
// Insert at head
void getInputs(struct node** head) {
	struct node *new;
	int a,i;
	for(i=0;i<6;i++) {
		printf("\nEnter value");
		scanf("%d",&a);
		new=(struct node*)malloc(1*sizeof(struct node));
		new->a=a;
		if(*head==NULL) {
			new->next=NULL;
			*head=new;
		}
		else {
			new->next=*head;
			*head=new;
		}
	}
}		

void insertAtEnd(struct node** head) {
	struct node *new,*tmp;
	int a,i;
	tmp=head;
	for(i=0;i<3;i++) {
		scanf("%d",&a);
		new=(struct node*)malloc(1*sizeof(struct node));
		new->a=a;
		if(tmp==NULL) {
			new->next=NULL;
			tmp=new;
		}
		else {
			while(tmp !=NULL) {
				tmp=tmp->next;
			}	
			tmp->next=new;

		}
	}
}
/*
struct node* BuildListAtEnd() {
	struct node* head=NULL;
	struct node* tail;
	int i;
	Push(&head,1);
	tail=head;
	for(i=2;i<6;i++) {
		Push(&(tail->next),i);
		tail=tail->next;
	}
	return head;
}
*/				




void printList(struct node *head) {
	while(head!=NULL) {
		printf("%d\t",head->a);
		head=head->next;
	}
}

void Push(struct node **head,int a) {
	struct node *new;
	new=(struct node*)malloc(1*sizeof(struct node));
	new->a=a;
	new->next=*head;
	*head=new;
}

struct node* pushAtTail() {
	struct node* head=NULL;
	struct node* tail;
	int i;
	Push(&head,1);
	tail=head;
	for(i=2;i<6;i++) {
		Push(&(tail->next),i);
		tail=tail->next;
	}
}

struct node* AppendNode(struct node **headref,int num) {
	struct node* current=*headref;
	struct node* newNode;
	newNode=(struct node*)malloc(1*sizeof(struct node));
	newNode->a=num;
	newNode->next=NULL;
	if(current==NULL)
		*headref=newNode;
	else {
		while(current->next !=NULL) {
			current=current->next;
		}
		current->next=newNode;
	}
}	

struct node* CopyList(struct node *head) {
	struct node *current;
	struct node *tail=NULL;
	current=head;
	struct node *newList=NULL;
	while(current!=NULL) {
		if(newList==NULL) {
			Push(&(newList),current->a);
			tail=newList;
		}
		else {
			Push(&(tail->next),current->a);
			tail=tail->next;
		}
		current=current->next;
	}
}

void pushItem(struct node **head,int a) {
	struct node *new;
	new=(struct node*)malloc(1*sizeof(struct node));
	new->a=a;
	new->next=*head;
	*head=new;
}

int CountItem(struct node* head,int a) {
	struct node* current;
	current=head;
	int cnt=0;
	while(current!=NULL) {
		if(current->a==a)
			cnt++;
		current=current->next;
	}
	return cnt;
}	

void DeleteList(struct node **head) {
	struct node* current;
	struct node*next;
	current=*head;
	while(current!=NULL) {
		next=current->next;
		free(current);
		current=next;
	}
}

int PopNode(struct node **head) {
	struct node *current;
	current=*head;
	int d;
	d=current->a;
	*head=current->next;
	free(current);
	return d;
}	

void InsertNth(struct node **head,int e,int i) {
	struct node *current;
	struct node *next;
	struct node *new;
	new=(struct node*)malloc(1*sizeof(struct node));
	new->a=e;
	new->next=NULL;
	current=*head;
	int cnt;
	cnt=0;
	if(i==0) {
		new->next=*head;
		*head=new;
	}
	else {
		while(current!=NULL) {
			if(cnt==i-1) {
				break;
			}	
			current=current->next;	
			cnt++;
		}
		next=current->next;
		current->next=new;
		new->next=next;
	}
	
}


void InsertNth2(struct node **head,int index,int data) {
	if(index==0)	Push(head,data);
	else {
		struct node *current=*head;
		int i;
		for(i=0;i<index-1;i++) {
			current=current->next;
		}
		Push(&(current->next),data);
	}
}

void SortedInsert(struct node **head,struct node *newNode) {
	if(*head==NULL || (*head)->a > newNode->a) {
		newNode->next=*head;
		*head=newNode;
	}
	else {
		struct node *current=*head;
		while(current->next !=NULL && current->next->a <newNode->a) {
			current=current->next;
		}
		newNode->next=current->next;
		current->next=newNode;
	}
}


void InsertSort(struct node **head) {
	struct node *current;
	struct node *next;
	current=*head;
	struct node *result=NULL;
	while(current !=NULL) {
		next=current->next;
		SortedInsert(&result,current);
		current=next;
	}
	*head=result;
}

void AppendList(struct node **a,struct node **b) {
	if(*a==NULL) {
		*a=*b;
	}
	else {
		struct node *curr;
		curr=*a;
		while(curr->next!=NULL) {
			curr=curr->next;
		}
		curr->next=*b;
	}
	*b=NULL;
}	


void FrontBackSplit(struct node *src,struct node**frontRef,struct node**backRef) {
	struct node *slowptr;
	struct node *fastptr;
	slowptr=src;
	fastptr=src->next;
	struct node *slist=NULL;
	if(src==NULL || src->next==NULL) {
		*frontRef=src;
		*backRef=NULL;
	}
	else {
		slowptr=src;
		fastptr=src->next;
		while(fastptr==NULL) {
			fastptr=fastptr->next;
			if(fastptr!=NULL) {
				slowptr=slowptr->next;
				fastptr=fastptr->next;
			}		
		}	
		*frontRef=src;
		*backRef=slowptr->next;
		slowptr->next=NULL;
	}

		
	
}

void RemoveDuplicates(struct node *head) {
	struct node *current=head;
	if(current==NULL)
		return;
	while(current->next!=NULL) {
		if(current->a==current->next->a) {
			struct node *myNext=current->next;
			free(current);
			current=myNext;
		}
		current=current->next;
	}
	/*
	printf("\nAfter removal\n");
	current=head;
	while(current!=NULL) 
		printf("%d\t",current->a);*/
}


void MoveNode(struct node **dst,struct node **src) {
	struct node *current;
	current=*src;
	*src=current->next;	
	current->next=*dst;
	*dst=current;
}

void AlternatingSplit(struct node *src,struct node **aRef,struct node **bRef) {
	struct node *a=NULL;
	struct node *b=NULL;
	struct node *current=src;
	while(current !=NULL) {
		MoveNode(&a,&current);
		if(current!=NULL) {
			MoveNode(&b,&current);
		}
	}
	*aRef=a;
	*bRef=b;	
}

struct node* ShuffleMerge(struct node *a,struct node *b) {
	

}

struct node* ShuffleMerge(struct node* a,struct node* b) {
	struct node *recur;
	struct node *result;
	if(a==NULL)
		return b;
	else if(b==NULL)
		return a;
	else {
		recur=ShuffleMerge(a->next,b->next);
		result=a;
		a->next=b;
		b->next=recur;
		return result;
	}
}

struct node* reverse(struct node *head) {
	struct node *prev,*curr,*next;
	prev=NULL;
	curr=head;
	while(curr!=NULL) {
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
	}
	head=prev;	

}


struct node* SortedMerge(struct node* a, struct node* b) {
	struct node dummy;
	struct node *tail=&dummy;
	dummy.next=NULL;	
	while(1) {
		if(a==NULL) {
			tail->next=b;
			break;
		}
		else if(b==NULL) {
			tail->next=a;
			break;
		}
		else {
			if(a->data <= b->data) {
				MoveNode(&(tail->next),&a);
			}
			else {
				MoveNode(&(tail->next),&b);
			}
			tail=tail->next;
		}
	}
	return dummy.next;
}
			
struct node* SortedMergeRecur(struct node*a, struct node*b) {
	struct node *result=NULL;
		if(a==NULL)
			return b;
		else if(b==NULL)
			return a;
		else {
			if(a->data<=b->data) {
				result=a;	
				result->next=SortedMergeRecur(a->next,b);
			}
			else {
				result=b;
				result->next=SortedMergeRecur(a,b->next);
			}
		}
	return result;
	
}













		





void main() {
	struct node*head=NULL;
	int a;
	getInputs(&head);
	printList(head);
	Rtrylink.ctrylink.cemoveDuplicates(head);

}
	

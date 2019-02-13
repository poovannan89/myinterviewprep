#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
struct node {
	int d;
	struct node *next;
};
void Push(struct node **headRef,int d) {
	struct node *newNode=(struct node*)malloc(1*sizeof(struct node));
	newNode->d=d;
	newNode->next=(*headRef);
	(*headRef)=newNode;
}

void Disp(struct node *head) {
	struct node *curr;
	curr=head;
	while(curr != NULL) {
		printf("%d\t",curr->d);
		curr=curr->next;
	}
}

int Length(struct node *head) {
	int cnt;
	struct node *curr;
	curr=head;
	while(curr !=NULL) {
		cnt++;
		curr=curr->next;
	}
	return cnt;
}	
int Pop(struct node **headRef) {
	int d;
	struct node *head;
	head=(*headRef);
	d=head->d;
	(*headRef)=head->next;
	free(head);
	return d;
}

int DeleteList(struct node **headRef) {
	struct node *curr;
	struct node *next;
	curr=*headRef;
	while(curr !=NULL) {
		next=curr->next;
		free(curr);
		curr=next;
	}
	*headRef=NULL;
}

void InsertNth(struct node **headref,int d,int pos) {
	if(pos==0) {
		Push(headref,d);
	}
	else {
		struct node *curr=*headref;
		int i;
		for(i=0;i<pos-1;i++) {
			assert(curr !=NULL);
			curr = curr->next;
		}
		assert(curr !=NULL);
		Push(&(curr->next),d);	
	}
}

void SortedInsert(struct node **headRef,struct node* newNode) {
	if(*headRef == NULL || (*headRef)->d >= newNode->d) {
		newNode->next=*headRef;
		*headRef=newNode;
	}
	else {
		struct node *curr=*headRef;
		while(curr->next !=NULL && curr->next->d<newNode->d) {
			curr=curr->next;
		}
		newNode->next=curr->next;
		curr->next=newNode;
	}
}

//Iterate thru the list and make it sorted list 
void InsertSort(struct node **headRef) {
	struct node *result; // Answer list
	struct node *curr = *headRef;
	struct node *next;

	while(curr !=NULL) {
		next=curr->next;
		SortedInsert(&result,curr);
		curr=next;
	}
	*headRef=result;
}

void FrontBackSplit(struct node *src,struct node **front,struct node **back) {
	struct node *fast;
	struct node *slow;
	if(src==NULL || src->next==NULL) {
		*front=src;
		*back=NULL;
	}
	else {
		fast=src->next;
		slow=src;
		int f;
		while(fast !=NULL) {
			fast=fast->next;
			if(fast!=NULL) {
				fast=fast->next;
				slow=slow->next;
			}
		}

		*front=src;
		*back=slow->next;
		slow->next=NULL;
		
	}
}

struct node* BuildOneTwoThree() {
	struct node * head;
	Push(&head,3);
	Push(&head,2);
	Push(&head,1);
	return head;
}

void MoveNodeToLast(struct node **a,struct node **b) {
	struct node *curr=*b;
	struct node *acurr=*a;
	if(acurr==NULL) {
		acurr=curr;
		*b=curr->next;
		curr->next=NULL;
	}
	else {
	
		while(acurr->next !=NULL)
			acurr=acurr->next;
		*b=curr->next;
	 	curr->next=acurr->next;
		acurr->next=curr;
	}
}	

void MoveNode(struct node **destRef, struct node **srcRef) {
	struct node *newNode = *srcRef;
	*srcRef=newNode->next;
	newNode->next=*destRef;
	*destRef=newNode;
}

void MoveNodeTest() {
	struct node *a=BuildOneTwoThree();
	struct node *b=BuildOneTwoThree();
	MoveNode(&a,&b);
}

void reverse(struct node **head) {
	struct node *prev=NULL;
	struct node *curr=*head;
	struct node *next;
	while(curr !=NULL) {
		next = curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
	}
	*head=prev;
}
		
			

void main() {
	struct node* head =NULL;
	Push(&head,4);
	Push(&head,2);
	Push(&head,10);
	Push(&head,20);
	Push(&head,30);
	//Pop(&head);
	//DeleteList(&head);
	Push(&head,40);
	//printf("\nBefore insertion\n");
	Disp(head);
	//InsertNth(&head,100,3);	
	//printf("\nAfter insertion\n");
	//Disp(head);
	reverse(&head);
	printf("\nAfter reversal\n");
	Disp(head);

}

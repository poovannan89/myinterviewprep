#include<stdio.h>
struct node {
	int data;
	struct node* next;
};

int Length(struct node* head) {
	int count=0;
	struct node* current =head;
	while(current !=NULL) {
		count++;
		current=current->next;i
	}
	return count;
}

struct node* AddAtHead() {
	struct node* head = NULL;
	int i;
	for(i=1;i<6;i++) {
		Push(&head,i);
	}
	return head;
}


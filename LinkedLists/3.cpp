#include <iostream>

using namespace std;

struct node{
    int data;
    struct node *next;
};

void traverse(struct node *node){

	while(node!=NULL){
		cout<<node->data<<" ";
		node=node->next;
	}
}

void push(struct node **head_ref,int data_new){

    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data_new;
    newnode->next=*head_ref;
    *head_ref=newnode;
}


void insert_after(struct node *prev,int new_data){

  struct node *newnode=(struct node *)malloc(sizeof(struct node));
  newnode->data=new_data;
  newnode->next=prev->next;
  prev->next=newnode;

}

void append(struct node **head_ref,int new_data){
   
   
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=new_data;
    newnode->next=NULL;

    if(*head_ref==NULL){
    	*head_ref=newnode;
    	return;
    }

    struct node *cur=*head_ref;
    
    while(cur->next!=NULL)
    	cur=cur->next;

    cur->next=newnode;

}



int main(){

	struct node *head=NULL;
	struct node *second=NULL;
	struct node *third=NULL;

	head=(struct node*)malloc(sizeof(struct node));
	second=(struct node*)malloc(sizeof(struct node));
	third=(struct node*)malloc(sizeof(struct node));

	head->data=1;
	head->next=second;
	second->data=2;
	second->next=third;
	third->data=3;
	third->next=NULL;
	append(&head,101);
	traverse(head);


    return 0;

}
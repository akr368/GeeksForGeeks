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
  cout<<endl;
}

void push(struct node **head_ref,int data_item){
   
   struct node *newnode=(struct node*)malloc(sizeof(struct node));
   newnode->data=data_item;
   newnode->next=*head_ref;
   *head_ref=newnode;

}


void swap(struct node **head_ref,int x,int y) {
   
    if(x==y)
      return;

    struct node *prev1=NULL;
    struct node *cur1=*head_ref;

    while(cur1!=NULL && cur1->data!=x){
        prev1=cur1;
        cur1=cur1->next;
    }

    struct node *prev2=NULL;
    struct node *cur2=*head_ref;

    while(cur2!=NULL && cur2->data!=y){
         prev2=cur2;
         cur2=cur2->next;
    }

    if(prev1!=NULL)
      prev1->next=cur2;
    else
      *head_ref=cur2;

    if(prev2!=NULL)
      prev2->next=cur1;
    else
      *head_ref=cur1;

    struct node *temp=cur2->next;
    cur2->next=cur1->next;
    cur1->next=temp;
   

}




int main() {

	struct node *head=NULL;
    push(&head,1);
    push(&head,2);
    push(&head,3);
    push(&head,4);
    traverse(head);
    swap(&head,3,2);
    traverse(head);


    


    return 0;

}
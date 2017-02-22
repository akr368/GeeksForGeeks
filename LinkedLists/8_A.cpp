#include <iostream>

using namespace std;

struct node{
    int data;
    struct node *next;
};


void push(struct node **head_ref,int data_item){
   
   struct node *newnode=(struct node*)malloc(sizeof(struct node));
   newnode->data=data_item;
   newnode->next=*head_ref;
      *head_ref=newnode;

}


bool search(struct node *node,int x){
   
     while(node!=NULL){
        if(node->data==x)
          return true;
        node=node->next;
     }
   return false;  

}



int main(){

	struct node *head=NULL;
    push(&head,1);
    push(&head,2);
    push(&head,3);
    cout<<"isPresent : "<<search(head,3)<<endl;


    return 0;

}
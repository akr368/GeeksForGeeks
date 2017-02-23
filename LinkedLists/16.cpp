#include <iostream>
using namespace std;

struct node {
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

int count(struct node *node,int key){

   int count=0;
   while(node!=NULL){
      if(node->data==key)
         count++;
      node=node->next;
   }
   return count;
}




int main(){

  struct node *head=NULL;
  push(&head,1);
  push(&head,1);
  push(&head,3);
  push(&head,1);
  push(&head,5);
  
  cout<<"Count: "<<count(head,1)<<endl;
  return 0;
}
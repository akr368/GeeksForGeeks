#include <iostream>
using namespace std;

struct node {
 int data;
 bool visited;
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
   newnode->visited=false;
   newnode->next=*head_ref;
   *head_ref=newnode;
}

void isLoop(struct node *node){
  
  while(node!=NULL){
        
        if(node->visited==true)
        {
          cout<<"Loop Exists"<<endl;
          return;
        }
        node->visited=true;
        node=node->next;
  }

  cout<<"No Loop";
  

}





int main() {

  struct node *head=NULL;
  push(&head,1);
  push(&head,2);
  head->next->next=head;
  //traverse(head);
  isLoop(head);
  

  return 0;

}
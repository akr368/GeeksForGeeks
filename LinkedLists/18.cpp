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


struct node* merge(struct node *a,struct node *b){

  struct node *result=NULL;

  if(a==NULL)
    return b;
  if(b==NULL)
    return a;

  if(a->data <= b->data){
      result=a;
      result->next=merge(a->next,b);
  }

  else{
      result=b;
      result->next=merge(a,b->next);
  }

  return result;

}


int main() {

  struct node *head1=NULL;
  struct node *head2=NULL;
  push(&head1,10);
  push(&head1,2);
  push(&head2,5);
  push(&head2,1);
  struct node *result=merge(head1,head2);
  traverse(result);

  return 0;

}
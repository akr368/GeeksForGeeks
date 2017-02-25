#include <iostream>

using namespace std;


struct node{
  int data;
  struct node *next;
};

void push(struct node **head_ref,int data_item){

  struct node *newnode=(struct node *)malloc(sizeof(struct node));
  newnode->data=data_item;
  newnode->next=*head_ref;
  *head_ref=newnode;

}

void traverse(struct node *node){

   while(node!=NULL){
      cout<<node->data<<" ";
      node=node->next;
   }
   cout<<endl;
}

bool identical(struct node *a,struct node *b){

   if(a==NULL && b==NULL)
    return true;

   while(a!=NULL && b!=NULL){

       if(a->data!=b->data)
        return false;

       a=a->next;
       b=b->next;

   }

   return true;


}

bool identical2(struct node *a,struct node *b){
  
     if(a==NULL && b==NULL)
       return true;
    
     if(a!=NULL && b!=NULL && a->data==b->data)
      return identical2(a->next,b->next);

     return false;


}


int main() {
  
  struct node *head1=NULL;
  push(&head1,2);
  push(&head1,1);
  
  struct node *head2=NULL;
    push(&head2,2);
  push(&head2,1);

  traverse(head1);
  traverse(head2);
  cout<<"Identical2: "<<identical2(head1,head2)<<endl;

  return 0;

}
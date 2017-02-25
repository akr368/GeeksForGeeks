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

void delete_alternate(struct node *head){
     
     if(head==NULL)
      return;

     struct node *prev=head;
     struct node *next_node=head->next;

     while(prev!=NULL && next_node!=NULL){
       
       struct node *temp=next_node;
       prev->next=temp->next;
       free(temp);
       prev=next_node;
       if(prev!=NULL)
         next_node=prev->next;

     }


}




int main() {
  
  struct node *head=NULL;
  push(&head,6);
  push(&head,5);
  push(&head,4);
  push(&head,3);
  push(&head,2);
  push(&head,1);
  traverse(head);
  delete_alternate(head);
  traverse(head);

  return 0;

}
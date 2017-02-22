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

  struct node *newnode=(struct node *)malloc(sizeof(struct node));
  newnode->data=data_item;
  newnode->next=*head_ref;
  *head_ref=newnode;

}

void delete_position(struct node **head_ref,int position){
  
    if(*head_ref==NULL)
        return;

    struct node *temp=*head_ref;
    struct node *prev=temp;

    if(position==0){
        
        *temp=*temp->next;
        free(temp);
        return;
    }

    while(position>=1 && temp!=NULL){
        prev=temp;
        temp=temp->next;
        position--;
    }

    if(temp==NULL){
        return;
    }

    if(temp->next==NULL){
      prev->next=NULL;
      free(temp);
      return;
    }

    prev->next=temp->next;
    free(temp);


}


int main(){

	struct node *head=NULL;
    push(&head,1);
    push(&head,2);
    push(&head,3);
    traverse(head);
    delete_position(&head,10);
    traverse(head);


    return 0;

}
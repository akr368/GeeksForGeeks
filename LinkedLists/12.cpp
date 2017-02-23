#include <iostream>
using namespace std;

struct node {
 int data;
 struct node *next;
};

void push(struct node **head_ref,int data_item){

   struct node *newnode=(struct node*)malloc(sizeof(struct node));
   newnode->data=data_item;
   newnode->next=*head_ref;
   *head_ref=newnode;
}

void middle1(struct node *node){
  
  int length=0;
  struct node *temp=node;
  while(node!=NULL){
    length++;
    node=node->next;
  }
  int mid=length/2;
  while(temp!=NULL && mid){
     temp=temp->next;
     mid--;
  }

  cout<<"Middle Element: "<<temp->data<<endl;

}

void middle2(struct node *node){

  struct node *pointer1=node;
  struct node *pointer2=node;
  
  if(node!=NULL){

  while(pointer2!=NULL && pointer2->next!=NULL){
        pointer1=pointer1->next;
        pointer2=pointer2->next->next;
  }
}

  cout<<"Middle Element: "<<pointer1->data<<endl;
}



void middle3(struct node *node){

    struct node *mid=node;
    int counter=0;

    while(node!=NULL){
        if(counter%2==1)
          mid=mid->next;
        node=node->next;
        counter++;
    }

   if(mid!=NULL)
    cout<<"Middle3 Element: "<<mid->data<<endl;

}



int main(){

  struct node *head=NULL;
  push(&head,1);
  push(&head,2);
  push(&head,3);
  push(&head,4);
  push(&head,5);
  

  middle3(head);

  return 0;
}
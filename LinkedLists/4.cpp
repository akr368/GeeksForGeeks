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

void delete_node(struct node **head_ref,int key){
   
    struct node *temp=*head_ref;
    struct node *prev=temp;

    if(temp->data==key && temp!=NULL){
        *head_ref=temp->next;
        free(temp);
        return;
    }

    while(temp->data!=key && temp!=NULL){
        prev=temp;
        temp=temp->next;
    }

    if(temp==NULL)
        return;

    prev->next=temp->next;
    free(temp);

}


void push(struct node **head_ref,int new_data){
  
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=new_data;
    newnode->next=*head_ref;
    *head_ref=newnode;

}


int main(){

	struct node *head=NULL;
    push(&head,3);
    push(&head,2);
    push(&head,1);
    traverse(head);
    delete_node(&head,2);
    traverse(head);


    return 0;

}
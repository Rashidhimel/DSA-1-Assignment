#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
};
struct node*head=NULL;
struct node*newnode;
struct node*temp;

void insertBeginning(){
    int value;
    printf("Enter value:");
    scanf("%d",&value);
    if(head==NULL){
        
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=value;
        newnode->next=NULL;
        head=newnode;

        printf("Inserted at Beginning\n");
        return;
    }
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=head;
    head=newnode;
    printf("Insert at Beginning\n");
    
}
void insertEnd(){
    int value;
    printf("Enter value:");
    scanf("%d",&value);
    if(head==NULL){
        
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=value;
        newnode->next=NULL;
        head=newnode;

        printf("Inserted at End\n");
        return;
    }
    temp=head;
    while (temp->next!=NULL){
        temp=temp->next;
    }
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=NULL;
    temp->next=newnode;  
    printf("Inserted at end\n");
}
void InsertedAtPosition(){
    temp=head;
    int value,pos,count=0;
    int i;
    printf("Enter value and position:");
    scanf("%d%d",&value,&pos);
    //scanf("%d",&pos);
    if (pos < 1) {
        printf("Invalid position! Position must be >= 1\n");
        return;
    }
    for (i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position! Position is greater than list length + 1\n");
        
        return;
    }
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=temp->next;
    temp->next=newnode;
     printf("Inserted at position %d\n",pos);     
    
}
void display(){
    temp=head;
    while (temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    
    
}
int main(){

    while(1){

        int choice;
        printf("\nEnter choice: 1. Insert Beginning 2. Insert End 3. Insert at Position 4. Display 5. Exit\n");
        scanf("%d",&choice);
        if(choice==1){
            insertBeginning();
        }
        else if(choice==2){
            insertEnd();
        }
        else if(choice==3){
            InsertedAtPosition();
        }
        else if(choice==4){
            display();
        }
        else{
            break;
        }


    }
}

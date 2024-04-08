#include<stdio.h>
#include<stdlib.h>
struct node{
        int data;
        struct node *next;
};
struct node *start;
void insert_beg(int ele);
void insert_end(int ele);
void insert_after(int search,int new);
void insert_before(int search,int new);
void print_reverse();
int delete_first();
int delete_last();
int delete_specific_element(int);
void traverse_forward();
void traverse_backward(struct node *start);
int main(){
    start = NULL;
    start = (struct node*)malloc(sizeof(struct node));
    int choice,ele,search,new;
    do{
    printf("enter choice\n1.insert beginning\n2.insert end\n3.insert after element\n4.insert before element\n5.print reverse list\n6.delete first\n7.delete last\n8.delete sepecific element\n9.display forward\n10.display backward::");
    scanf("%d",&choice);
    switch(choice){

        case 1 : printf("enter elements::");
                 scanf("%d",&ele);
                    insert_beg(ele);
                    break;
        case 2 :   printf("enter elements::");
                   scanf("%d",&ele);
                    insert_end(ele);
                        break;
        case 3 :  printf("enter the element after you insert new element:");
                  scanf("%d",&search);
                  printf("enter new element:");
                  scanf("%d",&new);
                  insert_after(search,new);
                  break;
        case 4 :   printf("enter the element before you insert new element:");
                  scanf("%d",&search);
                  printf("enter new element:");
                  scanf("%d",&new);
                  insert_before(search,new);
                  break;
        case 5 :  print_reverse();
                    break;
        case 6 :  printf("first element %d is deleted\n",delete_first());
                    break;
        case 7 :  printf("last element %d is deleted\n",delete_last());
                    break;
        case 8 :  printf("enter the element want to delete");
                    scanf("%d",&search);
                    // delete_specific_element(ele);
                    printf("element %d is deleted",delete_specific_element(search));
                    break;
        case 9 :    printf("call display\n");
                    traverse_forward();
                    break;
        case 10 :   traverse_backward(start);
                    break;
    }
    }while(choice!=0);
    free(start);
    return 0;
}
void insert_beg(int ele){
        struct node* temp;
        temp = (struct node*)malloc(sizeof(struct node));
        if(start != NULL){
            temp->data=ele;
            temp->next=NULL;
            start = temp;
        //     printf("temp =%p\n",temp);
        //  printf("start =%p",start);
            //printf("value inserted\n");
        }
        else printf("list is empty");
}
void insert_end(int ele){
    struct node* temp,*current;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data=ele;
    temp->next=NULL;
    if(start!=NULL){
        current = start;
        while(current->next!=NULL)
            current = current->next;
            current->next=temp;
    }
    else
    printf("list is empty\n");
    
}
void insert_after(int search,int new){
    struct node *temp,*current;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data=new;
    temp->next=NULL;
    if(start!=NULL){
        current=start;
        while(current!=NULL && current->data!=search)
                current=current->next;
        if(current!=NULL){
                temp->next=current->next;
                current->next=temp;
            }
        else printf("element not found\n");
        
    }
    else printf("list is empty\n");
}
void insert_before(int search,int new){
    struct node *temp,*current;
    temp =(struct node*)malloc(sizeof(struct node));
    temp->data=new;
    temp->next=NULL;
    if(start!=NULL){
        if(start->data==search){
            temp->next=start;
                start=temp;
            }
            else{
        current=start;
        while(current->next!=NULL && current->next->data!=search)
                current=current->next; 
                if(current->next!=NULL){
                    temp->next=current->next;
                    current->next=temp;
                }
                else printf("element not found\n");

    }
    }
    else printf("list is empty\n");
}
void print_reverse(){
    struct node *fwd=NULL;
    struct node *prev=NULL;
    while(start!=NULL){
        fwd=start->next;
        start->next=prev;
        prev=start;
        start=fwd;
    }
    start=prev;
}
int delete_first(){
    int x=-999;
    struct node* temp;
    if(start!=NULL){
        temp=start;
    start=start->next;
        x=temp->data;
        free(temp);
        
    }
    else printf("list is empty\n");
    return x;
}
int delete_last(){
    int x=-999;
    struct node *temp,*current;
    if(start!=NULL){
        if(start->next==NULL){
            temp=start;
            x=temp->data;
            start=NULL;
            free(temp);
        }
        else{
                current=start;
                while(current!=NULL && current->next->next!=NULL)
                    current=current->next;
                    if(current!=NULL){
                temp=current->next;
                x=temp->data;
                current->next=NULL;
                free(temp);
                    }
                else printf("element not found\n");
        }       
        }
        else
            printf("list is empty\n");
             return x;
}
int delete_specific_element(int search){
   int x=-999;
   struct node *current,*temp;
   if(start!=NULL){
        if(start->data==search){
            temp=start;
            start=temp->next;
            x=temp->data;
            temp->next=NULL;
            free(temp);
        }
        else{
            current=start;
            while(current->next!=NULL && current->next->data!=search)
                current=current->next;
                 if(current->next!=NULL){
                    temp=current->next;
                    current->next=temp->next;
                     x=temp->data;
                     temp->next=NULL;
                     free(temp);
                }
                else printf("element not found\n");
            }
        }
   else printf("list is empty\n");
    return x;
}
void traverse_forward(){
    struct node *current;
    if(start==NULL){
        printf("list is empty\n");
    }
    else{
        current=start;
        printf("element= ");
        while(current!=NULL){ 
            printf("%d ",current->data);
            current=current->next;
        }
    }
}
void traverse_backward(struct node *start){
    struct node *current;
            if(start==NULL)
            printf("list is empty\n");
            else{
                traverse_backward(start->next);
                printf("%d ",start->data);
            }
}

#include<stdio.h>
#include<stdlib.h>
  struct node{
  int data;
  struct node *next;
  };
  
  //////////////Insertion////////////////////////////////  
  void display(struct node*ptr){
  while(ptr!= NULL){
  printf("element %d\n",ptr->data);
  ptr=ptr->next;
  }
  } // end of the traversing the link list
  
  
  struct node*insertAtFirst(struct node *head,int data){
  struct node* ptr=(struct node*) malloc(sizeof(struct node));
  ptr->next=head;
  ptr->data=data;
  return ptr;
   } // end of the insertion in begining
  
  
  struct node*insertAtIndex(struct node*head,int data,int index){
  struct node* ptr=(struct node*) malloc(sizeof(struct node));
  struct node* p=head;
  int i=0;
  while(i!=index-1){
  p=p->next;
  i++;
  }
  ptr->data=data;
  ptr->next=p->next;
  p->next=ptr;
  return head;
  } // end of insert at index
  
  struct node * insertAfterNode(struct node*head,struct node*prevNode,int data){
  struct node *ptr=(struct node*) malloc(sizeof(struct node));
  
  ptr->data=data;
  ptr->next=prevNode->next;
  prevNode->next=ptr;
  
  return head;
  }
  
  //////////////Deletion////////////////////////////////
  
  struct node*deleteFirst(struct node*head){
  struct node*ptr = head;
  head=head->next;
  free(ptr);
  return head;
  }
  
  struct node*deleteAtIndex(struct node*head,int index){
  struct node*p=head;
    struct node*q=head->next;
    for(int i=0;i<index-1;i++){
    p=p->next;
    q=q->next;
    }
    p->next=q->next;
    free(q);
    return head; 
  }
  
   struct node*deleteAtLast(struct node*head){
   struct node*p=head;
   struct node*q=head->next;
   while(q->next!=NULL){
   p=p->next;
   q=q->next;
   }
   p->next=NULL;
   free(q);
   return head; 
   }
   
   struct node*deleteAtValue(struct node*head,int value){
   struct node*p=head;
   struct node*q=head->next;
   while(q->data != value && q->next != NULL){
   p=p->next;
   q=q->next;
   }
   if(q->data==value){
   p->next=q->next;
   free(q);
   }
   return head;
   }
   
   //////////////////////////////////////////////////////////////////////////////////////////
    
    void travelForward(struct node*head){
   if(start!=NULL){
   head=start;
      while(head->next!=NULL){
      printf("%d",head)
      }
   
   }
   
    }
 
  int main(){
 struct node*head;
 struct node*second;
 struct node*third;
 struct node*fourth;
 head=(struct node*) malloc(sizeof(struct node));
  second=(struct node*) malloc(sizeof(struct node));
  third=(struct node*) malloc(sizeof(struct node));
   fourth=(struct node*) malloc(sizeof(struct node));
   
  head->data =7;
  head->next=second;
   
  second->data=11;
  second->next=third;
  
  third->data=15;
  third->next=fourth;
  
  
  fourth->data=25;
  fourth->next=NULL;
  
 //head=insertAtFirst(head,56);
  //head=insertAtIndex(head,56,1);
   
   //insertAfterNode(head,second,45);
   
//  head= deleteFirst(head);
  
  // deleteAtIndex(head,2);
  
  //deleteAtLast(head);
  
  deleteAtValue(head,11);
    display(head);
  return 0;
  
  
  }

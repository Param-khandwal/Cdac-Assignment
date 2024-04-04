//Create a linked list ADT with functions for insertion, deletion, traverse forward, traverse
//reverse, searching for an element, reversing a list and also test the above functionality.



#include<stdio.h>
#include<stdlib.h>
  struct node{
  int data;
  };
  
  
 
 void display(struct node*ptr){
  while(ptr!= NULL){
  printf("element %d\n",ptr->data);
  ptr=ptr->next;
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
	
  display(head);
	


}

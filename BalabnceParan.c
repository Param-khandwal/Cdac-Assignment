#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stack{
    int size;
    int top;
    int *str;
};

struct stack s;

	int isEmpty(){
        if(s.top == -1)
        return 1;
        else
        return 0;
        }
	
	int isFull(){
        if(s.top == s.size-1)
        return 1;
        else
        return 0;
        }
        
        void push(int a){
        if(!isFull()){
        //s.top++;
        s.str[++s.top]=a;
        }
        else
        printf("Stack is full\n");
        }
        
        
        int pop(){
        int x=-111;
        if(!isEmpty()){
        x=s.str[s.top--];
//       printf("%d is pop from stack\n",x);
        }
        else
        	printf("stack is empty \n");
        
        return 0;
        }
        
        int peek(){
        int x=-999;
        if(!isEmpty ()){
        x=s.str[s.top];
        }
        else
        printf("stack is empty");
        }
        
        void display()
	{
	int i;

	for(i=0;i<=s.top;i++)
	printf("%d \n", s.str[i]);
	}
  
        
	
int main(){
   s.size=80;
   s.top=-1;
   s.str=NULL;

   s.str=(int*)malloc(s.size);
   
   char str[] = "{[a+b-(c*d)/e]}";
    
    int flag=0;
    
    int length = strlen(str);
    char x;
    
    for(int i=0;i<=length;i++){
    int ch=str[i];
    
    switch (ch){
    case('('):push(ch);
    break;
    
    case('['):push(ch);
    break;
    
    case('{'):push(ch);
    break;
    
    case(')'):if(!(ch==(')')&&peek()=='('))
           flag=1;
           else
	   x = pop();
    break;
    
    case('}'):if(!(ch==('}')&&peek()=='{'))
           flag=1;
            else
	   x = pop();
    break; 
    
    case(']'):if(!(ch==(']')&&peek()=='['))
           flag=1;
            else
	   x = pop();
             break; 
    
    default: printf("%c", ch);
     break;	
    
    }
    
    }
    
    if(flag == 1)
		printf("Expression is unbalanced \n");
		
	if(isEmpty())
		printf("\n Expression is balanced ");
	else 
		printf("Expression in unbalanced \n");
   
	 
	 
	
	free(s.str);
        s.str = NULL;		
		
  
  
   return 0;












}

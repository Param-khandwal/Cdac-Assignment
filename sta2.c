#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct __sta__
{
	char *s;
	int size;
	int tos;
} ;

struct __sta__ sta;

int isEmpty()
{
	if(sta.tos == -1)
		return 1;
		
	return 0;
}

int isFull()
{
	if(sta.tos == sta.size-1)
		return 1;
	
	return 0;
}

void push(int a)
{
	if(!isFull())
	{
		sta.s[++sta.tos] = a;
	}
	else
		printf("Stack is full \n");
}

int pop()
{
	int x = -999;
	
	if(!isEmpty())
		x = sta.s[sta.tos--];
	else
		printf("Stack is empty \n");
		
	return 0;
}

int peek()
{
int x = -999;
	if(!isEmpty())
	{
		x = sta.s[sta.tos];
	}
	else
		printf("Stack is empty \n");

return x;

}

void display()
{
int i;

	for(i=0;i<=sta.tos;i++)
		printf("%d ", sta.s[i]);
}

int main()
{
	
	sta.s = NULL;
	sta.size = 80;
	sta.tos = -1;
	
	//printf("Enter the size of the stack : \n");
	//scanf("%d", &sta.size);
	
sta.s = (char*) malloc (sta.size);

char str[] = "{[a+b-(c*d)/e]}";

int flag = 0;
int length = strlen(str); char x;

	for(int i=0 ; i<= length -1; i++)
	{
		int ch = str[i];
		
		switch(ch)
		{
			case('(') : push(ch);
			break;
			case('[') : push(ch);
			break;
			case('{') : push(ch);
			break;
			case(')') : if(!(ch==')' && peek() == '('))
					flag = 1;
				else
					x = pop();
					break;
			case(']') : if(!(ch==']' && peek() == '['))
					flag = 1;
				else
					x = pop();
					break;
			case('}') : if(!(ch=='}' && peek() == '{'))
					flag = 1;
				else
					x = pop();
					break;
			default: printf("%c", ch);
				
				break;			
		}
		if(flag == 1)
			break;
	
	
	}
if(flag == 1)
		printf("Expression is unbalanced \n");
		
	if(isEmpty())
		printf("Expression is balanced \n");
	else 
		printf("Expression in unbalanced \n");
		
free(sta.s);
sta.s = NULL;		
		

	

}



#include<stdio.h>
#include<stdlib.h>

struct __sta__
{
	int *s;
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
	sta.size = 0;
	sta.tos = -1;
	
	printf("Enter the size of the stack : \n");
	scanf("%d", &sta.size);
	
sta.s = (int*) malloc (sizeof(int)* sta.size);

	/*for(int i=0; i <= sta.size-1; i++)
	{
		printf("Enter the element %d", i+1);
		scanf("%d ", &sta.s[i]);
	} */
	
push(10);
push(20);
push(30);
push(40);
push(50);
display();
pop();	
pop();
pop();
display();
peek(); 

free(sta.s);

}


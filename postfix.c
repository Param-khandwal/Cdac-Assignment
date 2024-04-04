#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack
{
	char *ch;
	int size;
	int TOS;
};
struct stack str;


int IsEmpty()
{
	if(str.TOS==-1)
		return 1;
	else
	{
		return 0;
	
	}
}

int IsFull()
{
	if(str.TOS==str.size-1)
		return 1;
	return 0;
}

void push(int ele)
{
	if(!IsFull())
		str.ch[++str.TOS]=ele;
	//else
//		printf("\nStack is Full\n");
}

char pop()
{
	char x='#';
	if(!(IsEmpty()))
		{x=str.ch[str.TOS--];
		
	return x;
		}
	//else{
//		printf("\nStack is Empty\n");
	//	str.TOS=-1;
	//	return str.TOS;
	
}

int prec(char ch)
{
	switch (ch)
	{
		case '*' :
		case '/' : return 2;
		case '+' :
		case '-' : return 1;
		case '(' :
		case '[' :
		case '{' : return 0;
	}

}

char peek()
{

	char x='#';
	if(!(IsEmpty()))
		{
		x=str.ch[str.TOS];
		return x;
		}
	else{
		printf("\nStack is Empty\n");
		//sta.TOS=-1;
		//return sta.TOS;
	}
}


int main()
{	int flag=0;
	str.ch=NULL;
	str.size=0;
	str.TOS=-1;
	
	char stri[1000];
	printf("enter a string : ");
	scanf("%s",stri);
	
	int len=strlen(stri);
//	printf("len = %d ",len);
	str.size=len;
	str.ch=(char *)malloc(str.size);
	
	char optstr[len];
	
	for(int i=0;i<str.size-1;i++)
	{
		char ch=stri[i];
		switch (ch)
		{
			case '(' : push(ch);
				break;
			case '[' : push(ch);
				break;
			case '{' : push(ch);
				break;
			
				    break;
			case '*' :
			case '/' :
			case '+' :
			case '-' :	if(!IsEmpty())
					{
						while (prec(peek())>=prec(ch))
						optstr[i++]=pop();
					}
					push(ch);
					break;
					
			case ')' :  while(peek()!='(')
				{
					optstr[i++]=pop();
				}
			char	x=pop();
				break;
							
			case ']' :  while(peek()!='[')
					{
					optstr[i++]=pop();
					}
					x=pop();
					
					break;
				    
			case '}' : while(peek()!='(')
					{
					optstr[i++]=pop();
					}
					x=pop();
					break;
			default : optstr[i++]=ch;
		}//switch
		if(flag==1)
			break;	
		
	}//for loop
/*	if(flag==1)
		printf("\nUnbalanced\n");
	else if(IsEmpty())
		printf("\nBalance\n");
	else
		printf("UNBALANCED");
*/
	len =strlen(stri);
//	printf("\n\n");
	for(int i=0;i<len;i++)
	{
		printf("%c",optstr[i]);
	}		
	free(str.ch);
	str.ch=NULL;
	return 0;	
}

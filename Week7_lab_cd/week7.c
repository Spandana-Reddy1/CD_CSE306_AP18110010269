#include<stdio.h>
#include<stdlib.h>
void pop(),push(char ),display();
char stack[100]="\0";
char input[100];
int top=-1;
char *ip;
void main()
{
	printf("enter the input string followed by $ \n");
	scanf("%s",input);
	ip=input;
	push('$');
	push('E');
	printf("STACK\t INPUT \t ACTION\n");
	printf("------\t ------- \t ------\n");
	printf("\n%s\t%s\tSHIFT",stack,ip);
	while(stack[top]!='$')
	{
		if(stack[top]=='+' || stack[top]=='*'|| stack[top]=='i'|| stack[top]=='('|| stack[top]==')'||
		stack[top]=='$')
		{
			if(stack[top]==*ip)
			{
				pop();
				ip++;
				printf("\n%s\t%s\tSHIFT",stack,ip);
				printf("\n");
			}
			else
			{
				printf("\n error ");
				exit(0);
			}
		}
		else if(stack[top]=='E' && (*ip=='(' || *ip=='i'))
		{
			pop();
			push('E');
			push('T');
			printf("\n%s\t%s\t",stack,ip);
			printf("REDUCE BY E->TE'\n");
		}
		else if(stack[top]=='E' && (*ip==')' || *ip=='$'))
		{
			pop();
			printf("\n%s\t%s\t",stack,ip);
			printf("REDUCE BY E'->^\n");
		}
		else if(stack[top]=='E' && *ip=='+' )
		{
			pop();	
			push('E');	
			push('T');
push('+');
printf("\n%s\t%s\t",stack,ip);
printf("REDUCE BY E'->+TE'\n");
}
else if(stack[top]=='T' && (*ip=='(' || *ip=='i'))
{
pop();
push('T');
push('F');
printf("\n%s\t%s\t",stack,ip);
printf("REDUCE BY T->FT'\n");
}
else if(stack[top]=='T' && (*ip==')' || *ip=='$' || *ip=='+'))
{
pop();
printf("\n%s\t%s\t",stack,ip);
printf("REDUCE BY E->TE'\n");
}
else if(stack[top]=='T' && *ip=='*')
{
pop();
push('T');
push('F');

push('*');
printf("\n%s\t%s\t",stack,ip);
printf("REDUCE BY T'->*FT'\n");
}
else if(stack[top]=='F' && *ip=='(' )
{
pop();
push(')');
push('E');
push('(');
printf("\n%s\t%s\t",stack,ip);
printf("REDUCE BY F->(E)\n");
}
else if(stack[top]=='F' && *ip=='i')
{
pop();
push('i');
printf("\n%s\t%s\t",stack,ip);
printf("REDUCE BY F->id\n");
}
else
{
printf("\n error");
exit(0);
}
}
printf("\n%s\t%s\t",stack,ip);
printf(" Accept\n\n\n");
}
void push(char c)
{
top++;
stack[top]=c;
}
void pop()
{
stack[top]='\0';
top--;
}
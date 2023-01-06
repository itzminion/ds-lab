#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>


char stack[20];
int top=-1,eval[20];

void push(char item)
{
	top++;
	stack[top]=item;
}
char pop()
{
	char ch;
	ch=stack[top];
	top--;
	return ch;
}

int precedence(char item)
{
	if(item=='(')
	{
		return 0;
	}
	else if(item=='+' || item=='-')
	{
		return 1;
	}
	else if(item=='*' || item=='/')
	{
		return 2;
	}
	else if(item=='^')
	{
		return 3;
	}
	return 0;
}

int associativity(char ch)
{
	if(ch=='^')
	{
		return 2;
	}
	else
	{
		return 1;
	}
}

void infixToPostfix(char* infix,char* postfix)
{
	char ch,item;
	int k=0,i;
	for(i=0;i<strlen(infix);i++)
	{
		ch=infix[i];
		if(ch=='(')
		{
			push(ch);
		}
		else if(isalpha(ch) || isdigit(ch))
		{
			postfix[k]=ch;
			k++;
		}
		else if(ch==')')
		{
			while(stack[top] != '(')
			{
				postfix[k]=pop();
				k++;
			}
			item=pop();
		}
		else
		{
			int p1,p2,a,flag=0;
			while(flag==0)
			{
				p1=precedence(stack[top]);
				p2=precedence(ch);

				if(p2>p1)
				{
					push(ch);
					flag=1;
				}
				else if (p1>p2)
				{
					postfix[k]=pop();
					k++;
					flag=0;
				}
				else
				{
					a=associativity(ch);
					if(a==2)
					{
						push(ch);
					}
					else
					{
						postfix[k]=pop();
						k++;
						push(ch);
					}
					flag=1;
				}
			}
		}
	}
	while(top != -1)
	{
		postfix[k]=pop();
		k++;
	}
	postfix[k]='\0';

}

int evaluate(char* postfix)
{
	int op1,op2,i,top=-1;
	for(i=0;i<strlen(postfix);i++)
	{
		if(isalpha(postfix[i]))
		{
			printf("\nEnter the value %c : ",postfix[i]);
			top++;
			scanf("%d",&eval[top]);
		}
		else if(postfix[i]=='+' || postfix[i]=='-' || postfix[i]=='*' || postfix[i]=='/'|| postfix[i]=='^')
		{
			op2=eval[top];
			top--;
			op1=eval[top];
			switch(postfix[i])
			{
				case '+' : 	eval[top]=op1+op2;
							break;
				case '-' : 	eval[top]=op1-op2;
							break;
				case '*' : 	eval[top]=op1*op2;
							break;
				case '/' : 	eval[top]=op1/op2;
							break;
				case '^' : 	eval[top]=(pow,(op1,op2));
							break;
			}
		}
	}
	return eval[0];
}


void main()
{
	char infix[20],postfix[20];
	printf("Enter the infix expression : ");
	scanf("%s",infix);

	infixToPostfix(infix,postfix);

	printf("\nPostfix expression : %s",postfix);
	printf("\nValue after evaluation : %d",evaluate(postfix));
}

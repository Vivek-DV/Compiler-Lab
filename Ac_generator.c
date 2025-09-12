#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

char expr[30],postfix[30],stack[30];

int prec(char c){
	if(c=='^') return 3;
	else if(c=='/'||c=='*') return 2;
	else if(c=='+'||c=='-') return 1;
	else return -1;
}

void infixToPostfix(char *expr){
	int len=strlen(expr);
	int j=0,top=-1;
	for(int i=0;i<len;i++){
		char c=expr[i];
		if(isalnum(c)) 
			postfix[j++]=c;
		else if(c=='(')
			stack[++top]=c;
		else if(c==')'){
			while(top!=-1&&stack[top]!='(')
				postfix[j++]=stack[top--];
			top--;
		}
		else{
			while(top!=-1&&(prec(c)<prec(stack[top])||prec(c)==prec(stack[top])))
				postfix[j++]=stack[top--];
			stack[++top]=c;
		}
	}
	
	while(top!=-1)
		postfix[j++]=stack[top--];
	
	postfix[j]='\0';
	printf("Postfix expression:%s\n",postfix);
}

int main(){
	int addr,i;
	char ch,result[20];
	printf("Enter the expression\n");
	scanf("%s",expr);
	printf("Enter the starting address:\n");
	scanf("%d",&addr);
	infixToPostfix(expr);
	ch=postfix[i];
	while(ch!='\0')
	{
	 	if(isalpha(ch))
	 	{
	 		printf("%d : MOV A,%c\n",addr,ch);
	 		addr++;
	 		printf("%d : PUSH A\n",addr);
	 		addr++;
	 	}
	 	else{
	 		printf("%d : POP B\n",addr);
	 		addr++;
	 		printf("%d : POP A\n",addr);
	 		addr++;
	 		if(ch=='*')
	 		{
	 			printf("%d : MUL B\n",addr);
	 			addr++;
	 			printf("%d : PUSH A\n",addr);
	 			addr++;
	 		}
	 		else if(ch=='+')
	 		{
	 			printf("%d : ADD B\n",addr);
	 			addr++;
	 			printf("%d : PUSH A\n",addr);
	 			addr++;
	 		}
	 		else if(ch=='-')
	 		{
	 			printf("%d : SUB B\n",addr);
	 			addr++;
	 			printf("%d : PUSH A\n",addr);
	 			addr++;
	 		}
	 		else if(ch=='/')
	 		{
	 			printf("%d : DIV B\n",addr);
	 			addr++;
	 			printf("%d : PUSH A\n",addr);
	 			addr++;
	 		}
	 	}
	 	i++;
	 	ch=postfix[i];
	}
	if(ch=='\0')
	{
		printf("%d : POP A\n",addr);
		addr++;
		printf("%d : HLT\n",addr);
	}
}

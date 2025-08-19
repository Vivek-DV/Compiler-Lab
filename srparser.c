#include<stdio.h>
int top=0;
char input[30],stack[20];
int j=0,sl=1;
	
void reduce(){
	int z=0;
	for(z=0;z<=top;z++){
		if(stack[z]=='i'){
			stack[z]='E';
			printf("\n%d\t$%s\t%s$\tReduce E-->i",sl,stack,input);
			sl++;
		}
	}
	
	for(z=0;z<=top;z++){
		if(stack[z]== '('&&stack[z+1]=='E'&&stack[z+2]==')'){
			stack[z]='E';
			top=top-2;
			stack[z+1]='\0';
			printf("\n%d\t$%s\t%s$\tReduce E-->(E)",sl,stack,input);
			sl++;
		}
	}
	for(z=0;z<=top;z++){
		if(stack[z]=='E'&&stack[z+1]=='+'&&stack[z+2]=='E'){
			stack[z]='E';
			top=top-2;
			stack[z+1]='\0';
			printf("\n%d\t$%s\t%s$\tReduce E-->E+E",sl,stack,input);
			sl++;
		}
	}
	for(z=0;z<=top;z++){
		if(stack[z]=='E'&&stack[z+1]=='*'&&stack[z+2]=='E'){
			stack[z]='E';
			top=top-2;
			stack[z+1]='\0';
			printf("\n%d\t$%s\t%s$\tReduce E-->E*E",sl,stack,input);
			sl++;
		}
	}
}

int main(){
	printf("Enter the string\n");
	scanf("%s",input);
	printf("\nSl.No.\tStack\tInput\tAction\n");
	
	while(input[j]!='\0'){
		stack[top++]=input[j];
		stack[top]='\0';
		printf("\n%d\t$%s\t%s$\tShift->%c",sl,stack,input,input[j]);
		sl++;
		input[j]=' ';
		j++;
		reduce();
	}
	
	if(stack[0]=='E'&&stack[1]=='\0'){
		printf("String accepted\n");
	}
	else
		printf("String rejected\n");
}

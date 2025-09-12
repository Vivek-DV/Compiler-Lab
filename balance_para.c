#include<stdio.h>

int main(int argc, char * argv[])
{
	if(argc!=2)
	{
		printf("Enter file name!\n");
		return 1;
	}
	
	int line=1,top=-1;
	char ch,c,stack[30];
	FILE * fp=fopen(argv[1],"r");
	
	if(fp==NULL)
	{
		printf("Error Opening File\n");
		return 1;
	}
	
	while((ch=fgetc(fp))!=EOF)
	{
		switch(ch)
		{
			case '\n': 
				line++;
				break;
				
			case '(':
			case '{':
			case '[': 
				stack[++top]=ch;
				break;
				
			case '}':
				if(top==-1)
				{
					printf("Error %d: Missing Open Parenthesis\n",line);
				}
				else{
					c=stack[top--];
					if(c!='{')
					{
						printf("Error %d: Parenthesis mismatch\n",line);
					}
				}
				break;
			
			case ']': 
				if(top==-1)
				{
					printf("Error %d: Missing Open Parenthesis\n",line);
				}
				else{
					c=stack[top--];
					if(c!='[')
					{
						printf("Error %d: Parenthesis mismatch\n",line);
					}
				}
				break;
			
			case ')': 
				if(top==-1)
				{
					printf("Error %d: Missing Open Parenthesis\n",line);
				}
				else{
					c=stack[top--];
					if(c!='(')
					{
						printf("Error %d: Parenthesis mismatch\n",line);
					}
				}
				break;
			
			}
		}
	if(top!=-1)
	{
		printf("Error %d: Missing Closing Parenthesis\n",line);
	}
	else
		printf("Syntax Matched!\n");
}

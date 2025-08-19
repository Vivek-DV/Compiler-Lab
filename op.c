#include<stdio.h>
#include<string.h>

int main()
{
	int n,p,q;
	int top=-1,flag;
	char ter[20],ch,x,y,symbol;
	char opt[20][20];
	char input[30],stack[30];
	printf("Enter the no. of terminals:");
	scanf("%d",&n);
	printf("Enter the terminals:\n");
	for(int i=0;i<n;i++)
	{
		scanf(" %c",&ter[i]);
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("Enter precedence of %c to %c: ",ter[i],ter[j]);
			scanf(" %c",&opt[i][j]);
		}
	}
do{
    flag=0;
	printf("Enter the input string bounded by $: ");
	scanf("%s",input);
	
	int j=0;
	stack[++top]=input[j++];
	
	do{
		for(int k=0;k<n;k++)
		{
			if(stack[top]==ter[k]){
				p=k;
				
				break;
			}
		} 
		
		for(int k=0;k<n;k++)
		{
			if(input[j]==ter[k]){
				q=k;
				
				break;
			}
		} 
		ch=opt[p][q];
	//	printf("%c %c %c\n",stack[top],ch,input[j]);
		
		if(ch=='-')
		{
			printf("Rejected\n");
			flag=1;
			break;
		}
		
		else if(ch=='<'||ch=='=')
		{
			stack[++top]=input[j++];
		}
		
		else {
			do{
				x=stack[top--];
				y=stack[top];
				
				for(int k=0;k<n;k++)
				{
					if(x==ter[k]){
						p=k;
						break;
					}
				}	 
		
				for(int k=0;k<n;k++)
				{
					if(y==ter[k]){
						q=k;
						break;
					}
				} 
				
				symbol=opt[q][p];
				
			}while(symbol!='<' && symbol!='=');
		}
		
	}while(stack[top]!='$' && input[j]!='$');
	if(flag==0)
	    printf("Accepted\n");
	
}while(strcmp(input,"exit")!=0);
	
}
		

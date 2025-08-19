#include<stdio.h>
#include<string.h>

int main(){
	char stack[20],string[20],terminals[20],ch,pop,table[50][50];
	int n,index=0,m=0,p,q;
	printf("Enter the number of terminals\n");
	scanf("%d",&n);
	printf("Enter the terminals\n");
	for(int j=0;j<n;j++){
		scanf(" %c",&terminals[j]);
	}
	printf("Enter the precedence\n");
	for(int j=0;j<n;j++){
		for(int k=0;k<n;k++){
			printf("\n%c and %c-->",terminals[j],terminals[k]);
			scanf(" %c",&table[j][k]);
		}
	}
	
	printf("Enter the input string\n");
	scanf("%s",string);
	
	while(strcmp(string,"EXIT")!=0){
		printf("1");
		index=0,m=0;
		stack[index]=string[m];
		m++;
		while(string[m]!='$'&&stack[index]!='$'){
		printf("2");
			for(int j=0;j<n;j++){
				if(terminals[j]==stack[index]){
					 p=j;
				}
				else if(terminals[j]==string[m]){
					 q=j;
				}
				else
					continue;
			}
			printf("3");
			ch=table[p][q];
			
			if(ch=='-'){
				printf("String rejected\n");
				break;
			}
			else if(ch=='<'||ch=='='){
				index++;
				stack[index]=string[m];
				m++;
			}
			else if(ch=='>'){
			while(table[p][q]!='<'||table[p][q]!='='){
					pop=stack[index];
					index--;
					for(int j=0;j<n;j++){
						if(terminals[j]==pop){
							int p=j;
						}
						else if(terminals[j]==stack[index]){
							int q=j;
						}	
						else{}
					}
					
				}
			}
		}
		printf("string accepted\n");
		printf("Enter the input string\n");
		scanf("%s",string);
	}
}

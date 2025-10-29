#include<stdio.h>
#include<ctype.h>
#include<string.h>
void main()
{
	FILE *input,*output;
	input=fopen("input.txt","r");	
	output=fopen("output.txt","w");
	char keywords[100][100]={"if","else","while","for","return","break","int","char","float","void","main","printf"};
	char ch,next,str[30],num[30];
	int i,j,k,flag;
	
	while(!feof(input))
	{
		i=0,j=0,k=0,flag=0;
		ch=fgetc(input);
		if(ch=='/')
		{
			next=fgetc(input);
			if(next=='/')
			{
				next=fgetc(input);
				while(next!='\n')
				{
					next=fgetc(input);
					continue;
				}
			}
			else
				fprintf(output,"Operator: %c\n",ch);	
		}
		else if(ch=='+'||ch=='-'||ch=='*'||ch=='='||ch=='<'||ch=='>')
			fprintf(output,"Operator: %c\n",ch);
		else if(ch==','||ch==';'||ch=='{'||ch=='}'||ch=='('||ch==')'||ch=='['||ch==']')
			fprintf(output,"Delimiter: %c\n",ch);
		else if(isdigit(ch))
		{
			num[i]=ch;
			i++;
			next=fgetc(input);
			while(next!=' ' && isdigit(next))
			{
				num[i]=next;
				i++;
				next=fgetc(input);
			}
			num[i]='\0';
			fprintf(output,"Number: %s\n",num);
		}
		else if(isalpha(ch)||ch=='_')
		{	
			str[j]=ch;
			j++;
			next=fgetc(input);
			while(isalnum(next) && next!=' ')
			{
				str[j]=next;
				j++;
				next=fgetc(input);
			}
			str[j]='\0';
			for(k=0;k<=30;k++)
			{
				if(strcmp(str,keywords[k])==0)
				{
					flag=1;
					break;
				}
			}
			if(flag==1)
				fprintf(output,"Keyword: %s\n",str);
			else
				fprintf(output,"Identifier: %s\n",str);	
			ungetc(next,input);
		}	
		
	}
	fclose(input);
	fclose(output);
}

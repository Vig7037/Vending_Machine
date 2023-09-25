#include<stdio.h>
int main()
{
	char code[10],str[35];
	int stock_c,stock_f, quan, num, inum, i=0,cc=20,fc=30,tm=0,cm=0,fm=0, vw;
	for(i=0;i<30;i++)
	{
		str[i]=' ';
	}
	printf(" %s Welcome to our Vending Machine\n",str);
	printf("Enter 1 for order.\n");
	printf("Enter 2 for adding the stock.\n");
	printf("Enter the number for which task do you want to do:");
	scanf("%d",&vw);
	if(vw==1)
	{
	printf("We have 2 items available in our vending machine->\n");
	printf("1. Coke with price 20$\n2. Fanta with price 30$\n");
	printf("how many items do you want:");
	scanf("%d",&inum);
	printf("Enter 1 for coke.\nEnter 2 for fanta.\n");
	for(i=0;i<inum;i++)
	{
		printf("Enter the code:\n");
		fflush(stdin);
		scanf("%c",&code[i]);
	}
	code[i]='\0';
	i=0;
	FILE *fp=fopen("C:\\Users\\ASUS\\Documents\\OneNote Notebooks\\merge.txt","r");
	// this is for take the stock from the file
	if(fp!=NULL)
	{
		while(!feof(fp))
		{
			fscanf(fp,"%d",&stock_c);
			fscanf(fp,"%d",&stock_f);
		}
	}
    //this is for coke order
    while(code[i]!='\0')
    {if(code[i]=='1')
	{printf("Enter the quantity of coake:\n");
	scanf("%d",&quan);
	num=stock_c-quan;
	if(num>=0)
	{
		printf("Here is your %d coake\n",quan);
		cm=cc*quan;
		stock_c=stock_c-quan;
	}
	else
	{
		printf("Such quantity are not available.\n");
		printf("We have only %d coake is available\n",stock_c);
	}}
	i++;
	}	
	i=0;
	//this is for fanta order
	while(code[i]!='\0')
    {if(code[i]=='2')
    {
	printf("Enter the quantity of fanta:\n");
	scanf("%d",&quan);
	num=stock_f-quan;
	if(num>=0)
	{
		printf("Here is your %d fanta\n",quan);
		fm=fc*quan;
		stock_f=stock_f-quan;
	}
	else
	{
		printf("Such quantity are not available.\n");
		printf("We have only %d fanta is available\n",stock_f);
	}}
	i++;
	}
	tm=cm+fm;
	printf("\nThe total cost is %d$",tm);
	
	fclose(fp);
	// this is for return the stock to the filea
	fp=fopen("C:\\Users\\ASUS\\Documents\\OneNote Notebooks\\merge.txt","w");
	if(fp!=NULL)
	{
		fprintf(fp,"%d ",stock_c);
		fprintf(fp,"%d",stock_f);
	}
	fclose(fp);}
	// This for adding the stock in the file
	if(vw==2)
	{
	FILE *fp=fopen("C:\\Users\\ASUS\\Documents\\OneNote Notebooks\\merge.txt","r");
	if(fp!=NULL)
	{
		if(!feof(fp))
		{
			fscanf(fp,"%d%d",&stock_c,&stock_f);
		}
	}
	fclose(fp);
	printf("Enter 1 for coke adding.\nEnter 2 for fanta adding.\nEnter 3 for both adding.\n");
	printf("Enter the no:");
	scanf("%d",&num);
	if(num==1)
	{printf("Enter the quantity of coke which you are added:");
	scanf("%d",&quan);
	stock_c=stock_c+quan;	
	}
	if(num==2)
	{printf("Enter the quantity of fanta which you are added:");
	scanf("%d",&quan);
	stock_f=stock_f+quan;	
	}
	if(num==3)
	{printf("Enter the quantity of coke which you are added:");
	scanf("%d",&quan);
	stock_c=stock_c+quan;
	printf("Enter the quantity of fanta which you are added:");
	scanf("%d",&quan);
	stock_f=stock_f+quan;	
	}
	fp=fopen("C:\\Users\\ASUS\\Documents\\OneNote Notebooks\\merge.txt","w");
	if(fp!=NULL)
	{
	fprintf(fp,"%d ",stock_c);
	fprintf(fp,"%d",stock_f);
	}
	fclose(fp);
	printf("Your stock is added.");
	} 
	return 0;
}

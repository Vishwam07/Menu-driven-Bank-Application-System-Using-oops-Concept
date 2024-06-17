#include<stdio.h>
struct account
{
	char name[50];
	char address[50];
	int acc_no;
	int balance;
	int age;
};
void output(struct account[],int);
int search(struct account[],int,int);
void deposit(struct account[],int,int,int);
void withdraw(struct account[],int,int,int);
int main()
{
	struct account a[50];
	int n,i,num,choice,acc_no,count,amount,ac=1001;
	printf("Enter the Number of accounts to be created\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter details of user %d",i+1);
		printf("\nName:");
		scanf("%s",a[i].name);
		printf("\nAddress:");
		scanf("%s",a[i].address);
        a[i].acc_no=ac++;
		printf("\nAccount number is:%d",a[i].acc_no);
		printf("\nBalance:");
		scanf("%d",&a[i].balance);
		printf("\nAge:");
		scanf("%d",&a[i].age);
	}
	do
	{
	printf("\n\n*****BANKING*****");
	printf("\n1:Display Accounts.");
	printf("\n2:Search Account Details.");
	printf("\n3:Deposit Amount.");
	printf("\n4:Withdraw Amount.");
	printf("\n5:Exit");
	printf("\nEnter Your choice:");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			output(a,n);
			break;
		case 2:
			printf("Enter the account number to be searched:");
			scanf("%d",&acc_no);
			count=search(a,n,acc_no);
			if(count==-1)
			printf("Account not present\n");
			else
			{
			printf("Account Found\n");
			printf("loading details.......\n");
			printf("\nName:%s",a[count].name);
			printf("\nAddress:%s",a[count].address);
			printf("\nAccount number:%d",a[count].acc_no);
			printf("\nBalance:%d",a[count].balance);
			printf("\nAge:%d\n",a[count].age);
           	}
			break;
		case 3:
			printf("Enter Account number\n");
			scanf("%d",&acc_no);
			printf("Enter Amount to be deposited:");
			scanf("%d",&amount);
			deposit(a,n,acc_no,amount);
			break;
		case 4:
		    printf("Enter Account number\n");
			scanf("%d",&acc_no);
			printf("Enter Amount to be withdrawn:");
			scanf("%d",&amount);
			withdraw(a,n,acc_no,amount);
			break;
		case 5:
			printf("thank you");
			break;
		default:
			printf("entered invalid input");
	}
	}
	while(choice!=5);

}
void output(struct account a[50],int m)
{
	int i;
	for(i=0;i<m;i++)
    {
    printf("\nDetails of user %d",i+1);
	printf("\nName:%s",a[i].name);
	printf("\nAddress:%s",a[i].address);
	printf("\nAccount number:%d",a[i].acc_no);
	printf("\nBalance:%d",a[i].balance);
	printf("\nAge:%d\n",a[i].age);
	}
}
int search(struct account a[50], int m, int number)
{
    int i;
	for(i=0;i<m;i++)
    {
        if (a[i].acc_no==number)
        {
            return i;
        }
    }
    return(-1);
}
void deposit(struct account a[], int m, int number, int amount)
{
    int i=search(a,m,number);
    if (i==- 1)
    {
        printf("Account not found");
    }
    else
    {
        a[i].balance+=amount;
    }

}
void withdraw(struct account a[], int m, int number, int amount)
{
    int i=search(a,m,number);
    if (i==- 1)
    {
        printf("Account not found\n");
    }
    else if (a[i].balance<amount)
    {
        printf("Insufficient balance\n");
    }
    else
    {
        a[i].balance-= amount;
    }
}

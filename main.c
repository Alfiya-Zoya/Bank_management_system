#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
void account();
void transfermoney(char accno[]);
void checkbalance(char accno[]);
void loginsu(char accno[]);
void login();
void logout();
struct acc
{
	char name[20];
	char lname[20];
	char fname[20];
	char mname[20];
	char add[20];
	char at[20];
	char dob[10];
	char num[20];
	char ac[20];
	char am[20];
	char pw[20];
};
void main()
{
	int n;
	printf("1.CREATE ACCOUNT\n2.LOGIN");
	printf("\nWHAT DO YOU WANT = ");
	scanf("%d", &n);
	switch (n)
	{
	case 1:
	{
		account();
		break;
	}
	case 2:
	{
		login();
		break;
	}
	default:
		printf("INVALID INPUT");
	}

}
void account()
{
	struct acc a;
	FILE* fp;
	int i;
	char ch;
	char accno[20];
	printf("Enter account number = ");
	getchar();
	gets(accno);
	strcat(accno, ".txt");
	fp = fopen(accno, "w");
	printf("CREATE ACCOUNT!!");
	printf("\nFIRST NAME = ");
	gets(a.name);
	printf("\nLAST NAME = ");
	gets(a.lname);
	printf("\nFATHER's NAME = ");
	gets(a.fname);
	printf("\nMOTHER's NAME = ");
	gets(a.mname);
	printf("\nADDRESS = ");
	gets(a.add);
	printf("\nACCOUNT TYPE(single/joint) = ");
	gets(a.at);
	printf("\nDATE OF BIRTH = ");
	gets(a.dob);
	printf("\nPHONE NUMBER = ");
	gets(a.num);
	printf("\nACCOUNT NUMBER = ");
	gets(a.ac);
	printf("\nPASSWORD = ");
	gets(a.pw);
	printf("\nENTER AMOUNT(minimum Rs.1000) = ");
	gets(a.am);
	if (a.am < 1000)
	{
		printf("\nACCOUNT NOT CREATED(entered money is not appropriate.)");
	}
	else
	{
		fprintf(fp, "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s", a.name, a.lname, a.fname, a.mname, a.add, a.at, a.dob, a.num, a.ac, a.pw, a.am);
	}
	fclose(fp);
	printf("\nACCOUNT CREATED SUCCESSFULLY.... ");
}

void login()
{
	char c1[50];
	char pw[40], pw1[40];
	int i;
	char ch;
	FILE* f1;
	printf("Enter account number = ");
	getchar();
	gets(c1);
	strcat(c1, ".txt");
	f1 = fopen(c1, "r");
	if (f1 == NULL)
	{
		printf("Account not found\n");
		exit(0);
	}
	printf("ENTER THE PASSWORD: ");
	gets(pw);
	for (i = 1; i <= 11; i++)
	{
		fscanf(f1, "%s", pw1);
		if (i == 10)
		{

			if (strcmp(pw, pw1) != 0)
			{
				printf("INCORRECT PASSWORD");
				exit(0);
			}
			else
			{
				printf("LOGIN SUCCESSFULL");
				fclose(f1);
				loginsu(c1);
			}
		}
	}
}
void loginsu(char accno)
{
	int i;
	printf("FETCHING ACCOUNT DETAILS.......\n");
	for (i = 0; i < 20; i++)
	{

		i++;
		i--;
	}

	int n;
	printf("PROVIDED SERVICES:\n");
	printf("1.Check balance\n");
	printf("2.Money transfer\n");
	printf("3.Transaction History\n");
	printf("4.Logout\n");
	printf("ENTER THE DESIRED SERVICE(1,2,3,4)\n");
	scanf("%d", &n);
	switch (n)
	{
	case 1:
	{
		checkbalance(accno);
		break;
	}
	case 2:
	{
		transfermoney(accno);
		break;
	}
	case 3:
	{
		transction(accno);
		break;
	}
	case 4:
	{
		logout();
		break;
	}
	default:
		printf("INVALID INPUT.");
	}
}

void checkbalance(char accno[20])
{
	char money[20];
	char ch;
	int i, c = 0;
	FILE* fp;
	fp = fopen("102.txt", "r");
	if (fp == NULL)
	{
		printf("Account doesn't exist\n");
		exit(0);
	}
	printf("****BALANCE DASHBOARD****\n");
	for (ch = getc(fp); ch != EOF; ch = getc(fp))
	{
		if (ch == '\n')
			c++;
	}
	fseek(fp, 0, SEEK_SET);
	for (i = 0; i <= c + 1; i++)
	{
		fscanf(fp, "%s", &money);
		if (i == c + 1)
		{
			printf("Final Balance = %s\n", money);
		}
	}
	fclose(fp);
	loginsu(accno);
}

void transfermoney(char c1[50])
{
	char c2[20];
	printf("Enter reciever's account number = ");
	getchar();
	gets(c2);
	strcat(c2, ".txt");
	FILE* f1;
	FILE* f2;
	char b1[10], b2[10];
	int m, i, j, b3, b4;
	f1 = fopen("101.txt", "r");
	f2 = fopen(c2, "r");
	if (f1 == NULL || f2 == NULL)
	{
		printf("accounts doesn't exist\n");
		exit(0);
	}
	printf("ENTER THE AMOUNT TO BE TRANSFERRED = ");
	scanf("%d", &m);
	char c, cr;
	int cn = 0, cm = 0;
	for (c = fgetc(f1); c != EOF; c = fgetc(f1))
	{
		if (c == '\n')
			cn++;
	}
	for (cr = fgetc(f2); cr != EOF; cr = fgetc(f2))
	{
		if (cr == '\n')
			cm++;
	}
	fseek(f1, 0, SEEK_SET);
	fseek(f2, 0, SEEK_SET);
	for (i = 0; i <= cn + 1; i++)
	{
		fscanf(f1, "%s", b1);
		if (i == cn + 1)
		{
			printf("PRESENT VALUE IN 101.txt ACCOUNT IS %s\n", b1);
		}
	}
	for (i = 0; i <= cm + 1; i++)
	{
		fscanf(f2, "%s", b2);
		if (i == cm + 1)
		{
			printf("PRESENT VALUE IN %s account is %s\n", c2, b2);
		}
	}
	b3 = atoi(b1);
	b4 = atoi(b2);
	if (m <= b3)
	{
		b3 = b3 - m;
		b4 = b4 + m;
		printf("TRANSFERRING MONEY, PLEASE WAIT\n");
		for (i = 0; i < 10; i++)
		{
			for (j = 0; j < 5; j++)
			{
				j++;
				j--;
			}
			printf("*");
		}
		printf("\n");
		printf("TRANSACTION IS SUCCESSFUL\n");
		printf("new balance in 101.txt account is %d\n", b3);
		printf("new balance in %s account is %d\n", c2, b4);
	}
	else
	{
		printf("INSUFFICIENT BALANCE\n");
		exit(0);
	}
	fclose(f1);
	fclose(f2);
	sprintf(b1, "%d", b3);
	sprintf(b2, "%d", b4);
	f1 = fopen("101.txt", "a");
	f2 = fopen(c2, "a");
	fseek(f1, 0, SEEK_END);
	fseek(f2, 0, SEEK_END);
	fprintf(f1, "\n%s", b1);
	fprintf(f2, "\n%s", b2);
	fclose(f1);
	fclose(f2);
	loginsu(c1);
}
void logout()
{
	printf("Signing out now\n");
	printf("THANK YOU\n");
	exit(0);
}
void transcation(char accno[20])
{
	FILE* fp;
	fp = fopen("101.txt", "r");
	char ch, str[20];
	int c = 0, i;
	for (ch = getc(fp); ch != EOF; ch = getc(fp))
	{
		if (ch == '\n')
			c++;
	}
	fseek(fp, 0, SEEK_SET);
	printf("YOUR TRANSACTION HISTORY\n");
	for (i = 0; i <= c + 1; i++)
	{
		fgets(str, 20, fp);
		if (i > 10)
		{
			printf("%s", str);
		}
	}
	fclose(fp);
	loginsu(accno);
}

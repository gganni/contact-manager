#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include"data.h"
#include"searchin.h"

void main()
{    void add_contact();
	 void list_contact();
	 void delete_contact();
	 void edit_contact();
	 void search_contacts();
	 void change_password();
  char pass[30],original[30],ch,choice;
  int i;
  FILE*fp;
  window(1,1,80,25);
  textbackground(YELLOW);
  clrscr();
  window(20,10,60,15);
  textbackground(BLACK);
  clrscr();
  gotoxy(4,3);
  textcolor(RED);
  cprintf("enter the password :");
  i=0;
   while(1)
   {

  ch=getch();
  if(ch==13)
  { pass[i]='\0';
	break;
  }
  pass[i++]=ch;
  printf("*");
}
fp=fopen("password.dat","r");
fgets(original,30,fp);
fclose(fp);
if(strcmp(original,pass)!=0)
	{
	   gotoxy(4,5);
	   textcolor(WHITE);
	  cprintf("incorrect password\npress any key....");
	  getch();
	  exit(0);
	}

	else
	{
	window(1,1,80,25);
	textbackground(11);
	clrscr();
	gotoxy(30,2);
	textcolor(RED);
	cprintf("CONTACT MANAGER");
	gotoxy(30,3);
	textcolor(BLACK);
	cprintf("***************");
	gotoxy(31,5);
	textcolor(YELLOW);
	cprintf("version:1.0");
	gotoxy(20,8);
	textcolor(RED+BLACK);
	cprintf("Developed by : ");
	gotoxy(35,8);
	textcolor(BLUE);
	cprintf("GUGULOTH GANESH");
	gotoxy(5,15);
	textcolor(WHITE);
	cprintf("please wait");
	for(i=1;i<50;i++)
	{
	cprintf("%c",46);
	delay(100);

	}

  while(1)
	{
	window(1,1,80,25);
	textbackground(RED+YELLOW);
	clrscr();
	window(18,5,60,22);
	textbackground(BLACK);
	clrscr();
	gotoxy(18,2);
	textcolor(11);
	cprintf("MAIN MENU");
	gotoxy(18,3);
	textcolor(RED);
	cprintf("**********");
	textcolor(WHITE);
	gotoxy(14,5);
	cprintf("1.Add new contact ");
	gotoxy(14,6);
	cprintf("2.Delete contact");
	gotoxy(14,7);
	cprintf("3.Editing");
	gotoxy(14,8);
	cprintf("4.Search contact");
	gotoxy(14,9);
	cprintf("5.Iist of contact");
	gotoxy(14,10);
	cprintf("6.Change password");
	gotoxy(14,11);
	cprintf("7.Exit");
	gotoxy(11,12);
	cprintf("Enter your choice(1-7) : ");
	choice=getche();
	switch(choice)
	{
	case '1':
			add_contact();
			break;
	case '5':
			list_contact();
			break;
	case '2':
			delete_contact();
		   break;
	case '3':
			edit_contact();
			break;
	case '4':
		   search_contacts();
		   break;
	case '6':
		   change_password();
		   break;
	case '7':
		   exit(0);


	}
  }
 }
}
int getsno()
{
   FILE*fp;
   int n,size;
   fp=fopen("info.dat","rb");
   size=sizeof(cont);
   fseek(fp,-size,SEEK_END);
   fread(&cont,sizeof(cont),1,fp);
   n=cont.sno;
   fclose(fp);
   n++;
   return(n);
   }
   void add_contact()
   {     FILE*fp;
		window(1,1,80,25);
		textbackground(BLACK);
		clrscr();
		gotoxy(31,2);
		textcolor(WHITE);
		cprintf("Add new contact");
		gotoxy(31,3);
		cprintf("***************");
		cont.sno=getsno();
		printf("\n1.sno: %d",cont.sno);
		fflush(stdin);
		printf("\n2.category(frds,works): ");
		scanf("%s",&cont.category);
		fflush(stdin);
		printf("3.name: ");
		gets(cont.name);
		fflush(stdin);
		printf("4.gender: ");
		scanf("%s",&cont.gender);
		fflush(stdin);
		printf("5.age: ");
		scanf("%d",&cont.age);
		fflush(stdin);
		printf("6.address: ");
		gets(cont.address);
		fflush(stdin);
		printf("7.email: ");
		gets(cont.email);
		fflush(stdin);
		fp=fopen("info.dat","ab");
		fwrite(&cont,sizeof(cont),1,fp);
		fclose(fp);
		gotoxy(2,14);
		textcolor(RED+YELLOW);
		cprintf("successfully saved\npress any key.....");
		getch();
	}
	void list_contact()
	{  int i;
	   FILE*fp;
	   window(1,1,80,25);
	   textbackground(WHITE);
	   clrscr();
	   gotoxy(34,1);
	   textcolor(RED+BLUE);
	   cprintf(" List of contact ");
			 printf("\n");
	   for(i=1;i<=80;i++)
	   {
	   printf("-");
	   }
	   textcolor(BLUE);
	   gotoxy(1,3);
	   printf("SNO");
	   gotoxy(8,3);
	   printf("CATEGORY");
	   gotoxy(21,3);
	   printf("NAME");
	   gotoxy(35,3);
	   printf("GENDER");
	   gotoxy(45,3);
	   printf("AGE");
	   gotoxy(52,3);
	   printf("ADDRESS");
	   gotoxy(68,3);
	   printf("EMAIL");
	   printf("\n");
	   for(i=1;i<=80;i++)
	   printf("-");
fp=fopen("info.dat","rb");
	   i=5;
   while(fread(&cont,sizeof(cont),1,fp)!=NULL)
   {
		gotoxy(1,i);
	   cprintf("%d",cont.sno);
		gotoxy(8,i);
		printf("%s",cont.category);
		gotoxy(21,i);
		printf("%s",cont.name);
		gotoxy(35,i);
		printf("%s",cont.gender);
		gotoxy(45,i);
		printf("%d",cont.age);
		gotoxy(52,i);
		printf("%s",cont.address);
		gotoxy(68,i);
		printf("%s",cont.email);
		i++;
		 }
		fclose(fp);
	   getch();
	}
void delete_contact()
{   int i,n,found=0;
	FILE*fp1;
	FILE*fp2;
	window(1,1,80,25);
	textbackground(YELLOW+BLUE+RED);
	textcolor(BLACK);
	clrscr();
	gotoxy(31,1);
	cprintf("Delete contact");
	printf("\n");
	for(i=1;i<=80;i++)
	{
	printf("*");
	}
   printf("\nenter your sno : ");
   scanf("%d",&n);
   fp1=fopen("info.dat","rb");
   found=0;
   while(fread(&cont,sizeof(cont),1,fp1)!=0)
	   {
		   if(cont.sno==n)
		   {
		  printf("\ncategory : %s",cont.category);
		  printf("\nname     : %s",cont.name);
		  printf("\ngender   : %s",cont.gender);
		  printf("\nage      : %d",cont.age);
		  printf("\nAddress  : %s",cont.address);
		  printf("\nemail id : %s",cont.email);
		  found=1;
		  break;
		  }
		  }
   if(found==0)
   {
	printf("not there in file,please enter vailed sno ");
	fclose(fp1);
	return;
	}
	rewind(fp1);
	fp2=fopen("temp.dat","wb");
	while(fread(&cont,sizeof(cont),1,fp1)!=0)
	{
	 if(cont.sno!=n)
	 {
	  fwrite(&cont,sizeof(cont),1,fp2);
	  }
	 }
	 remove("info.dat");
	 rename("temp.dat","info.dat");
	 fclose(fp1);
	 fclose(fp2);
getch();
}
void edit_contact()
		{
		int n,pass,found;
		FILE*fp1;
		window(1,1,80,25);
		textbackground(YELLOW);
		textcolor(BLACK);
		clrscr();
		printf("Edit contact\n");
		printf("--------------------------------------------------------");
		printf("\n\nenter the sno to edited");
		scanf("%d",&n);
		fp1=fopen("info.dat","r+b");
		found=0;
  while(fread(&cont,sizeof(cont),1,fp1)!=NULL);
  {
	  if(cont.sno==n)
		{
			printf("\nCategory  : %s",cont.category);
			printf("\nName      : %s",cont.name);
			printf("\nGender    : %s",cont.gender);
			printf("\nAddress   : %s",cont.address);
			printf("\nAge       : %d",cont.age);
			printf("\nEmail id  : %s",cont.email);
			found=1;

		}
  }
  printf("\n------------------------------------------------------");
	   if(found==0)
	   {
	   printf("\n");
	   textcolor(RED+BLINK);
	   cprintf("Not found \n press any key to go home page");
	   fclose(fp1);
	   getch();
	   return;
	   }

	   printf("\n\nEnter New Data\n:");
	   pass=ftell(fp1);
	   fseek(fp1,pass-sizeof(cont),SEEK_SET);

		fflush(stdin);
		printf("2.category(frds,works): ");
		scanf("%s",&cont.category);
		fflush(stdin);
		printf("3.name: ");
		gets(cont.name);
		fflush(stdin);
		printf("4.gender: ");
		scanf("%s",&cont.gender);
		fflush(stdin);
		printf("5.age: ");
		scanf("%d",&cont.age);
		fflush(stdin);
		printf("6.address: ");
		gets(cont.address);
		fflush(stdin);
		printf("7.email: ");
		gets(cont.email);
		fflush(stdin);
		fwrite(&cont,sizeof(cont),1,fp1);
		fclose(fp1);
		printf("\n");
		textcolor(RED+BLINK);
		cprintf("successfully updated\npress any key to go back home page");
		getch();
	}
void search_contacts()
{  char ch;
   window(1,1,80,25);
   textbackground(1);
   textcolor(11);
   clrscr();
   textcolor(5);
   cprintf("SEARCH OPTIONS");
   printf("\n");
   printf("-------------------------------------------------");
   printf("\n1 search by serial no ");
   printf("\n2 search by category ");
   printf("\n3 search by name");
   printf("\n4 Back to back menu");
   printf("\n--------------------------------------------------");
   textcolor(YELLOW+BLINK);
   printf("\n");
   cprintf("Enter your choice ? ");
   ch=getche();
   switch(ch)
   {
	 case '1':
			  search_sno();
			  break;
	 case '2':
		   search_category();
		 break;
	case '3':
		search_name();
		break;
	case '4':
		   return;
	}
	getch() ;
}
 void change_password()
 {
   FILE*fp;
   char current[30],original[30],newpass[30],confirm[30];
   window(1,1,80,25);
   textcolor(BLUE);
   clrscr();
   printf("Change password");
   printf("\n-----------------------------------------------");
   printf("\nEnter the current password : ");
   gets(current);
   fp=fopen("password.dat","r");
   fgets(original,30,fp);
   fclose(fp);
   if(strcmp(current,original)!=0)
   {
	  printf("\nIncorrect password,press any key");
	  getch();
	  return;
	}
	printf("\nEnter new password : ");
	gets(newpass);
	printf("\nRe-Enter password : ");
	gets(confirm);
	if(strcmp(confirm,newpass)!=0)
	{
		  printf("\nNot match,press any key");
		  getch();
		  return;
	 }
	 fp=fopen("password.dat","w");
	 fprintf(fp,"%s",newpass);
	 fclose(fp);
	 printf("\nsuccesfull saved the password" );
	 getch();
}
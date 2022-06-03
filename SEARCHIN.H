void search_sno()
{
	FILE *fp;
	int found,n;
	textcolor(YELLOW);
	clrscr();
	printf("Enter the serial no : ");
	scanf("%d",&n);
	fp=fopen("info.dat","r");
	found=0;
	while(fread(&cont,sizeof(cont),1,fp)!=NULL)
	{
		 if(cont.sno==n)
		 {
			 printf("\nCategory   : %s",cont.category);
			 printf("\nName       : %s",cont.name);
			 printf("\nGender     : %s",cont.gender);
			 printf("\nAge        : %d",cont.age);
			 printf("\nAddress    : %s",cont.address);
			 printf("\nEmail      : %s",cont.email);
			 found=1;
			 break;
		 }
	}
	if(found==0)
	{
	  printf("not found");
	  fclose(fp);
	  getch();
	  return;
	}
	fclose(fp);
	getch();
}
  void search_category()
	{  int i;
	   char cat[20];
	   FILE*fp;
	   window(1,1,80,25);
	   textbackground(WHITE);
	   clrscr();
	   printf("enter category  : ");
	   gets(cat);
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
   {  if(strcmpi(cat,cont.category)==0)
	   {
		gotoxy(1,i);
	   cprintf("%d",cont.sno);
		fflush(stdin);
		gotoxy(8,i);
		printf("%s",cont.category);
		fflush(stdin);
		gotoxy(21,i);
		printf("%s",cont.name);
		fflush(stdin);
		gotoxy(35,i);
		printf("%s",cont.gender);
		fflush(stdin);
		gotoxy(45,i);
		printf("%d",cont.age);
		fflush(stdin);
		gotoxy(52,i);
		printf("%s",cont.address);
		fflush(stdin);
		gotoxy(68,i);
		printf("%s",cont.email);
		fflush(stdin);
		i++;
	  }
   }
	printf("\npress any key");
		fclose(fp);
	   getch();
	}
  void search_name()
	{  int i;
	   char na[20];
	   FILE*fp;
	   window(1,1,80,25);
	   textbackground(WHITE);
	   clrscr();
	   printf("enter name  : ");
	   gets(na);
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
   {  if(strcmpi(na,cont.name)==0)
	   {
		gotoxy(1,i);
	   cprintf("%d",cont.sno);
		fflush(stdin);
		gotoxy(8,i);
		printf("%s",cont.category);
		fflush(stdin);
		gotoxy(21,i);
		printf("%s",cont.name);
		fflush(stdin);
		gotoxy(35,i);
		printf("%s",cont.gender);
		fflush(stdin);
		gotoxy(45,i);
		printf("%d",cont.age);
		fflush(stdin);
		gotoxy(52,i);
		printf("%s",cont.address);
		fflush(stdin);
		gotoxy(68,i);
		printf("%s",cont.email);
		fflush(stdin);
		i++;
	  }
   }
	printf("\npress any key");
		fclose(fp);
	   getch();
	}



#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
void password();
void gotoxy(int x,int y)
{
 	 COORD CRD;     //set the coordinates of x and y
	 CRD.X=x;
	 CRD.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CRD); //setting the position of cursor
}

void heading();
void mainmenu();
void addbook();
void viewbook();
void searchbook();
void deletebook();
void addmembr();
void viewmembr();
void help();
void exit();


struct book{
  int id;
  int quantity;
  char name[10];
  char writer[10];
  int rack;


};
struct book b;

struct member{
  int mid;
  char mname[25] ;
  int phno[20];
  char a[20];
};
struct member r;
FILE *file, *file2, *nctrecord;

int d=1;
int main()
{
    password();
}
  void mainmenu(){
  system("cls");
  int n;
  printf("\n\n\t\t~~~~~~~~~~~~~ Main menu ~~~~~~~~~~~~~\n\n\n\t\t 1.Add book\n\t\t 2.View book\n\t\t 3.Delete book\n\t\t 4.Search book\n\t\t 5.Add member\n\t\t 6.View member record\n\t\t 7.Help\n\t\t 8.Exit\n\n\n\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  printf("Enter your choice\n");
   scanf("%d",&n);
   if(n == 1){
    addbook();
   }
   else if(n == 2){

    viewbook();
   }
      else if(n == 3){
    deletebook();
   }
   else if(n == 4){
    searchbook();

   }
    else if(n == 5){
    addmembr();
   }
    else if(n == 6){
    viewmembr();
   }
    else if(n == 7){
    help();
   }
     else if(n == 8){
       exit(1);
   }
    else
        {
    printf("choice is wrong \n\t try again");
    fflush(stdin);
    getchar();
    mainmenu();
    }
  }

void addbook(){

  system("cls");
  char d[10],count=0;
  printf("\n\n\t\t~~~~~~~~~~~~Add book~~~~~~~~~~~\n\n");
  file = fopen("nct.txt","a+");
  printf("\t\tEnter name: ");

    scanf("%s",d);

while(fscanf(file,"%s  %d   %s   %d   \n",b.name,&b.id,b.writer,&b.quantity)!=EOF){
    if(strcmp(b.name,d) == 0){
        printf("\n\n\t This book is already in the collection");
        count=1;
    }
  }
  if(count == 1){
    fflush(stdin);
    getchar();
    mainmenu();
  }

 strcpy(b.name,d);
  printf("\n\n\t enter ID: ");

scanf("%d",&b.id);
printf("\n\n\t enter writer  name: ");

scanf("%s",b.writer);
printf("\n\n\t enter quantity: ");

scanf("%d",&b.quantity);
//printf("\n\n\t\t enter rack: ");
//fflush(stdin);
//scanf("%d",&b.rack);
fprintf(file,"%s  %d  %s   %d  \n",b.name,b.id,b.writer,b.quantity);

fclose(file);
printf("\n\n\t\t Book added successfully");
    fflush(stdin);
    getchar();
    mainmenu();


}
void viewbook(){

    int r=5;
    system("cls");
    char ch;
    printf("\n\n\t\t~~~~~~~~~~~~~~~~~~~~~View book list~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    printf("          Name\t     ID  \tWriter\tQuantity\n\n");
    file = fopen("nct.txt","r");
		while(fscanf(file,"%s  %d   %s   %d   \n",b.name,&b.id,b.writer,&b.quantity)!=EOF){
            gotoxy(10,r);
			printf("%s",b.name);
			gotoxy(22,r);
			printf("%d",b.id);
			gotoxy(32,r);
			printf("%s",b.writer);
			gotoxy(45,r);
			printf("%d",b.quantity);
            r++;


    }

    fclose(file);
    printf("\n\n\t\tpress enter\n");
    fflush(stdin);
     getchar();
   mainmenu();


}
void searchbook(){
    char d[10];
    int c=0;
   system("cls");
   printf("\n\n\t\t~~~~~~~~~~~~~~~~~~~~~~~Search book in the collection~~~~~~~~~~~~~~~~~~ \n");
   printf("\n\t\t Searching book...............\n");

   file = fopen("nct.txt","r");
   printf("\n\t\t Enter Name: ");
    scanf("%s",d);

while(fscanf(file,"%s  %d   %s   %d   \n",b.name,&b.id,b.writer,&b.quantity)!=EOF)
    {
       if(strcmpi(b.name,d) == 0){
        printf("\n\n\t\tBook is found in the collection\n");
        printf("\t\t Name: %s",b.name);
        printf("\n\t\t ID: %d",b.id);
        printf("\n\t\t writer: %s\n",b.writer);
        printf("\n\t\t quantity: %d",b.quantity);
        //printf("\t\t Rack: %d",b.rack);

        c =1;
       }

    }
     if(c == 0){
        printf("\n\n Not found......\n");
     }
   printf("\n\n\t\t press enter--------\n");
   fflush(stdin);
   getchar();
   mainmenu();

}
void deletebook(){


	char name[10];
	int found=0;
	system("cls");

	FILE *file, *file2;
	file2=fopen("edited.txt","w+");
	file=fopen("nct.txt","r");
	printf("\n\n\t\t\t************* Delete  Record *************\n");
	gotoxy(12,8);
	printf("\n Enter  Name  : ");
	fflush(stdin);
	gets(name);

while(fscanf(file,"%s %d %s %d ",b.name,&b.id,b.writer,&b.quantity)!=EOF)
	{
		if (strcmpi(b.name,name)!=0)

		fprintf(file2,"%s %d %s %d \n",b.name,b.id,b.writer,b.quantity);


			found=1;

	}
	if(found==0)
	{
		printf("\n\n\t\t\t Record not found....");
		 fflush(stdin);
		getchar();
		mainmenu();
	}
	else
	{
		fclose(file);
		fclose(file2);
		remove("nct.txt");
		rename("edited.txt","nct.txt");
		printf("\n\n\t\t\t Record deleted successfully :) ");
		 fflush(stdin);
		getchar();
		mainmenu();
	}



    printf("\n\n\t\tpress enter......\n");
    fflush(stdin);
    getchar();
    mainmenu();

}

 void addmembr(){

    nctrecord = fopen("nctm.txt","a+");
    printf("Enter The user id no of the Member :\n");
        scanf("%d",&r.mid);
    printf("Enter The Name of the Member :\n");
        scanf("%s",r.mname);
    printf("Enter The Gender of the member:\n");
        scanf("%s",r.a);
    fprintf(nctrecord,"\n%d\t%s\t%s\t",r.mid,r.mname,r.a);
    fclose(nctrecord);
    printf("\n Added  A New member Successfully...............\n");
    printf("\n%d\t%s\t%s\t",r.mid,r.mname,r.a);


    printf("\n\n\t\tpress enter\n");
    fflush(stdin);
    getchar();
    mainmenu();

}
void viewmembr(){
    system("cls");
    int r=5;
    char ch;
    printf("\n\n\t\t~~~~~~~~~~~~~~~~~~~~~View member list~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    printf("ID\t Name\tGender\n\n");
    nctrecord = fopen("nctm.txt","r");
  while(1){
        ch=fgetc(nctrecord);
        if(ch == EOF)
            break;
        printf("%c",ch);
    }






    fclose(nctrecord);
    printf("\n\n\t\tpress enter\n");
    fflush(stdin);
     getchar();
   mainmenu();


}
void help(){

   system("cls");
   printf("\n\n\t\t~~~~~~~~~~~~Help section~~~~~~~~~~\n\n");
   printf("\t\t 1. This is a library management project\n\n");
   printf("\n\t\t 2.password is :admin\n");
   printf("\n\t\t 3.book can be added\n");
   printf("\n\t\t 4.Check out all the features in the main function\n");
   printf("\n\t\t 5.Use any of them if needed\n");
   printf("\n\t\t 6.press enter to go back to main function\n");
   printf("\n\t\t ............\n");

 printf("press enter....\n");
 fflush(stdin);
 getchar();
 mainmenu();


}


void heading(){
system("cls");
printf("\n\n\t\t ************** Library management project***********\n");

}

void password(){

   heading();

    char pwd1[10]={"admin"};
    char pwd2[10];
    printf("\n\t\tEnter password:");
    scanf("%s",pwd2);

    if(strcmp(pwd1,pwd2) == 0)
    {
        printf("\n\n\t\t Matched..\n");
        printf("\n\t\t press enter....");
    }

    else{


       printf("\n\n \t\t wrong password\n");
        printf("\n\n \t\t Try again");

        fflush(stdin);
        getchar();

        password();

    }

    mainmenu();
}



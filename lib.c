#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dateModule.c"
#include "userModule.c"
#define N 5000
#define E "€"
#define F fflush(stdin);

static struct libman
{
    char bname[151];
    char aname[51];
    char pname[101];
    char genre[51];
    float amt;
    int noca;
    int UID;
}no[N];

static int pos=-1;

void addBook()
{
    if(pos==N-1)
    {
        printf("Stack Overflow !!!!");
        return;
    }
    pos++;
    int n=0;
    printf("You are entering  %d th book ",pos);
    printf("Enter the genre of the book");
    gets(no[pos].genre);
    F
    printf("Enter the UID of the book");
    scanf("%d",&no[pos].UID);
    puts("Enter the book name : ");
    gets(no[pos].bname);
    F
    puts("Enter the author name : ");
    gets(no[pos].aname);
    F
    puts("Enter the publisher name :");
    gets(no[pos].pname);
    F
    do
    {
        puts("Enter the price of the book : ");
        scanf("%f",&no[pos].amt);
        if(no[pos].amt>0)
            break;
    }
    while(1);
    do
    {
        printf("Enter no. of copies : ");
        scanf("%d",&n);
        if(n>0)
            break;
    }
    while(1);
    no[pos].noca+=n;
}

void remBook()
{
    int rUID;
    printf("Enter the UID of the book , which you want to remove : ");
    scanf("%d",&rUID);
    register int i;int f=0;
    for(i=0;i<=pos;i++)
        if(rUID==no[pos].UID)
        {
            f=1;
            break;
        }
   int ctr=0;
   do
   {
   printf("Enter no. of copies you want to remove : ");
   scanf("%d",&ctr);
   if(ctr>no[i].noca)
      puts("\nSorry ! The no. of books isn't available ");
   else if (ctr<0)
        puts("\nPlease enter a positive number :");
   else
        break;
    }
   while(1);
   no[i].noca-=ctr;
}

void dispAllBooksDetails()
{
    int i;
    puts("\nThe details of all the books are :\t\n");
    for(i=0;i<pos;i++)
    {
        printf("\nUID:- %d",no[i].UID);
        printf("\nGenre of the book : ");
        puts(no[i].genre);
        printf("\nBook name :- ");
        puts(no[i].bname);
        printf("\nAuthor's Name :- ");
        puts(no[i].aname);
        printf("\nPublisher's Name :- ");
        puts(no[i].pname);
        printf("\nNo. of copies available :- %d ",no[i].noca);
        printf("\nPrice of the book :- %f",no[i].amt);
    }
}

void BorrowerReturn()
{
       int f=calculate();
    printf("Dear User , you have to pay a charge  of € 1.0 per each day");
    printf("\nTherefore ,you have to pay €%2.f",f*1.0 );
}
/*int main()
{
    BorrowerReturn();
}*/

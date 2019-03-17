#include"lib_sub_1.c"
int d1,d2,m1,m2,y1,y2;
void getData()
{
    printf("Issued Date : ");
    do
    {
        printf("\nEnter Day No:- ");
        scanf("%d",&d1);
        printf("\nEnter Month No :- ");
        scanf("%d",&m1);
        printf("\nEnter Year No :- ");
        scanf("%d",&y1);
        if(valiDate(d1,m1,y1)==1)
            break;
    }
    while(1);
    printf("Current Date : ");
    do
    {
        printf("\nEnter Day No:- ");
        scanf("%d",&d2);
        printf("\nEnter Month No :- ");
        scanf("%d",&m2);
        printf("\nEnter Year No :- ");
        scanf("%d",&y2);
        if(valiDateX(d2,m2,y2)==1)
            break;
    }
    while(1);
}

int valiDate(int d,int m,int y)
{
    if(m<1&&m>12)
        return 0;
   else if (m==1||m==3||m==5||m==7||m==8||m==10||m==12)
      {
          if(d<1&&d>31)
            return 0;
      }
    else if(m==4||m==6||m==9||m==11)
       {
           if(d<1&&d>30)
                return 0;
       }
   else if(m==2)
        if(y%400==0||y%4==0&&y%100!=0)
        {
            if(d<1&&d>29)
                    return 0;
        }
        else
            if(d<1&&d>28)
                    return 0;
   return 1;
}
int calculate()
{
    getData();
    int days=0;
    int nd[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    nd[2]=(y1%400==0||(y1%4==0&&y1%100!=0))?29:28;
    do
    {
        d1++;days++;
        if(d1>nd[m1])
        {
            d1=1;m1++;
        }
        if(m1>12)
        {
            d1=1;
            m1=1;
            y1++;
            nd[2]=(y1%400==0||(y1%4==0&&y1%100!=0))?29:28;
        }

        if((d1==d2)&&(m1==m2)&&(y1==y2))
            break;
    }
    while(1);
    return days;
}

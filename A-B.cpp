#include<stdio.h>
struct stu
{
    char gy[10];
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
    long long  sum;
}stu[2];
int main()
{
    scanf("%s%d%d%d%d%d%d",&stu[1].gy,&stu[1].year,&stu[1].month,&stu[1].day,&stu[1].hour,&stu[1].minute,&stu[1].second);
    scanf("%s%d%d%d%d%d%d",stu[2].gy,stu[2].year,stu[2].month,stu[2].day,stu[2].hour,stu[2].minute,stu[2].second);
    int i,flag,k;
    for(k=0;k<2;k++)
    {
        if (stu[k].gy=="BC")
        {
            for(i=1;i<stu[k].year;i++)
            {
            if(((0==i%4)&&(0!=i%100))||(0==i%400))
            {
                stu[k].sum+=366*24*3600;
            }
            else stu[k].sum+=365*24*3600;
            }
            if (((0==i%4)&&(0!=i%100))||(0==i%400))
            flag=1;
            else flag=0;
            for (i=1;i<stu[k].month;i++)
            {
                if((i==1)||(i==3)||(i==5)||(i==7)||(i==8)||(i==10)||(i==12))
                    stu[k].sum+=31*24*3600;
                else if((i==4)||(i==6)||(i==9)||(i==11))
                    stu[k].sum+=30*24*3600;
                    else if ((i==2)&&(flag==1))
                        stu[k].sum+=29*24*3600;
                        else stu[k].sum+=28*24*3600;
            }
            for (i=1;i<stu[k].day;i++)
                stu[k].sum+=24*3600;
            for (i=0;i<stu[k].hour;i++)
                stu[k].sum+=3600;
            for (i=1;i<stu[k].minute;i++)
                stu[k].sum+=60;
            stu[k].sum+=stu[k].second;
        }
        if(stu[k].gy=="AD")
        {
            for(i=1;i<stu[k].year;i++)
            {
            if(((0==i%4)&&(0!=i%100))||(0==i%400))
            {
                stu[k].sum+=366*24*3600;
            }
            else stu[k].sum+=365*24*3600;
            }
            if (((0==i%4)&&(0!=i%100))||(0==i%400))
            flag=1;
            else flag=0;
            for (i=(stu[k].month+1);i<13;i++)
            {
                if((i==1)||(i==3)||(i==5)||(i==7)||(i==8)||(i==10)||(i==12))
                    stu[k].sum+=31*24*3600;
                else if((i==4)||(i==6)||(i==9)||(i==11))
                    stu[k].sum+=30*24*3600;
                    else if ((i==2)&&(flag==1))
                        stu[k].sum+=29*24*3600;
                        else stu[k].sum+=28*24*3600;
            }
            if((stu[k].month==1)||(stu[k].month==3)||(stu[k].month==5)||(stu[k].month==7)||(stu[k].month==8)||(stu[k].month==10)||(stu[k].month==12))
            {
                for (i=(stu[k].day+1);i<32;i++)     /* 30/31/28/29*/
                    stu[k].sum+=24*3600;
            }
            else if((stu[k].month==4)||(stu[k].month==6)||(stu[k].month==9)||(stu[k].month==11))
            {
                for (i=(stu[k].day+1);i<31;i++)     /* 30/31/28/29*/
                    stu[k].sum+=24*3600;
            }
                else if ((stu[k].month==2)&&(flag=1))
                    {
                        for (i=(stu[k].day+1);i<30;i++)     /* 30/31/28/29*/
                            stu[k].sum+=24*3600;
                    }
                    else {
                            for (i=(stu[k].day+1);i<29;i++)     /* 30/31/28/29*/
                                stu[k].sum+=24*3600;
                        }
            for (i=(stu[k].hour+1);i<25;i++)
                stu[k].sum+=3600;
            for (i=stu[k].minute;i<61;i++)
                stu[k].sum+=60;
            stu[k].sum+=(60-stu[k].second);
            stu[k].sum=stu[k].sum*(-1);
        }
    }
    long long  run;
    run=(stu[2].sum-stu[1].sum);
    printf("%d",run);
    return 0;
}

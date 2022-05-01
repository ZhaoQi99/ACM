#include<stdio.h>
int main()
{
    int t,flag,i;
    scanf("%d",&t);
    int right[2][2];
    int num[t][2][2];
    flag=0;
    for (i=0;i<t;i++)
    {
        scanf("%d%d%d%d",&right[0][0],&right[0][1],&right[1][0],&right[1][1]);
        scanf ("%d%d%d%d",&num[i][0][0],&num[i][0][1],&num[i][1][0],&num[i][1][1]);
        if((num[i][0][0]==right[0][0])&&(num[i][0][1]==right[0][1])&&(num[i][1][0]==right[1][0])&&(num[i][1][1]==right[1][1]))
            flag=1;
        else if((num[i][0][0]==right[1][0])&&(num[i][0][1]==right[0][0])&&(num[i][1][0]==right[1][1])&&(num[i][1][1]==right[0][1]))
                flag=1;
            else if(num[i][0][0]==right[1][1]&&num[i][0][1]==right[1][0]&&num[i][1][0]==right[0][1]&&num[i][1][1]==right[0][0])
                    flag=1;
                else if(num[i][0][0]==right[0][1]&&num[i][0][1]==right[1][1]&&num[i][1][0]==right[0][0]&&num[i][1][1]==right[1][0])
                        flag=1;
        if(flag==1)
            printf("Case #%d: POSSIBLE\n",i+1);
        else printf("Case #%d: IMPOSSIBLE\n",i+1);
        flag=0;
    }
    return 0;
}

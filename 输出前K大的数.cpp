#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 1000050
int a[N];//当数据过大时要放在函数外面防止栈溢出
int m;
void QuickSort(int low,int high){
        int k;
        k=a[low];
        int left=low;
        int right=high;
        if(left>right)
                return ;
        while(left!=right){
                while(a[right]<k&&left<right)
                        right--;
                if(left<right){
                        a[left]=a[right];
                        left++;
                }
                while(a[left]>k&&left<right)
                        left++;
                if(left<right){
                        a[right]=a[left];
                        right--;
                }
        }
        a[left]=k;
        if(m<=left+1) QuickSort(low,left-1);
        else {
                QuickSort(low,left-1);
                QuickSort(left+1,high);
        }
}
int main(){
        int i;
        int n;
        while(scanf("%d%",&n)!=EOF){
                for(i=0;i<n;i++)
                        scanf("%d",&a[i]);
                scanf("%d",&m);
                QuickSort(0,n-1);
                for(i=0;i<m;i++){
                        printf("%d\n",a[i]);
                }
                printf("\n");//每组数据输出一行
        }
        return 0;
}

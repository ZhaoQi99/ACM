//排序算法
#include<bits/stdc++.h>

using namespace std;

void swap(int &a,int &b)
{
    int temp=a;
    a=b;
    b=temp;
}

void print(int a[], int n) //输出
{
    for(int i = 1; i < n+1; i++)
        cout << a[i] << ",";
    cout << endl;
}

int maopao(int a[], int n) //冒泡排序
{
    for(int i = 1; i <= n - 1; i++)
    {
        for(int j = 1; j <= n-i; j++)
        {
            if(a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
        }
    }
    cout << "冒泡排序:";
    print(a, n);
    return 0;
}

int xuanze(int a[], int n) //选择排序
{
    int index;
    for(int i = 1; i <= n - 1; i++)
    {
        index = i;
        for(int j = i + 1; j <= n; j++)
        {
            if(a[j] < a[index])
                index = j;
        }
        swap(a[i], a[index]);
    }
    cout << "选择排序:";
    print(a, n);
    return 0;
}

int charu(int a[], int n) //插入排序
{
    int b[n];
    b[1] = a[1];
    for(int i = 2; i < n+1; i++)
    {
        int temp = a[i]; //记录要插入的数
        int j = 1;
        while(b[j] < a[i] && j < i) //按照从小到大排序
            j++;
        for(int k = i - 1; k >= j; k--)
        {
            b[k + 1] = b[k];
        }
        b[j] = temp;
    }
    cout << "插入排序:";
    print(b, n);
}
int  partition(int* a, int p, int r)//划分
{
    int x = a[r];
    int i = p ;
    for(int j = p; j < r; j++)
    {
        if(a[j] <= x)
        {
            swap(a[i], a[j]);
            i++;
        }
    }
    swap(a[i], a[r]);
    return i ;
}

int quicksort(int *a, int p, int r) //快速排序
{
    int q;
    if(p < r)
    {
        q = partition(a, p, r);
        quicksort(a, p, q - 1);
        quicksort(a, q + 1, r);
    }
    return 0;
}

int jishu(int a[], int n) //计数排序
{
    int b[n];
    for(int i = 1; i < n+1; i++)
    {
        int count = 1;
        for(int j = 1; j < n+1; j++)
        {
            if(a[j] < a[i])
                count++;
        }
        b[count] = a[i];
    }
    cout << "计数排序:";
    print(b, 10);
}

void MinAndMax(int a[], int n) //最大值,最小值
{
    int max = a[1], min = a[1];
    for(int i = 2; i < n+1; i += 2)
    {
        if(a[i] > a[i + 1])
        {
            if(a[i] > max)
                max = a[i];
            if(a[i + 1] < min)
                min = a[i];
        }
        else
        {
            if(a[i + 1] > max)
                max = a[i];
            if(a[i] < min)
                min = a[i];
        }
    }
    cout << "最小值:" << min << ";" << "最大值:" << max << endl;
}

void adj(int *a, int i, int len) //调整堆
{
    int temp = i;
    if(a[i]<a[i * 2] && (i*2) <= len)
    {
        temp=i*2;
    }
    if(a[temp]<a[i*2+1] && (i*2+1) <= len)
    {
        temp=i*2+1;
    }
    if(temp != i)
    {
        swap(a[i], a[temp]);
        adj(a, temp, len);
    }
}
void bulid(int *a, int n) //建堆
{
    for(int i = n / 2; i >= 1; i--)
        adj(a, i, n);
}
int heapsort(int *a, int n)//堆排序
{
    bulid(a, n);
    for(int i = n; i >= 2; i--)
    {
        swap(a[i], a[1]);
        n--;
        adj(a, 1, n);
    }
}

int  partition2(int *a, int p, int r)//加入随机化
{
    int t=rand()%(r-p)+p;
    swap(a[t],a[r]);
    int x = a[r];
    int i = p - 1;
    for(int j = p; j < r; j++)
    {
        if(a[r] <= x)
        {
            ++i;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[r]);
    return i + 1;
}
int SearchDikxiao(int *a, int p, int r, int k)//查询第K小的数
{
    int q=partition(a,p,r);
    if(q==k)
        return a[q];
    else
    {
        if(k<q)
            return SearchDikxiao(a,p,q-1,k);
        else
            return SearchDikxiao(a,q+1,r,k);
    }
}
int main( )
{
    int test[] = { 0, 1, 15, 18, 77, 2, 5, 9, 150, 44, 100};
    print(test, 10);
//    maopao(test,10);
    xuanze(test,10);
    charu(test,10);
    jishu(test,10);
    MinAndMax(test,10);
    cout<<"the kth number is: "<<SearchDikxiao(test,1,10,4)<<endl;
    quicksort(test,1,10);
    cout<<"快速排序:";
    heapsort(test, 10);
    print(test, 10);
    return 0;
}

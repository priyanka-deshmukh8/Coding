#include<stdio.h>
 
#include<stdbool.h>
 
int bubbleSort(int *arr,int len)
 
{
 
    int count=0;
 
    int swap=1,i=0;
 
    while(swap!=0)
 
    {   
 
        swap=0;
 
        count++;
 
        for(int j=0;j<len-1-i;j++)
 
        {
 
            if(arr[j]>arr[j+1])
 
            {
 
                int t=arr[j];
 
                arr[j]=arr[j+1];
 
                arr[j+1]=t;
 
                swap=1;
 
            }
 
        }
 
                i++;
 
    }
 
    return count;
 
}
 
int main()
 
{
 
    int num;
 
    scanf("%d",&num);
 
    int arr[5000];
 
    for(int i=0;i<num;i++)
 
    {
 
        scanf("%d",&arr[i]);
 
    }
 
    printf("%d",bubbleSort(arr,num));
 
}
 
#include<iostream>
using namespace std; 

void Left_Rotate_Once(int arr[],int size)
{
    int temp=arr[0];
    for(int i=0;i<size;i++)
    {
        arr[i]=arr[i+1];
    }
    arr[size-1]=temp;
}

int main()
{
    int size;
    cin>>size;
    int arr[size];
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    Left_Rotate_Once(arr,size);
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
}
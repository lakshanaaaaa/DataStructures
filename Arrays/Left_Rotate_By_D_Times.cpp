#include<iostream>
using namespace std;
void reverse(int arr[],int lo,int hi)
{
    while(lo<hi)
    {
        swap(arr[lo],arr[hi]);
        lo++;
        hi--;
    }
}
int main()
{
    int size;
    int D;
    cin>>size>>D;
    int arr[size];
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    if(D>=size)
    {
        D%=size;
    }
    if(D!=0)
    {
        reverse(arr,0,D-1);
        reverse(arr,D,size-1);
        reverse(arr,0,size-1);
    }
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
}
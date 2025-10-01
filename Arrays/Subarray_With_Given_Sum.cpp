#include<iostream>
using namespace std;

bool Subarray_With_Given_Sum(int arr[],int size, int target)
{
    int lo=0;
    int sum=0;
    for(int i=0;i<size;i++)
    {
        sum+=arr[i];
        while(sum>target)
        {
            sum-=arr[lo];
            lo++;
        }
        if(sum==target)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    int size,target;
    cin>>size>>target;
    int arr[size];
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    cout<<((Subarray_With_Given_Sum(arr,size,target))?"YES":"NO");
}
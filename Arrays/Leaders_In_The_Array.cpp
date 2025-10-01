#include<iostream>
#include<vector>
using namespace std;

void Brute_Force(int arr[],int size)
{
    bool flag=true;
    for(int i=0;i<size;i++)
    {
        flag=true;
        for(int j=i+1;j<size;j++)
        {
            if(arr[i]<=arr[j])
            {
                flag=false;
                break;
            }
        }
        if(flag)
        {
            cout<<arr[i]<<" ";
        }
    }
}

void Optimised(int arr[],int size)
{
    vector<int> result;
    result.push_back(arr[size-1]);
    int current_Max=arr[size-1];
    for(int i=size-2;i>=0;i--)
    {
        if(arr[i]>current_Max)
        {
            current_Max=arr[i];
            result.push_back(arr[i]);
        }
    }
    for(int i=result.size()-1;i>=0;i--)
    {
        cout<<result[i]<<" ";
    }
}


int main()
{
    int size;
    cin>>size;
    int arr[size];
    for(int i=0;i<size;i++)cin>>arr[i];
    //Brute_Force(arr,size);
    Optimised(arr,size);

}
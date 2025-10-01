#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int Brute_Force(int arr[],int size)
{
    int res=0;
    for(int i=0;i<size;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            res=max(res,arr[j]-arr[i]); 
        }
    }
    return res<=0?-1:res;
}


int Better_Solution(int arr[],int size)
{
    int mini=arr[0];
    int res=arr[1]-arr[0];
    for(int i=1;i<size;i++)
    {
        res=max(res,arr[i]-mini);
        mini=min(arr[i],mini);
    }
    return res<=0?-1:res;
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
    cout<<Brute_Force(arr,size);
}
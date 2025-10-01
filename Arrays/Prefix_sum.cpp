#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void prefix_sum(int arr[],int n)
{
    vector<int> prefix_sum(n);
    prefix_sum[0]=arr[0];
    for(int i=1;i<n;i++)
    {
        prefix_sum[i]=prefix_sum[i-1]+arr[i];
    }

    for(int value : prefix_sum)
    {
        cout<<value<<" ";
    }
}


int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    prefix_sum(arr,n);
}

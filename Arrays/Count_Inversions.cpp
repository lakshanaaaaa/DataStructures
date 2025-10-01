#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int countInversions(vector<int>& arr,int lo,int mid,int hi)
{
    vector<int> ans;
    int cnt=0;
    int left=lo;
    int right=mid+1;
    while(left<=mid && right<=hi)
    {
        if(arr[left]<=arr[right])
        {
            ans.push_back(arr[left]);
            left++;
        }   
        else{
            ans.push_back(arr[right]);
            right++;
            cnt+=(mid-left+1);
        }
    }
    while(left<=mid)
    {
        ans.push_back(arr[left]);
        left++;
    }
    while(right<=hi)
    {
        ans.push_back(arr[right]);
        right++;
    }
    for(int i=lo;i<=hi;i++)
    {
        arr[i]=ans[i-lo];
    }
    return cnt;
}

int merge_sort(vector<int> &arr,int lo,int hi)
{
    if(lo<hi)
    {
        int cnt=0;
        int mid=lo+(hi-lo)/2;
        cnt+=merge_sort(arr,lo,mid);
        cnt+=merge_sort(arr,mid+1,hi);
        cnt+=countInversions(arr,lo,mid,hi);
        return cnt;
    }
    return 0;
}
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    cout<<merge_sort(arr,0,n-1);
}
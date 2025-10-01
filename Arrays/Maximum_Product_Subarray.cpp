#include<iostream>
#include<bits/stdc++.h>
using namespace std;

long long maximum_product(vector<int> arr)
{
    int size=arr.size();
    long long maxi=INT_MIN;
    long long prefix=1;
    long long suffix=1;
    for(int i=0;i<size;i++)
    {
        if(prefix==0)prefix=1;
        if(suffix==0)suffix=1;
        prefix*=arr[i];
        suffix*=arr[size-1-i];
        maxi=max(maxi,max(prefix,suffix));
    }
    return maxi;
}


long long Method_2(vector<int> arr)
{
    int maxi=arr[0];
    int mini=arr[0];
    int res=INT_MIN;
    for(int i=1;i<arr.size();i++)
    {
        int temp=max({arr[i],arr[i]*maxi,arr[i]*mini});
        mini=min({arr[i],arr[i]*maxi,arr[i]*mini});
        maxi=temp;
        res=max(res,maxi);
    }
    return res;
}


int main()
{
    int size;
    cin>>size;
    vector<int> v(size);
    for(int i=0;i<size;i++)cin>>v[i];
    cout<<maximum_product(v);
}
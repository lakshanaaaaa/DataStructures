#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void Next_Permutation(vector<int>&vec)
{
    int index=-1;
    for(int i=vec.size()-2;i>=0;i--)
    {
        if(vec[i]<vec[i+1])
        {
            index=i;
            break;
        }
    }
    if(index==-1)
    {
        reverse(vec.begin(),vec.end());
    }
    else
    {
        for(int i=vec.size()-1;i>=0;i--)
        {
            if(vec[i]>vec[index])
            {
                swap(vec[i],vec[index]);
                break;
            }
        }
        reverse(vec.begin()+index+1,vec.end());
    }
}
int main()
{
    int size;
    cin>>size;
    vector<int> vec(size);
    for(int i=0;i<size;i++)cin>>vec[i];
    Next_Permutation(vec);
    for(auto value : vec)
    {
        cout<<value<<" ";
    }
}
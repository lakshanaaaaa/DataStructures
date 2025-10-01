#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,zero_cnt=0;
    cin>>n;
    vector<int> Dynammic_Siz_arr(n);
    for(int i=0;i<n;i++)cin>>Dynammic_Siz_arr[i];

    for(int i=0;i<n;i++)
    {
        if(Dynammic_Siz_arr[i]!=0)
        {
            if(Dynammic_Siz_arr[i]==Dynammic_Siz_arr[zero_cnt])
            {
                zero_cnt++;
            }
            else
            {
                swap(Dynammic_Siz_arr[i],Dynammic_Siz_arr[zero_cnt]);
                zero_cnt++;
            }
        }
    }

    for(int i: Dynammic_Siz_arr)
    {
        cout<<i<<" ";
    }
}
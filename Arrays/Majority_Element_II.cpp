#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int> &arr)
{
    int vote1 = 0;
    int vote2 = 0;
    int cd1 = INT_MIN;
    int cd2 = INT_MIN;
    vector<int> res;
    for (int i = 0; i < arr.size(); i++)
    {
        if (vote1 == 0 && cd2 != arr[i])
        {
            vote1 = 1;
            cd1 = arr[i];
        }
        else if (vote2 == 0 && cd1 != arr[i])
        {
            vote2 = 1;
            cd2 = arr[i];
        }
        else if (cd1 == arr[i])
        {
            vote1++;
        }
        else if (cd2 == arr[i])
        {
            vote2++;
        }
        else
        {
            vote1--;
            vote2--;
        }
    }
    int cnt1 = 0;
    int cnt2 = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (cd1 == arr[i])
            cnt1++;
        if (cd2 == arr[i])
            cnt2++;
    }
    int min = (int)(arr.size() / 3) + 1;
    if (cnt1 >= min)
        res.push_back(cd1);
    if (cnt2 >= min)
        res.push_back(cd2);
    return res;
}
int main()
{
    int size;
    cin>>size;
    vector<int>res(size);
    for(int i=0;i<size;i++)cin>>res[i];
    vector<int>ans(majorityElement(res));
    for(auto i:ans)
    {
        cout<<i<<" ";
    }
}
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> Three_sum(vector<int> arr)
{
    sort(arr.begin(), arr.end());
    vector<vector<int>> res;
    int size = arr.size();
    for (int i = 0; i < size; i++)
    {
        if(i!=0 && arr[i]==arr[i-1])continue;
        int lo = i + 1;
        int hi = size - 1;
        while (lo < hi)
        {
            long long sum = arr[i] + arr[hi] + arr[lo];
            if (sum > 0)
            {
                hi--;
            }
            else if (sum < 0)
            {
                lo++;
            }
            else
            {
                res.push_back({arr[i], arr[lo], arr[hi]});
                lo++;
                hi--;
                while (lo < hi && arr[lo] == arr[lo - 1])
                    lo++;
                while (lo < hi && arr[hi] == arr[hi + 1])
                    hi--;
            }
        }
    }
    return res;
}


vector<vector<int>> Three_sum_method_2(vector<int> arr)
{
    int size=arr.size();
    set<vector<int>>st;
    for(int i=0;i<size;i++)
    {
        set<int>hashset;
        for(int j=i+1;j<size;j++)
        {
            int third=-(arr[i]+arr[j]);
            if(hashset.find(third)!=hashset.end())
            {
                vector<int>temp={arr[i],arr[j],third};
                sort(temp.begin(),temp.end());
                st.insert(temp);
            }
            hashset.insert(arr[j]);
        }
    }
    vector<vector<int>> ans(st.begin(),st.end());
    return ans;
}


int main()
{
    int size;
    cin >> size;
    vector<int> v(size);
    for (int i = 0; i < size; i++)
    {
        cin >> v[i];
    }
    vector<vector<int>> res=Three_sum_method_2(v);
    for(auto it:res)
    {
        for(auto re : it)
        {
            cout<<re<<" ";
        }
        cout<<'\n';
    }
}
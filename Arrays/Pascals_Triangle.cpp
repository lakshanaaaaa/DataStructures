#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int  find_pascal_triangle_value(int row,int col)
{
    int res=1;
    for(int i=0;i<col;i++)
    {
        res*=(row-i);
        res=res/(i+1);
    }
    return res;
}

vector<int> Pascal_Row(int row)
{
    vector<int> ans;
    long long value=1;
    ans.push_back(1);
    for(int i=1;i<row;i++)
    {
        value*=row-i;
        value/=i;
        ans.push_back(value);
    }
    return ans;
}
int main()
{
    // int row,col;
    // cin>>row>>col;
    // cout<<find_pascal_triangle_value(row-1,col-1)<<"\n";

    int row;
    cin>>row;
    vector<vector<int>> res;
    for(int i=1;i<=row;i++)
    {
        res.push_back(Pascal_Row(i));
    }
    for(auto value: res)
    {
        for(auto line: value)
        {
            cout<<line<<" ";
        }
        cout<<"\n";
    }
}
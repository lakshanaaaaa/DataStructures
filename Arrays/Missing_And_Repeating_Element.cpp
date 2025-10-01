#include<iostream>
#include<vector>
using namespace std;

pair<int,int> find(vector<int> v)
{
    int n=v.size();
    long long sn=(n*(n+1))/2;
    long long sn2=(n*(n+1)*(2*n+1))/6;
    long long s=0;
    long long s2=0;
    for(int i=0;i<n;i++)
    {
        s+=v[i];
        s2+=(long long)v[i]*(long long)v[i];
    }
    long long sum=s-sn;
    long long sum2=(s2-sn2)/sum;
    long long x=(sum+sum2)/2;
    long long y=x-sum;
    return {x,y};
}
int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    pair<int,int>p=find(v);
    cout<<"Repeating Element is : "<<p.first<<endl;
    cout<<"Missing Element is : "<<p.second<<endl;
}
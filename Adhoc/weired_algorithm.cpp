#include<iostream>
#define int long long
using namespace std;
signed main(){
    int n;
    cin>>n;
    cout<<n<<" ";
    while(n>1)
    {
        if(n&1)n=n*3+1;
        else n=n/2;
        cout<<n<<" ";
    }
}
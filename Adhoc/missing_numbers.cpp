// #include<iostream>
// #include<algorithm>
// using namespace std;
// int main(){
//     int n;
//     cin>>n;
//     n--;
//     int arr[n];
//     for(int i=0;i<n;i++)
//         cin>>arr[i];
//     sort(arr,arr+n);
//     int currentNumber = 1;
//     for(int i=0;i<n;i++){
//         if(arr[i]==currentNumber)
//         {
//             currentNumber++;
//         }
//         else break;
//     }
//     cout<<currentNumber;
// }

#include<iostream>
#define int long long
using namespace std;
signed main(){
    int n;
    cin>>n;
    int totSum = n*(n+1)/2;
    int arrSum = 0;
    for(int i=0;i<n-1;i++){
        int x;
        cin>>x;
        arrSum += x;
    }
    cout<<totSum - arrSum;
    return 0;
}
#include <iostream>
using namespace std;
int main()
{
    int size;
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    int queries;
    cin >> queries;
    int diff_arr[size + 1]{};
    while (queries--)
    {
        int l, r, k;
        cin >> l >> r >> k;
        diff_arr[l] += k;
        diff_arr[r + 1] -= k;
    }
    for (int i = 1; i < size; i++)
    {
        diff_arr[i] += diff_arr[i - 1];
    }
    for (int i = 0; i < size; i++)
    {
        arr[i] += diff_arr[i];
    }
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}
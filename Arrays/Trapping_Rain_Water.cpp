#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int brute_force(int arr[], int size)
{
    int result = 0;
    for (int i = 1; i < size - 1; i++)
    {
        // maximum left bar
        int left_max = arr[i];
        for (int j = 0; j < i; j++)
        {
            left_max = max(left_max, arr[j]);
        }
        int right_max = arr[i];
        for (int k = i + 1; k < size; k++)
        {
            right_max = max(right_max, arr[k]);
        }
        result += (min(left_max, right_max) - arr[i]);
    }
    return result;
}

int Better_Solution(int arr[], int size)
{
    int result = 0;
    int left_max[size];
    int right_max[size];
    left_max[0] = arr[0];
    right_max[size-1] = arr[size-1];
    for (int i = 1; i < size; i++)
    {
        left_max[i] = max(arr[i],left_max[i-1]);
    }
    for (int i = size - 2; i >= 0; i--)
    {
        right_max[i] = max(arr[i],right_max[i+1]);
    }
    for (int i = 1; i < size - 1; i++)
    {
        result += min(left_max[i], right_max[i]) - arr[i];
    }
    return result;
}

int main()
{
    int size;
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++)
        cin >> arr[i];
    cout << Better_Solution(arr, size);
}
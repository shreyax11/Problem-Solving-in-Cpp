#include<iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter " << n-1 << " elements:\n";
    for (int i = 0; i < n-1; i++)
    {
        cin >> arr[i];
    }
    int total = n*(n+1)/2;
    int sum = 0;

    for(int i = 0; i < n-1; i++)
        sum += arr[i];

    cout << "Missing: " << total - sum;
    return 0;
}


#include <iostream>
using namespace std;

int main()
{
    int A[10], B[10], C[20];
    int m, n, i = 0, j = 0, k = 0;
    cout << "Enter size of first array: ";
    cin >> m;
    cout << "Enter elements of first sorted array:\n";
    for(i = 0; i < m; i++)
        cin >> A[i];
    cout << "Enter size of second array: ";
    cin >> n;
    cout << "Enter elements of second sorted array:\n";
    for(i = 0; i < n; i++)
        cin >> B[i];
    i = j = 0;
    // Merge two sorted arrays
    while(i < m && j < n)
    {
        if(A[i] < B[j])
            C[k++] = A[i++];
        else
            C[k++] = B[j++];
    }
    while(i < m)
        C[k++] = A[i++];
    while(j < n)
        C[k++] = B[j++];
    cout << "Merged array:\n";
    for(i = 0; i < k; i++)
        cout << C[i] << " ";
    return 0;
}

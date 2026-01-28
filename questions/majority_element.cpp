//An element is called a majority element 
//if it appears more than n/2 times in an array of size n.
#include <iostream>
using namespace std;
//visited array
//complexity O(n^2)
int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    bool visited[n] = {false};
    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 0; i < n; i++)
    {
        if(visited[i] == true)
            continue;
        int count = 1;
        for(int j = i + 1; j < n; j++)
        {
            if(arr[i] == arr[j])
            {
                visited[j] = true;
                count++;
            }
        }
        if(count > n / 2)
        {
            cout << "Majority Element: " << arr[i];
            return 0;
        }
    }
    cout << "No Majority Element";
    return 0;
}

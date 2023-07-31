#include <bits/stdc++.h>
using namespace std;

void merge(long long arr1[], long long arr2[], int n, int m) {

    // Declare 2 pointers:
    int left = n - 1; // Pointer for arr1, initialized to the last index of arr1
    int right = 0; // Pointer for arr2, initialized to the first index of arr2

    // Swap the elements until arr1[left] is
    // smaller than arr2[right]:
    while (left >= 0 && right < m) {
        if (arr1[left] > arr2[right]) {
            swap(arr1[left], arr2[right]); // Swap the elements of arr1 and arr2 if arr1[left] is greater than arr2[right]
            left--, right++; // Move the pointers to the next elements in arr1 and arr2
        }
        else {
            break; // If arr1[left] is not greater than arr2[right], break out of the loop
        }
    }

    // Sort arr1[] and arr2[] individually:
    sort(arr1, arr1 + n); // Sort the elements of arr1 in ascending order
    sort(arr2, arr2 + m); // Sort the elements of arr2 in ascending order
}

int main()
{
    long long arr1[] = {1, 4, 8, 10};
    long long arr2[] = {2, 3, 9};
    int n = 4, m = 3;
    merge(arr1, arr2, n, m);
    cout << "The merged arrays are: " << "\n";
    cout << "arr1[] = ";
    for (int i = 0; i < n; i++) {
        cout << arr1[i] << " ";
    }
    cout << "\narr2[] = ";
    for (int i = 0; i < m; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
    return 0;
}

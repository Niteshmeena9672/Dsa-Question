#include <bits/stdc++.h>
using namespace std;

// Function to find the majority element in a given vector 'v'.
int majorityElement(vector<int> v) {

    // Size of the given vector 'v':
    int n = v.size();

    // Variables to keep track of the count and the current element being considered:
    int cnt = 0; // Count of occurrences of the current element
    int el; // Element under consideration

    // Applying the algorithm to find the potential majority element:
    for (int i = 0; i < n; i++) {
        if (cnt == 0) {
            // If the count is 0, we reset the count to 1 and store the new element as the current element.
            cnt = 1;
            el = v[i];
        }
        else if (el == v[i]) {
            // If the current element is the same as the stored element, we increment the count.
            cnt++;
        }
        else {
            // If the current element is different from the stored element, we decrement the count.
            cnt--;
        }
    }

    // Checking if the stored element is the majority element:
    int cnt1 = 0; // Count the occurrences of the potential majority element.
    for (int i = 0; i < n; i++) {
        if (v[i] == el) {
            cnt1++;
        }
    }

    // If the count of the potential majority element is greater than (n / 2), it is the majority element.
    if (cnt1 > (n / 2)) {
        return el;
    }

    // If there is no majority element, return -1 (or any other appropriate default value).
    return -1;
}

int main() {
    vector<int> arr = {2, 2, 1, 1, 1, 2, 2};
    int ans = majorityElement(arr);
    cout << "The majority element is: " << ans << endl;
    return 0;
}


// Explanation:

// The majorityElement function takes a vector v as input and is expected to find the majority element (the element that appears more than n/2 times in the vector).

// The function uses the Boyer-Moore Voting Algorithm to efficiently find a potential majority element. The algorithm traverses the vector linearly and keeps track of a candidate majority element and its count.

// The first loop iterates through the vector 'v', and when the count is 0, it sets the current element as the candidate majority element (stored in the variable 'el') and resets the count to 1. If the current element is the same as the candidate majority element, it increments the count; otherwise, it decrements the count.

// After finding the potential majority element using the Boyer-Moore Voting Algorithm, the second loop counts the occurrences of the potential majority element in the vector 'v' (stored in 'cnt1').

// If the count of the potential majority element ('cnt1') is greater than (n / 2), it means that the potential majority element is the majority element, and it is returned.

// If there is no majority element, the function returns -1 (or any other appropriate default value).

// In the main function, a sample vector arr is created, and the majorityElement function is called to find the majority element in arr. The result is printed to the console. In this case, the output will be "The majority element is: 2", as the majority element in the vector is 2.





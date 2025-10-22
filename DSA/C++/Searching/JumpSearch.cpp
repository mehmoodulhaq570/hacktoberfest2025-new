#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

/*
    Jump Search Algorithm
    ---------------------
    Works on sorted arrays.
    Time Complexity: O(√n)
    Space Complexity: O(1)
*/

int jumpSearch(const vector<int>& arr, int target) {
    int n = arr.size();
    int step = sqrt(n);         // Optimal jump size
    int prev = 0;

    // Jump ahead while target is greater than last element in block
    while (arr[min(step, n) - 1] < target) {
        prev = step;
        step += sqrt(n);
        if (prev >= n)
            return -1;  // not found
    }

    // Linear search within the identified block
    while (arr[prev] < target) {
        prev++;
        if (prev == min(step, n))
            return -1;  // not found
    }

    // If element found
    if (arr[prev] == target)
        return prev;

    return -1;
}

// ------------------------------
// Main Function for Testing
// ------------------------------
int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 13, 17, 21, 25, 29, 33, 37};
    int target;

    cout << "Enter element to search: ";
    cin >> target;

    int index = jumpSearch(arr, target);

    if (index != -1)
        cout << "Element " << target << " found at index " << index << endl;
    else
        cout << "Element " << target << " not found in array." << endl;

    return 0;
}

/**
 * Binary Search Algorithm
 * 
 * Description: Efficiently searches for a target value in a sorted array
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 * 
 * Use Cases:
 * - Finding element in sorted array
 * - Lower/upper bound queries
 * - Search space optimization problems
 */

#include <iostream>
#include <vector>
using namespace std;

/**
 * Standard binary search - finds exact match
 * @param arr: sorted array to search in
 * @param target: value to find
 * @return: index of target if found, -1 otherwise
 */
int binarySearch(const vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2; // Avoid overflow
        
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return -1; // Not found
}

/**
 * Lower bound - finds first position where element >= target
 * @param arr: sorted array
 * @param target: target value
 * @return: index of first element >= target
 */
int lowerBound(const vector<int>& arr, int target) {
    int left = 0, right = arr.size();
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    
    return left;
}

/**
 * Upper bound - finds first position where element > target
 * @param arr: sorted array
 * @param target: target value
 * @return: index of first element > target
 */
int upperBound(const vector<int>& arr, int target) {
    int left = 0, right = arr.size();
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] <= target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    
    return left;
}

// Example usage and test cases
int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11, 13, 15};
    
    cout << "Array: ";
    for (int x : arr) cout << x << " ";
    cout << "\n\n";
    
    // Test binary search
    cout << "Binary Search Tests:\n";
    cout << "Search for 7: " << binarySearch(arr, 7) << " (expected: 3)\n";
    cout << "Search for 4: " << binarySearch(arr, 4) << " (expected: -1)\n";
    cout << "Search for 1: " << binarySearch(arr, 1) << " (expected: 0)\n";
    cout << "Search for 15: " << binarySearch(arr, 15) << " (expected: 7)\n\n";
    
    // Test bounds
    cout << "Bounds Tests:\n";
    cout << "Lower bound of 7: " << lowerBound(arr, 7) << " (expected: 3)\n";
    cout << "Lower bound of 6: " << lowerBound(arr, 6) << " (expected: 3)\n";
    cout << "Upper bound of 7: " << upperBound(arr, 7) << " (expected: 4)\n";
    cout << "Upper bound of 6: " << upperBound(arr, 6) << " (expected: 3)\n";
    
    return 0;
}
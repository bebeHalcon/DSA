#include<iostream>
#include<sstream>

using namespace std;
string minDiffPairs(int* arr, int n){
    // STUDENT ANSWER
    if (n < 2) {
        // No pairs can be formed
        return "";
    }
    // Step 1: Sort
    sort(arr, arr + n);

    int minDiff = 100000;
    stringstream ss; // StringStream to construct the result string
    bool firstPair = true; // Flag to manage comma placement

    // Step 2: Calculate minimum difference and construct pairs
    for (int i = 1; i < n; i++) {
        int diff = arr[i] - arr[i - 1]; // Calculate difference between consecutive elements
        if (diff < minDiff) {
            minDiff = diff; // Update minimum difference
            ss.str(""); // Clear the stringstream for new pairs
            ss.clear(); // Clear any flags
            ss << "(" << arr[i - 1] << ", " << arr[i] << ")"; // Add the new pair
            firstPair = false; // Reset flag since we have added a pair
        } else if (diff == minDiff) {
            if (!firstPair) {
                ss << ", "; // Add a comma if it's not the first pair
            }
            ss << "(" << arr[i - 1] << ", " << arr[i] << ")"; // Add the pair
        }
    }

    return ss.str(); // Return the string containing pairs

}
int main(){

    int arr[] = {10, 5, 7, 9, 15, 6, 11, 8, 12, 2};
    cout << minDiffPairs(arr, 10);

    // (5, 6), (6, 7), (7, 8), (8, 9), (9, 10), (10, 11), (11, 12)
}

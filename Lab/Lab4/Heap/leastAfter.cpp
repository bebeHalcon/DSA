#include <iostream>
#include <string>
#include <cstring>
#include <climits>
#include <utility>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <functional>
#include <algorithm>

using namespace std;

int leastAfter(vector<int>& nums, int k) {
    // STUDENT ANSWER
    priority_queue <int, vector<int>, greater<int> > minHeap (nums.begin(), nums.end());
    
    for (int i=0; i<k; i++)
    {
        int smallest = minHeap.top();
        minHeap.pop();
        minHeap.push(smallest*2);
    }
    return minHeap.top();
}

int main(){

    vector<int> nums ({2, 3, 5, 7});
    int k = 3;
    cout << leastAfter(nums, k);
}
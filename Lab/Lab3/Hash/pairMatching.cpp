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

int pairMatching(vector<int>& nums, int target) {
    unordered_map <int,int> mp;
    int res = 0;
    int n = nums.size();
    
    for (int i=0; i<n; i++) 
    {
        if (mp.count(target - nums[i]) && mp[target-nums[i]] > 0)
        {
            res++;
            mp[target - nums[i]]--;
        }
        else mp[nums[i]]++;
    }
    return res;
}

int main(){

    int temp[] = {1, 3, 5, 3, 7};
    vector<int> items(temp, temp + sizeof(temp)/sizeof(temp[0]));
    // vector<int>items{1, 3, 5, 3, 7};

    int target = 6;
    cout << pairMatching(items, target); // 2

}
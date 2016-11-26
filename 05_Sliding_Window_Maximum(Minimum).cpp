// leetcode 239

// O(nlogn), not fast enough
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        multiset<int> window;
        for(int i = 0; i < nums.size(); i++) {
            window.insert(nums[i]);
            if(i >= k - 1) {
                res.push_back(*window.rbegin());
                window.erase(window.find(nums[i - k + 1]));
            }
        }
        return res;
    }
};

// deque, O(n)
// TODO

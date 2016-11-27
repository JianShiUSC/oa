// leetcode 1
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int, int> num2Index;
        for(int i = 0; i < nums.size(); i++) {
            num2Index[nums[i]] = i;
        }
        for(int i = 0; i < nums.size(); i++) {
            if(num2Index.find(target - nums[i]) != num2Index.end() && num2Index[target - nums[i]] != i) {
                if(i < num2Index[target-nums[i]]) {
                    res.push_back(i);
                    res.push_back(num2Index[target - nums[i]]);
                    break;
                } else {
                    res.push_back(num2Index[target - nums[i]]);
                    res.push_back(num2Index[nums[i]]);
                    break;
                }
            }
        }
        return res;
    }
};

class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
              
        int X = nums[n - 1] - nums[2];
        int Y = nums[n - 3] - nums[0];
        int Z = nums[n - 2] - nums[1];
              
        return min({ X , Y , Z });
    }
};

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        unordered_map<int, int> mp;

        for (int x : nums) {
            mp[x]++;
        }

        vector<int> ans;

        while (ans.size() < nums.size()) {

            for (int i = 0; i < nums.size(); i++) {
                if ((i == 0 || nums[i] != nums[i - 1]) && mp[nums[i]] > 0) {
                    ans.push_back(nums[i]);
                    mp[nums[i]]--;
                }
            }
        }
        return ans;
    }
};
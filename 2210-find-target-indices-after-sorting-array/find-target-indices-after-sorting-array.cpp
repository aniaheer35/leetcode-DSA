class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
            int n = nums.size() ; 
            sort(nums.begin() , nums.end()) ; 

            int count = 0 ; 
            vector<int> vec ; 
            for(int i = 0 ; i < n ; i++) {
                if(nums[i] == target ) {
                       vec.push_back(i) ; 

                }
            }
            return vec ; 
    }
};
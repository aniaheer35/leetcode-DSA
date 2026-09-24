class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size() ; 
        vector<int> presum ; 
        presum.push_back(nums[0]) ; 
        for( int i = 1 ; i < n ; i++ ){
             presum.push_back({presum[i-1] + nums[i]}) ; 
        }
        int count = 0 ;
        for(int i = 0 ; i < n-1 ; i++ ){
            if(((presum[n-1] - presum[i]) - presum[i])%2 == 0 ) {
                count++ ; 
            }
        }
        return count ; 
     }
};
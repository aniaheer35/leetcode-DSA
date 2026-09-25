class Solution {
public:
    int rob(vector<int>& nums) {
     int n = nums.size() ; 
     vector<int> DP(n) ; 
     if(n >= 1) {
         DP[0] = nums[0] ; 
      }
     if(n >= 2) {
         DP[1] = max(nums[0] , nums[1]) ;
     }
     for(int i = 2 ; i < n ; i++) {
         DP[i] = max(DP[i-2] + nums[i] , DP[i-1]) ;  
     }

     return DP[n-1] ; 
    }
};
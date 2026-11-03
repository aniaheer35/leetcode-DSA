class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size() ; 
        int Maxel = INT_MIN ; 
        for(int i = 0 ; i < n ; i++ ){
            if(Maxel < nums[i]) {
                Maxel = nums[i] ; 
            }
        }

        int ans = 0 ; 
        for(int i = 0 ; i < n ; i++){
             ans += Maxel - nums[i] ; 
        }
        return ans ;
    }
};
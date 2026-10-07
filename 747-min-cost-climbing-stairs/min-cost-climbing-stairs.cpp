class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // int n = cost.size();

        // vector<int> DP(n + 1);

        // DP[0] = 0;
        // DP[1] = 0;

        // for(int i = 2; i <= n; i++) {
        //     DP[i] = min(DP[i-1] + cost[i-1],
        //                 DP[i-2] + cost[i-2]);
        // }
        
        // return DP[n];

        int n = cost.size() ; 
        int prev1 = 0 ; 
        int prev2 = 0 ; 

        for(int i = 2 ; i <= n ; i++ ){
           
            int curr = min(prev1 + cost[i-1] , prev2 + cost[i-2]) ;
             prev2 = prev1 ;
            prev1 = curr ; 
            
        }
        return prev1 ;
    }
}; 
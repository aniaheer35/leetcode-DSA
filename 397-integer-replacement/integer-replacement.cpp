class Solution {
public:
    unordered_map<long long,long long> dp;
    long long solve(long long n){
        // base case
        if(n==1)return 0;
        if(dp.find(n) != dp.end())return dp[n];
        if(n%2==0){
            return dp[n] = 1+solve(n/2);
        }
        return dp[n] = 1+min(solve(n-1),solve(n+1));
    }
    int integerReplacement(int n){
        dp.clear();
        return (int)solve(n);
    }
};
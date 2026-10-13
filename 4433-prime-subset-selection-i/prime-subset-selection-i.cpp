class Solution {
public:
    vector<int> maxPrimes(int n, int s) {
   
        vector<bool> isPrime(n + 1, true);
        if (n >= 0) isPrime[0] = false;
        if (n >= 1) isPrime[1] = false;
        
        vector<int> vec;
     
        for (int i = 2; i <= n; i++) {
            if (isPrime[i]) {
                vec.push_back(i);
              
                for (long long j = (long long)i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        vector<int> ans;
        int sum = 0;
        for (int i = 0; i < vec.size(); i++) {
            if (sum + vec[i] <= s) {
                sum += vec[i];
                ans.push_back(vec[i]);
            }
        }
        
        return ans;
    }
};


class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        const long long MAX_PROD = 36288000; 

        for (int i = 0; i < n; ++i) {
            long long prod = 1;
            long long l = 1;
            int g = 0;

            for (int j = i; j < n; ++j) {
                prod *= nums[j];
            
                if (prod > MAX_PROD) {
                    break;
                }
                
                l = lcm(l, (long long)nums[j]);
                g = gcd(g, nums[j]);

                if (prod == l * g) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};

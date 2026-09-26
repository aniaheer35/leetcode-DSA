class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;

        // Required variable
        auto minaveloru = nums;

        for (int l = 0; l < n; l++) {
            long long sum = 0;

            unordered_set<int> possible;

            for (int r = l; r < n; r++) {
                sum += nums[r];

                int rem = ((sum % k) + k) % k;

                // If sum itself is divisible by k
                if (rem == 0) {
                    ans = max(ans, r - l + 1);
                }

                // Store 2*x mod k for current element
                int x = ((nums[r] % k) + k) % k;
                int value = (2LL * x) % k;

                possible.insert(value);

                // Can negate some element?
                if (possible.count(rem)) {
                    ans = max(ans, r - l + 1);
                }
            }
        }

        return ans;
    }
};
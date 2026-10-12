class Solution {
public:
    vector<int> maxPrimeSubset(int n, int s) {
        vector<int> primes;

        for (int x = 2; x <= n; x++) {
            bool prime = true;

            for (int d = 2; d * d <= x; d++) {
                if (x % d == 0) {
                    prime = false;
                    break;
                }
            }

            if (prime) primes.push_back(x);
        }

        // dp[sum] = minimum number of primes needed
        const int INF = 1e9;
        vector<int> dp(s + 1, INF);
        dp[0] = 0;

        for (int p : primes) {
            for (int sum = s; sum >= p; sum--) {
                if (dp[sum - p] != INF) {
                    dp[sum] = min(dp[sum], dp[sum - p] + 1);
                }
            }
        }

        // Find the largest achievable sum.
        int bestSum = s;
        while (bestSum > 0 && dp[bestSum] == INF) {
            bestSum--;
        }

        if (bestSum == 0) return {};

        // Reconstruct the lexicographically smallest subset.
        vector<int> ans;
        int remaining = bestSum;
        int remainingCount = dp[bestSum];

        for (int i = 0; i < (int)primes.size(); i++) {
            int p = primes[i];

            if (p > remaining) break;

            // Check whether choosing p permits an optimal completion.
            vector<int> nextDp(remaining + 1, INF);
            nextDp[0] = 0;

            for (int j = i + 1; j < (int)primes.size(); j++) {
                int q = primes[j];

                for (int sum = remaining - p; sum >= q; sum--) {
                    if (nextDp[sum - q] != INF) {
                        nextDp[sum] =
                            min(nextDp[sum], nextDp[sum - q] + 1);
                    }
                }
            }

            if (remainingCount >= 1 &&
                nextDp[remaining - p] == remainingCount - 1) {
                ans.push_back(p);
                remaining -= p;
                remainingCount--;
            }

            if (remainingCount == 0) break;
        }

        return ans;
    }
};
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) {
            return 1;
        }

        int total = 10;           // All 1-digit numbers (0-9)
        int currentWays = 9;      // Choices for the first digit of >=2-digit numbers
        int availableDigits = 9;  // Remaining digits (0-9 minus the first digit)

        for (int i = 2; i <= n && availableDigits > 0; i++) {
            currentWays *= availableDigits;
            total += currentWays;
            availableDigits--;
        }

        return total;
    }
};

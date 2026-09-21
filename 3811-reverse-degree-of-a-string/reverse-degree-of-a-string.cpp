

class Solution {
public:
    int reverseDegree(std::string s) {
        int totalDegree = 0;
        
        for (int i = 0; i < s.length(); ++i) {
            // Calculate the 1-based index in the reversed alphabet ('a' -> 26, 'z' -> 1)
            int reversedAlphabetPos = 26 - (s[i] - 'a');
            
            // 1-based index in the string
            int stringPos = i + 1;
            
            // Multiply and accumulate the product into the total score
            totalDegree += reversedAlphabetPos * stringPos;
        }
        
        return totalDegree;
    }
};

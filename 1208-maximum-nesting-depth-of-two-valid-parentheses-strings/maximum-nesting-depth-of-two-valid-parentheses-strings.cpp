class Solution {
public:
    vector<int> maxDepthAfterSplit(string s) {
        vector<int> vec;
        int depth = 0;
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
            
                vec.push_back(depth % 2);
                depth++;
            } else {
                depth--;
                vec.push_back(depth % 2);
            }
        }
        
        return vec;
    }
};
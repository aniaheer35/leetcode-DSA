class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        
        unordered_map<char, char> map1;
        unordered_map<char, char> map2;
        
        for (int i = 0; i < s.size(); i++) {
            // Check if s[i] was already mapped to a different character in t
            if (map1.count(s[i]) && map1[s[i]] != t[i]) {
                return false;
            }
            // Check if t[i] was already mapped to a different character in s
            if (map2.count(t[i]) && map2[t[i]] != s[i]) {
                return false;
            }
            
            map1[s[i]] = t[i];
            map2[t[i]] = s[i];
        }
        
        return true;
    }
};

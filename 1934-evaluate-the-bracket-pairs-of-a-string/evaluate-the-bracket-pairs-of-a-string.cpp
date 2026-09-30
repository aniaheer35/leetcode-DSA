class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;

        // Store key -> value
        for (auto& it : knowledge) {
            mp[it[0]] = it[1];
        }

        string result = "";

        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '(') {

                // Find closing bracket
                int j = i + 1;
                string key = "";

                while (s[j] != ')') {
                    key += s[j];
                    j++;
                }

                // Check whether key exists
                if (mp.find(key) != mp.end()) {
                    result += mp[key];
                } else {
                    result += "?";
                }

                // Move i to ')'
                i = j;
            } else {
                result += s[i];
            }
        }

        return result;
    }
};
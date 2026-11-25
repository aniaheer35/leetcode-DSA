
class Solution {
public:
    string decodeString(string s) {
        stack<int> num_stack;
        stack<string> str_stack;
        int curr_num = 0;
        string curr_str = "";

        for (char c : s) {
            if (isdigit(c)) {
                curr_num = curr_num * 10 + (c - '0');
            } 
            else if (c == '[') {
                num_stack.push(curr_num);
                str_stack.push(curr_str);
                curr_num = 0;
                curr_str = "";
            } 
            else if (c == ']') {
                int repeat_count = num_stack.top();
                num_stack.pop();
                
                string prev_str = str_stack.top();
                str_stack.pop();
                
                string expanded = "";
                for (int i = 0; i < repeat_count; i++) {
                    expanded += curr_str;
                }
                curr_str = prev_str + expanded;
            } 
            else {
                curr_str += c;
            }
        }

        return curr_str;
    }
};

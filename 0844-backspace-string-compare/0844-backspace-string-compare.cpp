class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st1, st2;

        for(char ch : s) {
            if(ch != '#') {
                st1.push(ch);
            }
            else if(!st1.empty()) {
                st1.pop();
            }
        }

        for(char ch : t) {
            if(ch != '#') {
                st2.push(ch);
            }
            else if(!st2.empty()) {
                st2.pop();
            }
        }

        if(st1.size() != st2.size())
            return false;

        while(!st1.empty()) {
            if(st1.top() != st2.top())
                return false;

            st1.pop();
            st2.pop();
        }

        return true;
    }
};
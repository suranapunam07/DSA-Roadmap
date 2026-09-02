class Solution {
public:
    bool backspaceCompare(string s, string t) {

        int i = s.length() - 1;
        int j = t.length() - 1;

        int skipS = 0;
        int skipT = 0;

        while(i >= 0 || j >= 0) {

            // Find next valid character in s
            while(i >= 0) {

                if(s[i] == '#') {
                    skipS++;
                    i--;
                }
                else if(skipS > 0) {
                    skipS--;
                    i--;
                }
                else {
                    break;
                }
            }

            // Find next valid character in t
            while(j >= 0) {

                if(t[j] == '#') {
                    skipT++;
                    j--;
                }
                else if(skipT > 0) {
                    skipT--;
                    j--;
                }
                else {
                    break;
                }
            }

            // Both have valid characters
            if(i >= 0 && j >= 0 && s[i] != t[j]) {
                return false;
            }

            // Only one has a valid character
            if((i >= 0) != (j >= 0)) {
                return false;
            }
            i--;
            j--;
        }

        return true;
    }
};

/*
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
*/

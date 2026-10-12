
class Solution {
public:
    int calculate(string s) {
        int result = 0;
        int lastNum = 0;
        int num = 0;
        char op = '+';

        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
            }

            if ((!isdigit(s[i]) && s[i] != ' ') || i == s.size() - 1) {
                if (op == '+') {
                    result += lastNum;
                    lastNum = num;
                } else if (op == '-') {
                    result += lastNum;
                    lastNum = -num;
                } else if (op == '*') {
                    lastNum = lastNum * num;
                } else if (op == '/') {
                    lastNum = lastNum / num;
                }

                op = s[i];
                num = 0;
            }
        }

        return result + lastNum;
    }
};

/*

class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int num = 0;
        char op = '+';

        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
            }

            if ((!isdigit(s[i]) && s[i] != ' ') || i == s.size() - 1) {
                if (op == '+') {
                    st.push(num);
                } else if (op == '-') {
                    st.push(-num);
                } else if (op == '*') {
                    int top = st.top();
                    st.pop();
                    st.push(top * num);
                } else if (op == '/') {
                    int top = st.top();
                    st.pop();
                    st.push(top / num);
                }

                op = s[i];
                num = 0;
            }
        }

        int result = 0;

        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        return result;
    }
};
*/

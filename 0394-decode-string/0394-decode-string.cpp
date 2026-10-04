class Solution
{
public:
    string decodeString(string s)
    {
        stack<pair<int, string>> st;

        string current = "";
        int number = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if (isdigit(s[i]))
            {
                number = number * 10 + (s[i] - '0');
            }

            else if (s[i] == '[')
            {
                st.push({number, current});

                number = 0;
                current = "";
            }

            else if (s[i] == ']')
            {
                int repeat = st.top().first;
                string previous = st.top().second;

                st.pop();

                for (int j = 0; j < repeat; j++)
                {
                    previous += current;
                }

                current = previous;
            }

            else
            {
                current += s[i];
            }
        }

        return current;
    }
};

/*
stack<int> stack_num;
        stack<string> stack_str;

        string curr = "";
        int num = 0;

        for(int i = 0; i < s.length(); i++)
        {
            if(isdigit(s[i]))
            {
                num = num * 10 + (s[i] - '0');
            }
            else if (s[i] == '[')
            {
                stack_num.push(num);
                stack_str.push(curr);
                num = 0;
                curr = "";
            }
            else if (s[i] == ']')
            {
                int repeat = stack_num.top();
                stack_num.pop();
                string previous = stack_str.top();
                stack_str.pop();

                for(int j = 0; j < repeat; j++)
                {
                    previous += curr;
                }
                curr = previous;
            }
            else
            {
                curr += s[i];
            }
        }
        return curr;
    }
*/
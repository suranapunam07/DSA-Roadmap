class Solution {
public:
    int myAtoi(string s)
    {
        int n = s.length();
        int i = 0;

        while(i < n && s[i] == ' ')
        {
            i++;
        }
        int sign = 1;
        if(i , n && (s[i] == '+' || s[i] == '-'))
        {
            if(s[i] == '-')
            {
                sign = -1;
            }
            i++;
        }

        long long num = 0;

        while(i < n && isdigit(s[i]))
        {
            int digit = s[i] - '0';

            if(sign == 1)
            {
                if(num > INT_MAX/10 || num == INT_MAX / 10 && digit > 7)
                {
                    return INT_MAX;
                }
            }
            else
            {
                if(num > INT_MAX/10 || num == INT_MAX / 10 && digit > 8)
                {
                    return INT_MIN;
                }
            }
            num = num * 10 + digit;
            i++;
        }
        return sign * num;  
    }
};
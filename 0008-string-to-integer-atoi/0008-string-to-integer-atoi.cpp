class Solution {
public:
    int myAtoi(string s)
    {
        int i = 0;
        int n = s.length();

        // Skip spaces
        while(i < n && s[i] == ' ')
        {
            i++;
        }

        // Sign
        int sign = 1;

        if(i < n && (s[i] == '+' || s[i] == '-'))
        {
            if(s[i] == '-')
            {
                sign = -1;
            }

            i++;
        }

        long long num = 0;

        // Read digits
        while(i < n && isdigit(s[i]))
        {
            int digit = s[i] - '0';

            // Overflow check
            if(sign == 1)
            {
                if(num > INT_MAX / 10 ||
                  (num == INT_MAX / 10 && digit > 7))
                {
                    return INT_MAX;
                }
            }
            else
            {
                if(num > INT_MAX / 10 ||
                  (num == INT_MAX / 10 && digit > 8))
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
class Solution {
public:
    bool isPalindrome(int x) 
    {
        // Negative numbers are not palindrome
        // Numbers ending with 0 are also not palindrome
        // except 0 itself
        if(x < 0 || (x % 10 == 0 && x != 0))
        {
            return false;
        }

        int rev = 0;

        // Reverse only half of the number
        while(x > rev)
        {
            int digit = x % 10;

            rev = rev * 10 + digit;

            x = x / 10;
        }

        // For even digits:
        // x == rev
        //
        // For odd digits:
        // x == rev/10
        return (x == rev || x == rev / 10);
    }
};


/*class Solution {
public:
    bool isPalindrome(int x) 
    {
        // Negative numbers are not palindrome
        if(x < 0)
        {
            return false;
        }

        string s = to_string(x);

        int i = 0;
        int j = s.length() - 1;

        while(i < j)
        {
            if(s[i] != s[j])
            {
                return false;
            }

            i++;
            j--;
        }

        return true;
    }
};
*/
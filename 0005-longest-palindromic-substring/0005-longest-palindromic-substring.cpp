class Solution {
public:
    string longestPalindrome(string s)
    {
        //T.C = O(n^2), S.C = O(1)
        int n = s.length();

        if(n <= 1)
        {
            return s;
        }

        int start = 0;
        int maxLen = 1;

        for(int i = 0; i < n; i++)
        {
            int left = i;
            int right = i;

            while(left >= 0 && right < n && s[left] == s[right])
            {
                if(right - left + 1 > maxLen)
                {
                    start = left;
                    maxLen = right - left + 1;
                }
                left--;
                right++;
            }

            left = i;
            right = i + 1;

            while(left >= 0 && right < n && s[left] == s[right])
            {
                if(right - left + 1 > maxLen)
                {
                    start = left;
                    maxLen = right - left + 1;
                }
                left--;
                right++;
            }
        }
        return s.substr(start,maxLen);  
    }
};

/*T.C = O(n^3)
  S.C = O(1) 

class Solution {
public:

    bool isPalindrome(string s)
    {
        int n = s.length();
        int left = 0;
        int right = n - 1;

        while(left < right)
        {
            if(s[left] != s[right])
            {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

    string longestPalindrome(string s)
    {
        int n = s.length();
        string ans = "";

        for(int i = 0; i < n; i++)
        {
            for(int j = i; j < n; j++)
            {
                string t = s.substr(i, j - i + 1);

                if(isPalindrome(t))
                {
                    if(t.length() > ans.length())  
                    {
                        ans = t;
                    }
                }
            }
        }
        return ans;
    }
};
*/
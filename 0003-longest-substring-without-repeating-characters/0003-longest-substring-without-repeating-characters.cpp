class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_set<char> st;
        int n = s.length();
        int i = 0;
        int maxLen = 0;

        for(int j = 0; j < n; j++)
        {
            while(st.find(s[j]) != st.end())
            {
                st.erase(s[i]);
                i++;
            }
            st.insert(s[j]);

            maxLen = max(maxLen, j - i + 1);
        }
        return maxLen; 
    }
};
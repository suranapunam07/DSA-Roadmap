class Solution {
public:
    void generate(int n, string curr, unordered_set<string>st, string &ans)
    {
        if(!ans.empty())
        {
            return;
        }
        if(curr.length() == n)
        {
            if(st.find(curr) == st.end())
            {
                ans = curr;
            }
            return;
        }
        generate(n, curr + '0', st, ans);
        generate(n, curr + '1', st, ans);
    }
    
    string findDifferentBinaryString(vector<string>& nums) 
    {
        unordered_set<string> st(nums.begin(), nums.end());

        string ans = "";

        generate(nums.size(), "",st, ans);

        return ans;
    }
};
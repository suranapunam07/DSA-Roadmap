class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {

        vector<int> ones;

        // Store positions of all 1s
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1')
                ones.push_back(i);
        }

        // Not enough 1s
        if (ones.size() < k)
            return "";

        string ans = "";
        int minLength = INT_MAX;

        // Take every group of k consecutive 1s
        for (int i = k - 1; i < ones.size(); i++) {

            int start = ones[i - k + 1];
            int end = ones[i];

            int length = end - start + 1;

            string temp = s.substr(start, length);

            if (length < minLength) {
                minLength = length;
                ans = temp;
            }
            else if (length == minLength && temp < ans) {
                ans = temp;
            }
        }

        return ans;
    }
};
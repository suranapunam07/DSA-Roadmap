class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();

        int left = 0;
        int ones = 0;

        string ans = "";

        for (int right = 0; right < n; right++) {

            // Add current character
            if (s[right] == '1')
                ones++;

            // More than k ones
            while (ones > k) {
                if (s[left] == '1')
                    ones--;

                left++;
            }

            // Exactly k ones
            if (ones == k) {

                // Remove unnecessary zeros from left
                while (s[left] == '0') {
                    left++;
                }

                string temp = s.substr(left, right - left + 1);

                // Shorter is better
                if (ans == "" || temp.length() < ans.length()) {
                    ans = temp;
                }

                // Same length -> lexicographically smaller
                else if (temp.length() == ans.length() && temp < ans) {
                    ans = temp;
                }
            }
        }

        return ans;
    }
};
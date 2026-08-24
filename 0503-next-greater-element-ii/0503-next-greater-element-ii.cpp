class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {

        int n = nums.size();

        vector<int> ans(n, -1);

        stack<int> st;

        for (int i = 2 * n - 1; i >= 0; i--) {

            int current = nums[i % n];

            while (!st.empty() && st.top() <= current) {
                st.pop();
            }

            if (i < n) {
                if (!st.empty()) {
                    ans[i] = st.top();
                }
            }

            st.push(current);
        }

        return ans;
    }
};
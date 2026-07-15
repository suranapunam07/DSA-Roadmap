class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {

        unordered_set<int> st(nums.begin(), nums.end());

        vector<int> ans;

        for (int i = 1; i <= nums.size(); i++) {
            if (st.find(i) == st.end())
                ans.push_back(i);
        }

        return ans;
    }
};

/*Sorting T.C = O(n log n) , S.C=O(1)
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<int> ans;
        int expected = 1;
        int i = 0;
        int n = nums.size();

        while (expected <= n) {
            while (i < n && nums[i] < expected)
                i++;

            if (i == n || nums[i] != expected)
                ans.push_back(expected);

            expected++;
        }

        return ans;
    }
};
*/
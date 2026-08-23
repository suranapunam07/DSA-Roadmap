class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> mp;

        for (int i = nums2.size() - 1; i >= 0; i--) {

            while (!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }

            if (st.empty()) {
                mp[nums2[i]] = -1;
            } else {
                mp[nums2[i]] = st.top();
            }

            st.push(nums2[i]);
        }

        vector<int> ans;

        for (int x : nums1) {
            ans.push_back(mp[x]);
        }

        return ans;
    }
};

/*
vector<int> ans;

        for(int x : nums1)
        {
            int greater = -1;

            for(int i = 0; i < nums2.size(); i++)
            {
                if(nums2[i] == x)
                {
                    for(int j = i + 1; j < nums2.size(); j++)
                    {
                        if(nums2[j] > x)
                        {
                            greater = nums2[j];
                            break;
                        }
                    }
                    break;
                }
            }
            ans.push_back(greater);
        }
        return ans; 
*/
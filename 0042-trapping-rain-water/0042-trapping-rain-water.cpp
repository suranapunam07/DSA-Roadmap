
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        stack<int> st;
        int water = 0;

        for (int i = 0; i < n; i++) {
            while (!st.empty() &&
                   height[i] > height[st.top()]) {

                int bottom = st.top();
                st.pop();

                if (st.empty()) {
                    break;
                }

                int left = st.top();
                int width = i - left - 1;

                int h = min(height[left], height[i])
                        - height[bottom];

                water += width * h;
            }

            st.push(i);
        }

        return water;
    }
};

/*
T.C = O(n2) & S.C = O(1)

int n = height.size();
        int trappedwater = 0;

        for(int i = 0; i < n; i++)
        {
            int leftmax = 0;
            int rightmax = 0;
            for(int j = 0; j <= i; j++)
            {
                leftmax= max(leftmax, height[j]);
            }
            for(int j = i; j < n; j++)
            {
                rightmax = max(rightmax, height[j]);
            }
            trappedwater += min(leftmax, rightmax) - height[i];
        }
        return trappedwater;
*/

class Solution {
public:
    int trap(vector<int>& arr) 
    {
        int n = arr.size();
        int lmax = 0;
        int rmax = 0;
        int total = 0;
        int l = 0;
        int r = n - 1;
        
        while(l < r)
        {
            if(arr[l] <= arr[r])
            {
                if(lmax > arr[l])
                {
                    total += lmax - arr[l];
                }
                else
                {
                    lmax = arr[l];
                }
                l = l + 1;
            }
            else
            {
                if(rmax > arr[r])
                {
                    total += rmax - arr[r];
                }
                else
                {
                    rmax = arr[r];
                }
                r = r - 1;
            }
        }
        return total;
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

/*
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
*/
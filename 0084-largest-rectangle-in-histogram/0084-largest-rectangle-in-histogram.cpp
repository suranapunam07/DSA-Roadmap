
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;

        for (int i = 0; i <= n; i++) {
            int currHeight;

            if (i == n)
                currHeight = 0;
            else
                currHeight = heights[i];

            while (!st.empty() &&
                   heights[st.top()] > currHeight) {

                int height = heights[st.top()];
                st.pop();

                int width;

                if (st.empty())
                    width = i;
                else
                    width = i - st.top() - 1;

                int area = height * width;
                maxArea = max(maxArea, area);
            }

            if (i < n)
                st.push(i);
        }

        return maxArea;
    }
};

/* 
T.C = O(n2) & S.C = O(1)

int n = heights.size();
        int maxarea = 0;
        for(int i = 0; i < n; i++)
        {
            int minheight = heights[i];
            for(int j = i; j < n; j++)
            {
                minheight = min(minheight, heights[j]);
                int width = j - i + 1;
                int area = minheight * width;   

                maxarea = max(maxarea, area);
            }
        }
        return maxarea; 
*/
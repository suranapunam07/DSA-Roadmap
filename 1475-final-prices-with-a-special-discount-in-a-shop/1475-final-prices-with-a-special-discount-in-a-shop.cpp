class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) 
    {
        stack<int> st;

        for(int i = prices.size() - 1; i >= 0; i--)
        {
            int original = prices[i];
            while(!st.empty() && st.top() > original)
            {
                st.pop();
            }
            if(!st.empty())
            {
                prices[i] = original - st.top();
            }
            st.push(original);
        }
        return prices;
    }
};
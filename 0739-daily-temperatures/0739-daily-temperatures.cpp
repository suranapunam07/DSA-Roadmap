class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        int n = temperatures.size();

        vector<int> ans(n,0);
       
        vector<int> stack;

        for(int i = 0; i < n; i++)
        {
            while(!stack.empty() && temperatures[i] > temperatures[stack.back()])
            {
                int prev = stack.back();
                stack.pop_back();

                ans[prev] = i - prev;
            } 
            stack.push_back(i); 
        }
        return ans;
    }
};

/*
int n = temperatures.size();

        vector<int> ans(n,0);
       
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                if(temperatures[j] > temperatures[i])
                {
                    ans[i] = j - i;
                    break;
                }
            }
        }
        return ans;   
*/
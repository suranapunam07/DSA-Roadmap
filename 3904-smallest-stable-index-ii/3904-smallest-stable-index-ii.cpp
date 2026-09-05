class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) 
    {
                int n = nums.size();

        vector<int> suffixMin(n);

        suffixMin[n - 1] = nums[n - 1];

        for(int i = n - 2; i >= 0; i--)
        {
            suffixMin[i] = min(nums[i],suffixMin[i + 1]);
        }

        int prefixmx = nums[0];

        for(int i = 0; i < n; i++)
        {
            prefixmx = max(prefixmx,nums[i]);

            if(prefixmx - suffixMin[i] <= k)
            {
                return i;
            }
        }
        return -1;
    }
};
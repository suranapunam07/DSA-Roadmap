class Solution {
public:
    int removeElement(vector<int>& nums, int val) 
    {
        int n = nums.size();
        int k = 0;

        for(int j = 0; j < n; j++) 
        {
            if(nums[j] != val) 
            {
                nums[k] = nums[j];
                k++;
            }
        }
        return k;
    }
};
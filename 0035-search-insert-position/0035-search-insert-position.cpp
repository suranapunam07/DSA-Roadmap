class Solution {
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        int n = nums.size();
        int st = 0, end = n - 1;

        while(st <= end)
        {
            int mid = st + (end - mid)/2;

            if(nums[mid] == target)
            {
                return mid;
            }
            else if(nums[mid] < target)
            {
                st = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        return st;   
    }
};
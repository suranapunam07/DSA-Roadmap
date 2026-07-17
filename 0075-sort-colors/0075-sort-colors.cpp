class Solution {
public:
//Dutch National flag algorithm...
    void sortColors(vector<int>& nums) 
    {
        int n = nums.size();
        int mid = 0, high = n - 1, low = 0;

        while(mid <= high)
        {
            if(nums[mid] == 0)
            {
                swap(nums[low],nums[mid]);
                mid++;
                low++;
            }
            else if(nums[mid] == 1)
            {
                mid++;
            }
            else
            {
                swap(nums[high],nums[mid]);
                high--;
            }
        }     
    }
};
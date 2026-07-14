class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
     int majority = 0;
     int count = 0;

     for(int num : nums)
     {
        if(count == 0)
        {
            majority = num;
        }
        if(num == majority)
        {
            count++;
        }
        else
        {
            count--;
        }
     }
     return majority;
    }
};


/* Two pointer- T.C=O(n^2)

    int n = nums.size();

        for(int num : nums)
        {
            int count = 0;
            for(int el : nums)
            {
                if(num == el)
                {
                    count++;
                }
            }
            if(count > n/2)
            {
                return num;
            }
        }
        return -1;
*/
/* sorting T.C = O(n logn)
class Solution {
public:
    int majorityElement(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());

        int count = 1;
        int ans = nums[0];
        int maxCount = 1;

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == nums[i - 1])
            {
                count++;
            }
            else
            {
                count = 1;
            }

            if (count > maxCount)
            {
                maxCount = count;
                ans = nums[i];
            }
        }

        return ans;
    }
};
*/


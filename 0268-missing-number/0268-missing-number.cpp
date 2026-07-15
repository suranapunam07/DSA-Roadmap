class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
        int n = nums.size();
        int actualSum = 0;
        int expectedSum = n * (n + 1) / 2;

        for(int i : nums)
        {
            actualSum += i;
        }
        return expectedSum - actualSum;
    }
};

/*
Using sorting T.C = O(n log n) S.C= O(1)
int n = nums.size();
        sort(nums.begin(),nums.end());

        for(int i = 0; i < n; i++)
        {
            if(nums[i] != i)
            {
                return i;
            }
        }
        return n;
*/
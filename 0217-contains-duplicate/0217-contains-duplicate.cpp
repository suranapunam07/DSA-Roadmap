class Solution {
public:
    bool containsDuplicate(vector<int>& nums) 
    {
        unordered_map<int,int> m;
       
        for(int i : nums)
        {
            if(m.find(i) != m.end())
            {
                return true;
            }
            m[i]++;
        }
        return false;
    }
};

/*
 int n = nums.size();

        unordered_map<int,int>m;
        int i = 0;
        for(int j = i+1; j < n; j++)
        {
            if(nums[i] == nums[j])
            {
                return true;
            }
*/
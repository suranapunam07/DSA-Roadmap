class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int n = height.size();
        int left = 0, right = n - 1;
        int MaxWater = 0;

        while(left < right)
        {
            int width = right - left;
            int ht = min(height[left],height[right]);
            int area = width * ht;

            MaxWater = max(MaxWater, area);

            if(height[left] < height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return MaxWater;
    }
};
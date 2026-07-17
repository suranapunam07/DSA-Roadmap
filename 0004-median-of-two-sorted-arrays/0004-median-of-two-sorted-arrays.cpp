class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int> arr;

        int n = nums1.size();
        int m = nums2.size();

        int i = 0;
        int j = 0;

        while(i < n && j < m)
        {
            if(nums1[i] < nums2[j])
            {
                arr.push_back(nums1[i++]);
            }
            else
            {
                arr.push_back(nums2[j++]);
            }
        }

        while(i < n)
        {
            arr.push_back(nums1[i++]);
        }

        while(j < m)
        {
            arr.push_back(nums2[j++]);
        }

        int k = arr.size();   // Calculate after merging

        if(k % 2 == 1)        // Odd
        {
            return arr[k / 2];
        }
        else                  // Even
        {
            return (arr[k / 2] + arr[k / 2 - 1]) / 2.0;
        }
    }
};
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

/*
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        // Always perform binary search on the smaller array
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);

        int n1 = nums1.size();
        int n2 = nums2.size();

        int start = 0;
        int end = n1;

        while (start <= end) {

            int cut1 = (start + end) / 2;
            int cut2 = (n1 + n2 + 1) / 2 - cut1;

            int left1, left2, right1, right2;

            // left1
            if (cut1 == 0)
                left1 = INT_MIN;
            else
                left1 = nums1[cut1 - 1];

            // right1
            if (cut1 == n1)
                right1 = INT_MAX;
            else
                right1 = nums1[cut1];

            // left2
            if (cut2 == 0)
                left2 = INT_MIN;
            else
                left2 = nums2[cut2 - 1];

            // right2
            if (cut2 == n2)
                right2 = INT_MAX;
            else
                right2 = nums2[cut2];

            // Correct partition
            if (left1 <= right2 && left2 <= right1) {

                if ((n1 + n2) % 2 == 0) {
                    return (max(left1, left2) + min(right1, right2)) / 2.0;
                } else {
                    return max(left1, left2);
                }
            }

            // Move left
            else if (left1 > right2) {
                end = cut1 - 1;
            }

            // Move right
            else {
                start = cut1 + 1;
            }
        }

        return 0.0;
    }
};
*/
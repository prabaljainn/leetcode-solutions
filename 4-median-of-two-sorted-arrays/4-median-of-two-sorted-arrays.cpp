class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        int M = nums1.size(), N = nums2.size();

        /* Why?? */
        if (M > N)
            return findMedianSortedArrays(nums2, nums1);

        int l = 0, r = M;
        while (l <= r) {
            int mid1 = ((size_t)l + r) / 2;
            int mid2 = (M + N + 1) / 2 - mid1;

            int max1_left = mid1 - 1 >= 0 ? nums1[mid1 - 1] : INT_MIN;
            int max2_left = mid2 - 1 >= 0 ? nums2[mid2 - 1] : INT_MIN;

            int min1_right = mid1 < M ? nums1[mid1] : INT_MAX;
            int min2_right = mid2 < N ? nums2[mid2] : INT_MAX;

            if (max1_left <= min2_right && max2_left <= min1_right) {
                int max_left = max(max1_left, max2_left);
                int min_right = min(min1_right, min2_right);
                return (M + N) % 2 ? max_left : (max_left + min_right) / 2.0;
            }

            if (max2_left > min1_right) {
                l = mid1 + 1;
            } else {
                r = mid1 - 1;
            }
        }
        return -1;
    }
};
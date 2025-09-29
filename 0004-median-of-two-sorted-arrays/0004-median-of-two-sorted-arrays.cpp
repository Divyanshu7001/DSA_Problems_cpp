class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int i = 0, j = 0;
        vector<int> result;
        while (i != nums1.size() && j != nums2.size()) {
            if (nums1[i] <= nums2[j]) {
                result.push_back(nums1[i]);
                i++;
            } else {
                result.push_back(nums2[j]);
                j++;
            }
        }
        while (i != nums1.size()) {
            result.push_back(nums1[i]);
            i++;
        }
        while (j != nums2.size()) {
            result.push_back(nums2[j]);
            j++;
        }

        int sz = result.size();
        double res;
        if (sz % 2 == 0) {
            res = (double)(result[sz / 2 - 1] + result[sz / 2]) / 2;
        } else
            res = result[sz / 2];

        return res;
    }
};
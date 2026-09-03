class Solution {
public:
    bool uniformArray(vector<int>& nums1) {

        int minEle = *min_element(nums1.begin(), nums1.end());

        // smallest odd..we can change other numbers to odd anyway
        if (minEle % 2 == 1)
            return true;

        // smallest is even..if any number is odd then..return false
        for (int& num : nums1) {
            if (num % 2 == 1)
                return false;
        }

        // smallest and all other elements ie even..return true
        return true;
    }
};
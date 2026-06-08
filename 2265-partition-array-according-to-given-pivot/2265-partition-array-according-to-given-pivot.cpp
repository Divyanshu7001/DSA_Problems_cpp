class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {

        int n = nums.size();
        vector<int> result(n);

        // Original nums iterators
        int i = 0, j = n - 1;
        // result vector iterators
        int i_ = 0, j_ = n - 1;

        while (i < n && j >= 0) {

            if (nums[i] < pivot) {
                result[i_] = nums[i];
                i_++;
            }

            if (nums[j] > pivot) {
                result[j_] = nums[j];
                j_--;
            }

            i++;
            j--;
        }

        // fill the left vacant boxes with pivot value
        while (i_ <= j_) {
            result[i_] = pivot;
            i_++;
        }

        return result;
    }
};
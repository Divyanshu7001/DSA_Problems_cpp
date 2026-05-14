class Solution {
public:
    bool isGood(vector<int>& nums) {
        int max = *max_element(nums.begin(), nums.end()), n = nums.size();
        if (n != max + 1)
            return false;

        if (n == 2)
            return nums[1] == nums[0];

        vector<int> vec(max, 0);

        for (int i = 0; i < n; i++)
            vec[nums[i] - 1]++;

        for (int i = 0; i < max - 1; i++)
            if (vec[i] == 0)
                return false;

        return vec[max - 1] == 2;
    }
};

// class Solution {
// public:
//     int n, max;
//     bool isIncreasing(vector<int>& nums) {
//         int count = 0;
//         for (int i = 1; i < n; i++) {
//             if (nums[i] - nums[i - 1] != 1 && nums[i] != max)
//                 return false;
//             else if (nums[i] == max)
//                 count++;
//         }

//         if (count != 2)
//             return false;

//         return true;
//     }

//     bool isGood(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         if (nums[0] != 1)
//             return false;
//         max = *max_element(nums.begin(), nums.end());

//         n = nums.size();
//         if (n != max + 1)
//             return false;

//         if (n == 2)
//             return nums[1] == nums[0];

//         return isIncreasing(nums);
//     }
// };
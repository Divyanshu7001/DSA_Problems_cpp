class Solution {
public:
    int maximumDifference(vector<int>& nums) {

        int maxDifference = -1;
        int ithPos = 0, jthPos = 0;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (i < j && (nums[i]<nums[j])&& ((nums[j] - nums[i]) > maxDifference)) {
                    ithPos = i;
                    jthPos = j;
                    maxDifference = nums[j] - nums[i];
                }
            }
        }
        cout << "Ith: " << ithPos << endl;
        cout << "Jth: " << jthPos << endl;
        cout << "Max Diff: " << maxDifference;
        return maxDifference;
    }
};
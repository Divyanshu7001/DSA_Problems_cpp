class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {

        int n = nums.size();

        // store all pair XORs
        unordered_set<int> st;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++)
                st.insert(nums[i] ^ nums[j]);
        }

        // Find triplets
        unordered_set<int> s2;
        for (int pairXor : st) {
            for (int& num : nums) {
                s2.insert(pairXor ^ num);
            }
        }

        return s2.size();
    }
};
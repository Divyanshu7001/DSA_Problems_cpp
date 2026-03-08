class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        for (auto& it : nums) {
            // inserting decimal value of the strings in the set
            st.insert(stoi(it, nullptr, 2));
        }
        for (int i = 0; i < (1 << n); i++) {
            // checking if the binary value is in the set..if not ..we got it &
            // the generated string is less than 2^n
            if (st.count(i) == 0) {
                string s = bitset<32>(i).to_string();
                return s.substr(32 - n);
            }
        }
        return "";
    }
};
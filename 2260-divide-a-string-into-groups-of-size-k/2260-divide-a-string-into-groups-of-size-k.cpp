class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> result;
        int initial = 0;

        while (initial < s.length()) {
            string temp = "";
            for (int i = 0; i < k; i++) {
                if (initial + i < s.length()) {
                    temp += s[initial + i];
                } else {
                    temp += fill;
                }
            }
            result.push_back(temp);
            initial += k;
        }

        return result;
    }
};

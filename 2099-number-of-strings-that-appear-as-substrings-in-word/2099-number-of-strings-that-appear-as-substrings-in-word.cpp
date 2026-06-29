class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {

        int res = 0;
        for (string& sub : patterns) {
            res += (word.find(sub) > word.length()) ? 0 : 1;
        }
        return res;
    }
};
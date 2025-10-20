// T.C=O(N)
class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {

        int x = 0;

        for (const string& op : operations) {
            (op[1] == '-') ? x-- : x++;
        }

        return x;
    }
};
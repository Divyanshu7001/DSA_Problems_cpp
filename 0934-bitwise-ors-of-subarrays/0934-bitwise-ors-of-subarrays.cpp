// T>C=O(n*n) but as the inner loop will run at most upto 32 times in worst case
// when every bit is getting set one by one
//  then T.C=O(n*32) == O(n)

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {

        unordered_set<int> prev, curr, result;
        for (int i = 0; i < arr.size(); i++) {
            for (const int& x : prev) {
                curr.insert(x | arr[i]);
                result.insert(x | arr[i]);
            }
            curr.insert(arr[i]);
            result.insert(arr[i]);

            prev = curr;
            curr.clear();
        }
        return result.size();
    }
};
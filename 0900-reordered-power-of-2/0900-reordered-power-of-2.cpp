// we can get the power values of 2 by keep updating left bit manipulation
// starting from i=1 then pass it in a function where the passed value is taken
// in a string and sorted by char values and returns the sorted string the
// question asks to see if any of ordering can match with some power of 2 in the
// function if passed value's sorted string can match the original number's
// sorted string..then we can return true

//T.C=O(Klogk)
class Solution {
public:
    string getOrderedString(int n) {
        string s = to_string(n);
        sort(s.begin(), s.end());
        return s;
    }
    bool reorderedPowerOf2(int n) {
        string signature = to_string(n);
        sort(signature.begin(), signature.end());
        for (int i = 1; i <= 1e9; i <<= 1) {
            if (signature == getOrderedString(i))
                return true;
        }

        return false;
    }
};
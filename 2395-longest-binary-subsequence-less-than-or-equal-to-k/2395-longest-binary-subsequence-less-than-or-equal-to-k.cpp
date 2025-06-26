//take powerValue at first to be 1...2^0, length=0 a first
//scan from left to right as we do for binary to decimal

//There is two values possible 0 or 1
//Taking 0 doesnt effect the value of the substring in any way..so blindly take it...and increase length
//in else ..the value is 1
//if powerValue is less than or equal to remaining k..then
//increase length & decrease k by the powerValue

//if current powerValue is less than or equal to k..then increase powerValue by 2 for next bit like 2^0..2^1
class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.length();

        long long powerValue = 1; // 2^0
        int length = 0;

        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0') {
                length++;
            } else if (powerValue <= k) {
                k -= powerValue;
                length++;
            }

            if (powerValue <= k) {
                powerValue *= 2;
            }
        }
        return length;
    }
};



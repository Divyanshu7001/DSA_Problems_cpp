class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {

        int n = bits.size();
        if (n == 1)
            return true;
        if (n == 2) {
            if (bits[n - 2] == 0 && bits[n - 1] == 0)
                return true;
            else if (bits[n - 2] == 1 && bits[n - 1] == 0)
                return false;
        }

        int i = 0, twoBitBefore = false;
        while (i < n) {
            if (i == n - 1) {
                if (twoBitBefore)
                    return true;
                else {
                    if (bits[n - 2] == 0) {
                        return true;
                    }
                    return false;
                }
            }

            if (bits[i] == 0)
                i++;
            else {
                twoBitBefore = true;
                i += 2;
            }
        }
        return false;
    }
};
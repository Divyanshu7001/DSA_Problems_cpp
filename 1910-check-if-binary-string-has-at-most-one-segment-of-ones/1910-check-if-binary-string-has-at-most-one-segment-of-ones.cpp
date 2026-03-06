class Solution {
public:
    bool checkOnesSegment(string s) {
        if (count(s.begin(), s.end(), '1') == 1)
            return true;

        int countSeg = 1, prev = 0;
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == '1') {
                if (i - prev > 1)
                    countSeg++;
                prev = i;
            }
        }
        return countSeg == 1 ? true : false;
    }
};
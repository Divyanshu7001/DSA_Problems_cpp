class Solution {
public:
    bool sumGame(string num) {
        int n = num.length();
        int leftQmarkCount = 0, leftKnownSum = 0;
        int rightQmarkCount = 0, rightKnownSum = 0;

        for (int i = 0; i < n; i++) {
            if (num[i] == '?') {
                if (i < n / 2)
                    leftQmarkCount++;
                else
                    rightQmarkCount++;
            } else {
                if (i < n / 2)
                    leftKnownSum += (num[i] - '0');
                else
                    rightKnownSum += (num[i] - '0');
            }
        }

        if ((leftQmarkCount + rightQmarkCount) % 2 ==
            1) // odd question marks..always alice wins
            return true;

        int left = 2 * leftKnownSum + 9 * leftQmarkCount;
        int right = 2 * rightKnownSum + 9 * rightQmarkCount;

        if (left == right) // even sum both side..bob matches anyway and wins
            return false;

        return true;
    }
};
class Solution {
public:
    int smallestNumber(int n) {

        for (int i = 0; i <= 10; i++) {
            int num = 2 << i;
            if (num > n)
                return num - 1;
        }
        return -1;
    }
};
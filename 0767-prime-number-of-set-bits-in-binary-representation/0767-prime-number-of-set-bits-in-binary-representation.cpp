class Solution {
public:
    bool isPrimeSetBit(string num) {
        int setBit = 0;
        for (char& str : num)
            setBit += str == '1' ? 1 : 0;

        if (setBit == 0 || setBit == 1)
            return false;
        if (setBit == 2)
            return true;

        for (int i = 2; i * i <= setBit; i++) {
            if (setBit % i == 0)
                return false;
        }
        return true;
    }
    int countPrimeSetBits(int left, int right) {
        int res = 0;
        for (int i = left; i <= right; i++) {
            string num = bitset<32>(i).to_string().substr(
                bitset<32>(i).to_string().find('1'));
            if (isPrimeSetBit(num))
                res++;
        }
        return res;
    }
};
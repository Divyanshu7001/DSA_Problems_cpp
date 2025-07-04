class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {

        int shift = 0;
        vector<long long> length;
        long long len = 1;

        for (int op : operations) {
            len *= 2;
            length.push_back(len);
            if (len >= k)
                break;
        }

        for (int i = length.size() - 1; i >= 0; i--) {
            long long half = length[i] / 2;
            int op = operations[i];
            if (k > half) {
                k -= half;
                if (op == 1)
                    shift++;
            }
        }

        return (char)((('a' - 'a' + shift) % 26) + 'a');
    }
};
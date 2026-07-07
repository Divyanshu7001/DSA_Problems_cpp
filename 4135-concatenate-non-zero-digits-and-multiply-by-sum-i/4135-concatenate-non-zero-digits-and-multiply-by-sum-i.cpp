class Solution {
public:
    long long sumAndMultiply(int n) {

        long long res = 0;
        string s = to_string(n);
        int sum = 0;
        string tmp = "";
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '0')
                continue;
            sum += s[i] - '0';
            tmp.push_back(s[i]);
        }

        stringstream ss(tmp);
        ss >> res;
        return res * sum;
    }
};
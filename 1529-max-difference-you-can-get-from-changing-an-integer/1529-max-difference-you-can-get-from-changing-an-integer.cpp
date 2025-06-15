class Solution {
public:
    int maxDiff(int num) {
        string str1 = to_string(num);
        string str2 = str1;
        int n = str1.length();

        // Maximize: Replace first non-9 digit with 9
        for (int i = 0; i < n; i++) {
            if (str1[i] != '9') {
                char to_replace = str1[i];
                for (int j = 0; j < n; j++) {
                    if (str1[j] == to_replace) str1[j] = '9';
                }
                break;
            }
        }

        // Minimize
        if (str2[0] != '1') {
            char to_replace = str2[0];
            for (int j = 0; j < n; j++) {
                if (str2[j] == to_replace) str2[j] = '1';
            }
        } else {
            for (int i = 1; i < n; i++) {
                if (str2[i] != '0' && str2[i] != '1') {
                    char to_replace = str2[i];
                    for (int j = i; j < n; j++) {
                        if (str2[j] == to_replace) str2[j] = '0';
                    }
                    break;
                }
            }
        }

        return stoi(str1) - stoi(str2);
    }
};

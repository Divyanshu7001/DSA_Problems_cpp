class Solution {
public:
    string largestGoodInteger(string num) {
        string maxElement = "";
        int n = num.length();
        int i = 0, j = 0, count = 0;
        while (i < n && j < n) {
            string temp = "";
            if (num[i] == num[j]) {
                count++;
                cout << "Count value: " << count;
                if (count == 3) {
                    if (num.substr(i, 3) > temp) {
                        temp = num.substr(i, 3);
                        maxElement = max(maxElement, temp);
                    }
                    i = j;
                    j++;
                    temp.clear();
                    count = 0;
                } else {
                    j++;
                }
            } else {
                i++;
                count = 0;
            }
        }
        return maxElement;
    }
};
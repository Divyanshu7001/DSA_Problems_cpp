class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;

        while (i >= 0 || j >= 0 || carry) {
            int sum = 0;
            if (i >= 0) {
                sum += a[i] - '0';
                i--;
            }
            if (j >= 0) {
                sum += b[j] - '0';
                j--;
            }
            sum += carry;

            // The bit for the result is sum % 2 (e.g., 2 % 2 = 0)
            result += to_string(sum % 2);

            // The carry for the next step is sum / 2 (e.g., 2 / 2 = 1)
            carry = sum / 2;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
// class Solution {
// public:
//     string res = "", temp = "";
//     int n;
//     pair<bool, string> fractionCheck(string s, int i) {
//         if (i == temp.size())
//             return make_pair(false, s);
//         int currentSize = s.size();
//         string temp_match = "";
//         while (currentSize != 0) {
//             i++;
//             temp_match += temp[i];
//             if (i == temp.size()) {
//                 if (temp_match == s)
//                     return make_pair(true, temp_match);
//                 else
//                     return make_pair(false, s);
//             }
//             currentSize--;
//         }
//         if (temp_match == s)
//             return make_pair(true, temp_match);
//         else
//             return fractionCheck(temp_match, i);
//     }

//     string fractionToDecimal(int numerator, int denominator) {

//         float result = static_cast<float>(numerator) / denominator;
//         ostringstream oss;
//         oss << result;
//         temp = oss.str();
//         n = temp.size();
//         if (n == 1)
//             return temp;
        
//         cout<<temp;
//         int i = 0;
//         while (i < n && temp[i] != '.') {
//             res += temp[i];
//             i++;
//         }
//         res += temp[i];
//         i++;
//         pair<bool, string> p = fractionCheck(to_string(temp[i]), i);
//         if (p.first == true) {
//             res += '(';
//             res += p.second;
//             res += ')';
//         } else
//             res += p.second;

//         return res;
//     }
// };


class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";

        string res;

        // Handle sign
        if ((numerator < 0) ^ (denominator < 0))
            res += "-";

        long long n = llabs((long long)numerator);
        long long d = llabs((long long)denominator);

        // Integer part
        res += to_string(n / d);
        long long rem = n % d;
        if (rem == 0) return res;

        res += ".";
        unordered_map<long long, int> remPos;

        while (rem != 0) {
            // If remainder already seen â repeating starts here
            if (remPos.find(rem) != remPos.end()) {
                res.insert(remPos[rem], "(");
                res += ")";
                return res;
            }

            remPos[rem] = res.size();
            rem *= 10;
            res += to_string(rem / d);
            rem %= d;
        }

        return res;
    }
};

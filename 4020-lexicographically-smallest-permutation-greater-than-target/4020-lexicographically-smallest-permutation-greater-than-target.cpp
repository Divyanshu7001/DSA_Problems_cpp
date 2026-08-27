// backtracking + greedy will work
// we will try to match as much as possible(equals)
// as soon as we cant match exactly..we will take the next closest greater
// character of current one(greedy first..& make the bool greater as
// true..marking the flow that the current string is already greater than
// target)

// if greater true..then we keep putting the other character in ascending order
// if greater false and we reached end..then start backtracking and trying if
// any other options available by which greater can be true
class Solution {
public:
    vector<int> freq;
    string res = "";
    bool solve(string curr, string& target, int i, bool greater) {
        if (i == target.length()) {
            if (greater) {
                res = curr;
                return true;
            }
            return false;
        }

        for (char ch = 'a'; ch <= 'z'; ch++) {
            if (freq[ch - 'a'] == 0)
                continue;

            if (greater == false && ch < target[i])
                continue;

            curr.push_back(ch);
            freq[ch - 'a']--;

            bool isGreater = greater || (ch > target[i]);
            if (solve(curr, target, i + 1, isGreater))
                return true;

            curr.pop_back();
            freq[ch - 'a']++;
        }

        return false;
    }

    string lexGreaterPermutation(string s, string target) {
        freq.resize(26, 0);
        for (char& ch : s)
            freq[ch - 'a']++;

        string curr;
        // current string, target string, current index, is greater already
        solve(curr, target, 0, false);
        return res;
    }
};

// class Solution {
// public:
//     vector<int> freq;
//     char solve(char ch) {
//         int idx = ch - 'a';
//         if (freq[idx] != 0) {
//             freq[idx]--;
//             return idx + 'a';
//         }

//         for (int i = 0; i < 26; i++) {
//             if (freq[i] != 0) {
//                 freq[i]--;
//                 return i + 'a';
//             }
//         }

//         return 'a';
//     }

//     string lexGreaterPermutation(string s, string target) {
//         freq.resize(26, 0);
//         for (char& ch : s)
//             freq[ch - 'a']++;

//         string res = "";
//         for (char& ch : target)
//             res.push_back(solve(ch));
//         return (res == target) ? "" : res;
//     }
// };
// let the substring length=L & given times=k,length of input string=n
// Therefore L*K<=n => L<=n/k

// Frequency of all the characters of the substrings must be >=k
// Filter the characters less than k

// Get the at most freq. of each character that can be used in a substring
// freq<=freq[charcater]/k

// Find all possible subsequences from valid characters.(sub) => Backtracking
// keep checking if (sub*k) is present in S as a subsequence

// Backtracking approach checking all the subsequences from 1 length to max n/k
// length
//  class Solution {
//  public:
//      string result = "";

//     bool isSubsequence(string& s, string& sub, int k) {
//         int i = 0, j = 0, n = s.length(), m = sub.length();
//         int count = 0;

//         while (i < n) {
//             if (s[i] == sub[j]) {
//                 j++;
//                 if (j == m) {
//                     j = 0;
//                     count++;
//                     if (count == k)
//                         return true;
//                 }
//             }
//             i++;
//         }
//         return false;
//     }

//     void backtracking(string s, string& curr, vector<bool>& canUse,
//                       vector<int>& requiredFreq, int k, int maxLen) {

//         if (curr.length() > maxLen) {
//             return;
//         }

//         if (((curr.length() > result.length()) ||
//              (curr.length() == result.length() && curr > result)) &&
//             isSubsequence(s, curr, k)) {
//             result = curr;
//         }

//         for (int i = 0; i < 26; i++) {
//             if (canUse[i] == false || requiredFreq[i] == 0) {
//                 continue;
//             }
//             // DO
//             char ch = i + 'a';
//             curr.push_back(ch);
//             requiredFreq[i]--;

//             // EXPLORE
//             backtracking(s, curr, canUse, requiredFreq, k, maxLen);

//             // UNDO
//             curr.pop_back();
//             requiredFreq[i]++;
//         }
//     }

//     string longestSubsequenceRepeatedK(string s, int k) {

//         int n = s.length();
//         int freq[26] = {};
//         for (char& ch : s) {
//             freq[ch - 'a']++;
//         }

//         vector<bool> canUse(26, false);
//         vector<int> requiredFreq(26, 0);

//         for (int i = 0; i < 26; i++) {
//             if (freq[i] >= k) {
//                 canUse[i] = true;
//                 requiredFreq[i] = freq[i] / k; // At most freq
//             }
//         }

//         int maxLength = n / k;

//         string curr;
//         backtracking(s, curr, canUse, requiredFreq, k,
//                      maxLength); // To get all the subseuqneces and check if
//                      it
//                                  // is valid accordingly

//         return result;
//     }
// };

// Improved Backtracking
// Early return concept...start by checking from lengest subsequence possible
// i.e n/k length to minus in backtracking loop...start from 'z' character i.e
// from 25th index....to have guaranteed lexographically largest subsequence
class Solution {
public:
    string result = "";

    bool isSubsequence(string& s, string& sub, int k) {
        int i = 0, j = 0, n = s.length(), m = sub.length();
        int count = 0;

        while (i < n) {
            if (s[i] == sub[j]) {
                j++;
                if (j == m) {
                    j = 0;
                    count++;
                    if (count == k)
                        return true;
                }
            }
            i++;
        }
        return false;
    }

    bool backtracking(string s, string& curr, vector<bool>& canUse,
                      vector<int>& requiredFreq, int k, int maxLen) {

        if (curr.length() == maxLen) {
            if(isSubsequence(s,curr,k)){
                result=curr;
                return true;
            }
            return false;
        }

        for (int i = 25; i >= 0; i--) {
            if (canUse[i] == false || requiredFreq[i] == 0) {
                continue;
            }
            // DO
            char ch = i + 'a';
            curr.push_back(ch);
            requiredFreq[i]--;

            // EXPLORE
            if(backtracking(s, curr, canUse, requiredFreq, k, maxLen)==true){
                return true;
            }

            // UNDO
            curr.pop_back();
            requiredFreq[i]++;
        }
        return false;
    }

    string longestSubsequenceRepeatedK(string s, int k) {

        int n = s.length();
        int freq[26] = {};
        for (char& ch : s) {
            freq[ch - 'a']++;
        }

        vector<bool> canUse(26, false);
        vector<int> requiredFreq(26, 0);

        for (int i = 0; i < 26; i++) {
            if (freq[i] >= k) {
                canUse[i] = true;
                requiredFreq[i] = freq[i] / k; // At most freq
            }
        }

        int maxLength = n / k;

        for (int len = maxLength; len >= 0; len--) {
            vector<int> tempRequiredFreq=requiredFreq;
            string curr="";
            if (backtracking(s, curr, canUse, tempRequiredFreq, k, len) ==
                true) {
                return result;
            }
        }

        return result;
    }
};

//Maxmimum subsequences length possible n/k
//n to check all those subseuqnces if they are subsequence

//T.C=O(n*(n/k)!)  
//!=factorial
//S.C=n/k
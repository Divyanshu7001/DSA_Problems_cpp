// Brute force - semi optimal approach with unordered_map
// At first create a map to store the frequency of characters in the given input
// string then start looping through according to the iterations given in input
// create another map called temp
// loop throguh the map and do the char changes accordingly
// if char is not z - put that char in the new temp map & increase its frequency
// in map including the possibility of it being in the previous map if char is z
// - add char 'a' and char 'b' in the temp map and increase their frequency
// accordingly now after one iteration move temp map to mp map to free the temp
// and update the original one

// at last get a integer type result to store the length of new map
// loop through the map and get the length added
// return res

// T.C = o(n+t)
// Suitable for small string and iterations
//  class Solution {
//  public:
//      int m = 1e9 + 7;
//      int lengthAfterTransformations(string s, int t) {
//          int n = s.length();
//          unordered_map<char, int> mp;

//         for (char& ch : s) {
//             mp[ch]++;
//         }

//         for (int count = 1; count <= t; count++) {
//             unordered_map<char, int> temp;

//             for (auto& it : mp) {
//                 char ch = it.first;
//                 int freq = it.second;

//                 if (ch != 'z') {
//                     temp[ch + 1] = (temp[ch + 1] + freq) % m;
//                 } else {
//                     temp['a'] = (temp['a'] + freq) % m;
//                     temp['b'] = (temp['b'] + freq) % m;
//                 }
//             }
//             mp = move(temp);
//         }
//         int res = 0;
//         for (auto& it : mp) {
//             res = (res + it.second) % m;
//         }
//         return res;
//     }
// };


//Replacing the unordered map with vector of size 26
//size 26 as only lowercase characters will be in the string
//index will be the characters - 0-a,1-b,2-c...
//values will be frequency

//T.C=o(t+n) and it will be the average case everytime soleving all the problems
class Solution {
public:
    int m = 1e9 + 7;
    int lengthAfterTransformations(string s, int t) {
        int n = s.length();
        // unordered_map<char, int> mp;
        vector<int> mp(26, 0);
        for (char& ch : s) {
            mp[ch - 'a']++; // Character to index presentation = character - 'a'
        }

        for (int count = 1; count <= t; count++) {
            // unordered_map<char, int> temp;
            vector<int> temp(26, 0);
            for (int i = 0; i < 26; i++) {
                char ch = i + 'a'; // index to character in vector/array = index
                                   // + 'a' as a=0,1=b,2=c ...
                int freq = mp[i];

                if (ch != 'z') {
                    temp[(ch + 1) - 'a'] = (temp[(ch + 1) - 'a'] + freq) % m;
                } else {
                    temp[0] = (temp[0] + freq) % m;
                    temp[1] = (temp[1] + freq) % m;
                }
            }
            mp = move(temp);
        }
        int res = 0;
        for (int i = 0; i < 26; i++) {
            res = (res + mp[i]) % m;
        }
        return res;
    }
};
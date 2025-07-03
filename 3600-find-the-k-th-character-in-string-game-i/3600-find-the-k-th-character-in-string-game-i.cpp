// class Solution {
// public:
//     char last = 'a';
//     string word = "a";

//     void recurse(string& word, int k) {
//         cout << word;
//         if (word.length() == k) {
//             return;
//         }
//         for (int i = 0; i < word.length(); i++) {
//             char ch = word[i];
//             cout << "Character: " << ch;
//             ch == 'z' ? last = 'a' : last = ch + 1;
//             word += last;
//             if (word.length() == k)
//                 return;
//         }

//         recurse(word, k);
//     }

//     char kthCharacter(int k) {
//         if (word.length() == k) {
//             return 'a';
//         }
//         // char out = 'a' + 1;
//         // cout << out;
//         recurse(word, k);
//         return last;
//     }
// };

class Solution {
public:
    char nextChar(char c) {
        return (c == 'z') ? 'a' : c + 1;
    }

    char kthCharacter(int k) {
        string word = "a";
        while (word.length() < k) {
            string temp;
            for (char c : word) {
                temp += nextChar(c);
            }
            word += temp;
        }
        return word[k - 1];
    }
};

class Solution {
public:
    string word = "a";

    void recurse(string& word, int k) {
        if (word.length() >= k) {
            return;
        }

        string temp;
        for (char ch : word) {
            char next = (ch == 'z') ? 'a' : ch + 1;
            temp += next;
        }
        word += temp;
        recurse(word, k);
    }

    char kthCharacter(int k) {
        if (word.length() >= k) {
            return word[k - 1];
        }

        recurse(word, k);
        return word[k-1];
    }
};

//T.C=O(k)
// class Solution {
// public:
//     char nextChar(char c) {
//         return (c == 'z') ? 'a' : c + 1;
//     }

//     char kthCharacter(int k) {
//         string word = "a";
//         while (word.length() < k) {
//             string temp;
//             for (char c : word) {
//                 temp += nextChar(c);
//             }
//             word += temp;
//         }
//         return word[k - 1];
//     }
// };

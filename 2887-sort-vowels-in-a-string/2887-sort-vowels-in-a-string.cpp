// T.C = O(Nlogn)
 class Solution {
 public:
     string sortVowels(string s) {
         vector<int> asciiValues;
         vector<int> asciiIndexes;
         for (int i = 0; i < s.length(); i++) {
             if (s[i] == 'a' || s[i] == 'A' || s[i] == 'e' || s[i] == 'E' ||
                 s[i] == 'i' || s[i] == 'I' || s[i] == 'o' || s[i] == 'O' ||
                 s[i] == 'u' || s[i] == 'U') {
                 asciiValues.push_back((int)s[i]);
                 asciiIndexes.push_back(i);
             }
         }

        if (asciiValues.size() == 0)
            return s;

        sort(asciiValues.begin(), asciiValues.end(), greater<int>());

        for (int index : asciiIndexes) {
            s[index] = asciiValues.back();
            asciiValues.pop_back();
        }
        return s;
    }
};

class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries,
                                vector<string>& dictionary) {

        vector<string> res;

        for (int i = 0; i < queries.size(); i++) {
            string queryWord = queries[i];
            for (int i = 0; i < dictionary.size(); i++) {
                string dictionaryWord = dictionary[i];
                int diff = 0;
                for (int i = 0; i < dictionaryWord.length(); i++) {
                    if (queryWord[i] != dictionaryWord[i])
                        diff++;
                    if(diff>2) break;
                }
                if (diff <= 2) {
                    res.push_back(queryWord);
                    break;
                }
            }
        }
        return res;
    }
};
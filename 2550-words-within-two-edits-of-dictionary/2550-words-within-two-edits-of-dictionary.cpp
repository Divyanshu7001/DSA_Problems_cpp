class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries,
                                vector<string>& dictionary) {

        int n = queries.size();
        vector<string> res;

        for (int i = 0; i < n; i++) {
            string queryWord = queries[i];
            for (int i = 0; i < dictionary.size(); i++) {
                string dictionaryWord = dictionary[i];
                int diff = 0;
                for (int i = 0; i < dictionaryWord.length(); i++) {
                    if (queryWord[i] != dictionaryWord[i])
                        diff++;
                }
                if (diff <= 2){
                    res.push_back(queryWord);
                    break;
                }      
            }
        }

        return res;
    }
};
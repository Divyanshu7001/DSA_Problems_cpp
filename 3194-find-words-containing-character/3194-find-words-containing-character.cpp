class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        int n = words.size();
        vector<int> result;

        //[]=lambda capture
        //()=parameter
        auto lambda = [&x](char ch) { return ch == x; };

        for (int i = 0; i < n; i++) {
            if (any_of(begin(words[i]), end(words[i]), lambda) == true) {
                result.push_back(i);
            }
        }
        return result;
    }
};
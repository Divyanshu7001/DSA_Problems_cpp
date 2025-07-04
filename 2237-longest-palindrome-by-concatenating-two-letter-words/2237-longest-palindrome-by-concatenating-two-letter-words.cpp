class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> mp;

        int result=0;

        for(string word:words){
            string reversedWord=word;
            swap(reversedWord[0],reversedWord[1]);

            if(mp[reversedWord]>0){
                result+=4;
                mp[reversedWord]--;
            }
            else{
                mp[word]++;
            }
        }

        //check equal character words,edge case
        for(auto &it:mp){
            string word=it.first;
            int count=it.second;

            if(word[0]==word[1]&&count>0){
                result+=2;
                break;
            }
        }

        return result;
    }
};
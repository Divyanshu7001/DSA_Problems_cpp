class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        
        for(char ch:letters){
            if((int)ch>(int)target)return ch;
        }
        return letters[0];
    }
};
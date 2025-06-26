class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n=s.length(); 

        long long powerValue=1;//2^0
        int length=0;

        for(int i=n-1;i>=0;i--){
            if(s[i]=='0'){
                length++;
            }
            else if(powerValue<=k){
                k-=powerValue;
                length++;
            }

            if(powerValue<=k){
                powerValue*=2;
            }
        }
        return length;

    }
};
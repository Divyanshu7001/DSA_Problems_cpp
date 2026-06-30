class Solution {
public:
    int numberOfSubstrings(string s) {
        int i=0,j=0,ans=0;
        int n=s.size();
        unordered_map<char,int>mp;
        while(j<s.size()){
            mp[s[j]]++;
            while(mp.size()==3){
                ans+=(n-j);
                mp[s[i]]--;
                if(mp[s[i]]==0)mp.erase(s[i]);
                i++;
            }
            j++;
        }
        return ans;
    }
};

//TLE
// class Solution {
// public:
//     int solve(string s) {
//         bool gotA = false, gotB = false, gotC = false;

//         for (int i = 0; i < s.length(); i++) {
//             char ch = s[i];

//             if (ch == 'a')
//                 gotA = true;
//             else if (ch == 'b')
//                 gotB = true;
//             else if (ch == 'c')
//                 gotC = true;

//             if (gotA && gotB && gotC)
//                 return 1;
//         }

//         return gotA && gotB && gotC ? 1 : 0;
//     }


//     int numberOfSubstrings(string s) {
//         int n = s.length();

//         int res = 0;
//         for (int i = 0; i < n; i++) {
//             for (int len = 1; len <= n - i; len++) {
//                 res += solve(s.substr(i, len));
//             }
//         }

//         return res;
//     }
// };
class Solution {
public:
    int countPalindromicSubsequence(string s) {

        unordered_map<char, vector<int>> mp;
        int n=s.length();

        for (int i=0;i<n;i++) {
            // Ensure vector is initialized with {-1, -1}
            if (mp[s[i]].empty()) {
                mp[s[i]] = vector<int>(2, -1);
            }
            // First occurrence
            if (mp[s[i]][0] == -1) {
                mp[s[i]][0] = i;
            }
            // Update last occurrence
            mp[s[i]][1] = i;
        }

        int count = 0;
        for (auto& p : mp) {
            if(p.second[0]==p.second[1])continue;
            unordered_set<char>distinct;

            for(int i=p.second[0]+1;i<p.second[1];i++){
                distinct.insert(s[i]);
            }
            count+=distinct.size();
        }

        return count;
    }
};
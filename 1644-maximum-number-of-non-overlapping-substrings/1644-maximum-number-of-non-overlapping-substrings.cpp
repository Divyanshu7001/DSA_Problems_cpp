class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.length();
        vector<int> leftmost(26, n);
        vector<int> rightmost(26, -1);
        
        // Step 1: Record first and last occurrence of each character
        for (int i = 0; i < n; ++i) {
            int c = s[i] - 'a';
            leftmost[c] = min(leftmost[c], i);
            rightmost[c] = max(rightmost[c], i);
        }
        
        auto getValidRight = [&](int i) {
            int right = rightmost[s[i] - 'a'];
            for (int j = i; j <= right; ++j) {
                // If any character inside has an occurrence before 'i', it's invalid
                if (leftmost[s[j] - 'a'] < i) {
                    return -1;
                }
                right = max(right, rightmost[s[j] - 'a']);
            }
            return right;
        };
        
        vector<string> ans;
        int last_right = -1;
        
        // Greedy pick valid non-overlapping substrings
        for (int i = 0; i < n; ++i) {
            // Only check when we are at the first occurrence of a character
            if (i == leftmost[s[i] - 'a']) {
                int new_right = getValidRight(i);
                if (new_right == -1) continue;
                
                // If it overlaps with the previous interval, update the previous one 
                // (greedy choice to minimize total length)
                if (i <= last_right && !ans.empty()) {
                    ans.back() = s.substr(i, new_right - i + 1);
                } else {
                    ans.push_back(s.substr(i, new_right - i + 1));
                }
                last_right = new_right;
            }
        }
        
        return ans;
    }
};
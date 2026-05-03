class Solution {
public:
    int n;
    bool isMatch(string& s, string& goal, int idx) {
        int i = 1;
        while (i < n) {
            if (s[(idx + 1) % n] == goal[i]) {
                idx++;
                i++;
            } else
                return false;
        }
        return true;
    }

    bool rotateString(string s, string goal) {
        if (s.length() != goal.length())
            return false;
        n = s.length();
        vector<int> idxList;
        for (int i = 0; i < n; i++) {
            if (s[i] == goal[0])
                idxList.push_back(i);
        }
        for (int& idx : idxList) {
            if (isMatch(s, goal, idx))
                return true;
        }

        return false;
    }
};
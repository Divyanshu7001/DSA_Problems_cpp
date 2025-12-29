// CLassic Backtracking Problem example
// Multiple choices and paths possible & we need to find one possible solution
class Solution {
public:
    unordered_map<string, bool> t;
    bool solve(string curr, unordered_map<string, vector<char>>& mp, int idx,
               string above) {

        if (curr.length() == 1)
            return true;

        string key = curr + "_" + to_string(idx) + "_" + above;

        if (t.count(key))
            return t[key];

        if (idx == curr.length() - 1)
            return t[key] = solve(above, mp, 0, "");
        // reached end index of current  string,so calling
        // the solve again with above as current for that &
        // empty string as above for that

        string pair = curr.substr(idx, 2);

        if (mp.find(pair) == mp.end())
            return t[key] = false;

        for (char& ch : mp[pair]) {
            above.push_back(ch); // attached with above (DO)

            if (solve(curr, mp, idx + 1, above) == true)
                return t[key] = true; // EXPLORE

            above.pop_back(); // UNDO
        }

        return t[key] = false;
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {

        unordered_map<string, vector<char>> mp;

        for (auto& pattern : allowed) {
            mp[pattern.substr(0, 2)].push_back(pattern[2]); // ab->{c}
        }

        return solve(bottom, mp, 0, "");
    }
};
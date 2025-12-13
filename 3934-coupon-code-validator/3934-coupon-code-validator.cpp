class Solution {
public:
    vector<pair<string, string>> temp;
    unordered_map<string, int> priority = {
        {"electronics", 0}, {"grocery", 1}, {"pharmacy", 2}, {"restaurant", 3}};

    bool isValidCode(string str) {
        for (char ch : str) {
            if (!isalpha(ch) && !isdigit(ch) && ch != '_')
                return false;
        }
        return true;
    }
    vector<string> validateCoupons(vector<string>& code,
                                   vector<string>& businessLine,
                                   vector<bool>& isActive) {
        for (int i = 0; i < code.size(); i++) {
            if (code[i] != "" && isValidCode(code[i]) &&
                priority.count(businessLine[i]) && isActive[i] == true)
                temp.push_back({businessLine[i], code[i]});
        }

        sort(temp.begin(), temp.end(), [&](const auto& a, const auto& b) {
            if (priority[a.first] != priority[b.first])
                return priority[a.first] <
                       priority[b.first]; // businessLine order
            return a.second < b.second;   // lexicographical code order
        });

        vector<string> res;
        for (auto& p : temp)
            res.push_back(p.second);
        return res;
    }
};
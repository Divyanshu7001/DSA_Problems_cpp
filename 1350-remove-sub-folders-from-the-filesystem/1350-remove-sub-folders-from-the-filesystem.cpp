// Logic:
// Sort the folders vector to have the folder structures given in ascending
// order define string type vector & push the folder[0] as first given folder
// will always be a parent loop over..check and match if the current folder
// structure string is equals to the last added string in the result vector if
// matches and we can find it..then continue else add this current in result

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {

        sort(folder.begin(), folder.end());
        vector<string> result;

        for (const auto& a : folder) {
            if (result.empty())
                result.push_back(a);
            else {
                const string& prev = result.back();
                if (a.find(prev) == 0 && a.size() > prev.size() &&
                    a[prev.size()] == '/') {
                    continue;
                } else
                    result.push_back(a);
            }
        }
        return result;
    }
};
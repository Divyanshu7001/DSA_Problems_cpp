// Construct trie
// Populate tree (subfolders):
/// DO recursion: bottom up where the current node sends it sub-directory data
/// upwards to parent create a subfolder map to have a track of the matching
/// sub-directories / duplicates
// Removal of duplicates
// Reconstruct the trie

class Solution {
public:
    struct Node {
        string val;       // Value to store
        string subfolder; // Store subfolder structure
        unordered_map<string, Node*> children;
    };

    Node* getNode(string val) {
        Node* temp = new Node();
        temp->val = val;
        temp->subfolder = "";

        return temp;
    }

    void insert(Node* root, vector<string>& path) {
        for (auto& folder : path) {
            if (!root->children.count(folder)) {
                root->children[folder] = getNode(folder);
            }

            root = root->children[folder];
        }
    }

    string populateNodes(Node* root, unordered_map<string, int>& subfolderMap) {

        vector<pair<string, string>> subfolderPaths;

        for (auto& [childName, child] : root->children) {
            string subfolderResult = populateNodes(child, subfolderMap);
            subfolderPaths.push_back({childName, subfolderResult});
        }

        sort(begin(subfolderPaths), end(subfolderPaths));

        string completePath = ""; // This is the subfolder of current node which
                                  // we will form from the children paths
        for (auto& [childName, childPath] : subfolderPaths) {
            completePath +=
                "(" + childName + childPath +
                ")"; // This structure is built to not get caught in the test
                     // cases where the subfolder structure might show same due
                     // to multiple sub directories under them..but they are not
                     // really same
        }

        root->subfolder = completePath;

        if (!completePath.empty()) {
            subfolderMap[completePath]++;
        }

        return completePath;
    }

    void removeDuplicates(Node* root,
                          unordered_map<string, int>& subfolderMap) {
        for (auto it = root->children.begin(); it != root->children.end();) {
            string childName = it->first;
            Node* child = it->second;

            if (!child->subfolder.empty() &&
                subfolderMap[child->subfolder] > 1) {
                it = root->children.erase(it);
            } else {
                removeDuplicates(child, subfolderMap);
                it++;
            }
        }
    }

    void constructResult(Node* root, vector<string>& path,
                         vector<vector<string>>& result) {
        for (auto& [childName, child] : root->children) {
            path.push_back(childName);
            result.push_back(path);
            constructResult(child, path, result);
            path.pop_back();
        }
    }

    vector<vector<string>>
    deleteDuplicateFolder(vector<vector<string>>& paths) {

        Node* root = getNode("/");

        // Construct trie
        for (auto& path : paths) {
            insert(root, path);
        }

        unordered_map<string, int> subfolderMap;
        populateNodes(root, subfolderMap);

        removeDuplicates(root, subfolderMap);

        vector<vector<string>> result;
        vector<string> path;
        constructResult(root, path, result);

        return result;
    }
};
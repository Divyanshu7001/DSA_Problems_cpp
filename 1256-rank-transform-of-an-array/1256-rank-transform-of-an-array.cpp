class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if (arr.size() == 0)
            return {};

        int n = arr.size();

        map<int, vector<int>> mp;

        for (int i = 0; i < n; i++)
            mp[arr[i]].push_back(i);
        

        vector<int> res(n, 0);
        int rnk = 1;

        for (auto& p : mp) {
            int num = p.first;
            for (int&idx : p.second)
                res[idx] = rnk;

            rnk++;
        }

        return res;
    }
};

// Cant win against negative nos.
//  class Solution {
//  public:
//      vector<int> arrayRankTransform(vector<int>& arr) {
//          if (arr.size() == 0)
//              return {};

//         int maxEle = *max_element(arr.begin(), arr.end()), n = arr.size();

//         vector<vector<int>> idxList(maxEle + 1);

//         for (int i = 0; i < n; i++) {
//             idxList[arr[i]].push_back(i);
//         }

//         vector<int> res(n, 0);
//         int rnk = 1;

//         for (int i = 0; i < idxList.size(); i++) {
//             if (idxList[i].size() == 0)
//                 continue;

//             const vector<int>& list = idxList[i];
//             for (int idx : list)
//                 res[idx] = rnk;

//             rnk++;
//         }

//         return res;
//     }
// };
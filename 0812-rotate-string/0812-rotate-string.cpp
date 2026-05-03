//T.C=O(N),S.C=O(1)
//Concat to itself as after 1 full round,,it becomes the same string..then find the goal as substring in it
class Solution {
public:
    bool rotateString(string& s, string& goal) {
        return s.size()==goal.size() && (s+s).find(goal)!=-1;
    }
};

//T.C=O(n2),S.C=O(N)
// class Solution {
// public:
//     int n;
//     bool isMatch(string& s, string& goal, int idx) {
//         int i = 1;
//         while (i < n) {
//             if (s[(idx + 1) % n] == goal[i]) {
//                 idx++;
//                 i++;
//             } else
//                 return false;
//         }
//         return true;
//     }

//     bool rotateString(string s, string goal) {
//         if (s.length() != goal.length())
//             return false;

//         n = s.length();
//         vector<int> idxList;
//         for (int i = 0; i < n; i++) {
//             if (s[i] == goal[0])
//                 idxList.push_back(i);
//         }
//         for (int& idx : idxList) {
//             if (isMatch(s, goal, idx))
//                 return true;
//         }

//         return false;
//     }
// };
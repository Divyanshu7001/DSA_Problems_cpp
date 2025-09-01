//T.C = O(N+KâLog(N))
// class Solution {
// public:
//     double maxGainPossible(int a, int b) {
//         return (double)(a + 1) / (b + 1) - (double)a / b;
//     }

//     double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
//         int n = classes.size();
//         priority_queue<pair<double, vector<int>>> pq;

//         for (auto& c : classes) {
//             pq.push({maxGainPossible(c[0], c[1]), {c[0], c[1]}});
//         }

//         while (extraStudents > 0) {
//             auto top = pq.top();
//             pq.pop();

//             int passingStudents = top.second[0];
//             int totalStudents = top.second[1];
//             passingStudents++;
//             totalStudents++;

//             pq.push({maxGainPossible(passingStudents, totalStudents),
//                      {passingStudents, totalStudents}});
//             extraStudents--;
//         }

//         double result = 0.0;
//         while (!pq.empty()) {
//             auto top = pq.top();
//             pq.pop();
//             result += (double)top.second[0] / top.second[1];
//         }

//         return result / n;
//     }
// };

//Optimized overhead reduced with lambda gain expression approach and pair,pair instead of pair & vector in pq
//Not me => from chatgpt
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto gain = [](int a, int b) {
            return (double)(a + 1) / (b + 1) - (double)a / b;
        };

        int n = classes.size();
        priority_queue<pair<double, pair<int,int>>> pq;

        for (auto& c : classes) {
            pq.push({gain(c[0], c[1]), {c[0], c[1]}});
        }

        for (int i = 0; i < extraStudents; i++) {
            auto [g, cls] = pq.top();
            pq.pop();

            int pass = cls.first + 1;
            int total = cls.second + 1;

            pq.push({gain(pass, total), {pass, total}});
        }

        double result = 0.0;
        while (!pq.empty()) {
            auto [g, cls] = pq.top();
            pq.pop();
            result += (double)cls.first / cls.second;
        }

        return result / n;
    }
};

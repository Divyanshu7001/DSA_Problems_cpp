class Solution {
public:
    double maxGainPossible(int a, int b) {
        return (double)(a + 1) / (b + 1) - (double)a / b;
    }

    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();
        priority_queue<pair<double, vector<int>>> pq;

        for (auto& c : classes) {
            pq.push({maxGainPossible(c[0], c[1]), {c[0], c[1]}});
        }

        while (extraStudents > 0) {
            auto top = pq.top();
            pq.pop();

            int passingStudents = top.second[0];
            int totalStudents = top.second[1];
            passingStudents++;
            totalStudents++;

            pq.push({maxGainPossible(passingStudents, totalStudents),
                     {passingStudents, totalStudents}});
            extraStudents--;
        }

        double result = 0.0;
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            result += (double)top.second[0] / top.second[1];
        }

        return result / n;
    }
};

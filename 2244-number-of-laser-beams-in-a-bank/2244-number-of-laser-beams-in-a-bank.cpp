class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int> deviceCounts;

        // Count number of '1's in each non-empty row
        for (auto& row : bank) {
            int count = count_if(row.begin(), row.end(),
                                 [](char c) { return c == '1'; });
            if (count > 0)
                deviceCounts.push_back(count);
        }

        int beams = 0;
        // Multiply consecutive non-empty rows
        for (int i = 1; i < deviceCounts.size(); ++i)
            beams += deviceCounts[i - 1] * deviceCounts[i];

        return beams;
    }
};
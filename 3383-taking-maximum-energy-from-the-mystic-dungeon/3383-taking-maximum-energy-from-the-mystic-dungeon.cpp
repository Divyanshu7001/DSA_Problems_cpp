class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {

        int n = energy.size();

        for (int i = n-1; i >= 0; i--) {
            if (i + k < n)
                energy[i] += energy[i + k];
        }

        return *max_element(energy.begin(), energy.end());
    }
};
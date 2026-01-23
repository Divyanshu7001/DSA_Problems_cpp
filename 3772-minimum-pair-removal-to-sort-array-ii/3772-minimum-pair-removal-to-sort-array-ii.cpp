class Solution {
public:
    typedef long long ll;
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();

        // the resultant sum values might be more than int..so taking long long
        vector<ll> temp(n);
        for (int i = 0; i < n; i++)
            temp[i] = nums[i];

        set<pair<ll, int>> minPairSet;

        vector<int> prevIndex(n);
        vector<int> nextIndex(n);

        for (int i = 0; i < n; i++) {
            nextIndex[i] = i + 1;
            prevIndex[i] = i - 1;
        }

        int badPairs = 0; // indicator of array got sorted or not..until not
                          // sorted we need to do the operations
        for (int i = 0; i < n - 1; i++) {
            if (temp[i] > temp[i + 1])
                badPairs++;

            minPairSet.insert({temp[i] + temp[i + 1], i});
        }

        int op = 0;
        while (badPairs > 0) {
            int first = minPairSet.begin()->second;
            int second = nextIndex[first];

            int first_left = prevIndex[first], second_right = nextIndex[second];

            minPairSet.erase(begin(minPairSet));

            if (temp[first] > temp[second])
                badPairs--;

            // Managing effects of deletion in the neighbouring indexes

            //(d,(a,b))
            if (first_left >= 0) {
                if (temp[first_left] > temp[first] &&
                    temp[first_left] <= temp[first] + temp[second]) {
                    // bad pair became good
                    badPairs--;
                } else if (temp[first_left] <= temp[first] &&
                           temp[first_left] > temp[first] + temp[second]) {
                    // good pair became bad
                    badPairs++;
                }
            }

            //((a,b),d)
            if (second_right < n) {
                if (temp[second_right] < temp[second] &&
                    temp[second_right] >= temp[first] + temp[second]) {
                    // bad pair became good
                    badPairs--;
                } else if (temp[second_right] >= temp[second] &&
                           temp[second_right] < temp[first] + temp[second]) {
                    // good pair became bad
                    badPairs++;
                }
            }

            // Delete the neighbouring index pairs with the initial pair that
            // was deleted
            if (first_left >= 0) {
                minPairSet.erase({temp[first_left] + temp[first], first_left});
                minPairSet.insert(
                    {temp[first_left] + temp[first] + temp[second],
                     first_left});
            }

            if (second_right < n) {
                minPairSet.erase({temp[second] + temp[second_right], second});
                minPairSet.insert(
                    {temp[first] + temp[second] + temp[second_right], first});
                prevIndex[second_right] = first;
            }

            nextIndex[first] = second_right;
            temp[first] += temp[second];

            op++;
        }
        return op;
    }
};
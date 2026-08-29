class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {

        int n = nums.size();

        vector<int> vec = nums;
        // sort vec
        sort(vec.begin(), vec.end());

        int groupNum = 0;
        unordered_map<int, int> numToGrp;
        numToGrp[vec[0]] = groupNum;

        unordered_map<int, list<int>>
            groupToList; // list-> linked list..why? because popping from front
                         // in vector is o(n)..which is TLE..but for list(here
                         // head and tail is maintained...so push and pop both
                         // are o(1))
        groupToList[groupNum].push_back(vec[0]);

        // grouping
        for (int i = 1; i < n; i++) {
            if (abs(vec[i] - vec[i - 1]) > limit)
                groupNum++;
            numToGrp[vec[i]] = groupNum;
            groupToList[groupNum].push_back(vec[i]);
        }

        // build the answer-> merge the groups
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            int group = numToGrp[num];

            // smallest number of the group
            // derefence..in case of list..dont have front...use begin() &
            // dereferenve
            res[i] = *(groupToList[group].begin());
            groupToList[group].pop_front();
        }
        return res;
    }
};
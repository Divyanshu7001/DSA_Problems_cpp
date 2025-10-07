class Solution {
public:

    vector<int> avoidFlood(vector<int>& rains) {

        int n = rains.size();
        unordered_map<int, int> mp; // lake->first day it rains
        set<int> st;                // zero days in sorted fashion

        vector<int> ans(n, 1);

        for (int i = 0; i < n; i++) {
            int lake = rains[i];

            if (lake == 0) {
                st.insert(i); // ith no rain day
            } else {
                ans[i] = -1;
                // also check if this lake already has water, if does..check if
                // we can dry it up

                if (mp.count(lake)) { // it already has water
                    auto it = st.lower_bound(mp[lake]);

                    if (it == st.end()) { // we cant dry it and it will flood
                        return {};
                    }

                    // The day on which no rain happened
                    int day = *it;
                    ans[day] = lake;
                    st.erase(it);
                }
            }

            mp[lake] = i; // ith day it rain on lake
        }
        return ans;
    }
};
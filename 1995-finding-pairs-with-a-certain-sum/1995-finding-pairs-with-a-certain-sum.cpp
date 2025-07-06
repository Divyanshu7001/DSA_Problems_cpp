class FindSumPairs {
public:
    vector<int> vec1, vec2;
    unordered_map<int, int> mp;
    // T.C=O(m+n)
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        vec1 = nums1; // O(m)
        vec2 = nums2; // O(n)
        for (int& num :
             nums2) { // length of nums2 is 100 times bigger from
                      // constraints..so better keep it in a map to work forward
            // O(n)
            mp[num]++;
        }
    }

    // O(1)
    // Just updating at index
    void add(int index, int val) {
        mp[vec2[index]]--;
        vec2[index] += val;
        mp[vec2[index]]++;
    }

    // O(n)s
    int count(int tot) {
        int c = 0;
        for (int& x : vec1) {
            c += mp[tot - x];
        }

        return c;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
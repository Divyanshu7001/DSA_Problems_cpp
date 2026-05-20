class Solution {
public:
    int n;
    unordered_set<int> st;

    int solve(int idx, vector<int>& A, vector<int>& B) {
        if (A[idx] == B[idx])
            return 1;

        int val = 0;
        if (st.empty()) {
            st.insert(A[idx]);
            st.insert(B[idx]);
            return 0;
        }

        if (st.count(A[idx])) {
            val++;
            st.erase(A[idx]);
        } else
            st.insert(A[idx]);

        if (st.count(B[idx])) {
            val++;
            st.erase(B[idx]);
        } else
            st.insert(B[idx]);

        return val;
    }

    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        n = A.size();
        vector<int> ans(n, 0);

        int prev = 0;
        for (int i = 0; i < n; i++) {
            ans[i] = prev + solve(i, A, B);
            prev = ans[i];
        }

        return ans;
    }
};
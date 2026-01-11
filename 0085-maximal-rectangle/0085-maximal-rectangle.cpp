class Solution {
public:
    vector<int> getNSR(vector<int>& heights) {

        stack<int> st;
        int n = heights.size();

        vector<int> NSR(n);

        for (int i = n - 1; i >= 0; i--) {
            if (st.empty()) {
                NSR[i] = n; // out of bound index right side
            } else {
                while (!st.empty() && heights[st.top()] >= heights[i]) {
                    st.pop();
                }

                if (st.empty()) {
                    NSR[i] = n;
                } else
                    NSR[i] = st.top();
            }
            st.push(i);
        }
        return NSR;
    }

    vector<int> getNSL(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();

        vector<int> NSL(n);

        for (int i = 0; i < n; i++) {
            if (st.empty()) {
                NSL[i] = -1; // out of bound index left side
            } else {
                while (!st.empty() && heights[st.top()] >= heights[i]) {
                    st.pop();
                }

                if (st.empty()) {
                    NSL[i] = -1;
                } else
                    NSL[i] = st.top();
            }
            st.push(i);
        }
        return NSL;
    }

    int findMaxArea(vector<int>& heights) {
        // width=NSR[i]-NSL[i]-1
        // height=heights[i]

        vector<int> NSR = getNSR(heights);
        vector<int> NSL = getNSL(heights);

        int n = heights.size();

        vector<int> width(n);
        for (int i = 0; i < n; i++) {
            width[i] = NSR[i] - NSL[i] - 1;
        }
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            int a = heights[i] * width[i];

            maxArea = max(maxArea, a);
        }

        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {

        int m = matrix.size(), n = matrix[0].size();

        vector<int> heights(n);

        for (int i = 0; i < n; i++) {
            heights[i] = (matrix[0][i] == '1') ? 1 : 0;
        }

        int maxArea = findMaxArea(heights);

        for (int row = 1; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (matrix[row][col] == '0') {
                    heights[col] = 0;
                } else
                    heights[col] += 1;
            }
            maxArea = max(maxArea, findMaxArea(heights));
        }
        return maxArea;
    }
};
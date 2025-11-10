//Brute force..TLE
// class Solution {
// public:
//     int minOperations(vector<int>& nums) {

//         unordered_set<int> st(nums.begin(), nums.end());

//         int n = nums.size();
//         int op = 0;

//         for (int target : st) {
//             if (target == 0)
//                 continue;

//             bool flow = false;
//             for (int i = 0; i < n; i++) {
//                 if (nums[i] == target) {
//                     if (!flow) {
//                         flow = true;
//                         op++;
//                     }
//                 } else if (nums[i] < target)
//                     flow = false;
//             }
//         }
//         return op;
//     }
// };

//Monotonic Increasing Stack
//As we are touching every element at most 2 times...T.C=(2*n)=>O(n)
class Solution {
public:
    int minOperations(vector<int>& nums) {

        stack<int> st;
        int op = 0;

        for(int i=0;i<nums.size();i++){
            while(!st.empty()&&st.top()>nums[i]){
                st.pop();
            }

            if(nums[i]==0)continue;

            if(st.empty()||st.top()<nums[i]){
                st.push(nums[i]);
                op++;
            }   
        }
        return op;
    }
};
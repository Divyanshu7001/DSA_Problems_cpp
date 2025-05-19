// Map Approach of adding elements and checking size
// class Solution {
// public:
//     string triangleType(vector<int>& nums) {
//         if (nums[0] + nums[1] > nums[2] && nums[0] + nums[2] > nums[1] &&
//             nums[1] + nums[2] > nums[0]) {
//             unordered_map<int, int> store;
//             for (int i = 0; i < nums.size(); i++) {
//                 if (store.find(nums[i])==store.end()){
//                     store[nums[i]] = store[nums[i]] + 1;       
//                 }
//             }
//             if(store.size()==1){
//                 return "equilateral";
//             }
//             else if(store.size()==2){
//                 return "isosceles";
//             }
//             else 
//                 return "scalene";
//         } else {
//             return "none";
//         }
//     }
// };

//Just the simple approach
class Solution {
public:
    string triangleType(vector<int>& nums) {
        int a = nums[0], b = nums[1], c = nums[2];

        if(a + b > c && b + c > a && a + c > b) {
            if(a == b && b == c && c == a) return "equilateral";
            else if((a == b) || (b == c) || (c == a)) return "isosceles";
            return "scalene";
        }
        return "none";
    }
};
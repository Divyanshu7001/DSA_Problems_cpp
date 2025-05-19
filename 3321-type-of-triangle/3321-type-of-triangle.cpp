class Solution {
public:
    string triangleType(vector<int>& nums) {
        if (nums[0] + nums[1] > nums[2] && nums[0] + nums[2] > nums[1] &&
            nums[1] + nums[2] > nums[0]) {
            unordered_map<int, int> store;
            for (int i = 0; i < nums.size(); i++) {
                if (store.find(nums[i])==store.end()){
                    store[nums[i]] = store[nums[i]] + 1;       
                }
            }
            if(store.size()==1){
                return "equilateral";
            }
            else if(store.size()==2){
                return "isosceles";
            }
            else 
                return "scalene";
        } else {
            return "none";
        }
    }
};
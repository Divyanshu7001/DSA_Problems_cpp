class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int>res;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int target=nums[i],c=0;
            for(int j=0;j<n;j++){
                if(nums[j]<target)c++;
            }
            res.push_back(c);
        }        
        return res;
    }
};
// class Solution {
// public:
//     vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
//         set<int, greater<int>> s(nums.begin(),nums.end());

//         vector<int>res;
//         int i=1;
//         for(int n:s){
//             res.push_back(s.size()-i);
//             i++;
//         }
//         return res;
//     }
// };
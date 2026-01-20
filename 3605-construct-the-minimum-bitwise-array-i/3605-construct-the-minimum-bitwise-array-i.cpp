class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int>res;
        for(int num:nums){
            bool found=false;
            for(int i=1;i<num;i++){
                if((i|(i+1))==num){
                    res.push_back(i);
                    found=true;
                    break;
                }
            }
            if(!found)res.push_back(-1);
        }
        return res;
    }
};
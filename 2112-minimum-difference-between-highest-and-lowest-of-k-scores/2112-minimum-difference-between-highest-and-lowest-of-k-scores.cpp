class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if (k == 1)
            return 0;
        sort(nums.begin(), nums.end());
        int res=INT_MAX;
        int i=0,j=k-1;

        while(j<nums.size()){
            int minL=nums[i],maxL=nums[j];
            res=min(res,maxL-minL);
            
            i++;
            j++;
        }
        return res;
    }
};
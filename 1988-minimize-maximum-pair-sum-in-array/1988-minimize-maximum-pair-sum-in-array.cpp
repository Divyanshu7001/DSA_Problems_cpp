// The maximal pair sum has to be minimized
// thats why we will try to put the biggest number with smallest one possible
// and keep going forward accordingly
class Solution {
public:
    int minPairSum(vector<int>& nums) {

        sort(nums.begin(),nums.end());

        int i=0,j=nums.size()-1,res=INT_MIN;
        while(i<j){
            int sum = nums[i]+nums[j];
            res=max(res,sum);
            i++;
            j--;
        }

        return res;
    }
};
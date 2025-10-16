class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        
        unordered_map<int,int>mp;

        for(int &num:nums){
            int res=((num%value)+value)%value; //+value)%value to handle the negative number cases
            mp[res]++;
        }

        int MEX=0;

        while(mp[(MEX%value)]>0){
            mp[MEX%value]--;
            MEX++;
        }

        return MEX;

    }
};
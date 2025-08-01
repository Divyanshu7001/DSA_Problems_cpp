class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>result={{1}};
        vector<int>prev={1};
        for(int i=2;i<=numRows;i++){
            vector<int>temp;
            temp.push_back(prev[0]);
            for(int j=1;j<=prev.size();j++){
                if(j==prev.size()){
                    temp.push_back(prev[j-1]);
                }else{
                    temp.push_back(prev[j-1]+prev[j]);
                }
            }
            result.push_back(temp);
            prev=temp;
            temp.clear();
        }
        return result;
    }
};
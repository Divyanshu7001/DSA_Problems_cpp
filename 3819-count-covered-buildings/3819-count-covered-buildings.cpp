class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        
        unordered_map<int,set<int>>mp_x,mp_y;

        for(auto building:buildings){
            mp_x[building[0]].insert(building[1]);
            mp_y[building[1]].insert(building[0]);
        }

        int count=0;
        for(auto i:buildings){
            int x=i[0],y=i[1];

            //the coordinate stored shouldnt be the extremes as that says there is no surrounding
            if(*mp_x[x].begin()==y||*mp_y[y].begin()==x)continue;
            if(*mp_x[x].rbegin()==y||*mp_y[y].rbegin()==x)continue;

            count++;
        }

        return count;

    }
};
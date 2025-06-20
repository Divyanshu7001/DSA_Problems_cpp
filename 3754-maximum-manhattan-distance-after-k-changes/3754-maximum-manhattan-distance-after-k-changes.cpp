//As distance wanted from origin
//M.D=|x|+|y|
//Horizontal net distance=|E-W|
//Vertical Net Distance=|N-S|
//One modfication gives +2 steps increment

class Solution {
public:
    int maxDistance(string s, int k) {
        
        int maxMD=0;
        int east=0,west=0,south=0,north=0;

        for(int i=0;i<s.length();i++){
            if(s[i]=='E')east++;
            else if(s[i]=='W')west++;
            else if(s[i]=='S')south++;
            else if(s[i]=='N')north++;

            int currentMD=abs(east-west)+abs(north-south);
            int steps=i+1;
            int wastedSteps=steps-currentMD;

            int extraStepsNeeded=0;
            if(wastedSteps!=0){
                extraStepsNeeded=min(2*k,wastedSteps);
            }

            int finalCurrentMD=currentMD+extraStepsNeeded;

            maxMD=max(maxMD,finalCurrentMD);
        }

        return maxMD;
    }
};
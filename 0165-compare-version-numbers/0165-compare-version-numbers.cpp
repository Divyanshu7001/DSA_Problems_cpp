class Solution {
public:
    int compareVersion(string version1, string version2) {
        
        int i=0,j=0,n1=version1.size(),n2=version2.size();

        while(i<n1||j<n2){
            string temp1="",temp2="";

            while(i<n1&&version1[i]!='.'){
                temp1+=version1[i];
                i++;
            }

            while(j<n2&&version2[j]!='.'){
                temp2+=version2[j];
                j++;
            }

            i++,j++;

            int num1=temp1.empty()?0:stoi(temp1);
            int num2=temp2.empty()?0:stoi(temp2);

            if(num1<num2)return -1;
            if(num1>num2)return 1;
        }

        return 0;
    }
};
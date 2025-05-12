class Solution {
public:
    //Divide the 3 digit numbers into Hundreds,Tens & Ones.
    //Hundreds place- 1 to 9 can be taken to avoid leading 0
    //Tens place- 0 to 9 available
    //Ones place- 2,4,6,8 available to make the whole number even

    //Have an constant size array like array[10] to store the frequency of every element in given digits array
    //Now do nested loop accordingly 
    //If the current loop index number is not available in digits array..continue
    //if the current loop index number is available in digits array 
    //Decrease the frequency once & take combinations for that perticular number..no need to check for even
    //push the number in a vector called result
    //return the result vector at last..no need of sorting  as the numbers is created in ascending order

    //T.C=o(1)
    //S.C=o(1)

    vector<int> findEvenNumbers(vector<int>& digits) {
   
        
        vector<int> result;
        vector<int> counter(10,0);

        for(int &digit:digits){
            counter[digit]++;
        }

        for(int i=1;i<=9;i++){
            if(counter[i]==0)
               continue;
            counter[i]--;//Decrease the frequency here as we are going to use it and get its combinations
            for(int j=0;j<=9;j++){
                if(counter[j]==0)
                   continue;
                counter[j]--;//Similar to i...decrease the frequency as we are gonna use it
                for(int k=0;k<=8;k+=2){
                    if(counter[k]==0)
                       continue;
                    counter[k]--;//we are using it to make the number right after this..so reduce to make the number
                    int num=i*100+j*10+k;
                    result.push_back(num);

                    counter[k]++;//Increase the frequency for next iteration
                }
                counter[j]++;//Increase the freq. for next iteration and for inner of i
            }
            counter[i]++;
        }
        return result;
    }
};
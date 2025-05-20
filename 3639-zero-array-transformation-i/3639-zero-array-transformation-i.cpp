// Simple simulation approach
// Memory limit exceed problem
// T.C=O(queries size * nums size)
//  class Solution {
//  public:
//      bool isVectorZero(const std::vector<int>& vec) {
//          for (int element : vec) {
//              if (element != 0) {
//                  return false;
//              }
//          }
//          return true;
//      }
//      vector<int> simulateQueries(vector<int>&num,int startingIndex,int
//      endingIndex){
//          for(int i=startingIndex;i<=endingIndex;i++){
//              num[i]--;
//              if(num[i]<0){
//                  num[i]=0;
//              }
//          }
//          return num;
//      }
//      bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
//          for (auto pair : queries) {
//              vector<int>updatedVector=simulateQueries(nums,pair[0],pair[1]);
//              if(isVectorZero(updatedVector)){
//                  return true;
//              }
//              nums=updatedVector;
//          }
//          return false;
//      }
//  };

// Optimized array difference approach
// take one vector of size same with nums
// according to the queriy numbers..do the plus/minus accordingly in the new
// array startig index will be plus ending index + 1 will have a minus 1 in case
// that it doesnt go out of bound at last when all the queries is finished match
// the new vector with the nums vector

// T>C=O(Q+N)
// S.C=O(N+N)
class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        // STEP-1: make the difference array using the queries
        vector<int> diff(n, 0);

        for (auto query : queries) {
            int start = query[0];
            int end = query[1];
            int x = 1; // Operation value ..as 1 is already given in question

            diff[start] += x;
            if (end + 1 < n) {
                diff[end + 1] -= x;
            }
        }

        // STEP-2: Find the difference of old and updated vector elemnents
        vector<int> result(n, 0);
        int cummSum = 0;
        for (int i = 0; i < n; i++) {
            cummSum += diff[i];
            result[i] = cummSum;
        }
        for (int i = 0; i < n; i++) {
            if (result[i] < nums[i]) {
                return false;
            }
        }
        return true;
    }
};
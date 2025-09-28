// class Solution {
// public:
//     int largestPerimeter(vector<int>& nums) {
//         int n = nums.size(),maxPerimeter=0;
//         for(int i=0;i<n-2;i++){
//             for(int j=i+1;j<n-1;j++){
//                 for(int k=j+1;k<n;k++){
//                     int a=nums[i],b=nums[j],c=nums[k];
//                     if(a+b>c&&b+c>a&&c+a>b){
//                         maxPerimeter=max(maxPerimeter,a+b+c);
//                     }
//                 }
//             }
//         }
//         return maxPerimeter;
//     }
// };

// T.C=O(NLogN)
class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        //Find the first maximum triplet and return that as it guarantees max perimeter
        for (int i = n - 1; i >= 2; i--) {
            int a = nums[i], b = nums[i - 1], c = nums[i - 2];
            if (a + b > c && b + c > a && c + a > b) {
                return a + b + c;
            }
        }
        return 0;
    }
};
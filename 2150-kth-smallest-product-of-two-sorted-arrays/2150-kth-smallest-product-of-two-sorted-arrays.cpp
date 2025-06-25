// Simulation
//T.C=O((n Ã m) Ã log(n Ã m))
//S.C=O(n*m)
//Works for test cases..not the big inputs
//Very slow and complex..due to which it doesnt work in certain conditions
// class Solution {
// public:
//     long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
//         vector<long long> multipliedValues;

//         for (int i = 0; i < nums1.size(); i++) {
//             for (int j = 0; j < nums2.size(); j++) {
//                 multipliedValues.push_back((long long)nums1[i] * nums2[j]);
//             }
//         }

//         sort(multipliedValues.begin(), multipliedValues.end());
//         for(long long val:multipliedValues){
//             cout<<val<<endl;
//         }

//         if (k <= 0 || k > multipliedValues.size())
//             return -1;

//         return multipliedValues[k - 1];
//     }
// };


//Optimal Binary Search Approach
//Small values possible with: 
//1. Smallest positive value, 2.Biggest negative value

//Let Num=some supposed value
//do binary search and see which pair product values are less than or equal to that Num
//Suppose that Num is 5th smallest and we need 2nd smallest
//so we can go forward with the left side elements of the binary search
class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
       
       long long left=-1e10,right=1e10;

       while(left<right){
        long long mid=left+(right-left)/2;

        if(countProduct(nums1,nums2,mid)<k)left=mid+1;
        else right=mid;
       }
       return left;
    }

    long long countProduct(vector<int>& nums1,vector<int>& nums2,long long u){
        long long count=0;
        for(int num1:nums1){
            if(num1==0){
                if(u>=0){
                    count+=nums2.size();
                    continue;
                }
            }
            int low=0,high=nums2.size();
            while(low<high){
                int mid=(low+high)/2;
                long long product=1LL*num1*nums2[mid];
                if(product<=u){
                    if(num1>0)low=mid+1;
                    else high=mid;
                }
                else{
                    if(num1>0)high=mid;
                    else low=mid+1;
                }
            }
            count+=(num1>0)?low:(nums2.size()-low);
        }
        return count;
    }
};
class Solution {
public:
    int getDigitSum(int n) {
        if (n < 10)
            return n;
        int sum = 0;
        while (n > 0) {
            sum += (n % 10);
            n /= 10;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return 0;

        vector<int> afterSorted(nums);

        auto lambda = [&](int a, int b) {
            int num1 = getDigitSum(a);
            int num2 = getDigitSum(b);
            if (num1 != num2)
                return num1 < num2;
            return a < b;
        };

        sort(afterSorted.begin(), afterSorted.end(), lambda);

        unordered_map<int,int>valToIdx;
        for(int i=0;i<n;i++)
            valToIdx[nums[i]]=i;

        int swap=0;
        for(int i=0;i<n;i++){
            int expectedVal=afterSorted[i],currVal=nums[i];

            if(currVal==expectedVal)
                continue;

            int idx=valToIdx[expectedVal];
            nums[i]=expectedVal,nums[idx]=currVal;

            valToIdx[expectedVal]=i;
            valToIdx[currVal]=idx;

            swap++;
        }

        return swap;
        // int diff = 0;
        // for (int i = 0; i < n; i++)
        //     if (afterSorted[i] != nums[i])
        //         diff++;

        // return diff - 1;

    }
};
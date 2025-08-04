// Sliding Window - Maximum Subarray concept with two distinct conditions
// variation

// T.C=O(n)
// S.C=O(1)
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        if(fruits.size()==1){
            return 1;
        }
        unordered_map<int, int> basket;
        int maxLen = 0, left = 0;
        basket[fruits[left]]++;
        for (int right = left + 1; right < fruits.size(); right++) {
            basket[fruits[right]]++;
            while (basket.size() > 2) {
                basket[fruits[left]]--;
                if (basket[fruits[left]] == 0) {
                    basket.erase(fruits[left]);
                }
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};
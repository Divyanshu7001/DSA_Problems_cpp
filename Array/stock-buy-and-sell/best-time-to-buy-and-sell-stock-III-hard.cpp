/*
 *
 * [123] Best Time to Buy and Sell Stock III
 *
 * You are given an array prices where prices[i] is the price of a given stock on the ith day.
Find the maximum profit you can achieve. You may complete at most two transactions.
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).


Example 1:
Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.

Example 2:
Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.

Example 3:
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
 *
 *
 *
 */

class Solution
{
    // Divide & conqueor approach
    // divide in two parts left and right
    // come from left to right in case of left vector ...taking new points as selling points and comapring the profits at every point in case of buying at first value supposing no other less value than first value is found
    // if less value is found...update the leftMin with that value
    // come from right to left in case of right vector
    // take new points as buying points and keep comparing to get the profits
    // Compare at last and return the max profit

    // T.C=o(n),S.C=o(n)
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        if (n == 0)
            return 0;

        vector<int> left(n), right(n);

        int leftMin = prices[0];
        for (int i = 1; i < n; i++)
        {
            left[i] = max(left[i - 1], prices[i] - leftMin);
            leftMin = min(leftMin, prices[i]);
        }

        int rightMax = prices[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            right[i] = max(right[i + 1], rightMax - prices[i]);
            rightMax = max(rightMax, prices[i]);
        }

        int profit = right[0];
        for (int i = 1; i < n; i++)
        {
            profit = max(profit, left[i - 1] + right[i]);
        }
        return profit;
    }
};

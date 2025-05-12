/*
 *
 * [2094] Finding 3-Digit Even Numbers
 *
 * You are given an integer array digits, where each element is a digit. The array may contain duplicates.
You need to find all the unique integers that follow the given requirements:
The integer consists of the concatenation of three elements from digits in any arbitrary order.
The integer does not have leading zeros.
The integer is even.
For example, if the given digits were [1, 2, 3], integers 132 and 312 follow the requirements.
Return a sorted array of the unique integers.

Example 1:
Input: digits = [2,1,3,0]
Output: [102,120,130,132,210,230,302,310,312,320]
Explanation: All the possible integers that follow the requirements are in the output array.
Notice that there are no odd integers or integers with leading zeros.


Example 2:
Input: digits = [2,2,8,8,2]
Output: [222,228,282,288,822,828,882]
Explanation: The same digit can be used as many times as it appears in digits.
In this example, the digit 8 is used twice each time in 288, 828, and 882.

Example 3:
Input: digits = [3,7,5]
Output: []
Explanation: No even integers can be formed using the given digits.
 *
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // Divide the 3 digit numbers into Hundreds,Tens & Ones.
    // Hundreds place- 1 to 9 can be taken to avoid leading 0
    // Tens place- 0 to 9 available
    // Ones place- 2,4,6,8 available to make the whole number even

    // Have an constant size array like array[10] to store the frequency of every element in given digits array
    // Now do nested loop accordingly
    // If the current loop index number is not available in digits array..continue
    // if the current loop index number is available in digits array
    // Decrease the frequency once & take combinations for that perticular number..no need to check for even
    // push the number in a vector called result
    // return the result vector at last..no need of sorting  as the numbers is created in ascending order

    // T.C=o(1)
    // S.C=o(1)

    vector<int> findEvenNumbers(vector<int> &digits)
    {

        vector<int> result;
        vector<int> counter(10, 0);

        for (int &digit : digits)
        {
            counter[digit]++;
        }

        for (int i = 1; i <= 9; i++)
        {
            if (counter[i] == 0)
                continue;
            counter[i]--; // Decrease the frequency here as we are going to use it and get its combinations
            for (int j = 0; j <= 9; j++)
            {
                if (counter[j] == 0)
                    continue;
                counter[j]--; // Similar to i...decrease the frequency as we are gonna use it
                for (int k = 0; k <= 8; k += 2)
                {
                    if (counter[k] == 0)
                        continue;
                    counter[k]--; // we are using it to make the number right after this..so reduce to make the number
                    int num = i * 100 + j * 10 + k;
                    result.push_back(num);

                    counter[k]++; // Increase the frequency for next iteration
                }
                counter[j]++; // Increase the freq. for next iteration and for inner of i
            }
            counter[i]++;
        }
        return result;
    }
};

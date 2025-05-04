/*
 *
 * [8] String to Integer (atoi)
 *
 * Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.

The algorithm for myAtoi(string s) is as follows:
Whitespace: Ignore any leading whitespace (" ").
Signedness: Determine the sign by checking if the next character is '-' or '+', assuming positivity if neither present.
Conversion: Read the integer by skipping leading zeros until a non-digit character is encountered or the end of the string is reached. If no digits were read, then the result is 0.
Rounding: If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then round the integer to remain in the range. Specifically, integers less than -231 should be rounded to -231, and integers greater than 231 - 1 should be rounded to 231 - 1.
Return the integer as the final result.


Example 1:
Input: s = "42"
Output: 42
Explanation:
The underlined characters are what is read in and the caret is the current reader position.
Step 1: "42" (no characters read because there is no leading whitespace)   ^
Step 2: "42" (no characters read because there is neither a '-' nor '+       ^
Step 3: "42" ("42" is read in)
           ^
Example 2:
Input: s = " -042"
Output: -42
Explanation:
Step 1: "   -042" (leading whitespace is read and ignored)
            ^
Step 2: "   -042" ('-' is read, so the result should be negative)
             ^
Step 3: "   -042" ("042" is read in, leading zeros ignored in the result)
 */

#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    int myAtoi(string s)
    {
        int max_int = 2147483647, min_int = -2147483648;
        int i = 0, n = s.length(), sign = 1, result = 0;

        // Step 1: Skip leading whitespace
        while (i < n && s[i] == ' ')
            i++;

        // Step 2: Check for optional sign
        if (i < n && (s[i] == '-' || s[i] == '+'))
        {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // Step 3: Convert digits to integer
        while (i < n && isdigit(s[i]))
        {
            int digit = s[i] - '0';
            // Check for overflow
            if (result > (max_int - digit) / 10)
            {
                return sign == 1 ? max_int : min_int;
            }
            result = result * 10 + digit;
            i++;
        }

        return sign * result;
    }
};

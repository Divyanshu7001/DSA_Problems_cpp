class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        for (int i = digits.size() - 1; i >= 0; i--) {
            
            if (digits[i] != 9) {
                //no carry left situation
                digits[i] += 1;
                return digits;
            }
            //this digit was a 9..so we update this index to zero and loop continues
            digits[i] = 0;
        }
        //This means all the digits were 9
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
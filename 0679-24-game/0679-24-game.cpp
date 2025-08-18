// 1. Divison results can go to float values & we have to take them..no
// approximation
// 2. unary operations not allowed..binary only ..one complete, then go to
// another
// 3. any type of ordering is possible

//{4,1,8,7} => lets say you did 4+8..then => {1,7,12}

// Operations logic:
//  can be binary + or - or * or /
//  possibilites that can be explored: a+b,a*b,a-b,b-a,a/b,b/a ; as a+b=b+a *
//  a*b=b*a

// This is a problem having so many options => recursion

// Logic:
// The main logic is, in present cards..do some operation..append the
// result..explore with it if we get a result...id not pop it and go for other
// options do-append-explore-pop => backtracking
class Solution {
public:
    double epsilon = 0.1;

    bool solve(vector<double>& cards) {
        if (cards.size() == 1) {
            return abs(cards[0] - 24) <= epsilon;
        }

        for (int i = 0; i < cards.size(); i++) {
            for (int j = 0; j < cards.size(); j++) {
                if (i == j)
                    continue;

                vector<double> temp;
                for (int k = 0; k < cards.size(); k++) {
                    if (k != i && k != j)
                        temp.push_back(cards[k]);
                }

                double a = cards[i], b = cards[j];

                vector<double> possibleValues = {a + b, a - b, b - a, a * b};

                if (abs(b) > 0.0) {
                    possibleValues.push_back(a / b);
                }
                if (abs(a) > 0.0) {
                    possibleValues.push_back(b / a);
                }

                // Backtracking
                for (double val : possibleValues) {
                    temp.push_back(val); // append
                    if (solve(temp) == true)
                        return true; // Explore
                    temp.pop_back(); // pop
                }
            }
        }
        return false;
    }

    bool judgePoint24(vector<int>& cards) {
        vector<double> nums;
        for (int& num : cards) {
            nums.push_back(1.0 * num);
        }

        return solve(nums);
    }
};
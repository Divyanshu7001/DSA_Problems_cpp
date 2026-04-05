class Solution {
public:
    bool judgeCircle(string moves) {

        vector<int> res = {0, 0};

        for (int i = 0; i < moves.length(); i++) {
            if (moves[i] == 'U')
                res[0] += 1;
            if (moves[i] == 'D')
                res[0] -= 1;

            if (moves[i] == 'L')
                res[1] += 1;
            if (moves[i] == 'R')
                res[1] -= 1;
        }

        return res[0] == 0 && res[1] == 0;
    }
};
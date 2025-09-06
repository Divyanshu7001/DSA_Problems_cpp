// The logic or pattern is basically 4^s-1 shows the range of elements which can
// be divided by 4 in s no.of steps. Ex: for s=1 ... L = 1 , R = 4*L -1 => 3
// ...elements of this range can be divided by 4 in 1 steps
//  for s=2...L = 4, R=4*L-1 =>15...elements of this range can be divided by 4
//  in 2 steps..etc
typedef long long LL;
class Solution {
public:
    LL solve(int l, int r) {
        // L,R range check
        //! to 3: 1 steps needed
        // 4 to 15: 2 steps needed
        LL L = 1, S = 1; // R can be derived as => 4*L-1
        LL steps = 0;

        // Start from L=1...keep checking the right range for current L...check
        // how many elements lie in that range and accordingly the steps will be
        // (end-start+1)*S..keep adding and updating
        while (L <= r) {
            LL R = 4 * L - 1;
            LL start = max(L, (LL)l),
               end = min(R, (LL)r); // Have to get start,end to cover the
                                    // transitioning range case
            if (start <= end)
                steps += (end - start + 1) *
                         S; // (end-start+1)..to get elements between the range

            S += 1;
            L = L * 4;
        }

        return steps;
    }

    LL minOperations(vector<vector<int>>& queries) {

        LL result = 0;

        for (auto& query : queries) {
            int l = query[0], r = query[1];

            LL steps = solve(l, r);

            result += (steps + 1) / 2;
        }

        return result;
    }
};
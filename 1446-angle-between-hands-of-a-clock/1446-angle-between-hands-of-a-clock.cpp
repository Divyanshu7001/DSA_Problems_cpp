class Solution {
public:
    double angleClock(int hour, int minutes) {

        return min(abs((hour * 30 + minutes * 0.5) - minutes * 6),
                   360 - abs((hour * 30 + minutes * 0.5) - minutes * 6));
    }
};
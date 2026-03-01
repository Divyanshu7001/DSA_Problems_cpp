// Trick
class Solution {
public:
    int minPartitions(string n) {
        char maxCh = *max_element(n.begin(), n.end());
        return maxCh - '0';
    }
};
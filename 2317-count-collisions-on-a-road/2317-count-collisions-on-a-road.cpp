class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();
        int left = 0, right = n - 1;

        // Skip leading 'L' cars (never collide)
        while (left < n && directions[left] == 'L')
            left++;

        // Skip trailing 'R' cars (never collide)
        while (right >= 0 && directions[right] == 'R')
            right--;

        int collisions = 0;

        // All remaining 'L' or 'R' cars in the middle will collide
        for (int i = left; i <= right; i++) {
            if (directions[i] != 'S')
                collisions++;
        }

        return collisions;
    }
};

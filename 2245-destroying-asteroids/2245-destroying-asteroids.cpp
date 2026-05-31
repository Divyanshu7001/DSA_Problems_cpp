class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        long newMass = mass;
        for (int& ast : asteroids) {
            if (newMass < ast)
                return false;
            else
                newMass = newMass + ast;
        }

        return true;
    }
};
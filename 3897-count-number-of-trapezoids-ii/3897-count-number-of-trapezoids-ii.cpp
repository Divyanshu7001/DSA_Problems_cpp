// As the horizontal line is not fixed here...
// we will rely on the slope and intercept made by a perticular line on the
// plane

// Slope=> For (x1,y1)&(x2,y2) set..slope made by these two set of
// points=>dy/dx=(y2-y1)/(x2-x1)

// Intercept=>
// Any line in a generic manner can be represented by y=mx+c =>c=y-mx
// y=(dy/dx)*x+c,where c=y-intercept of the perticular line
// By solving=> supposing for points (x1,y1) & (x2,y2) =>c = y1-(dy/dx)*x1
// therefore, c = (y1*dx-x1*dy)/dx
// Edge case of intercept => if dx=0
// if dx=0...slope=infinity=>assign some large value
// dx=0 means a perpendicular line on the x-axis..so intercept can be either x1
// or x2(any)

// Edge case of the problem => paralellogram / square where the vertical sides
// also get calculated & duplicate trapezoids are counted property of
// square/paralellogram => mid-points of the diagonals are same ->
// trapezoids(never) so we will have to calculate the midpoints of every line
// also with accoding slopes..and decrease these extras when two mid-points are
// same

// midpoint is a perticular pair of x,y but we cant store pair in
// unordered_map...so unique key is created from midpoints =>
// (x1+x2)*10000+(y1+y2)
class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {

        int n = points.size();

        // slope->{intercepts}
        unordered_map<float, vector<float>> slopeIntercepts;

        unordered_map<int, vector<float>> midPointMap;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];

                int dx = x2 - x1, dy = y2 - y1;

                float slope, intercept;
                if (dx == 0) {
                    slope = 1e9 + 7;
                    intercept = x1; // any of x1 or x2 can be taken as intercept
                } else {
                    slope = (float)dy / dx;
                    intercept = (float)(y1 * dx - x1 * dy) / dx;
                }
                slopeIntercepts[slope].push_back(intercept);

                int midPointKey = (x1 + x2) * 10000 + (y1 + y2);
                midPointMap[midPointKey].push_back(slope);
            }
        }
        int result = 0;
        for (auto& it : slopeIntercepts) {
            //need at least two intercepts to count it in
            if (it.second.size() <= 1)
                continue;

            map<float, int> mp; // intercepts->count

            for (float intercept : it.second)
                mp[intercept]++;

            int prevHorizontalLines = 0;
            for (auto& it : mp) {
                int interceptCount = it.second;
                result += interceptCount *
                          prevHorizontalLines; // Duplicates also included here

                prevHorizontalLines += interceptCount;
            }
        }

        for (auto& it : midPointMap) {
            //need at least two intercepts to count it in
            if (it.second.size() <= 1)
                continue;
                
            map<float, int> mp; // intercepts->count

            for (float slope : it.second)
                mp[slope]++;

            int prevHorizontalLines = 0;
            for (auto& it : mp) {
                int interceptCount = it.second;
                result -=
                    interceptCount * prevHorizontalLines; // Removing duplicates

                prevHorizontalLines += interceptCount;
            }
        }

        return result;
    }
};
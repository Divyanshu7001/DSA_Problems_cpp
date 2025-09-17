//T.C=O(N)....TLE
// class FoodRatings {
// public:
//     vector<string> foodsList;
//     vector<string> cuisinesList;
//     vector<int> ratingsList;

//     FoodRatings(vector<string>& foods, vector<string>& cuisines,
//                 vector<int>& ratings) {
//         foodsList = foods;
//         cuisinesList = cuisines;
//         ratingsList = ratings;
//     }

//     void changeRating(string food, int newRating) {
//         for (int i = 0; i < foodsList.size(); i++) {
//             if (foodsList[i] == food) {
//                 ratingsList[i] = newRating;
//                 break;
//             }
//         }
//     }

//     string lexoGraphicalCompare(string a, string b) {
//         int n = min(a.size(), b.size());

//         for (int i = 0; i < n; i++) {
//             if (a[i] < b[i]) return a;
//             if (a[i] > b[i]) return b;
//         }

//         return (a.size() < b.size()) ? a : b;
//     }

//     string highestRated(string cuisine) {
//         int maxRating = -1;
//         string maxRatedFood = "";

//         for (int i = 0; i < cuisinesList.size(); i++) {
//             if (cuisinesList[i] == cuisine) {
//                 if (ratingsList[i] > maxRating) {
//                     maxRating = ratingsList[i];
//                     maxRatedFood = foodsList[i];
//                 } else if (ratingsList[i] == maxRating) {
//                     maxRatedFood = lexoGraphicalCompare(maxRatedFood, foodsList[i]);
//                 }
//             }
//         }

//         return maxRatedFood;
//     }
// };

// Complexity
// changeRating: O(log n) (erase + insert in set).
// highestRated: O(1) (just get .begin()).
class FoodRatings {
public:
    // food -> {cuisine, rating}
    unordered_map<string, pair<string, int>> foodMap;

    // cuisine -> ordered set of (rating, food)
    unordered_map<string, set<pair<int, string>>> cuisineMap;

    // Custom comparator for ratings (higher first, tie -> lexicographically smaller food)
    struct Compare {
        bool operator()(const pair<int, string>& a, const pair<int, string>& b) const {
            if (a.first != b.first) return a.first > b.first; // higher rating first
            return a.second < b.second; // smaller lexicographically
        }
    };

    // cuisine -> ordered set with custom comparator
    unordered_map<string, set<pair<int, string>, Compare>> cuisineSets;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); i++) {
            foodMap[foods[i]] = {cuisines[i], ratings[i]};
            cuisineSets[cuisines[i]].insert({ratings[i], foods[i]});
        }
    }

    void changeRating(string food, int newRating) {
        auto& [cuisine, oldRating] = foodMap[food];

        // Remove old entry
        cuisineSets[cuisine].erase({oldRating, food});

        // Insert new entry
        cuisineSets[cuisine].insert({newRating, food});

        // Update in foodMap
        oldRating = newRating;
    }

    string highestRated(string cuisine) {
        // First element is always the best one (due to comparator)
        return cuisineSets[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
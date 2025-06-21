// Loop trhough and count every chaacter's frequency
// Use hashmap to store them
// Sort the frequencies

// Check frequency conversions taking every freq as base
// for every frequency taken as base
// Check the range until there wont be a problem for the perticular freq
// freq:[freq,fre+k]
// 1. freq<base => Complete delete the freq
// 2. freq+k>base => Delete k extras
// 3. count deletions

// Return the minimum value

// class Solution {
// public:
//     int minimumDeletions(string word, int k) {

//         unordered_map<char,int> freq;
//         for(char c:word){
//             frequencies[c-'a']++;
//         }

//         vector<int>frequencies;
//         for(auto& pair:freq){
//             frequencies.push_back(pair.second);
//         }

//         sort(frequencies.begin(),frequencies.end());

//         int minDeletions=INT_MAX;
//         int n=frequencies.size();

//         for(int i=0;i<n;i++){
//             int base=frequencies[i];
//             int totalDeletions=0;

//             for(int j=0;j<i;j++){
//                 totalDeletions+=frequencies[j];
//             }

//             for(int j=i;j<n;j++){
//                 if(frequencies[j]>base+k){
//                     totalDeletions+=frequencies[j]-(base+k);
//                 }
//             }

//             if(totalDeletions<minDeletions){
//                 minDeletions=totalDeletions;
//             }
//         }

//         return minDeletions;
//     }
// };

class Solution {
public:
    int minimumDeletions(string word, int k) {

        vector<int> frequencies(26, 0);
        for (char c : word) {
            frequencies[c - 'a']++;
        }
        
        sort(frequencies.begin(), frequencies.end());

        int minDeletions = INT_MAX;

        for (int i = 0; i < 26; i++) {
            int base = frequencies[i];
            // if (base == 0)
            //     break;
            int totalDeletions = 0;

            for (int j = 0; j < i; j++) {
                totalDeletions += frequencies[j];
            }

            for (int j = i; j < 26; j++) {
                if (frequencies[j] > base + k) {
                    totalDeletions += frequencies[j] - (base + k);
                }
            }

            if (totalDeletions < minDeletions) {
                minDeletions = totalDeletions;
            }
        }

        return minDeletions;
    }
};
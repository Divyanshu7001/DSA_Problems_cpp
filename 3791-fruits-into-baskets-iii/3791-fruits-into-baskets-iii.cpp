// class Solution {
// public:
//     void traverseAndFill(int fruitValue,vector<int>baskets)
//     int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {

//         int n = fruits.size(), filledFruits = 0;
//         sort(begin(baskets),end(baskets));
//         vector<int> filled(n, false);

//         for (int i = 0; i < n; i++) {

//             for (int j = 0; j < n; j++) {
//                 if (fruits[i] <= baskets[j] && !filled[j]) {
//                     filled[j] = true;
//                     filledFruits += 1;
//                     break;
//                 }
//             }
//         }

//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (fruits[i] <= baskets[j] && !filled[j]) {
//                     filled[j] = true;
//                     filledFruits += 1;
//                     break;
//                 }
//             }
//         }
//         return n - filledFruits;
//     }
// };

class Solution {
public:
    int unplaced = 0;

    void build(int i, int l, int r, vector<int>& baskets,
               vector<int>& segmentTree) {
        if (l == r) {
            segmentTree[i] = baskets[l];
            return;
        }

        int mid = l + (r - l) / 2;

        // Recursively building the left segment tree
        build(2 * i + 1, l, mid, baskets, segmentTree);

        // Recursively building the right segment tree
        build(2 * i + 2, mid + 1, r, baskets, segmentTree);

        // Populating the root node value with max of left & right child tree
        segmentTree[i] = max(segmentTree[2 * i + 1], segmentTree[2 * i + 2]);
    }

    bool querySegmentTree(int i, int l, int r, vector<int>& segmentTree, int fruit) {
        
        if(segmentTree[i]<fruit){
            return false;
        }

        if(l==r){
            segmentTree[i]=-1; //mark this last node as assigned and come back
            return true;
        }

        int mid=l+(r-l)/2;
        bool placed=true;

        //check if left child node value is greater than fruit value..if true..we can go towards the left segment tree path
        if(segmentTree[2*i+1]>=fruit){
            placed=querySegmentTree(2*i+1,l,mid,segmentTree,fruit);
        }else {
            placed=querySegmentTree(2*i+2,mid+1,r,segmentTree,fruit);
        }

        segmentTree[i]=max(segmentTree[2*i+1],segmentTree[2*i+2]);

        return placed;
    }

    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        vector<int> segmentTree(4 * n, -1);

        // i=0,l=0 to r=n-1
        build(0, 0, n - 1, baskets, segmentTree);

        int unplaced = 0;
        for (int& fruit : fruits) {
            if (querySegmentTree(0, 0, n - 1, segmentTree, fruit) == false) {
                unplaced++;
            }
        }
        return unplaced;
    }
};

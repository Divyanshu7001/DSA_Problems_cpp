class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> inWindow;
        int curr = 0, best = 0, left = 0;

        for (int right = 0; right < nums.size(); right++) {
            int x = nums[right];

            // Shrink from left until x not in window
            while (inWindow.count(x)) {
                inWindow.erase(nums[left]);
                curr -= nums[left];
                left++;
            }

            // Include x
            inWindow.insert(x);
            curr += x;
            best = max(curr, best);
        }

        return best;
    }
};

// Only adding the unique elements here...not according to the question
// According to the question , it should add elements of an unique subarray
//  class Solution {
//  public:
//      int maximumUniqueSubarray(vector<int>& nums) {
//          unordered_map<int, int> freq;
//          int result = 0;
//          if (nums.size() == 1) {
//              return result + nums[0];
//          }
//          for (int& num : nums) {
//              freq[num]++;
//          }

//         for (auto& pair : freq) {
//             cout<<pair.first<<endl;
//             result += pair.first;
//         }

//         return result;
//     }
// };

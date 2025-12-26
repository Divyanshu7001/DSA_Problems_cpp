class Solution {
public:
    int bestClosingTime(string customers) {

        int n = customers.size(), totalCustomers = 0;

        for (char c : customers) {
            if (c == 'Y')
                totalCustomers++;
        }

        int mini = 1e9, prefix = 0, time = n;
        for (int i = 0; i <= n; i++) {
            int remCustomer = totalCustomers - prefix; // shop closed
            int penalty = i - prefix;

            penalty += remCustomer;

            if (mini > penalty) {
                mini = penalty;
                time = i;
            }

            if (i != n && customers[i] == 'Y')
                prefix++;
        }
        return time;
    }
};
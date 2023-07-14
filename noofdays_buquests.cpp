class Solution {
    bool possible(vector<int>& bloomDay, int days, int m, int k) {
        int n = bloomDay.size();
        int count = 0;
        int NoOfBouquets = 0;
        for (int i = 0; i < n; i++) {
            if (bloomDay[i] <= days)
                count++;
            else {
                NoOfBouquets += (count / k);
                count = 0;
            }
        }
        NoOfBouquets += (count / k);
        if (NoOfBouquets >= m)
            return true;
        else
            return false;
    }

public:
    int findMin(vector<int>& bloomDay) {
        int mini = INT_MAX;
        int n = bloomDay.size();
        for (int i = 0; i < n; i++) {
            mini = min(mini, bloomDay[i]);
        }
        return mini;
    }

public:
    int findMax(vector<int>& bloomDay) {
        int maxi = INT_MIN;
        int n = bloomDay.size();
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, bloomDay[i]);
        }
        return maxi;
    }

public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        long long value = m * 1LL * k * 1LL;
        if (n < value)
            return -1;
        int low = findMin(bloomDay);
        int high = findMax(bloomDay);
        while (low <= high) {
            int mid = (low + high) >> 1;
            if (possible(bloomDay, mid, m, k) == true) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};

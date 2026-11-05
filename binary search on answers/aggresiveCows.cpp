#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Check if we can place 'k' cows with at least 'mid' distance apart
bool canWePlace(const vector<int>& stalls, int mid, int k) {
    int cowsCount = 1;
    int lastPosition = stalls[0];

    for (int i = 1; i < stalls.size(); i++) {
        if (stalls[i] - lastPosition >= mid) {
            cowsCount++;
            lastPosition = stalls[i];
        }
        if (cowsCount >= k) {
            return true;
        }
    }
    return false;
}

int aggressiveCows(vector<int>& stalls, int k) {
    sort(stalls.begin(), stalls.end()); // 1. Sort the stall positions
    
    int low = 1;
    int high = stalls.back() - stalls.front();
    int ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canWePlace(stalls, mid, k)) {
            ans = mid;         // Try for a larger minimum distance
            low = mid + 1;
        } else {
            high = mid - 1;    // Reduce the distance
        }
    }
    return ans;
}

int main() {
    vector<int> stalls = {1, 2, 4, 8, 9};
    int k = 3;
    cout << "Maximum possible minimum distance: " << aggressiveCows(stalls, k) << endl;
    return 0;
}

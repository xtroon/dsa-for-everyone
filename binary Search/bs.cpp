#include <iostream>
using namespace std;

int bs(int arr[], int size, int key) {
    int start = 0;
    int end = size - 1;
    int mid =
        start +
        (end - start) /
            2;  //{start+end}/2 not use coz of if there long value 2^31 -2 then out of ring int
    while (start <= end) {
        if (arr[mid] == key) {
            return mid;
        }

        if (arr[mid] < key) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
        mid = (start + end) / 2;
    }
    return -1;
}

int main() {
    int even[] = {2, 4, 6, 8, 12, 18};
    int odd[] = {3, 8, 11, 14, 16};

    cout << "index is " << bs(odd, 5, 13);

    return 0;
}
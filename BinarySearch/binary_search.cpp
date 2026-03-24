#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int target) {
    int left = 0, right = n - 1;

    while(left <= right) {
        int mid = (left + right) / 2;

        if(arr[mid] == target)
            return mid;
        else if(arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main() {
    int arr[] = {1,2,3,4,5,6,7};
    int n = 7;
    int target = 5;

    int result = binarySearch(arr, n, target);

    if(result != -1)
        cout << "Element found at index " << result;
    else
        cout << "Element not found";

    return 0;
}
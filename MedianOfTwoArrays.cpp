#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size(), n = nums2.size();
    if (m > n) {
        swap(nums1, nums2);
        swap(m, n);
    }
    int low = 0, high = m;
    while (low <= high) {
        int mid1 = (low + high) / 2;
        int mid2 = (m + n + 1) / 2 - mid1;
        if (mid1 < m && nums2[mid2 - 1] > nums1[mid1]) {
            low = mid1 + 1;
        } else if (mid1 > 0 && nums1[mid1 - 1] > nums2[mid2]) {
            high = mid1 - 1;
        } else {
            double median1;
            if (mid1 == 0) {
                median1 = nums2[mid2 - 1];
            } else if (mid2 == 0) {
                median1 = nums1[mid1 - 1];
            } else {
                median1 = max(nums1[mid1 - 1], nums2[mid2 - 1]);
            }
            if ((m + n) % 2 == 1) {
                return median1;
            }
            double median2;
            if (mid1 == m) {
                median2 = nums2[mid2];
            } else if (mid2 == n) {
                median2 = nums1[mid1];
            } else {
                median2 = min(nums1[mid1], nums2[mid2]);
            }
            return (median1 + median2) / 2;
        }
    }
    return 0.0;
}

int main() {
    vector<int> nums1 = {1, 3, 5};
    vector<int> nums2 = {2, 4, 6};
    cout << findMedianSortedArrays(nums1, nums2) << endl;
    return 0;
}

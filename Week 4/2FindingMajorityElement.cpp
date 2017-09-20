#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;
using std::ceil;

// int mergesort(vector<int>&a, int left, int right) {
//   int mid = ceil((right + left)  / 2);
// }

// int get_majority_element(vector<int> &a, int left, int right) {
//   int threshold = ceil((right - left) / 2);
//   std::cout << left << ' ' << threshold << ' ' << right << std::endl;
//   //write your code here

//   int result = -1;

//   switch (right - left) {
//     case 2:
//       if (a[left] == a[left + 1]) {
//         result = a[left];
//       }

//       if (a[left + 1] == a[right]) {
//         result = a[right];
//       }
//       break;
//     case 1: 
//     case 0:
//       break;
//     default: 
//       result = get_majority_element(a, left, threshold) == get_majority_element(a, threshold + 1, right) ? 1 : -1;
//   }

//   std::cout << left << ' ' << threshold << ' ' << right << ' ' << result << std::endl;

//   return result;
// }

int countsort(vector<int> &a) {
  int size = a.size();
  vector<int> count(size);
  for (int i = 0; i < size; i++) {
    int ele = a[i];
    if (!count[ele]) {
      count[ele] = 0;
    }

    std::cout << ele << ' ' << count[ele] << std::endl;

    if (++count[ele] > std::floor(size / 2)) {
      return 1;
    }
  }
  return 0;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << countsort(a) << '\n';
}

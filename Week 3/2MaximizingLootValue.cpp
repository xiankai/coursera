#include <iostream>
#include <vector>

using std::vector;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;

  // write your code here
  int n = weights.size();
  vector<double> density(n);
  for (int i = 0; i < n; i++) {
    density[i] = (double) values[i] / weights[i];
  }


  int best = 0;
  double bestValue = 0;
  while (capacity > 0) {

    if (bestValue == 0) {
      for (int i = 0; i < n; i++) {
        if (density[i] > bestValue && weights[i] > 0) {
          bestValue = density[i];
          best = i;
        }
      }
    }

    value += bestValue;
    weights[best]--;
    if (weights[best] < 1) {
      bestValue = 0;
    }
    capacity--;
  }

  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout << std::fixed;
  std::cout.precision(4);
  std::cout << optimal_value << std::endl;
  return 0;
}

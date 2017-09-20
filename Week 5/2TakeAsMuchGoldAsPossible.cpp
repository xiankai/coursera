#include <iostream>
#include <vector>

using std::vector;

vector<int> weights;

int optimal_weight(const vector<int> &w, int i) {
  auto lookup [](int n) {
    if (weights[n]) {
      weights[n] = optimal_weight(w, n);
    }
    return weights[n];
  }

  if (lookup(w, i - 1) > lookup(w, i - 1))

  int current_weight = 0;
  for (size_t i = 0; i < w.size(); ++i) {
    if (current_weight + w[i] <= W) {
      current_weight += w[i];
    }
  }
  return current_weight;
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  weights.resize(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}

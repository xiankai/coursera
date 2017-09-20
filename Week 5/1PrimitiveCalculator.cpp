#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

vector<int> lookupDb;

int optimal_steps(int n) {
  if (n == 1) {
    return 0;
  }

  std::vector<int> sequences;
  if (n % 3 == 0) {
    sequences.push_back(lookupDb[n / 3]);
  }

  if (n % 2 == 0) {
    sequences.push_back(lookupDb[n / 2]);
  }

  sequences.push_back(lookupDb[n - 1]);

  std::vector<int>::iterator result = std::min_element(sequences.begin(), sequences.end());

  return *result + 1;
}

void construct_lookup(int n) {
  lookupDb[1] = 0;
  for (int i = 2; i <= n; i++) {
    std::vector<int> sequences;
    if (i % 3 == 0) {
      sequences.push_back(lookupDb[i / 3]);
    }

    if (i % 2 == 0) {
      sequences.push_back(lookupDb[i / 2]);
    }

    sequences.push_back(lookupDb[i - 1]);

    std::vector<int>::iterator result = std::min_element(sequences.begin(), sequences.end());

    lookupDb[i] = *result + 1;
  }
}

int main() {
  int n;
  std::cin >> n;
  lookupDb.resize(n + 1);
  construct_lookup(n);
  int optimal = optimal_steps(n);

  vector<int> optimal_sequence;
  int current = n;
  for (int i = optimal; i > 0; i--) {
    if (current % 3 == 0 && lookupDb[current / 3] == i - 1) {
      current = current / 3;
      optimal_sequence.push_back(current);
      continue;
    }

    if (current % 2 == 0 && lookupDb[current / 2] == i - 1) {
      current = current / 2;
      optimal_sequence.push_back(current);
      continue;
    }

    current--;
    optimal_sequence.push_back(current);
  }

  std::cout << optimal_sequence.size() << std::endl;
  reverse(optimal_sequence.begin(), optimal_sequence.end());
  for (size_t i = 0; i < optimal_sequence.size(); ++i) {
    std::cout << optimal_sequence[i] << " ";
  }
  std::cout << std::endl;
}

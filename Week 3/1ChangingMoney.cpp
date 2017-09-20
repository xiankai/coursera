#include <iostream>

int get_change(int m) {
  //write your code here
  int tens, fives, ones, remainder;
  tens = m / 10;
  remainder = m % 10;
  fives = remainder / 5;
  remainder = remainder % 5;

  return tens + fives + remainder;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}

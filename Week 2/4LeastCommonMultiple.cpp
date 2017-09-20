#include <iostream>

long long lcm_naive(int a, int b) {
	for (long l = 1; l <= (long long) a * b; ++l)
		if (l % a == 0 && l % b == 0)
			return l;

	return (long long) a * b;
}

long long lcm_smart(long long a, long long b) {
	long long a2 = a,
		b2 = b,
		product = 0,
		gcd,
		lcm;

	do {
		product = a2 % b2;
		a2 = b2;
		b2 = product;
	} while (product > 0);

	gcd = a2;
	lcm = a * b / gcd;

	return lcm;
}

int main() {
	long long a, b, temp;

	std::cin >> a >> b;

	// swap so a is highest
	if (b > a) {
		temp = a;
		a = b;
		b = temp;
	}

	std::cout << lcm_smart(a, b) << std::endl;
	return 0;
}
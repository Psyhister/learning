#include <iostream>
#include <cstdlib>

int power_ten(int index) {
	int num = 1;
	while(index > 0){
		num *= 10;
		index--;
	}
	return num;
}


int karatsuba_mul(const int x, const int y) {
	if(x < 10 || y < 10) return x * y;
	int first = std::abs(x), second = std::abs(y);
	size_t first_digits = 0, second_digits = 0;
	do {
		first_digits++;
		first /= 10;
	} while(first > 0);

	do {
		second_digits++;
		second /= 10;
	} while(second > 0);

	const size_t max_digits2 = std::max(first_digits, second_digits) / 2;
	int a = x / power_ten(max_digits2), b = x - a * power_ten(max_digits2),
	c = y / power_ten(max_digits2), d = y - c * power_ten(max_digits2);
	std::cout << a << " " << b << " " << c << " " << d << std::endl;
	int ac = karatsuba_mul(a, c), bd = karatsuba_mul(b, d),
	    part_sum = karatsuba_mul(a + b, c + d) - ac - bd;
	return ac * power_ten(max_digits2 * 2) +
		part_sum * power_ten(max_digits2) + bd;
}

int main(int argc, char **argv) {
	if (argc != 3) {
		std::cerr << "2 arguments required" << std::endl;
		return 1;
	}
	int x = atoi(argv[1]), y = atoi(argv[2]);
	std::cout << "Karatsuba result: " << karatsuba_mul(x, y) << std::endl;
	std::cout << "Normal multiplication result: " << x * y << std::endl;
	return 0;
}

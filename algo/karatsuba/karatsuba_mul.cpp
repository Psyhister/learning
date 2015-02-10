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

	int a, b, c, d;
	if(first_digits == 1) {
		if(second_digits == 1)
			return x * y;
		else {
			a = 0;
			b = x;
		}
	}
	else {
		a = x / power_ten(first_digits / 2);
		b = x - a * power_ten(first_digits / 2);
	}
	if(second_digits == 1) {
		c = 0;
		d = y;
	}
	else {
		c = y / power_ten(second_digits / 2);
		d = y - c * power_ten(second_digits / 2);
	}
	std::cout << a << " " << b << " " << c << " " << d << std::endl;
	int ac = karatsuba_mul(a, c), bd = karatsuba_mul(b, d),
	    part_sum = karatsuba_mul(a + b, c + d) - ac - bd;
	return ac * power_ten(first_digits) +
		part_sum * power_ten(first_digits / 2) + bd;
}

int main() {
	std::cout << karatsuba_mul(1020, 30430) << std::endl;
	std::cout << 1020 * 30430 << std::endl;
	return 0;
}

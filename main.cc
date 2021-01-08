#include <iostream>
#include <string>
#include <algorithm>

const std::string digits = "0123456789abcdefghijklmnopqrstuvwxyz";

template <typename T>
std::string ntos(T n, unsigned int b) {
	std::string s = "";
	while (n) {
		s += digits[n % b];
		n /= b;
	}
	std::reverse(s.rbegin(), s.rend());
	return s;
}

template <typename T>
T ston(const std::string& s, unsigned int b) {
	T n {0};
	for (auto c: s) {
		auto v = digits.find_first_of(c, 0);
		n = (n * b) + ((v == std::string::npos) ? 0 : v);
	}
	return n;
}

int main(int argc, char* argv[]) {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::cout << ntos(1936944443049, 36) << '\n';
	std::cout << ntos(ston<unsigned long long>("macintosh", 36), 16) << '\n';

	std::cout << "Hello, world!\n";
	return 0;
}

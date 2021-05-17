#include <iostream>
#include <string>
#include <algorithm>
#include "ap_n.hh"

// const std::string symbol = "0123456789abcdefghijklmnopqrstuvwxyz";
const std::string symbol = "0123456789abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ._-@<>";

template <typename T>
std::string ntos(T n, unsigned int base) {
	T b {base};
	std::string s {""};
	while (n) {
		s += symbol[static_cast<size_t>(n % b)];
		n /= b;
	}
	std::reverse(s.rbegin(), s.rend());
	return s;
}

template <typename T>
T ston(const std::string& s, unsigned int base) {
	T n {0};
	T b {base};
	for (auto c: s) {
		auto v {symbol.find_first_of(c, 0)};
		T m {(v == std::string::npos) ? 0 : v};
		n = (n * b) + m;
	}
	return n;
}

int main(int argc, char* argv[]) {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cout
		<< ntos(ston<ap_n>("1936944443049", 10) , 36) << '\n'
		<< ntos(ston<ap_n>("macintosh", 36), 16) << '\n';

	std::string x {"Desmond Rhodes <desmond.rhodes@outlook.com>"};
	auto y {ston<ap_n>(x, symbol.size())};

	std::cout
		<< x.size() << ": " << x << '\n'
		<< y << '\n'
		<< ntos(y, symbol.size()) << '\n';

	return 0;
}

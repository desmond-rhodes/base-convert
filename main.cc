#include <iostream>
#include <string>
#include <algorithm>
#include "ap_n.hh"

const std::string symbol = "0123456789abcdefghijklmnopqrstuvwxyz";

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
	std::vector<std::string> args(argv+1, argv+argc);

	if (args.size() != 3) {
		std::cerr
			<< "usage:\n"
			<< "\tsource-base target-base number\n";
		return -1;
	}

	unsigned int sbase;
	unsigned int tbase;
	try {
		sbase = stoull(args[0], nullptr, 0);
		tbase = stoull(args[1], nullptr, 0);
	}
	catch (...) {
		std::cerr << "Fail to parse base.\n";
		return -1;
	}

	if (sbase < 2 || sbase > symbol.size() || tbase < 2 || tbase > symbol.size()) {
		std::cerr << "Base cannot be smaller than 2 or larger than " << symbol.size() << ".\n";
		return -1;
	}

	for (auto c: args[2]) {
		for (size_t i {0}; i < symbol.size(); ++i)
			if (c == symbol[i]) {
				if (i < sbase)
					goto skip;
				else
					break;
			}
		std::cerr << "Number is not in base " << sbase << ".\n";
		return -1;
		skip:;
	}

	std::cout << ntos(ston<ap_n>(args[2], sbase), tbase) << '\n';

	return 0;
}

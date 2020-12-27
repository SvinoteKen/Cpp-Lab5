#pragma once
#include <string>
class Symbols
{
public:
	Symbols(std::string tester) {
		tester_ = tester;
	}
	bool operator()(std::string test) {
		return tester_[0] == test[0];
	}
private:
	std::string tester_;
};



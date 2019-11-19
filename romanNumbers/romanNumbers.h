#include <string>

#pragma once

class Roman {
public:
	int toInt(std::string s);

private:
	int toInt_(std::string s, int i);
};

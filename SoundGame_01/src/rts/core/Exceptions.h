#pragma once

#include <exception>
#include <string>

struct InitException
{
private:
	const std::string msg;
	const std::string error;

public:
	InitException(const std::string& msg = "", const std::string& error = "")
		: msg(msg), error(error)
	{}

	const std::string what() const {
		if (error == "") {
			return "Error during Initialization\n" + msg;
		}
		return "Error during Initialization\n" + msg + '\n' + error;
	}
};
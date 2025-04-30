#include "pch.h"
#include "cMyString.h"
int main()
{
	cMyString cStr;
	cStr = "hello";
	std::cout << cStr << std::endl;
	cStr = cStr + " world";
	std::cout << cStr << std::endl;
	if (cStr == "hello world")
	{
		std::cout << "true";
	}
}
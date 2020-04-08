#pragma once
#include <string>

using namespace std;

static class RPN
{
	static bool IsDelimeter(char el);
	static int GetPriority(char el);
	static bool IsOperator(char el);
	static string Reverse(string input);
public:
	static string Ñalculation(string input);
};


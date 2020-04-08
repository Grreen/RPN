#pragma once
#include <string>

using namespace std;

//union Data
//{
//	double DoubleValue;
//	string StringValue;
//};

struct Data
{
	double DoubleValue = NULL;
	string StringValue = "";
};

class Value
{
public:
	Data data;
	Value(string value);
	bool IsString();
	bool IsDouble();
	int TypeInfo();
};

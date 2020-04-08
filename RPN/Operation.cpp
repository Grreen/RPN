#include "Operation.h"

#include <iostream>

using namespace std;

string Operation::Addition(Value one, Value two)
{
	if (one.TypeInfo() == two.TypeInfo())
	{
		if (one.IsDouble())
		{
			string temp = to_string(two.data.DoubleValue + one.data.DoubleValue);
			return temp.substr(0, temp.find_last_not_of('0') + 1);
		}
		if (one.IsString())
			return two.data.StringValue + " + " + one.data.StringValue;
	}
	if (one.IsDouble() && two.IsString())
		return two.data.StringValue + " + " + to_string(one.data.DoubleValue).substr(0, to_string(one.data.DoubleValue).find_last_not_of('0') + 1);
	return to_string(two.data.DoubleValue).substr(0, to_string(two.data.DoubleValue).find_last_not_of('0') + 1)
		+ " + " + one.data.StringValue;
}

string Operation::Subtraction(Value one, Value two)
{
	if (one.TypeInfo() == two.TypeInfo())
	{
		if (one.IsDouble())
		{
			string temp = to_string(two.data.DoubleValue - one.data.DoubleValue);
			return temp.substr(0, temp.find_last_not_of('0') + 1);
		}
		if (one.IsString())
			return two.data.StringValue + " - " + one.data.StringValue;
	}
	if (one.IsDouble() && two.IsString())
		return two.data.StringValue + " - " + to_string(one.data.DoubleValue).substr(0, to_string(one.data.DoubleValue).find_last_not_of('0') + 1);
	return to_string(two.data.DoubleValue).substr(0, to_string(two.data.DoubleValue).find_last_not_of('0') + 1)
		+ " - " + one.data.StringValue;
}

string Operation::Multiply(Value one, Value two)
{
	if (one.TypeInfo() == two.TypeInfo())
	{
		if (one.IsDouble())
		{
			string temp = to_string(two.data.DoubleValue * one.data.DoubleValue);
			return temp.substr(0, temp.find_last_not_of('0') + 1);
		}
		if (one.IsString())
			return two.data.StringValue + " * " + one.data.StringValue;
	}
	if (one.IsDouble() && two.IsString())
		return two.data.StringValue + " * " + to_string(one.data.DoubleValue).substr(0, to_string(one.data.DoubleValue).find_last_not_of('0') + 1);
	return to_string(two.data.DoubleValue).substr(0, to_string(two.data.DoubleValue).find_last_not_of('0') + 1)
		+ " * " + one.data.StringValue;
}

string Operation::Divide(Value one, Value two)
{
	if (one.TypeInfo() == two.TypeInfo())
	{
		if (one.IsDouble())
		{
			string temp = to_string(two.data.DoubleValue / one.data.DoubleValue);
			return temp.substr(0, temp.find_last_not_of('0') + 1);
		}
		if (one.IsString())
			return two.data.StringValue + " / " + one.data.StringValue;
	}
	if (one.IsDouble() && two.IsString())
		return two.data.StringValue + " / " + to_string(one.data.DoubleValue).substr(0, to_string(one.data.DoubleValue).find_last_not_of('0') + 1);
	return to_string(two.data.DoubleValue).substr(0, to_string(two.data.DoubleValue).find_last_not_of('0') + 1)
		+ " / " + one.data.StringValue;
}

string Operation::Pow(Value one, Value two)
{
	if (one.TypeInfo() == two.TypeInfo())
	{
		if (one.IsDouble())
		{
			string temp = to_string(pow(two.data.DoubleValue, one.data.DoubleValue));
			return temp.substr(0, temp.find_last_not_of('0') + 1);
		}
		if (one.IsString())
			return two.data.StringValue + "^" + one.data.StringValue;
	}
	if (one.IsDouble() && two.IsString())
		return two.data.StringValue + "^" + to_string(one.data.DoubleValue).substr(0, to_string(one.data.DoubleValue).find_last_not_of('0') + 1);

	return to_string(two.data.DoubleValue).substr(0, to_string(two.data.DoubleValue).find_last_not_of('0') + 1)
		+ "^" + one.data.StringValue;
}

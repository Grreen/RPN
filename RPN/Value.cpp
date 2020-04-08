#include "Value.h"

Value::Value(string value)
{
	char* end;
	double res = strtod(value.c_str(), &end);

	if (end == value.c_str() || *end != '\0')
		data.StringValue = value;
	//data->StringValue = value;
	else
		data.DoubleValue = res;
		//data->DoubleValue = res;
}

bool Value::IsDouble()
{
	/*if (sizeof(data) == sizeof(double))
		return true;
	return false;*/
	if (data.DoubleValue == NULL)
		return false;
	return true;
}

bool Value::IsString()
{
	//if (sizeof(data) == sizeof(string))
	//	return true;
	//return false;
	if (data.StringValue == "")
		return false;
	return true;
}

int Value::TypeInfo()
{
	if (IsDouble())
		return 1;
	return 2;
}


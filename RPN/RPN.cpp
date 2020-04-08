#include "RPN.h"
#include "Stack.h"
#include "Operation.h"
#include <iostream>
#include <fstream>
#include "Value.h"

using namespace Operation;

bool RPN::IsDelimeter(char el)
{
	if (string(" =").find(el) != string::npos)
		return true;
	return false;
}

bool RPN::IsOperator(char el)
{
	if (string("+-/*^()").find(el) != string::npos)
		return true;
	return false;
}

int RPN::GetPriority(char el)
{
	switch (el)
	{
	case '(': return 0;
	case ')': return 1;
	case '+': return 2;
	case '-': return 3;
	case '*': return 4;
	case '/': return 4;
	case '^': return 5;
	default: return 6;
	}
}

string RPN::Reverse(string input)
{
	if (input.empty())
		return "Error. The string is empty!";

	string output;
	Stack <char> operStack;


	string temp = "";
	for (int i = 0; i < input.length(); i++)
		if (input[i] != ' ')
			temp += input[i];

	input = temp;

	for (int i = 0; i < input.length(); i++)
	{
		if (IsDelimeter(input[i]))
			continue;

		if (isdigit(input[i]))
		{
			while (!IsDelimeter(input[i]) && !IsOperator(input[i]) && i < input.length())
			{
				output += input[i];
				i++;
			}
			output += " ";
			i--;
		}
		else if (isalpha(input[i]))
		{
			string temp;
			while (!IsDelimeter(input[i]) && !IsOperator(input[i]) && i < input.length())
			{
				temp += input[i];
				i++;
			}
			ifstream fin("Data.txt");
			if (fin.is_open())
			{
				string str;
				while (getline(fin, str))
				{
					string tempStr;
					tempStr = str.substr(0, str.find_first_of('='));
					if (temp == tempStr)
					{
						output += str.substr(str.find_first_of('=')+1, str.length()-1) + " ";
						temp = "";
						break;
					}
				}
				
				output += temp;
			}
			else
				cout << "Failed to open the file" << endl;

			fin.close();
		}

		if (IsOperator(input[i]))
		{
			if (input[i] == '(')
			{
				operStack.Push(input[i]);
			}
			else if (input[i] == ')')
			{
				char s = operStack.Pop();
				try
				{
					while (s != '(')
					{
						output += s;
						s = operStack.Pop();
					}
				}
				catch (exception ex)
				{
					cout << "Perhaps there is no '('" << endl;
				}
			}
			else
			{
				if (!operStack.IsEmpty())
				{
					if (GetPriority(input[i]) <= GetPriority(operStack.Peek()))
					{
						output += operStack.Pop();
						operStack.Push(input[i]);
					}
					else
						operStack.Push(input[i]);
				}
				else
					operStack.Push(input[i]);

			}
		}
	}
	while (!operStack.IsEmpty())
	{
		char el = operStack.Pop();
		if (el == '(')
			cout << "Missing ')'" << endl;
		else
			output += el;
	}

	return output;
}

string RPN::Ñalculation(string input)
{
	string result = "";
	Stack<string> temp;
	string RevInput = Reverse(input);

	for (int i = 0; i < RevInput.length(); i++)
	{
		if (isdigit(RevInput[i]) || isalpha(RevInput[i]))
		{
			string str;

			while (!IsDelimeter(RevInput[i]) && !IsOperator(RevInput[i]))
			{
				str += RevInput[i];
				i++;
				if (i == RevInput.length())
					break;
			}
			temp.Push(str);
			i--;
		}
		else if (IsOperator(RevInput[i]))
		{
			if (temp.Count() < 2)
				return temp.Pop() + " " + RevInput[i];
			Value first(temp.Pop());
			Value second(temp.Pop());

			//double first = temp.Pop();
			//double second = temp.Pop();

			switch (RevInput[i])
			{

			case '+': 
				result = Addition(first, second);
				break;
			case '-':
				result = Subtraction(first, second);
				break;
			case '*':
				result = Multiply(first, second);
				break;
			case '/':
				result = Divide(first, second);
				break;
			case '^':
				result = Pow(first, second);
				break;
			}
			temp.Push(result);
		}
	}
	string str;
	while (!temp.IsEmpty())
		str += temp.Pop() + " ";
	return str;
}

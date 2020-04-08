#include <iostream>
#include <fstream>
#include "RPN.h"

using namespace std;

int main(int argc, char* argv[])
{
    string expression = "";
    for (int i = 0; i < argc; i++)
    {
        if ((string("--expression").find(argv[i]) != string::npos) && (i+1 < argc))
            expression = argv[i+1];
        else if ((string("--variable").find(argv[i]) != string::npos) && (i + 1 < argc))
        {
            ofstream fout("Data.txt");

            int beg = i;
            for (i = i + 1; i < argc; i++)
            {
                if (string(argv[i]).find("=") != string::npos)
                {
                    string variable;
                    double value;
                    
                    bool fl = false;
                    string tempValue;

                    for (int b = 0; b < string(argv[i]).length(); b++)
                    {
                        if (argv[i][b] == '=')
                            fl = true;
                        if (!fl)
                            variable += argv[i][b];
                        else if (isdigit(argv[i][b]))
                            tempValue += argv[i][b];
                    }
                    value = atof(tempValue.c_str());

                    fout << variable << "=" << tempValue << endl;
                    cout << "'" + variable + "' = " + tempValue << endl;
                }
                else
                {
                    cout << "Expression number "<< i-beg << " is written incorrectly!" << endl;
                }
            }
        }
    }
    cout << expression<< " = " <<RPN::Сalculation(expression) << endl;

    //cout << "Otvet: "<<RPN::Сalculation("b*(4+4)*5*3/5+3-17+a") << endl;

}


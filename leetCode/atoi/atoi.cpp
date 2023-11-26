#include <iostream>
#include <vector>
#include <fstream>
#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <vector>

using namespace std;

FILE *fptr;
int number_of_case;
int length_of_array;
int target;
int maximum = 2147483647;
int minimum = -2147483648;
int myAtoi(string str)
{
    int num = 0;
    int sign = 1;
    bool firstPassed = false;
    for (int i = 0; i < str.length(); i++)
    {

        if ((str[i] >= '0' && str[i] <= '9') || str[i] == '-')
        {
            if (str[i] == '-')
            {
                sign = -1;
            }
            else
            {
                firstPassed = true;
                int t = str[i] - '0';

                if ((num < minimum / 10) || (num == minimum / 10 && t > 8))
                {
                    return minimum;
                }
                if ((num > maximum / 10) || (num == maximum / 10 && t > 7))
                {
                    return maximum;
                }
                num = num * 10 + sign * t;
            }
        }
        else
        {
            if (!firstPassed && !isspace(str[i]))
            {
                return 0;
            }
            else
            {
                break;
            }
        }
    }
    return num;
}

void readInput()
{
    ifstream infile;
    string input;
    infile.open("atoi.txt");

    //number_of_case = getline(&line, &len, fp);
    infile >> number_of_case;
    printf("number of case: %d \n", number_of_case);
    while (number_of_case > 0)
    {

        infile >> input;
        int res = myAtoi(input);
        cout << input << " = " << res << "\n";

        --number_of_case;
    }

    infile.close();
}

int main()
{
    readInput();
    return 0;
}

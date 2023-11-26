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

string convert(string s, int numRows)
{
    int c = 0;
    int p = 0;
    vector<vector<char>> cont;
    vector<char> temp;
    for (int i = 0; i < s.length(); i++)
    {
        if (c - p == 0 || c - p == numRows - 1)
        {
            temp.push_back(s[i]);
            p = c;
        }
        else
        {
            int r = numRows - (c - p) - 1;
            if( r < 0) {
                r = 0;
            }
            int j = 0;
            for (int j = 0; j < numRows; j++)
            {
                if (j != r)
                {
                    temp.push_back(1);
                }
                else
                {
                    temp.push_back(s[i]);
                }
            }
        }
        if (temp.size() == numRows)
        {
            cont.push_back(temp);
            temp.clear();
            c++;
        }
    }

    for (int j = 0; j < numRows; j++)
    {
        if (j >= temp.size())
        {
            temp.push_back(1);
        }
    }
    cont.push_back(temp);

    string res = "";
    for (int j = 0; j < numRows; j++)
    {
        for (int i = 0; i < cont.size(); i++)
        {
            if (cont[i][j] != 1)
            {
                res += cont[i][j];
            }
        }
    }
    return res;
}

void readInput()
{
    ifstream infile;
    string input;
    int row;
    string output;
    infile.open("zigzag.txt");

    //number_of_case = getline(&line, &len, fp);
    infile >> number_of_case;
    printf("number of case: %d \n", number_of_case);
    while (number_of_case > 0)
    {

        infile >> input;
        infile >> row;
        infile >> output;
        string res = convert(input, row);
        cout << res << "\n";
        if (res == output)
        {
            cout << "**OK\n";
        }
        else
        {
            cout << "***NOT OK \n";
        }
        --number_of_case;
    }

    // while ((read = getline(&line, &len, fp)) != -1) {
    //     printf("Retrieved line of length %zu:\n", read);
    //     printf("%s", line);
    // }
    infile.close();
}

int main()
{
    readInput();
    return 0;
}

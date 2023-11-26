#include <iostream>
#include <vector>
#include <fstream>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

FILE *fptr;
int number_of_case;
int length_of_array;
int target;

bool isMatch(string s, string p)
{
    int i = 0;
    int j = 0;
    while (1)
    {
        if (s[i] == p[i] || p[i] == '.')
        {
            i++, j++;
        }
        if (p[i] == '*')
        {
            int cI = i;
            int cJ = j - 1;
            while (cI < s.length() && cJ >= 0)
            {
                bool match = false;
                for (int k = i, l = cJ; k <= cI, l <= j; k++, l++)
                {
                    if (s[k] != p[l] && p[l] == '.')
                    {
                        match = false;
                        break;
                    }
                    else
                    {
                        match = true;
                    }
                }
                if (match)
                {
                    i = cI + 1;
                    cJ = j;
                }
                cI++, cJ--;
            }
            j++;
        }
        if (i == s.length())
        {
            return true;
        }
        if (j == p.length())
        {
            return false;
        }
    }
}

void readInput()
{
    ifstream infile;
    string str, patt;
    infile.open("regex.txt");

    //number_of_case = getline(&line, &len, fp);
    infile >> number_of_case;
    printf("number of case: %d \n", number_of_case);
    while (number_of_case > 0)
    {

        infile >> str;
        infile >> patt;

        bool res = isMatch(str, patt);
        cout << res << "\n";
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

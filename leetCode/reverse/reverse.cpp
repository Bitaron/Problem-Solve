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
int maximum = 2147483648 -1;
int minimum = -(2147483648);
int reverse(int x)
{
 //   cout << maximum << " " << minimum;
    bool sign = false;
    int nn, r, range;
    if (x < 0)
    {
        sign = true;
        if( x < maximum / -1) {
            return 0;
        }
        x = -1 * x;
    }
    nn = 0;
    r = 1;

    while (x > 9)
    {
        int t = x % 10;
        x = x / 10;
        if (nn > maximum / 10)
        {
            return 0;
        }
        nn = nn * 10 + t;
    }

    if (nn > maximum / 10)
    {
        return 0;
    }
    nn = nn * 10 + x;

    if (sign)
    {
        return -1 * nn;
    }
    else
    {
        return nn;
    }
}

void readInput()
{
    ifstream infile;
    int input;
    infile.open("reverse.txt");

    //number_of_case = getline(&line, &len, fp);
    infile >> number_of_case;
    printf("number of case: %d \n", number_of_case);
    while (number_of_case > 0)
    {

        infile >> input;
        int res = reverse(input);
        cout << input << " = " << res << "\n";

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

#include <iostream>
#include <vector>
#include <fstream>
#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

FILE *fptr;
int number_of_case;
int length_of_array;
int target;

int expandFromCenter(string str, int start, int end)
{
    while (start >= 0 && end < str.length())
    {
        if (str[start] == str[end])
        {
            start--;
            end++;
        }
        else
        {
            break;
        }
    }
    start++;
    end--;
    if (start <= end)
    {
        return end - start + 1;
    }
    else
    {
        return 0;
    }
}

string longestPalindrome(string str)
{
    if (str.empty())
    {
        return "";
    }
    int s = 0;
    int e = 0;
    for (int i = 0; i < str.length(); i++)
    {
        int len1 = expandFromCenter(str, i, i);
        int len2 = expandFromCenter(str, i, i + 1);
        int len = max(len1, len2);
        if (len > e - s)
        {
            s = i - (len - 1) / 2;
            e = i + (len / 2);
        }
    }
    return str.substr(s, e - s + 1);
}

void readInput()
{
    ifstream infile;
    string input;
    infile.open("pallindrom.txt");

    //number_of_case = getline(&line, &len, fp);
    infile >> number_of_case;
    printf("number of case: %d \n", number_of_case);
    while (number_of_case > 0)
    {

        infile >> input;

        string res = longestPalindrome(input);
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

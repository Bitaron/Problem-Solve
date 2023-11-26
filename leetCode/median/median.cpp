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

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> total;
    vector<int>::iterator i1 = nums1.begin();
    vector<int>::iterator i2 = nums2.begin();
    while (i1 != nums1.end() && i2 != nums2.end())
    {
        if (*i1 < *i2)
        {
            total.push_back(*i1);
            i1++;
        }
        else
        {
            total.push_back(*i2);
            i2++;
        }
    }

    while (i1 != nums1.end())
    {
        total.push_back(*i1);
        i1++;
    }

    while (i2 != nums2.end())
    {
        total.push_back(*i2);
        i2++;
    }

    int size = total.size();
    int mid = size / 2;
    if (size % 2 == 0)
    {
        double median = ((double) total.at(mid) + (double) total.at(mid - 1)) / 2.0;
        return median;
    }
    else
    {
        return (double) total.at(mid);
    }
}

void readInput()
{
    ifstream infile;
    vector<int> a1;
    vector<int> a2;
    infile.open("median.txt");

    //number_of_case = getline(&line, &len, fp);
    infile >> number_of_case;
    printf("number of case: %d \n", number_of_case);
    while (number_of_case > 0)
    {
        for (int i = 0; i < 2; i++)
        {
            vector<int> temp;

            infile >> length_of_array;
            for (int j = 0; j < length_of_array; j++)
            {
                int num;
                infile >> num;
                temp.push_back(num);
            }
            if (i == 0)
            {
                a1 = temp;
            }
            else
            {
                a2 = temp;
            }
        }
        double res = findMedianSortedArrays(a1, a2);
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

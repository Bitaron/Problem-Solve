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
int minimum = -(2147483648);

bool isPalindrome(int x) {
    if(x< 0) {
        return false;
    } 
    if(0 == x || x<=9) {
        return true;
    }
    if(x % 10 == 0) {
        return false;
    }

    int num = x;
    int revNum = 0;
    do{
        int t = num % 10;
        if(revNum > (maximum - t)/10) {
            return false;
        }
        revNum = revNum*10 + t;
        num = num/10;
    }while (num > 0);
    
    if(x == revNum) {
        return true;
    }else{
        return false;
    }
  
}

void readInput()
{
    ifstream infile;
    int input;
    infile.open("numPalin.txt");

    //number_of_case = getline(&line, &len, fp);
    infile >> number_of_case;
    printf("number of case: %d \n", number_of_case);
    while (number_of_case > 0)
    {

        infile >> input;
        bool res = isPalindrome(input);
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

#include <iostream>
#include <vector>
#include <fstream>
#include <iostream>
#include<bits/stdc++.h> 

using namespace std;

FILE *fptr;
int number_of_case;
int length_of_array;
int target;

int lengthOfLongestSubstring(string str) {
    int s =0;
    int e = str.length();
    vector<char> cont;
    int current=0, max=0;
    for(int i=s; i<e; i++) {
        char c = str[i];
        vector<char>::iterator it = find(cont.begin(), cont.end(), c);
        if(it != cont.end()) {
            current = cont.size();
            if(current > max) {
                max = current;
            }
            cont.erase(cont.begin(), ++it);
        }
        cont.push_back(c);
        
    }
    if(cont.size() > max) {
        max = cont.size();
    }
    return max;

}

void readInput()
{
    ifstream infile; 
    string input;
    infile.open("substring.txt"); 
   

    //number_of_case = getline(&line, &len, fp);
    infile >> number_of_case;
    printf("number of case: %d \n", number_of_case);
    while (number_of_case > 0)
    {
       
        infile >> input;

        int res = lengthOfLongestSubstring(input);
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

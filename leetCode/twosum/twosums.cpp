#include <iostream> 
#include <vector>

using namespace std;

FILE *fptr;
int number_of_case;
int length_of_array;
int target;


void solveProblem(vector<int>& input_array, int target){
    printf("in solve");
}

void readInput() {
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    vector<int> input_array;

    fp = fopen("twosums.txt", "r");
    if (fp == NULL) {
        printf("file pointer null \n");
        return;
    }
    
    //number_of_case = getline(&line, &len, fp);
    fscanf(fp, "%d", &number_of_case);
    printf("number of case: %d \n", number_of_case);
    while(number_of_case > 0 ) {
        fscanf(fp, "%d", &length_of_array);

        for(int i=0 ; i<length_of_array; i++) {
            int temp;
            fscanf(fp, "%d", &temp);
            input_array.push_back(temp);
        }
        fscanf(fp, "%d", &target);
        solveProblem(input_array, target);
        --number_of_case;
    }
    

    // while ((read = getline(&line, &len, fp)) != -1) {
    //     printf("Retrieved line of length %zu:\n", read);
    //     printf("%s", line);
    // }

    fclose(fp);
 
}

int main() {
    readInput();
    return 0;
}

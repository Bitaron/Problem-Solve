#include<stdio.h>
#include<stdlib.h>

FILE *fptr;
int number_of_case;
int length_of_array;
int target;


void solveProblem(int* input_array, int length_of_array){
    printf("in solve");
}

void readInput() {
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    int *input_array;

    fp = fopen("twosum.txt", "r");
    if (fp == NULL) {
        printf("file pointer null \n");
        return;
    }
    
    //number_of_case = getline(&line, &len, fp);
    fscanf(fp, "%d", &number_of_case);
    printf("number of case: %d \n", number_of_case);
    while(number_of_case > 0 ) {
        fscanf(fp, "%d", &length_of_array);
        input_array = (int*) malloc(length_of_array * sizeof(int));
        for(int i=0 ; i<length_of_array; i++) {
            int temp;
            fscanf(fp, "%d", &temp);
            input_array[i] = temp;
        }
        fscanf(fp, "%d", &target);
        solveProblem(input_array, length_of_array);
        --number_of_case;
    }
    

    // while ((read = getline(&line, &len, fp)) != -1) {
    //     printf("Retrieved line of length %zu:\n", read);
    //     printf("%s", line);
    // }

    fclose(fp);
    if (line)
        free(line);
}

int main() {
    readInput();
    return 0;
}

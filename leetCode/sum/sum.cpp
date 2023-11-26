#include <iostream> 
#include <vector>

using namespace std;

FILE *fptr;
int number_of_case;
int length_of_array;
int target;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

// int getNumber(ListNode* l) {
//     int num = l->val;
//     l = l->next;
//     int count = 10;
//     while(l != NULL) {
//         int tem = l->val * count;
//         num += tem;
//         count *= 10;
//         l = l->next;
//     }
//     return num;
// }

// ListNode* getListNode(int number) {
//     string str = to_string(number);
//     ListNode* head;
//     ListNode* prev;
//     int i = 0;
//     for(i = str.length()-1; i>=0; i--) {
//         int num = str[i] - '0';
//         ListNode* temp = new ListNode(num);
//         if(i == str.length()-1) {
//             head = temp;
//             prev = temp;
//         }else{
//             prev->next = temp;
//             prev = temp;
//         }
//     }
//     return head;
// }

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* res ;
    ListNode* prev;
    int carry = 0;
    int i = 0;
    int num;
    int val;
    while((l1 != NULL) || (l2 != NULL)) { 
        num = carry;
        if(l1 != NULL){
            num+= l1->val;
            l1 = l1->next;
        }
        if(l2 != NULL){
            num+= l2->val;
            l2 = l2->next;
        }
        if(num > 9) {
            val = num - 10;
            carry = 1;
        }else{
            val = num;
            carry = 0;
        }
        ListNode* temp = new ListNode(val);
        if(i == 0) {
            res = temp;
            prev = temp;
            i++;
        }else {
            prev->next = temp;
            prev = temp;
        }
    }
    if(carry != 0) {
        ListNode* t = new ListNode(carry);
        prev->next = t;
    }
    ListNode* temp = res;
    while (temp != NULL)
    {
        cout<<temp->val<<"";
        temp = temp->next;
    }
    cout<<"\n";
    return res;
    
}



void readInput() {
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    ListNode* l1 ;
    ListNode* l2;
    ListNode* prev;

    fp = fopen("sum.txt", "r");
    if (fp == NULL) {
        printf("file pointer null \n");
        return;
    }
    
    
    //number_of_case = getline(&line, &len, fp);
    fscanf(fp, "%d", &number_of_case);
    printf("number of case: %d \n", number_of_case);
    while(number_of_case > 0 ) {
        int array_count = 2;
        while(array_count > 0){
            ListNode* head;
            
            fscanf(fp, "%d", &length_of_array);
            for(int i=0 ; i<length_of_array; i++) {
                int temp;
                fscanf(fp, "%d", &temp);
                ListNode* temp_list = new ListNode(temp);
                if(i == 0) {
                    head = temp_list;
                    prev = temp_list;
                }else {
                    prev->next = temp_list;
                    prev = temp_list;
                }
            }
             if(array_count == 2) {
                l1 = head;
            }else
            {
                l2 = head;
            }
            head = NULL;
            array_count--;
        }
        ListNode* result = addTwoNumbers(l1, l2);
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

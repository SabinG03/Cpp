#include <iostream>
#include <cstring>
using namespace std;

/*
    Loops through the string till it reaches the end.
    Increases by 1 for str and for length 
    returns len which is the length of the string
*/
unsigned int length(const char* str){
    unsigned int len = 0;
    while (*str!= 0) {
        str++;
        len++;
    }
    return len;
}
/*
    While loop to go through the source string (while its not = 0) 
    and stops once it reaches the end, for each iteration it copies
    the character from src to dest.
*/
char* copy(char* dest, const char* src){
    int i =0;
    while(src[i] !='\0') {
        dest[i] =src[i];
        i++;
    }
    dest[i]='\0';
}
/*
    It accepts both upper and lower case C. While loop to go to end
    Checks if current matches to either lower or upper, if a 
    match is found return i or else return -1.
*/
int indexOf(char c, const char* str){
    int i = 0;
    char lowerC= (c >='A' && c <= 'Z')? c + ('a' - 'A'): c;
    char upperC = (c>= 'a'&&c <= 'z')? c - ('a' - 'A') : c;

    while (str[i] !=0){
        if (str[i] ==lowerC || str[i] == upperC) {
            return i;
        }
        i++;
    }
    return -1;
}
/*
    While loop to go to end, Validator to check if start (i) is
    greater than end, if i is less than 0 or end(j) is longer than 
    the length it returns NULL. Uses a loop to copy chars starting 
    at i till j. It marks the end of the string using \0 then it 
    returns the result
*/

char* substring(int i, int j, const char* str){
    int length =0;
    while(str[length] != '\0') {
       length++;
    }

    if(i >j|| i < 0||j >=length) {
        cout <<"Invalid" << endl;
        return nullptr;
    }

    static char result[100];
    for (int k= 0; k <= j - i; ++k) {
        result[k]= str[i + k];
    }
    result[j -i+1] = '\0';
    return result;
} 

/*
    Counts the length of given string in the while loop. Makes
    a new string called result. The loop checks if it matches with
    c, if it does it copies p in the same location in result, 
    else it copies same char from string. After its all added
    it gives it a null (\0) to show end of word then retuns it 
*/
char* replace(char c, char p, const char* str){
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    char* result = new char[length +1];
    for (int i = 0; i< length;++i) {
        if (str[i] ==c) {
            result[i] = p; 
        } else {
            result[i]= str[i]; 
        }
    }
    result[length] ='\0';
    return result;
}


////////////////////////////////////////////////////
                // Test Cases
////////////////////////////////////////////////////

void length_test_case() {
    cout << "////////////////////////////////" << endl;
    cout << "TEST CASES" << endl;
    cout << "////////////////////////////////" << endl;
    const char* test_input ="queen";
    unsigned int expected_output = 5;
    unsigned int result = length(test_input);
    if (result == expected_output) {
        cout << "length test case PASSED" << endl;
    } else {
        cout << "length test case FAILED" << endl;
    }
}

void copy_test_case() {
    const char* test_input = "world";
    char dest[100];
    char expected_output[100];
    copy(dest, test_input);
    snprintf(expected_output, sizeof(expected_output), "%s", test_input); // Prepare expected output
    if (strcmp(dest, expected_output) == 0) {
        cout << "copy test case PASSED" << endl;
    } else {
        cout << "copy test case FAILED" << endl;
    }
}

void indexOf_test_case() {
    const char* test_input = "example";
    char char_to_find = 'x';
    int expected_output = 1;
    int result = indexOf(char_to_find, test_input);
    if (result == expected_output) {
        cout << "indexOf test case PASSED" << endl;
    } else {
        cout << "indexOf test case FAILED" << endl;
    }
}

void substring_test_case() {
    const char* test_input = "substring";
    int start = 0;
    int end = 3;
    const char* expected_output = "subs";
    char* result = substring(start, end, test_input);
    if (result && strcmp(result, expected_output) == 0) {
        cout << "substring test case PASSED" << endl;
    } else {
        cout << "substring test case FAILED" << endl;
    }
}

void replace_test_case() {
    const char* test_input = "replace";
    char char_to_replace = 'r';
    char replacement_char = 'R';
    const char* expected_output = "Replace";
    char* result = replace(char_to_replace, replacement_char, test_input);
    if (result && strcmp(result, expected_output) == 0) {
        cout << "replace test case PASSED" << endl;
    } else {
        cout << "replace test case  FAILED" << endl;
    }
    delete[] result;
}


int main() {

    char input[100];
    char dest[100];

////////////////////////////////////////////////////
                // Run Test Cases
////////////////////////////////////////////////////

    length_test_case();
    copy_test_case();
    indexOf_test_case();
    substring_test_case();
    replace_test_case();

////////////////////////////////////////////////////
                //Question 1
////////////////////////////////////////////////////

    cout << "////////////////////////////////" << endl;
    cout << "Question 1 : String Length" << endl;
    cout << "Enter a string: ";
    cin >> input; 
    cout << "////////////////////////////////" << endl;
    cout << "Question 1 : String Length" << endl;
    unsigned int len = length(input);
    cout << "Length of String is : " << len << endl;

////////////////////////////////////////////////////
                //Question 2
////////////////////////////////////////////////////    

    cout << "////////////////////////////////" << endl;
    cout << "Question 2 : String Copy" << endl;
    copy(dest, input);
    cout << "Original : " << input << endl;
    cout << "Result : " << dest << endl;

////////////////////////////////////////////////////
                //Question 3
////////////////////////////////////////////////////

    cout << "////////////////////////////////" << endl;
    cout << "Question 3 : Index Of (C/c)" << endl;
    char y = 'c';
    int index = indexOf(y, input);
    if (index != -1) {
        cout << "'" << y << "' is at index " << index << endl;
    } else {
        cout << "-1" << endl;
    }

////////////////////////////////////////////////////
                //Question 4
////////////////////////////////////////////////////

    cout << "////////////////////////////////" << endl;
    cout << "Question 4 : Substring" << endl;
    int start, end;
    cout << "Index Start: ";
    cin >> start;
    cout << "Index End: ";
    cin >> end;

    char* result = substring(start, end, input);
    if (result) {
        cout << "Extracted substring: " << result << endl;
    }

////////////////////////////////////////////////////
                //Question 5
////////////////////////////////////////////////////

    cout << "////////////////////////////////" << endl;
    cout << "Question 5 : Replace " << endl;
    char c, p;
    cout << "Replace: ";
    cin >> c;
    cout << "With: ";
    cin >> p;

    char* newRes= replace(c,p,input);
    cout << "Original string: " << input<< endl;
    cout << "New string: " <<newRes << endl;
    cout << "////////////////////////////////" << endl;

    return 0;
}

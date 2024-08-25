#include <iostream>
using namespace std;

// Function to calculate the smaller number:
int min(int m, int n) {
    return (m < n) ? m : n;
}

// Function for calculating string length:
int strlen(const char str[]) {
    int len = 0;
    while (str[len]) {
        len++;
    }
    return len;
}

// Function to concatenate 2 strings:
void concat(const char str1[], const char str2[]) {
    int m = strlen(str1);
    int n = strlen(str2);
    int size = m + n + 1;
    char conc_str[size];
    for (int i = 0; i < m; i++) {
        conc_str[i] = str1[i];
    }
    for (int i = m; i < m + n; i++) {
        conc_str[i] = str2[i - m];
    }
    conc_str[m + n] = '\0'; // Add null terminator
    cout << "Concatenated string: " << conc_str << endl;
}

// Function to compare 2 strings:
void strcomp(const string& s1, const string& s2) {
    if (s1 != s2) {
        if (s1 < s2) {
            cout << s1 << " is smaller than " << s2 << endl;
        } else {
            cout << s2 << " is smaller than " << s1 << endl;
        }
    } else {
        cout << s1 << " = " << s2 << endl;
    }
}

// Function to insert a substring into a string
void insertSubstring(char mainStr[], const char subStr[], int pos) {
    int mainLen = strlen(mainStr);
    int subLen = strlen(subStr);

    // Shift the characters of the main string to the right to make space for the substring
    for (int i = mainLen; i >= pos; i--) {
        mainStr[i + subLen] = mainStr[i];
    }

    // Insert the substring into the main string
    for (int i = 0; i < subLen; i++) {
        mainStr[pos + i] = subStr[i];
    }

    // Add the null terminator at the end
    mainStr[mainLen + subLen] = '\0';
}

// Function to delete a substring from the main string:
void deleteSubstring(char* str, const char* substr) {
    int lenStr = strlen(str);
    int lenSubstr = strlen(substr);

    // Iterate through the main string
    for (int i = 0; i <= lenStr - lenSubstr; ++i) {
        int j;
        // Check if substring matches
        for (j = 0; j < lenSubstr; ++j) {
            if (str[i + j] != substr[j]) {
                break;
            }
        }
        // If substring is found, shift the remaining characters to the left
        if (j == lenSubstr) {
            for (int k = i; k <= lenStr - lenSubstr; ++k) {
                str[k] = str[k + lenSubstr];
            }
            lenStr -= lenSubstr;
            i--; // Check again in case of multiple occurrences
        }
    }
}

int main() {
    char str1[] = "Hello";
    char str2[] = "Sir";
    cout << "String1: " << str1 << endl;
    cout << "String2: " << str2 << endl;

    // String length:
    int len = strlen(str1);
    cout << "Length of String1: " << len << endl;

    // String Concatenation:
    concat(str1, str2);

    // String compare:
    string c1 = "My Name is Alvin";
    string c2 = "My Name is Parth";
    cout << "String Compare: ";
    strcomp(c1, c2);

    // Inserting Substring:
    char mainStr[100], subStr[50];
    int position;
    
    cout << "Enter the main string: ";
    cin.getline(mainStr, 100);
    cout << "Enter the substring: ";
    cin.getline(subStr, 50);
    cout << "Enter the position where the substring should be inserted: ";
    cin >> position;
    if (position < 0 || position > strlen(mainStr)) {
        cout << "Invalid position!" << endl;
    } else {
        insertSubstring(mainStr, subStr, position);
        cout << "String after insertion: " << mainStr << endl;
    }

    // Deletion of substring:
    char str[100];
    char substr[100];
    cin.ignore(); // To clear the newline character from the buffer
    cout << "Enter the main string: ";
    cin.getline(str, 100);
    cout << "Enter the substring to delete: ";
    cin.getline(substr, 100);
    deleteSubstring(str, substr);
    cout << "String after deletion: " << str << endl;

    return 0;
}












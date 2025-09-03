#include <iostream>
#include <cstring>
using namespace std;

void concatenate_strings() {
    int size1,size2;
    cout << "Enter size of first string: ";
    cin >> size1;
    cout << "Enter size of second string: ";
    cin >> size2;
    cout << "Enter first string: ";
    char str1[size1 ];
    cin >> str1;
    cout << "Enter second string: ";
    char str2[size2 ];
    cin >> str2;
    char res[size1+size2+1];
    int i = 0, j = 0;
    while (str1[i] != '\0') {
        res[j++] = str1[i++];
    }
    i = 0;
    while (str2[i] != '\0') {
        res[j++] = str2[i++];
    }
    res[j] = '\0';
    cout << "Concatenated string: " << res << endl;
}
void reverse_string() {
    int size;
    cout << "Enter size of string: ";
    cin >> size;
    cout << "Enter string: ";
    char str[size];
    cin >> str;
    for(int i = 0; i < size/2; i++) {
        char temp = str[i];
        str[i] = str[size - i - 1];
        str[size - i - 1] = temp;
    }
    cout << "Reversed string: " << str << endl;
}
void delete_vowels() {
    int size;
    cout << "Enter size of string: ";
    cin >> size;
    cout << "Enter string: ";
    char str[size];
    cin >> str;
    char res[size];
    int j = 0;
    for(int i = 0; i < size; i++) {
        if (str[i] != 'a' && str[i] != 'e' && str[i] != 'i' && str[i] != 'o' && str[i] != 'u' &&
            str[i] != 'A' && str[i] != 'E' && str[i] != 'I' && str[i] != 'O' && str[i] != 'U') {
            res[j++] = str[i];
        }
        else{
            continue;
        }
    }
    res[j] = '\0';
    cout << "String after deleting vowels: " << res << endl;
}
void sort_string() {
    int size;
    cout << "Enter size of string: ";
    cin >> size;
    cout << "Enter string: ";
    char str[size];
    cin >> str;
    for(int i = 0; i < size - 1; i++) {
        for(int j = i + 1; j < size; j++) {
            if (str[i] > str[j]) {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
    cout << "Sorted string: " << str << endl;
}
void lowercase() {
    int size;
    cout << "Enter size of string: ";
    cin >> size;
    cout << "Enter string: ";
    char str[size];
    cin >> str;
    for(int i = 0; i < size; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;
        }
    }
    cout << "String in lowercase: " << str << endl;
}
int main(){
    int choice;
    cout << "String Related Programs:\n";
    cout << "1. Concatenate two strings\n";
    cout << "2. Reverse a string\n";
    cout << "3. Delete all vowels from a string\n";
    cout << "4. Sort the string in alphabetical order\n";
    cout << "5. Convert uppercase to lowercase\n";
    cout << "6. EXIT\n";
    cout << "Enter your choice : ";
    cin >> choice;
    while(choice != 6) {
    switch(choice) {
        case 1:
            concatenate_strings();
            break;
        case 2:
            reverse_string();
            break;
        case 3:
            delete_vowels();
            break;
        case 4:
            sort_string();
            break;
        case 5:
            lowercase();
            break;
        default:
            cout << "Enter a valid choice " << endl;
        }
        cout << "\nEnter your choice : ";
        cin >> choice;
    }
    return 0;
}
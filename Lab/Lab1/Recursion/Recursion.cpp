#include <iostream>
#include <string>

using namespace std;

// Bai 1: Print array
// printArray(5);
// 0, 1, 2, 3, 4, 5
void printArray(int n){
    if (n==0){
        cout << n;
        return;
    }
    printArray(n-1);
    cout << ", " << n;
}

// Bai 2: Print pattern
// printPattern(14);
// 14 9 4 -1 4 9 14

void printPattern(int n) { 
    if (n <= 0){
        cout << n;
        return;
    }
    cout << n << " ";
    printPattern(n - 5);
    cout << " " << n;
}

// Bai 3: Find max
int findMax(int* arr, int n){
    if (n == 1) return arr[0];
    return max(arr[n-1], findMax(arr, n-1));
}

// Bai 4: Is Palindrome
// cout << isPalindrome("do geese see god");
// 1

bool isPalindromeHelper(string &str, int head, int tail){
    if (head >= tail) return true;
    if (str[head] == ' ') return isPalindromeHelper(str, head + 1, tail);
    if (str[tail] == ' ') return isPalindromeHelper(str, head, tail - 1);
    if (str[head] == str[tail]){
        return isPalindromeHelper(str, head + 1, tail - 1);
    }
    else return false;
}

bool isPalindrome(string str) { 
    return isPalindromeHelper(str, 0, str.length() - 1);
}

// Bai 5: Find GCD
int findGCD(int a,int b){
    if (b == 0) return a;
    else return findGCD(b, a%b);
}

// Bai 6: Find LCM
int findLCM(int a, int b){
    return (a*b) / findGCD(a, b);
}

// Bai 7: Expand string
// cout << expand("2(x0(y))3(z)") << "\n";
// xxzzz

// cout << expand("2(ab3(cde)x)") << "\n";
// abcdecdecdexabcdecdecdex

int findEnd(string s, int start, int count) {
    int end = start;
    if (count == 0) return end;
    end++;
    if (s[end] == '(') count++;
    if (s[end] == ')') count--;
    return findEnd(s, end, count);
}

string repeat(string s, int n){    
    if (n == 0) {
        return "";
    }
    else {
        return s + repeat(s, n - 1);
    }
}

string expand(string s, int i = 0){
    if (i == (int)s.length()){
        return "";
    }
    else{
        if (isalpha(s[i])) {
            return s[i] + expand(s, i + 1);
        }
        else if (isdigit(s[i])){
            int n = s[i] - '0';     //chuyen tu char thanh int 
            i++; 
            int start = i + 1;
            int count = 1;      
            int end = findEnd(s, start, count);
            string sub = s.substr(start, end - start);
            string expanded = expand(sub);
            return repeat(expanded, n) + expand(s, end + 1);
        }
    }
    return "";
}

// Bai 8: Print Hailstone
// Hailstone Sequences follow these rules: 
    // If a number is even, divide it by 2 
    // If a number is odd, multiply it by 3 and add 1
    // Stop at 1

// printHailstone(3);
// 3 10 5 16 8 4 2 1

void printHailstone(int number){
    if (number == 1) {
        cout << number;
        return;
    }
    
    if (number % 2 == 0){
        cout << number << " ";
        printHailstone(number / 2);
    } else{
        cout << number << " ";
        printHailstone(number * 3 + 1);
    }
}

// Bai 9: Array to Int
// char str[] = "2020";
// printf("%d", myArrayToInt(str, 4));
// 2020

int myArrayToInt(char *str, int n){ 
    if (n == 0) return 0;
    else{
        int last = str[n - 1] - '0';
        int tmp = myArrayToInt(str, n-1);
        return tmp * 10 + last;
    }
}

// Bai 10: Strlen
int strLen(char* str){
    if (!str[0]) return 0;
    return 1 + strLen(str+1); 
}

int main() {
    // Bai 1
    printArray(5);
    cout << endl;

    // Bai 2
    printPattern(14);
    cout << endl;

    // Bai 3
    int arr[] = {10, 5, 7, 9, 15, 6, 11, 8, 12, 2};
    cout << findMax(arr, 10) << endl;

    // Bai 4
    if (isPalindrome("do geese see god")) cout << "True" << endl;
    else cout << "False" << endl;

    // Bai 5
    cout << findGCD(124,32) << endl;

    // Bai 6
    cout << findLCM(32, 128) << endl;

    // Bai 7
    // cout << expand("2(a)b") << endl;
    cout << expand("2(ab3(cde)x)") << endl;

    // Bai 8
    printHailstone(3);
    cout << endl;

    // Bai 9
    char array[] = "2020";
    printf("%d", myArrayToInt(array, 4));
    cout << endl;

    // Bai 10
    char str[] = "Truong DH Bach Khoa";
    cout << strLen(str) << endl;

    return 0;
}

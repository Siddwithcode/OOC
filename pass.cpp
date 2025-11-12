#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class PasswordChecker {
private:
    string password;
    bool hasUppercase;
    bool hasLowercase;
    bool hasDigit;
    bool hasSpecialChar;
    int length;

public:
    // Constructor
    PasswordChecker(string pwd) {
        password = pwd;
        hasUppercase = false;
        hasLowercase = false;
        hasDigit = false;
        hasSpecialChar = false;
        length = pwd.length();
    }

    // Method to check password strength
    void checkStrength() {
        // Loop through each character in the password
        for (int i = 0; i < length; i++) {
            char ch = password[i];

            // Check for uppercase letters
            if (isupper(ch)) {
                hasUppercase = true;
            }
            // Check for lowercase letters
            else if (islower(ch)) {
                hasLowercase = true;
            }
            // Check for digits
            else if (isdigit(ch)) {
                hasDigit = true;
            }
            // Check for special characters
            else if (!isalnum(ch)) {
                hasSpecialChar = true;
            }
        }
    }

    // Method to get strength level
    string getStrengthLevel() {
        int score = 0;

        if (hasUppercase) score++;
        if (hasLowercase) score++;
        if (hasDigit) score++;
        if (hasSpecialChar) score++;
        if (length >= 8) score++;

        if (score <= 1) {
            return "Very Weak";
        } else if (score == 2) {
            return "Weak";
        } else if (score == 3) {
            return "Moderate";
        } else if (score == 4) {
            return "Strong";
        } else {
            return "Very Strong";
        }
    }

    // Method to display results
    void displayResults() {
        cout << "\n========== PASSWORD ANALYSIS ==========" << endl;
        cout << "Password: " << password << endl;
        cout << "Length: " << length << endl;
        cout << "----------------------------------------" << endl;
        cout << "Uppercase letters: " << (hasUppercase ? "Yes" : "No") << endl;
        cout << "Lowercase letters: " << (hasLowercase ? "Yes" : "No") << endl;
        cout << "Digits (0-9): " << (hasDigit ? "Yes" : "No") << endl;
        cout << "Special characters: " << (hasSpecialChar ? "Yes" : "No") << endl;
        cout << "----------------------------------------" << endl;
        cout << "Strength Level: " << getStrengthLevel() << endl;
        cout << "========================================\n" << endl;
    }
};

int main() {
    string pwd;

    cout << "===== PASSWORD STRENGTH CHECKER =====" << endl;
    cout << "Enter a password to check: ";
    getline(cin, pwd);

    // Create object and check password
    PasswordChecker checker(pwd);
    checker.checkStrength();
    checker.displayResults();

    return 0;
}
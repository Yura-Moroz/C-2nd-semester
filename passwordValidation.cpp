#include <string>
#include <iostream>

bool hasUpperCase(const std::string& password) {
    for (char c : password) {
        if (isupper(c)) {
            return true;
        }
    }
    return false;
}

bool hasLowerCase(const std::string& password) {
    for (char c : password) {
        if (islower(c)) {
            return true;
        }
    }
    return false;
}

bool hasDigit(const std::string& password) {
    for (char c : password) {
        if (isdigit(c)) {
            return true;
        }
    }
    return false;
}

bool hasSpecialChar(const std::string& password) {
    std::string specialChars = "!@#$%^&*()_+-=[]{}|;':\"<>,.?/\\";
    for (char c : password) {
        if (specialChars.find(c) != std::string::npos) {
            return true;
        }
    }
    return false;
}

int main() {
    std::string password;
    std::getline(std::cin, password);

    bool isValid = true;
    if (password.length() < 8) {
        std::cout << "Password must be at least 8 characters long." << std::endl;
        isValid = false;
    }

    if (!hasUpperCase(password)) {
        std::cout << "Password must contain at least one uppercase letter." << std::endl;
        isValid = false;
    }

    if (!hasLowerCase(password)) {
        std::cout << "Password must contain at least one lowercase letter." << std::endl;
        isValid = false;
    }

    if (!hasDigit(password)) {
        std::cout << "Password must contain at least one digit." << std::endl;
        isValid = false;
    }

    if (!hasSpecialChar(password)) {
        std::cout << "Password must contain at least one special character." << std::endl;
        isValid = false;
    }

    if (isValid) {
        std::cout << "Password is valid." << std::endl;
    }

    return 0;
}

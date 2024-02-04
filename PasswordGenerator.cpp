#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>

template <typename T>
class PasswordGenerator {
public:
    PasswordGenerator(int length) : passwordLength(length) {
        std::srand(static_cast<unsigned int>(std::time(0)));
    }

    std::string generatePassword() {
        const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
        const int charsetSize = sizeof(charset) - 1;

        password.reserve(passwordLength);

        for (int i = 0; i < passwordLength; ++i) {
            password += charset[rand() % charsetSize];
        }

        return password;
    }

    bool checkPasswordLength() const {
        return password.length() >= 8; // Минимальная длина пароля
    }

    bool checkPasswordDigit() const {
        return std::any_of(password.begin(), password.end(), ::isdigit);
    }

    void printPassword() const {
        std::cout << "Сгенерированный пароль: " << password << std::endl;
    }

    bool checkPassword() const {
        return checkPasswordLength() && checkPasswordDigit();
    }

private:
    int passwordLength;
    std::string password;
};

int main() {
    int passwordLength;
    std::cout << "Введите длину пароля: ";
    std::cin >> passwordLength;

    PasswordGenerator<int> passwordGenerator(passwordLength);

    passwordGenerator.generatePassword();
    passwordGenerator.printPassword();

    if (passwordGenerator.checkPassword()) {
        std::cout << "Пароль прошел проверку." << std::endl;
    } else {
        std::cout << "Пароль не соответствует требованиям." << std::endl;
    }

    return 0;
}
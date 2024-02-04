## *6 задание по MarkDown*
### Написал шаблонный класс генератор строки↔пароля
#### А также функции-методы i/o валидации ⬇
![image](https://github.com/BeautifulSosalochka/markdownRepo/assets/85421342/708a7cb1-6e76-43d9-8b2f-ef52b8e3a4bd)

#### Пример точки входа:

```cpp
int main() {
    int passwordLength;
    std::cout << "Enter password length: ";
    std::cin >> passwordLength;

    PasswordGenerator<int> passwordGenerator(passwordLength);

    passwordGenerator.generatePassword();
    passwordGenerator.printPassword();

    if (passwordGenerator.checkPassword()) {
        std::cout << "Successful." << std::endl;
    } else {
        std::cout << "Error." << std::endl;
    }

    return 0;
}
```

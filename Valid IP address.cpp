#include <iostream>
#include <string>

class IPAddress {
public:
    IPAddress(const std::string& address);
    IPAddress(const IPAddress& other);
    void print() const;

protected:
    std::string address;
};

IPAddress::IPAddress(const std::string& address)
    : address(address) {}

IPAddress::IPAddress(const IPAddress& other)
    : address(other.address) {}

void IPAddress::print() const {
    std::cout << address << std::endl;
}

class IPAddressChecked : public IPAddress {
public:
    IPAddressChecked(const std::string& address, bool isCorrect);
    IPAddressChecked(const IPAddressChecked& other);
    void print() const;

private:
    bool isCorrect;
};

IPAddressChecked::IPAddressChecked(const std::string& address, bool isCorrect)
    : IPAddress(address), isCorrect(isCorrect) {}

IPAddressChecked::IPAddressChecked(const IPAddressChecked& other)
    : IPAddress(other), isCorrect(other.isCorrect) {}

void IPAddressChecked::print() const {
    IPAddress::print();
    std::cout << (isCorrect ? " - Correct" : " - Not Correct") << std::endl;
}

int main() {
    std::string address1, address2, address3;

    std::cout << "Enter IP address 1: ";
    std::getline(std::cin, address1);

    std::cout << "Enter IP address 2: ";
    std::getline(std::cin, address2);
    bool isCorrect2;
    std::cout << "Is IP address 2 correct? (1 for Yes, 0 for No): ";
    std::cin >> isCorrect2;
    std::cin.ignore();  // Ignore the newline character

    std::cout << "Enter IP address 3: ";
    std::getline(std::cin, address3);
    bool isCorrect3;
    std::cout << "Is IP address 3 correct? (1 for Yes, 0 for No): ";
    std::cin >> isCorrect3;
    std::cin.ignore();  // Ignore the newline character

    IPAddress ip1(address1);
    IPAddressChecked ipChecked2(address2, isCorrect2);
    IPAddressChecked ipChecked3(address3, isCorrect3);

    std::cout << "Printing IP addresses:" << std::endl;
    ip1.print();
    ipChecked2.print();
    ipChecked3.print();

    return 0;
}

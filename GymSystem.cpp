#include <iostream>
#include <vector>
#include <sstream>

class GymMember {
public:
    GymMember(int id, const std::string& name);
    void printStatus();
    bool extendSubscription(int months);
    void cancelSubscription();
    int getId() const { return id; }

private:
    int id;
    std::string name;
    int subscriptionMonths;
};

GymMember::GymMember(int id, const std::string& name)
    : id(id), name(name), subscriptionMonths(0) {}

void GymMember::printStatus() {
    std::cout << "Member " << id << " : " << name << ", subscription valid for " << subscriptionMonths << " months\n";
}

bool GymMember::extendSubscription(int months) {
    if (months >= 0) {
        subscriptionMonths += months;
        return true;
    }
    return false;
}

void GymMember::cancelSubscription() {
    subscriptionMonths = 0;
}

int main() {
    std::vector<GymMember> members;
    std::string command;
    int id, months;
    std::string name;

    while (command != "quit") {
        std::cout << "Enter command: ";
        std::getline(std::cin, command);

        std::stringstream ss(command);
        ss >> command;

        if (command == "create") {
            ss >> id >> name;

            if (id <= 0 || id > 10) {
                std::cout << "Cannot create member. Invalid ID.\n";
                continue;
            }

            bool memberExists = false;
            for (const GymMember& member : members) {
                if (member.getId() == id) {
                    memberExists = true;
                    break;
                }
            }

            if (memberExists) {
                std::cout << "Cannot create member. Member with ID " << id << " already exists.\n";
            }
            else {
                members.emplace_back(id, name);
                std::cout << "Member created successfully.\n";
            }
        }
        else if (command == "delete") {
            ss >> id;

            auto it = std::find_if(members.begin(), members.end(), [id](const GymMember& member) {
                return member.getId() == id;
                });

            if (it != members.end()) {
                members.erase(it);
                std::cout << "Member deleted successfully.\n";
            }
            else {
                std::cout << "Cannot delete member. Member with ID " << id << " does not exist.\n";
            }
        }
        else if (command == "extend") {
            ss >> id >> months;

            auto it = std::find_if(members.begin(), members.end(), [id](const GymMember& member) {
                return member.getId() == id;
                });

            if (it != members.end()) {
                if (it->extendSubscription(months)) {
                    std::cout << "Subscription extended successfully.\n";
                }
                else {
                    std::cout << "Cannot extend subscription. Invalid number of months.\n";
                }
            }
            else {
                std::cout << "Cannot extend subscription. Member with ID " << id << " does not exist.\n";
            }
        }
        else if (command == "cancel") {
            ss >> id;

            auto it = std::find_if(members.begin(), members.end(), [id](const GymMember& member) {
                return member.getId() == id;
                });

            if (it != members.end()) {
                it->cancelSubscription();
                std::cout << "Subscription canceled successfully.\n";
            }
            else {
                std::cout << "Cannot cancel subscription. Member with ID " << id << " does not exist.\n";
            }
        }
    }
    return 0;
}

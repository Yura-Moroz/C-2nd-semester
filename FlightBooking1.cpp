#include <iostream> 
using namespace std;

class FlightBooking {
public:

	FlightBooking(int id, int capacity, int reserved);
	void set(int id, int capacity, int reserved);
	void printStatus();
private:
	int id;
	int capacity;
	int reserved;
};

void FlightBooking::printStatus() {
	cout << "Flight" << this->id << " : " << this->reserved / this->capacity << " { " << double(this->reserved) / double(this->capacity) * 100 << "% of reserved seats";
}

void FlightBooking::set(int id, int capacity, int reserved) {
	this->id = id;
	this->capacity = capacity;
	this->reserved = reserved;
}

FlightBooking::FlightBooking(int id, int capacity, int reserved) {
	set(id, capacity, reserved);
}

int main() {
	int reserved = 0,
		capacity = 0;
	std::cout << "Provide flight capacity: ";
	std::cin >> capacity;
	std::cout << "Provide number of reserved seats: ";
	std::cin >> reserved;
	FlightBooking booking(1, capacity, reserved);
	booking.printStatus();
	return 0;
}
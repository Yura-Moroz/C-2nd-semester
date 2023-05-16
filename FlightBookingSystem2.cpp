#include <iostream>
#include <string>
#include <vector>

using namespace std;

class FlightBooking {
public:
    FlightBooking(int id, int capacity, int reserved);
    void printStatus() const;
    void add(int n);
    void cancel(int n);
    int getId() const;
    int getReserved() const;
    int getCapacity() const;
private:
    int id;
    int capacity;
    int reserved;
    void set_reserved(int reserved);
    void set_capacity(int capacity);
};

void FlightBooking::printStatus() const
{
    double percent = 0.0;
    if (this->capacity > 0)
    {
        percent = 100.0 * ((double)this->reserved / this->capacity);
        printf("Flight %d: %d/%d (%.2lf%%) seats taken\n", this->id, this->reserved, this->capacity, percent);
    }
}

FlightBooking::FlightBooking(int id, int capacity, int reserved)
{
    this->id = id;
    this->set_capacity(capacity);
    this->set_reserved(reserved);
}

void FlightBooking::add(int n)
{
    if (n > 0 && this->reserved + n <= this->capacity)
    {
        this->set_reserved(this->reserved + n);
    }
    else
    {
        cout << "Cannot perform this operation. Not enough capacity.\n";
    }
}

void FlightBooking::cancel(int n)
{
    if (n > 0 && n <= this->reserved)
    {
        this->set_reserved(this->reserved - n);
    }
    else
    {
        cout << "Cannot perform this operation. Not enough reservations.\n";
    }
}

int FlightBooking::getId() const
{
    return this->id;
}

int FlightBooking::getReserved() const
{
    return this->reserved;
}

int FlightBooking::getCapacity() const
{
    return this->capacity;
}

class BookingSystem {
public:
    BookingSystem();
    void create(int id, int capacity);
    void deleteFlight(int id);
    void addReservation(int id, int n);
    void cancelReservation(int id, int n);
    void printStatus() const;
private:
    vector<FlightBooking> flights;
    bool isValidFlight(int id) const;
};

BookingSystem::BookingSystem()
{
    // initialize the flights vector with empty flights
    for (int i = 0; i < 10; i++)
    {
        this->flights.push_back(FlightBooking(i + 1, 0, 0));
    }
}

void BookingSystem::create(int id, int capacity)
{
    if (id <= 0 || id > 10)
    {
        cout << "Cannot perform this operation. Invalid flight ID.\n";
        return;
    }

    if (this->isValidFlight(id))
    {
        cout << "Cannot perform this operation. Flight already exists.\n";
        return;
    }

    if (capacity < 0)
    {
        cout << "Cannot perform this operation. Invalid capacity.\n";
        return;
    }

    this->flights[id - 1] = FlightBooking(id, capacity, 0);
    cout << "Flight "
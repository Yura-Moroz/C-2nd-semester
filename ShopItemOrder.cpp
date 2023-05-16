#include <iostream> 
#include <string> 
using namespace std;

class ShopItemOrder {
private:
	string name;
	double price;
	int numberOfItems;

public:
	ShopItemOrder(string name, double price, int numberOfItems);
	void set(string name, double price, int numberOfItems);
	void get();
	double total_price(double price, int numberOfItems);
	void print();
};

ShopItemOrder::ShopItemOrder(string name, double price, int numberOfItems) {
	set(name, price, numberOfItems);
}

void ShopItemOrder::get() {
	cout << this->name << this->price << this->numberOfItems;
}

double ShopItemOrder::total_price(double price, int numberOfItems) {
	return price * numberOfItems;
}

void ShopItemOrder::set(string name, double price, int numberOfItems) {
	this->name = name;
	this->price = price;
	this->numberOfItems = numberOfItems;
};

void ShopItemOrder::print() {
	cout << this->name << '/' << this->price << '/' << this->numberOfItems << '/' << '\n' << "Total Price: " << total_price(this->price, this->numberOfItems);
}

int main() {
	ShopItemOrder bag1("computer1", 20000, 2);
	bag1.print();
	return 0;
}
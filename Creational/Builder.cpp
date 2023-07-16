#include <stdlib.h>
#include <iostream>

using namespace std;

class CoffeeBuilder;

class Coffee {
public:
	string requestorName;
	bool isHot = false;
	bool hasMilk = false;
	bool hasSugar = false;
	double cost = 0;

	Coffee(string requestorName): requestorName(requestorName) {}

	friend class CoffeeBuilder;
	static CoffeeBuilder create(string requestorName);
};

class CoffeeBuilder {
	Coffee coffee;

public:
	CoffeeBuilder(string requestorName): coffee(Coffee(requestorName)) {}

	operator Coffee() { return move(coffee); }

	CoffeeBuilder& makeHot();
	CoffeeBuilder& addMilk();
	CoffeeBuilder& addSugar();
	CoffeeBuilder& costs(double cost);
};

CoffeeBuilder Coffee::create(string requestorName) {
	return CoffeeBuilder{ requestorName };
}

CoffeeBuilder& CoffeeBuilder::makeHot() {
	coffee.isHot = true;
	return *this;
}

CoffeeBuilder& CoffeeBuilder::addMilk() {
	coffee.hasMilk = true;
	return *this;
}
CoffeeBuilder& CoffeeBuilder::addSugar() {
	coffee.hasSugar = true;
	return *this;
}
CoffeeBuilder& CoffeeBuilder::costs(double cost) {
	coffee.cost = cost;
	return *this;
}


int main() {
	Coffee coffee = Coffee::create("Aakarshit")
		.addMilk().addSugar().makeHot().costs(100.00);

	Coffee coffee2 = Coffee::create("Agarwal")
		.makeHot().costs(70.00);

	cout << coffee.cost << endl;
	cout << coffee2.cost << endl;

	return EXIT_SUCCESS;
}
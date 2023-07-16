#include "stdlib.h"
#include <iostream>
#include <map>

using namespace std;

enum CoffeeMachineType {
	SIMPLE_COFFEE_MACHINE,
	COMPLEX_COFFEE_MACHINE,
	ESPRESSO_COFFEE_MACHINE
};

class CoffeeMachine {
public:
	virtual CoffeeMachine* clone() = 0;
	virtual void brew() = 0;
};

class SimpleCoffeeMachine : public CoffeeMachine {
public:
	CoffeeMachine* clone() {
		cout << "Cloning simple coffee machine!" << endl;
		return new SimpleCoffeeMachine;
	}

	void brew() {
		cout << "Brewing simple coffee!" << endl;
	}
};

class ComplexCoffeeMachine : public CoffeeMachine {
public:
	CoffeeMachine* clone() {
		cout << "Cloning complex coffee machine!" << endl;
		return new ComplexCoffeeMachine;
	}

	void brew() {
		cout << "Brewing complex coffee!" << endl;
	}
};

class EspressoCoffeeMachine :public CoffeeMachine {
public:
	CoffeeMachine* clone() {
		cout << "Cloning espresso coffee machine!" << endl;
		return new EspressoCoffeeMachine;
	}

	void brew() {
		cout << "Brewing espresso coffee!" << endl;
	}
};

class CoffeeMachineManager {
private:
	static map<CoffeeMachineType, CoffeeMachine*> coffeeMachines;

public:
	~CoffeeMachineManager(){}
	static CoffeeMachine* createMachine(CoffeeMachineType machineType);
};

map<CoffeeMachineType, CoffeeMachine*> CoffeeMachineManager::coffeeMachines = {
	{SIMPLE_COFFEE_MACHINE, new SimpleCoffeeMachine},
	{COMPLEX_COFFEE_MACHINE, new ComplexCoffeeMachine},
	{ESPRESSO_COFFEE_MACHINE, new EspressoCoffeeMachine}
};

CoffeeMachine* CoffeeMachineManager::createMachine(CoffeeMachineType machineType) {
	return coffeeMachines[machineType]->clone();
}

/*
int main() {
	CoffeeMachine* simpleCoffeeMachine = CoffeeMachineManager::createMachine(SIMPLE_COFFEE_MACHINE);
	CoffeeMachine* complexCoffeeMachine = CoffeeMachineManager::createMachine(COMPLEX_COFFEE_MACHINE);
	CoffeeMachine* espressoCoffeeMachine = CoffeeMachineManager::createMachine(ESPRESSO_COFFEE_MACHINE);
	cout << endl;

	simpleCoffeeMachine->brew();
	complexCoffeeMachine->brew();
	espressoCoffeeMachine->brew();
	cout << endl;

	CoffeeMachine* clonedSimpleCoffeeMachine = simpleCoffeeMachine->clone();
	CoffeeMachine* clonedComplexCoffeeMachine = complexCoffeeMachine->clone();
	CoffeeMachine* clonedEspressoCoffeeMachine = espressoCoffeeMachine->clone();
	cout << endl;

	clonedSimpleCoffeeMachine->brew();
	clonedComplexCoffeeMachine->brew();
	clonedEspressoCoffeeMachine->brew();

	return EXIT_SUCCESS;
}
*/
#include "stdlib.h"
#include <map>
#include <string>
#include <iostream>

using namespace std;

class GlobalCoffeeMachineConfig {
    map<string, string> coffeeState;

    // Private Constructor
    GlobalCoffeeMachineConfig() {}

    public:
        GlobalCoffeeMachineConfig(GlobalCoffeeMachineConfig const&) = delete;
        GlobalCoffeeMachineConfig &operator=(GlobalCoffeeMachineConfig const&) = delete;

        static GlobalCoffeeMachineConfig& get() {
            static GlobalCoffeeMachineConfig config;
            return config;
        }

        void setState(const string &key, const string &value) {
            coffeeState.insert({ key, value });
        }

        string getState(const string &key) {
            auto iterator = coffeeState.find(key);
            return iterator->second;
        }
};

/*
int main() {
    GlobalCoffeeMachineConfig& coffeeMachineConfig = GlobalCoffeeMachineConfig::get();
    
    coffeeMachineConfig.setState("COFFEE_STATUS", "ON");
    coffeeMachineConfig.setState("COFFEE_HEALTH_URL", "./health");

    printf("COFFEE_STATE: %s\n", coffeeMachineConfig.getState("COFFEE_STATUS").c_str());
    printf("COFFEE_HEALTH_URL: %s\n", coffeeMachineConfig.getState("COFFEE_HEALTH_URL").c_str());
    return EXIT_SUCCESS;
}

*/
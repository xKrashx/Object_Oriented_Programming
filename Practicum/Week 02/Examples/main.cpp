#include <iostream>
#include "smartcity.hpp"

int main() {
    Building building;
    Event event;
    
    std::cout << "=== Enter building details ===\n";
    inputBuildingData(building);
    
    std::cout << "\n=== Building info ===\n";
    printBuildingInfo(building);
    
    std::cout << "\n=== Enter event details ===\n";
    inputEventData(event);
    
    std::cout << "\n=== Event info ===\n";
    printEventInfo(event);
    
    return 0;
}
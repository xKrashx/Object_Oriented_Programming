#include "smartcity.hpp"
#include <iostream>
#include <cstring>

void printBuildingInfo(const Building& b) {
    std::cout << "Name: " << b.name << '\n'
              << "Type: ";
              
    switch(b.type) {
        case BuildingType::RESIDENTIAL: std::cout << "Residential Building"; break;
        case BuildingType::HOSPITAL: std::cout << "Hospital"; break;
        case BuildingType::POLICE: std::cout << "Police Station"; break;
        case BuildingType::FIRE_STATION: std::cout << "Fire Station"; break;
    }
    
    std::cout << "\nLocation: (" << b.loc.x << ", " << b.loc.y << ")\n"
              << "Operational: " << (b.status.isOperational ? "Yes" : "No") << '\n'
              << "Power Status: " << b.status.powerStatus << "/3\n"
              << "Occupancy: " << b.status.occupancy << "/3\n";
}

void inputBuildingData(Building& b) {
    std::cout << "Enter name: ";
    std::cin.ignore();
    std::cin.getline(b.name, 32);
    
    b.type = getBuildingTypeFromUser();
    
    std::cout << "Enter x coordinate: ";
    std::cin >> b.loc.x;
    std::cout << "Enter y coordinate: ";
    std::cin >> b.loc.y;
    
    std::cout << "Is the building operational (1/0): ";
    bool operational;
    std::cin >> operational;
    b.status.isOperational = operational;
    
    unsigned int power;
    do {
        std::cout << "Enter power level (0-3): ";
        std::cin >> power;
    } while(power > 3);
    b.status.powerStatus = power;
    
    unsigned int occ;
    do {
        std::cout << "Enter occupancy level (0-3): ";
        std::cin >> occ;
    } while(occ > 3);
    b.status.occupancy = occ;
}

void printEventInfo(const Event& e) {
    std::cout << "Description: " << e.description << '\n'
              << "Location: (" << e.loc.x << ", " << e.loc.y << ")\n"
              << "Emergency Level: ";
    
    switch(e.level) {
        case EmergencyLevel::LOW: std::cout << "Low"; break;
        case EmergencyLevel::MEDIUM: std::cout << "Medium"; break;
        case EmergencyLevel::HIGH: std::cout << "High"; break;
    }
    std::cout << '\n';
}

void inputEventData(Event& e) {
    std::cout << "Enter description: ";
    std::cin.ignore();
    std::cin.getline(e.description, 64);
    
    std::cout << "Enter x coordinate: ";
    std::cin >> e.loc.x;
    std::cout << "Enter y coordinate: ";
    std::cin >> e.loc.y;
    
    e.level = getEmergencyLevelFromUser();
}
#include "city_types.hpp"

namespace {
    // Constants for validation
    const int MIN_BUILDING_TYPE = static_cast<int>(BuildingType::RESIDENTIAL);
    const int MAX_BUILDING_TYPE = static_cast<int>(BuildingType::FIRE_STATION);
    
    // Helper messages
    const char* const BUILDING_NAMES[] = {
        "Residential Building",
        "Hospital",
        "Police Station",
        "Fire Station"
    };
    
    const char* const EMERGENCY_LEVELS[] = {
        "Low",
        "Medium",
        "High"
    };
    
    // Helper functions
    bool isValidBuildingType(int choice) {
        return choice >= MIN_BUILDING_TYPE && choice <= MAX_BUILDING_TYPE;
    }
    
    bool isValidEmergencyLevel(int choice) {
        return choice >= static_cast<int>(EmergencyLevel::LOW) && choice <= static_cast<int>(EmergencyLevel::HIGH);
    }
    
    void printErrorMessage() {
        std::cout << "Invalid choice! Returning default value.\n";
    }
    
    void printMenuBuilding() {
        std::cout << "Select building type:\n";
        for(int i = MIN_BUILDING_TYPE; i <= MAX_BUILDING_TYPE; i++) {
            std::cout << i << " - " << BUILDING_NAMES[i] << '\n';
        }
        std::cout << "Enter number: ";
    }
    
    void printMenuEmergency() {
        std::cout << "Select emergency level:\n";
        for(int i = static_cast<int>(EmergencyLevel::LOW); i <= static_cast<int>(EmergencyLevel::HIGH); i++) {
            std::cout << i << " - " << EMERGENCY_LEVELS[i] << '\n';
        }
        std::cout << "Enter number: ";
    }
}

BuildingType getBuildingTypeFromUser() {
    printMenuBuilding();
    int choice;
    std::cin >> choice;
    if(isValidBuildingType(choice)) {
        // Preferred way, using static_cast
        return static_cast<BuildingType>(choice);
    }
    printErrorMessage();
    return BuildingType::UNKNOWN;
}

EmergencyLevel getEmergencyLevelFromUser() {
    printMenuEmergency();
    int choice;
    std::cin >> choice;
    if(isValidEmergencyLevel(choice)) {
        return static_cast<EmergencyLevel>(choice);
    }
    printErrorMessage();
    return EmergencyLevel::UNKNOWN;
}
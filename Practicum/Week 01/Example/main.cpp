#include <iostream>

enum BuildingType {
    RESIDENTIAL,
    HOSPITAL,
    POLICE,
    FIRE_STATION
};

enum EmergencyLevel {
    LOW,
    MEDIUM,
    HIGH
};

namespace {
    // Константи за валидация
    const int MIN_BUILDING_TYPE = RESIDENTIAL;
    const int MAX_BUILDING_TYPE = FIRE_STATION;
    
    // Помощни съобщения
    const char* const BUILDING_NAMES[] = {
        "Residential",
        "Hospital",
        "Police",
        "Fire station"
    };

    const char* const EMERGENCY_LEVELS[] = {
        "Low",
        "Medium",
        "High"
    };
    
    // Помощни функции
    bool isValidBuildingType(int choice) {
        return choice >= MIN_BUILDING_TYPE && choice <= MAX_BUILDING_TYPE;
    }

    bool isValidEmergencyLevel(int choice) {
        return choice >= LOW && choice <= HIGH;
    }
    
    void printErrorMessage() {
        std::cout << "Invalid value.\n";
    }
    
    void printMenuBuilding() {
        std::cout << "Enter building type:\n";
        for(int i = MIN_BUILDING_TYPE; i <= MAX_BUILDING_TYPE; i++) {
            std::cout << i << " - " << BUILDING_NAMES[i] << '\n';
        }
        std::cout << "Enter a number: ";
    }

    void printMenuEmergency() {
        std::cout << "Enter emergency level:\n";
        for(int i = LOW; i <= HIGH; i++) {
            std::cout << i << " - " << EMERGENCY_LEVELS[i] << '\n';
        }
        std::cout << "Enter a number: ";
    }
}

BuildingType getBuildingTypeFromUser() {
    printMenuBuilding();
    
    int choice;
    std::cin >> choice;
    
    if(isValidBuildingType(choice)) {
        // Предпочитания начин, но не сме го учили
        // return static_cast<BuildingType>(choice);
        return (BuildingType)choice; // Още наречен "C-style cast"
    }
    
    printErrorMessage();
    return RESIDENTIAL;
}

EmergencyLevel getEmergencyLevelFromUser() {
    printMenuEmergency();
    
    int choice;
    std::cin >> choice;
    
    if(isValidEmergencyLevel(choice)) {
        return (EmergencyLevel)choice;
    }
    
    printErrorMessage();
    return LOW;
}

void printBuildingType(BuildingType type) {
    std::cout << "Type: " << BUILDING_NAMES[type] << std::endl;
}

void printEmergencyLevel(EmergencyLevel level) {
    std::cout << "Emergency: " << EMERGENCY_LEVELS[level] << std::endl;
}

int main() {
    BuildingType userChoice = getBuildingTypeFromUser();
    printBuildingType(userChoice);
    
    return 0;
}
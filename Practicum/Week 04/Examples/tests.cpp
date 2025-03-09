#include "smartcity.hpp"
#include <iostream>

// Function to display menu and get choice
int getMenuChoice() {
    int choice;
    std::cout << "\n=== Building Management System ===\n"
              << "1. Create and save a single building\n"
              << "2. Load a single building from file\n"
              << "3. Create and save multiple buildings\n"
              << "4. Load multiple buildings from file\n"
              << "5. Search for operational buildings\n"
              << "0. Exit\n"
              << "Enter your choice: ";
    std::cin >> choice;
    return choice;
}

// Function to demonstrate single building operations
void handleSingleBuilding() {
    Building building;
    
    std::cout << "\n=== Creating Building Data ===\n";
    inputBuildingData(building);
    
    std::cout << "\n=== Building Information ===\n";
    printBuildingInfo(building);
    
    std::cout << "\n=== Saving Building to Binary File ===\n";
    if (saveBuildingToFile(building, "building.bin")) {
        std::cout << "Building saved successfully to \"building.bin\"\n";
    }
}

// Function to demonstrate loading a single building
void handleLoadBuilding() {
    Building building;
    
    std::cout << "\n=== Loading Building from Binary File ===\n";
    if (loadBuildingFromFile(building, "building.bin")) {
        std::cout << "Building loaded successfully from \"building.bin\"\n";
        
        std::cout << "\n=== Loaded Building Information ===\n";
        printBuildingInfo(building);
    }
}

// Function to demonstrate multiple building operations
void handleMultipleBuildings() {
    const int MAX_BUILDINGS = 3;
    Building buildings[MAX_BUILDINGS];
    
    std::cout << "\n=== Creating Multiple Buildings ===\n";
    for (int i = 0; i < MAX_BUILDINGS; i++) {
        std::cout << "\n--- Building " << (i + 1) << " ---\n";
        inputBuildingData(buildings[i]);
    }
    
    std::cout << "\n=== Saving Buildings to Binary File ===\n";
    if (saveBuildingsToFile(buildings, MAX_BUILDINGS, "buildings.bin")) {
        std::cout << "Buildings saved successfully to \"buildings.bin\"\n";
    }
}

// Function to demonstrate loading multiple buildings
void handleLoadMultipleBuildings() {
    const int MAX_BUILDINGS = 10; // Max capacity to load
    Building buildings[MAX_BUILDINGS];
    
    std::cout << "\n=== Loading Buildings from Binary File ===\n";
    int count = loadBuildingsFromFile(buildings, MAX_BUILDINGS, "buildings.bin");
    
    if (count > 0) {
        std::cout << "Successfully loaded " << count << " buildings from \"buildings.bin\"\n";
        
        std::cout << "\n=== Loaded Buildings Information ===\n";
        for (int i = 0; i < count; i++) {
            std::cout << "\n--- Building " << (i + 1) << " ---\n";
            printBuildingInfo(buildings[i]);
        }
    } else {
        std::cout << "No buildings loaded or file could not be opened.\n";
    }
}

// Function to search for operational buildings
void handleSearchOperationalBuildings() {
    const int MAX_BUILDINGS = 10; // Max capacity to load
    Building buildings[MAX_BUILDINGS];
    Building results[MAX_BUILDINGS];
    
    std::cout << "\n=== Loading Buildings for Search ===\n";
    int count = loadBuildingsFromFile(buildings, MAX_BUILDINGS, "buildings.bin");
    
    if (count > 0) {
        std::cout << "Successfully loaded " << count << " buildings from \"buildings.bin\"\n";
        
        std::cout << "\n=== Searching for Operational Buildings ===\n";
        int found = searchOperationalBuildings(buildings, count, results, MAX_BUILDINGS);
        
        if (found > 0) {
            std::cout << "Found " << found << " operational buildings:\n";
            for (int i = 0; i < found; i++) {
                std::cout << "\n--- Building " << (i + 1) << " ---\n";
                printBuildingInfo(results[i]);
            }
        } else {
            std::cout << "No operational buildings found.\n";
        }
    } else {
        std::cout << "No buildings loaded or file could not be opened.\n";
    }
}

int main() {
    int choice;
    bool running = true;
    
    while (running) {
        choice = getMenuChoice();
        
        switch (choice) {
            case 1:
                handleSingleBuilding();
                break;
            case 2:
                handleLoadBuilding();
                break;
            case 3:
                handleMultipleBuildings();
                break;
            case 4:
                handleLoadMultipleBuildings();
                break;
            case 5:
                handleSearchOperationalBuildings();
                break;
            case 0:
                running = false;
                std::cout << "Exiting program. Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice! Please try again.\n";
                break;
        }
    }
    
    return 0;
}
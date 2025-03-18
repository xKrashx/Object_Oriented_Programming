#include "test_weapon.hpp"
#include "test_player.hpp"
#include <iostream>

// Function to display menu and get choice
int getMenuChoice() {
    int choice;
    std::cout << "\n=== Elden Ring Class System Tests ===\n"
              << "1. Run all tests\n"
              << "2. Run Weapon tests\n"
              << "3. Run Player basic tests\n"
              << "4. Run Player flask tests\n"
              << "0. Exit\n"
              << "Enter your choice: ";
    std::cin >> choice;
    return choice;
}

int main() {
    int choice;
    bool running = true;
    
    while (running) {
        choice = getMenuChoice();
        
        switch (choice) {
            case 1:
                // Run all tests
                WeaponTest::runAllTests();
                std::cout << "\n-----------------------------\n" << std::endl;
                PlayerTest::runAllTests();
                break;
            case 2:
                // Run Weapon tests
                WeaponTest::runAllTests();
                break;
            case 3:
                // Run Player basic tests
                PlayerTest::runBasicTests();
                break;
            case 4:
                // Run Player flask tests
                PlayerTest::runFlaskTests();
                break;
            case 0:
                running = false;
                std::cout << "Exiting program...\n";
                break;
            default:
                std::cout << "Invalid choice! Try again.\n";
                break;
        }
    }
    
    return 0;
}
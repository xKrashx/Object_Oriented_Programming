#pragma once
#include "player.hpp"
#include "weapon.hpp"
#include <iostream>

namespace PlayerTest {
    void runBasicTests() {
        // Create a new player with default values
        Player player;
        
        // Initialize stats since we don't have a constructor
        player.setHp(player.getMaxHp());
        player.setMp(player.getMaxMp());
        player.setStamina(player.getMaxStamina());
        
        // Print initial status
        std::cout << "Initial player status:" << std::endl;
        player.printStatus();
        player.printInventory();
        
        // Create some weapons
        Weapon longsword;
        longsword.initialize("Longsword", 80, 5.0f, 12);
        
        Weapon greatsword;
        greatsword.initialize("Greatsword", 120, 12.0f, 20);
        
        Weapon dagger;
        dagger.initialize("Dagger", 45, 1.5f, 5);
        
        // Try to equip weapons
        std::cout << "\nAttempting to equip weapons:" << std::endl;
        
        // Should succeed (required strength 5 < player's strength 10)
        bool equipped = player.equipWeapon(dagger, 0);
        std::cout << "Equipping Dagger: " << (equipped ? "Success" : "Failed") << std::endl;
        
        // Should succeed (required strength 12 > player's strength 10)
        equipped = player.equipWeapon(longsword, 1);
        std::cout << "Equipping Longsword: " << (equipped ? "Success" : "Failed") << std::endl;
        
        // Should fail (required strength 20 > player's strength 10)
        equipped = player.equipWeapon(greatsword, 2);
        std::cout << "Equipping Greatsword: " << (equipped ? "Success" : "Failed") << std::endl;
        
        // Print updated inventory
        std::cout << "\nUpdated inventory:" << std::endl;
        player.printInventory();
        
        // Should succeed now (required strength 20 <= player's new strength 20)
        equipped = player.equipWeapon(greatsword, 2);
        std::cout << "Equipping Greatsword: " << (equipped ? "Success" : "Failed") << std::endl;
        
        // Print updated status and inventory
        std::cout << "\nUpdated player status and inventory:" << std::endl;
        player.printStatus();
        player.printInventory();
    }
    
    void runFlaskTests() {
        Player player;
        player.setHp(player.getMaxHp());
        player.setMp(player.getMaxMp());
        
        // Test flasks
        std::cout << "\nTesting healing flasks:" << std::endl;
        std::cout << "Initial HP: " << player.getHp() << "/" << player.getMaxHp() << std::endl;
        
        // Take some damage
        player.takeDamage(50);
        std::cout << "After taking 50 damage: " << player.getHp() << "/" << player.getMaxHp() << std::endl;
        
        // Use HP flask
        player.useHpFlask();
        std::cout << "After using HP flask: " << player.getHp() << "/" << player.getMaxHp() << std::endl;
        std::cout << "HP Flasks remaining: " << player.getFlaskChargesHp() << std::endl;
        
        // Try using all flasks
        std::cout << "\nTrying to use all HP flasks:" << std::endl;
        for (int i = 0; i < 5; i++) {
            bool success = player.useHpFlask();
            std::cout << "Flask use " << (i+1) << ": " << (success ? "Success" : "Failed") << std::endl;
        }
    }
    
    void runAllTests() {
        std::cout << "=== Running Player Tests ===\n" << std::endl;
        runBasicTests();
        std::cout << "\n-----------------------------\n" << std::endl;
        runFlaskTests();
        std::cout << "\n=== Player Tests Completed ===\n" << std::endl;
    }
}
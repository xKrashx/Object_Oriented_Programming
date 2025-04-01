#pragma once
#include "spell.hpp"
#include <iostream>

namespace SpellTest {
    void runBasicTests() {
        std::cout << "=== Testing Spell Basic Functionality ===\n" << std::endl;
        
        // Default constructor
        std::cout << "Creating spell with default constructor:" << std::endl;
        Spell defaultSpell;
        defaultSpell.printInfo();
        
        // Parameterized constructor
        std::cout << "\nCreating spells with parameterized constructor:" << std::endl;
        Spell fireball("Fireball", 30, 15, 2, 12, 0);
        fireball.printInfo();
        
        std::cout << std::endl;
        Spell healingLight("Healing Light", 0, 20, 3, 5, 15);
        healingLight.printInfo();
        
        // Test cooldown functionality
        std::cout << "\nTesting cooldown functionality:" << std::endl;
        std::cout << "Initial state:" << std::endl;
        std::cout << "Is Fireball on cooldown? " << (fireball.isOnCooldown() ? "Yes" : "No") << std::endl;
        
        fireball.resetCooldown();
        std::cout << "After reset cooldown:" << std::endl;
        std::cout << "Is Fireball on cooldown? " << (fireball.isOnCooldown() ? "Yes" : "No") << std::endl;
        std::cout << "Cooldown remaining: " << fireball.getRemainingCooldown() << std::endl;
        
        fireball.decrementCooldown();
        std::cout << "After decrement cooldown:" << std::endl;
        std::cout << "Is Fireball on cooldown? " << (fireball.isOnCooldown() ? "Yes" : "No") << std::endl;
        std::cout << "Cooldown remaining: " << fireball.getRemainingCooldown() << std::endl;
        
        fireball.decrementCooldown();
        std::cout << "After second decrement cooldown:" << std::endl;
        std::cout << "Is Fireball on cooldown? " << (fireball.isOnCooldown() ? "Yes" : "No") << std::endl;
        std::cout << "Cooldown remaining: " << fireball.getRemainingCooldown() << std::endl;
    }
    
    void runCopyMoveTests() {
        std::cout << "\n=== Testing Copy and Move Operations ===\n" << std::endl;
        
        // Create original spell
        Spell original("Lightning Bolt", 45, 25, 3, 15, 8);
        std::cout << "Original spell:" << std::endl;
        original.printInfo();
        
        // Test copy constructor
        std::cout << "\nUsing copy constructor:" << std::endl;
        Spell copied(original);
        std::cout << "Copied spell:" << std::endl;
        copied.printInfo();
        
        // Test move constructor
        std::cout << "\nUsing move constructor:" << std::endl;
        Spell moved(std::move(Spell("Ice Shard", 20, 10, 1, 10, 5)));
        std::cout << "Moved spell:" << std::endl;
        moved.printInfo();
        
        // Test copy assignment
        std::cout << "\nUsing copy assignment:" << std::endl;
        Spell copyAssigned;
        copyAssigned = original;
        std::cout << "Copy assigned spell:" << std::endl;
        copyAssigned.printInfo();
        
        // Test move assignment
        std::cout << "\nUsing move assignment:" << std::endl;
        Spell moveAssigned;
        moveAssigned = Spell("Fire Nova", 60, 40, 5, 20, 10);
        std::cout << "Move assigned spell:" << std::endl;
        moveAssigned.printInfo();
    }
    
    void runAllTests() {
        std::cout << "=== Running Spell Tests ===\n" << std::endl;
        runBasicTests();
        runCopyMoveTests();
        std::cout << "\n=== Spell Tests Completed ===\n" << std::endl;
    }
}
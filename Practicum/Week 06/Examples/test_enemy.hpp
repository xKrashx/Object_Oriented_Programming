#pragma once
#include "enemy.hpp"
#include "player.hpp"
#include <iostream>

namespace EnemyTest {
    void runBasicTests() {
        std::cout << "=== Testing Enemy Basic Functionality ===\n" << std::endl;
        
        // Default constructor
        std::cout << "Creating enemy with default constructor:" << std::endl;
        Enemy defaultEnemy;
        defaultEnemy.printStatus();
        
        // Parameterized constructor
        std::cout << "\nCreating enemy with parameterized constructor:" << std::endl;
        Enemy zombie("Zombie", 100, 15);
        zombie.printStatus();
        
        // Test exception handling
        std::cout << "\nTesting exception handling with invalid parameters:" << std::endl;
        try {
            Enemy invalidEnemy("Invalid", -50, 10);
            std::cout << "This should not be printed!" << std::endl;
        } catch (const std::exception& e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }
    }
    
    void runAttackPatternTests() {
        std::cout << "\n=== Testing Attack Pattern System ===\n" << std::endl;
        
        // Create enemy
        Enemy boss("Boss", 300, 40);
        std::cout << "Created boss enemy:" << std::endl;
        boss.printStatus();
        
        // Add attack patterns
        std::cout << "\nAdding attack patterns:" << std::endl;
        boss.addAttackPattern("Slash", 30, 1);
        boss.addAttackPattern("Heavy Slam", 70, 3);
        boss.addAttackPattern("Whirlwind", 45, 2);
        boss.addAttackPattern("Lunge", 40, 1);
        boss.addAttackPattern("Fury Combo", 80, 4);
        
        // Link attacks with probabilities
        std::cout << "Linking attack patterns:" << std::endl;
        // From Slash
        boss.linkAttacks(0, 1, 30); // 30% chance of Heavy Slam after Slash
        boss.linkAttacks(0, 2, 40); // 40% chance of Whirlwind after Slash
        boss.linkAttacks(0, 3, 30); // 30% chance of Lunge after Slash
        
        // From Heavy Slam
        boss.linkAttacks(1, 0, 60); // 60% chance of Slash after Heavy Slam
        boss.linkAttacks(1, 4, 40); // 40% chance of Fury Combo after Heavy Slam
        
        // From Whirlwind
        boss.linkAttacks(2, 3, 50); // 50% chance of Lunge after Whirlwind
        boss.linkAttacks(2, 4, 50); // 50% chance of Fury Combo after Whirlwind
        
        // From Lunge
        boss.linkAttacks(3, 0, 70); // 70% chance of Slash after Lunge
        boss.linkAttacks(3, 2, 30); // 30% chance of Whirlwind after Lunge
        
        // From Fury Combo
        boss.linkAttacks(4, 1, 100); // 100% chance of Heavy Slam after Fury Combo
        
        // Print attack patterns
        boss.printAttackPatterns();
        
        // Test exception handling for invalid attack indices
        std::cout << "\nTesting exception handling with invalid attack indices:" << std::endl;
        try {
            boss.linkAttacks(10, 0, 50);
            std::cout << "This should not be printed!" << std::endl;
        } catch (const std::exception& e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }
    }
    
    void runCopyTests() {
        std::cout << "\n=== Testing Copy Operations with Attack Patterns ===\n" << std::endl;
        
        // Create original enemy with attack patterns
        Enemy knight("Knight", 200, 35);
        knight.addAttackPattern("Sword Strike", 25, 1);
        knight.addAttackPattern("Shield Bash", 20, 2);
        knight.linkAttacks(0, 1, 70);
        knight.linkAttacks(1, 0, 80);
        
        std::cout << "Original enemy:" << std::endl;
        knight.printStatus();
        knight.printAttackPatterns();
        
        // Test copy constructor
        std::cout << "\nCopying enemy with copy constructor:" << std::endl;
        Enemy knightCopy(knight);
        knightCopy.printStatus();
        knightCopy.printAttackPatterns();
        
        // Modify the copy
        std::cout << "\nModifying copy:" << std::endl;
        knightCopy.setHp(100);
        knightCopy.addAttackPattern("Charge", 35, 3);
        knightCopy.printStatus();
        knightCopy.printAttackPatterns();
        
        // Show original is unchanged
        std::cout << "\nOriginal enemy after modifying copy:" << std::endl;
        knight.printStatus();
        knight.printAttackPatterns();
        
        // Test copy assignment operator
        std::cout << "\nTesting copy assignment operator:" << std::endl;
        Enemy assignedEnemy;
        assignedEnemy = knight;
        std::cout << "Assigned enemy:" << std::endl;
        assignedEnemy.printStatus();
        assignedEnemy.printAttackPatterns();
    }
    
    void runCombatTests() {
        std::cout << "\n=== Testing Combat with Attack Patterns ===\n" << std::endl;
        
        // Create player
        Player player;
        player.setHp(player.getMaxHp());
        
        // Create enemy with attack patterns
        Enemy demon("Demon", 250, 35);
        demon.addAttackPattern("Claw", 30, 1);
        demon.addAttackPattern("Fireball", 45, 2);
        demon.addAttackPattern("Hellfire", 70, 3);
        
        // Link attacks
        demon.linkAttacks(0, 1, 60);
        demon.linkAttacks(1, 2, 40);
        demon.linkAttacks(2, 0, 100);
        
        std::cout << "Enemy attack patterns:" << std::endl;
        demon.printAttackPatterns();
        
        std::cout << "\nInitial status:" << std::endl;
        player.printStatus();
        std::cout << std::endl;
        demon.printStatus();
        
        // Simulate several rounds of combat
        std::cout << "\nSimulating combat:" << std::endl;
        for (int round = 1; round <= 6; round++) {
            std::cout << "\n--- Round " << round << " ---" << std::endl;
            
            // Enemy attacks player
            std::cout << "Enemy's turn:" << std::endl;
            demon.attackPlayer(player);
            player.printStatus();
            
            // Check if player is dead
            if (player.isDead()) {
                std::cout << "Player has been defeated!" << std::endl;
                break;
            }
            
            // Player attacks enemy
            std::cout << "\nPlayer's turn:" << std::endl;
            std::cout << "Player attacks enemy for 30 damage!" << std::endl;
            demon.takeDamage(30);
            demon.printStatus();
            
            // Check if enemy is dead
            if (demon.isDead()) {
                std::cout << "Enemy has been defeated!" << std::endl;
                break;
            }
        }
    }
    
    void runAllTests() {
        std::cout << "=== Running Enemy Tests ===\n" << std::endl;
        runBasicTests();
        runAttackPatternTests();
        runCopyTests();
        runCombatTests();
        std::cout << "\n=== Enemy Tests Completed ===\n" << std::endl;
    }
}
#pragma once
#include "player.hpp"
#include "spell.hpp"
#include <iostream>

namespace PlayerSpellTest {
    void runBasicSpellTests() {
        std::cout << "=== Testing Player with Spells ===\n" << std::endl;
        
        // Create a new player
        Player player;
        
        // Initialize stats
        player.setHp(player.getMaxHp());
        player.setMp(player.getMaxMp());
        player.setStamina(player.getMaxStamina());
        
        // Print initial status
        std::cout << "Initial player status:" << std::endl;
        player.printStatus();
        player.printSpells();
        
        // Create some spells
        Spell fireball("Fireball", 30, 15, 2, 12, 0);
        Spell healingLight("Healing Light", 0, 20, 3, 5, 15);
        Spell lightningBolt("Lightning Bolt", 45, 25, 3, 15, 8);
        
        // Learn spells
        std::cout << "\nLearning spells:" << std::endl;
        bool learned = player.learnSpell(fireball, 0);
        std::cout << "Learning Fireball: " << (learned ? "Success" : "Failed") << std::endl;
        
        learned = player.learnSpell(healingLight, 1);
        std::cout << "Learning Healing Light: " << (learned ? "Success" : "Failed") << std::endl;
        
        // Use move semantics to learn a spell
        learned = player.learnSpell(std::move(lightningBolt), 2);
        std::cout << "Learning Lightning Bolt with move semantics: " << (learned ? "Success" : "Failed") << std::endl;
        
        // Print updated spell list
        std::cout << "\nUpdated spell list:" << std::endl;
        player.printSpells();
        
        // Try to equip spells
        std::cout << "\nEquipping spells:" << std::endl;
        bool equipped = player.setEquippedSpell(0);
        std::cout << "Equipping Fireball: " << (equipped ? "Success" : "Failed") << std::endl;
        
        player.printSpells();
    }
    
    void runCastingTests() {
        std::cout << "\n=== Testing Spell Casting ===\n" << std::endl;
        
        // Create a player with increased intelligence
        Player player;
        player.setHp(player.getMaxHp());
        player.setMp(player.getMaxMp());
        
        // Increase intelligence to meet requirements
        for (int i = 0; i < 5; i++) {
            player.increaseIntelligence();
        }
        
        // Learn a spell
        Spell fireball("Fireball", 30, 15, 2, 12, 0);
        player.learnSpell(fireball, 0);
        player.setEquippedSpell(0);
        
        std::cout << "Player status before casting:" << std::endl;
        player.printStatus();
        player.printSpells();
        
        // Cast the spell
        std::cout << "\nCasting spell:" << std::endl;
        int damage = player.castSpell();
        std::cout << "Spell dealt " << damage << " damage" << std::endl;
        
        std::cout << "\nPlayer status after casting:" << std::endl;
        player.printStatus();
        
        // Try to cast again (should be on cooldown)
        std::cout << "\nTrying to cast again:" << std::endl;
        damage = player.castSpell();
        
        // Decrease cooldown
        std::cout << "\nDecreasing spell cooldowns:" << std::endl;
        player.decrementSpellCooldowns();
        
        // Try to cast again
        std::cout << "\nTrying to cast after cooldown decrease:" << std::endl;
        damage = player.castSpell();
        
        // Decrease cooldown again
        std::cout << "\nDecreasing spell cooldowns again:" << std::endl;
        player.decrementSpellCooldowns();
        
        // Try to cast again (should work now)
        std::cout << "\nTrying to cast after cooldown finished:" << std::endl;
        damage = player.castSpell();
        
        // Show final status
        std::cout << "\nFinal player status:" << std::endl;
        player.printStatus();
    }
    
    void runStatRequirementTests() {
        std::cout << "\n=== Testing Spell Stat Requirements ===\n" << std::endl;
        
        // Create a player
        Player player;
        player.setHp(player.getMaxHp());
        player.setMp(player.getMaxMp());
        
        // Create spell with high requirements
        Spell arcaneBlast("Arcane Blast", 60, 30, 3, 20, 5);
        player.learnSpell(arcaneBlast, 0);
        player.setEquippedSpell(0);
        
        std::cout << "Player status:" << std::endl;
        player.printStatus();
        player.printSpells();
        
        // Try to cast (should fail due to intelligence requirement)
        std::cout << "\nTrying to cast spell with insufficient stats:" << std::endl;
        player.castSpell();
        
        // Increase intelligence
        std::cout << "\nIncreasing intelligence to meet requirements:" << std::endl;
        for (int i = 0; i < 10; i++) {
            player.increaseIntelligence();
        }
        
        std::cout << "Updated player stats:" << std::endl;
        player.printStatus();
        
        // Try to cast again
        std::cout << "\nTrying to cast spell after meeting requirements:" << std::endl;
        player.castSpell();
    }
    
    void runAllTests() {
        std::cout << "=== Running Player Spell Tests ===\n" << std::endl;
        runBasicSpellTests();
        runCastingTests();
        runStatRequirementTests();
        std::cout << "\n=== Player Spell Tests Completed ===\n" << std::endl;
    }
}
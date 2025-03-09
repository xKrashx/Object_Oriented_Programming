#include "smartcity.hpp"
#include <iostream>

// Function to display menu and get choice
int getMenuChoice() {
    int choice;
    std::cout << "\n=== Event Management System ===\n"
              << "1. Create and save a single event\n"
              << "2. Load a single event from file\n"
              << "3. Create and save multiple events\n"
              << "4. Load multiple events from file\n"
              << "5. Search events by level\n"
              << "6. Search events by description\n"
              << "7. Search events by location\n"
              << "0. Exit\n"
              << "Enter your choice: ";
    std::cin >> choice;
    return choice;
}

// Function to demonstrate single event operations
void handleSingleEvent() {
    Event event;
    
    std::cout << "\n=== Creating Event Data ===\n";
    inputEventData(event);
    
    std::cout << "\n=== Event Information ===\n";
    printEventInfo(event);
    
    std::cout << "\n=== Saving Event to File ===\n";
    if (saveEventToFile(event, "event.txt")) {
        std::cout << "Event saved successfully to \"event.txt\"\n";
    }
}

// Function to demonstrate loading a single event
void handleLoadEvent() {
    Event event;
    
    std::cout << "\n=== Loading Event from File ===\n";
    if (loadEventFromFile(event, "event.txt")) {
        std::cout << "Event loaded successfully from \"event.txt\"\n";
        
        std::cout << "\n=== Loaded Event Information ===\n";
        printEventInfo(event);
    }
}

// Function to demonstrate multiple event operations
void handleMultipleEvents() {
    const int MAX_EVENTS = 3;
    Event events[MAX_EVENTS];
    
    std::cout << "\n=== Creating Multiple Events ===\n";
    for (int i = 0; i < MAX_EVENTS; i++) {
        std::cout << "\n--- Event " << (i + 1) << " ---\n";
        inputEventData(events[i]);
    }
    
    std::cout << "\n=== Saving Events to File ===\n";
    if (saveEventsToFile(events, MAX_EVENTS, "events.txt")) {
        std::cout << "Events saved successfully to \"events.txt\"\n";
    }
}

// Function to demonstrate loading multiple events
void handleLoadMultipleEvents() {
    const int MAX_EVENTS = 10; // Max capacity to load
    Event events[MAX_EVENTS];
    
    std::cout << "\n=== Loading Events from File ===\n";
    int count = loadEventsFromFile(events, MAX_EVENTS, "events.txt");
    
    if (count > 0) {
        std::cout << "Successfully loaded " << count << " events from \"events.txt\"\n";
        
        std::cout << "\n=== Loaded Events Information ===\n";
        for (int i = 0; i < count; i++) {
            std::cout << "\n--- Event " << (i + 1) << " ---\n";
            printEventInfo(events[i]);
        }
    } else {
        std::cout << "No events loaded or file could not be opened.\n";
    }
}

// Function to search events by level
void handleSearchByLevel() {
    Event results[10];
    EmergencyLevel level = getEmergencyLevelFromUser();
    
    std::cout << "\n=== Searching Events by Level ===\n";
    int found = searchEventsInFile("events.txt", EventSearchCriteria::BY_LEVEL, &level, results, 10);
    
    if (found > 0) {
        std::cout << "Found " << found << " events with the specified level:\n";
        for (int i = 0; i < found; i++) {
            std::cout << "\n--- Match " << (i + 1) << " ---\n";
            printEventInfo(results[i]);
        }
    } else {
        std::cout << "No matching events found.\n";
    }
}

// Function to search events by description
void handleSearchByDescription() {
    Event results[10];
    char searchText[64];
    
    std::cout << "Enter description text to search for: ";
    std::cin.ignore();
    std::cin.getline(searchText, 64);
    
    std::cout << "\n=== Searching Events by Description ===\n";
    int found = searchEventsInFile("events.txt", EventSearchCriteria::BY_DESCRIPTION, searchText, results, 10);
    
    if (found > 0) {
        std::cout << "Found " << found << " events containing \"" << searchText << "\":\n";
        for (int i = 0; i < found; i++) {
            std::cout << "\n--- Match " << (i + 1) << " ---\n";
            printEventInfo(results[i]);
        }
    } else {
        std::cout << "No matching events found.\n";
    }
}

// Function to search events by location
void handleSearchByLocation() {
    Event results[10];
    int searchParams[3]; // x, y, radius
    
    std::cout << "Enter x coordinate: ";
    std::cin >> searchParams[0];
    std::cout << "Enter y coordinate: ";
    std::cin >> searchParams[1];
    std::cout << "Enter search radius: ";
    std::cin >> searchParams[2];
    
    std::cout << "\n=== Searching Events by Location ===\n";
    int found = searchEventsInFile("events.txt", EventSearchCriteria::BY_LOCATION, searchParams, results, 10);
    
    if (found > 0) {
        std::cout << "Found " << found << " events within radius " << searchParams[2] 
                  << " of location (" << searchParams[0] << ", " << searchParams[1] << "):\n";
        for (int i = 0; i < found; i++) {
            std::cout << "\n--- Match " << (i + 1) << " ---\n";
            printEventInfo(results[i]);
        }
    } else {
        std::cout << "No matching events found.\n";
    }
}

int main() {
    int choice;
    bool running = true;
    
    while (running) {
        choice = getMenuChoice();
        
        switch (choice) {
            case 1:
                handleSingleEvent();
                break;
            case 2:
                handleLoadEvent();
                break;
            case 3:
                handleMultipleEvents();
                break;
            case 4:
                handleLoadMultipleEvents();
                break;
            case 5:
                handleSearchByLevel();
                break;
            case 6:
                handleSearchByDescription();
                break;
            case 7:
                handleSearchByLocation();
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
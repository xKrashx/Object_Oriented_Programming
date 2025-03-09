#include "smartcity.hpp"
#include <iostream>
#include <cstring>
#include <fstream>
#include <cmath>
#include <cstdlib>

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

// Helper function to calculate distance between two points
double calculateDistance(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    return std::sqrt(dx*dx + dy*dy);
}

// Helper function to check if a string contains a substring (case insensitive)
bool containsSubstring(const char* str, const char* substr) {
    char* lowerStr = new char[strlen(str) + 1];
    char* lowerSubstr = new char[strlen(substr) + 1];
    
    // Convert both strings to lowercase for case-insensitive comparison
    for (int i = 0; str[i]; i++) {
        lowerStr[i] = tolower(str[i]);
    }
    lowerStr[strlen(str)] = '\0';
    
    for (int i = 0; substr[i]; i++) {
        lowerSubstr[i] = tolower(substr[i]);
    }
    lowerSubstr[strlen(substr)] = '\0';
    
    bool result = strstr(lowerStr, lowerSubstr) != NULL;
    
    delete[] lowerStr;
    delete[] lowerSubstr;
    
    return result;
}

// New file serialization/deserialization implementation
bool saveEventToFile(const Event& event, const char* filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cout << "Error: Could not open file " << filename << " for writing.\n";
        return false;
    }
    
    file << "DESCRIPTION=" << event.description << '\n'
         << "LEVEL=" << static_cast<int>(event.level) << '\n'
         << "LOCATION_X=" << event.loc.x << '\n'
         << "LOCATION_Y=" << event.loc.y;
    
    file.close();
    return true;
}

bool loadEventFromFile(Event& event, const char* filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Error: Could not open file " << filename << " for reading.\n";
        return false;
    }
    
    char buffer[128];
    char description[64] = {0};
    int level = 0;
    int locX = 0, locY = 0;
    
    while (file.getline(buffer, sizeof(buffer))) {
        char* value = strchr(buffer, '=');
        if (value) {
            *value = '\0'; // Split string at '='
            value++; // Move to value part
            
            if (strcmp(buffer, "DESCRIPTION") == 0) {
                strncpy(description, value, 63);
            } else if (strcmp(buffer, "LEVEL") == 0) {
                level = atoi(value);
            } else if (strcmp(buffer, "LOCATION_X") == 0) {
                locX = atoi(value);
            } else if (strcmp(buffer, "LOCATION_Y") == 0) {
                locY = atoi(value);
            }
        }
    }
    
    file.close();
    
    // Assign values
    strcpy(event.description, description);
    event.level = (level >= static_cast<int>(EmergencyLevel::LOW) && level <= static_cast<int>(EmergencyLevel::HIGH)) ? static_cast<EmergencyLevel>(level) : EmergencyLevel::LOW;
    event.loc.x = locX;
    event.loc.y = locY;
    
    return true;
}

bool saveEventsToFile(const Event* events, int count, const char* filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cout << "Error: Could not open file " << filename << " for writing.\n";
        return false;
    }
    
    file << "EVENT_COUNT=" << count << '\n';
    
    for (int i = 0; i < count; i++) {
        file << "\n[EVENT_" << i << "]\n"
             << "DESCRIPTION=" << events[i].description << '\n'
             << "LEVEL=" << static_cast<int>(events[i].level) << '\n'
             << "LOCATION_X=" << events[i].loc.x << '\n'
             << "LOCATION_Y=" << events[i].loc.y;
    }
    
    file.close();
    return true;
}

int loadEventsFromFile(Event* events, int maxCount, const char* filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Error: Could not open file " << filename << " for reading.\n";
        return -1;
    }
    
    char buffer[128];
    int totalCount = 0;
    int currentEvent = -1;
    
    // First read the EVENT_COUNT
    if (file.getline(buffer, sizeof(buffer))) {
        char* value = strchr(buffer, '=');
        if (value && strncmp(buffer, "EVENT_COUNT", 11) == 0) {
            value++; // Move past '='
            totalCount = atoi(value);
            
            if (totalCount > maxCount) {
                totalCount = maxCount; // Limit to available space
            }
        }
    }
    
    // Now read event data
    while (file.getline(buffer, sizeof(buffer))) {
        // Check for new event section
        if (buffer[0] == '[' && strncmp(buffer, "[EVENT_", 7) == 0) {
            currentEvent++;
            if (currentEvent >= totalCount) break;
            
            events[currentEvent].description[0] = '\0';
            events[currentEvent].level = EmergencyLevel::LOW;
            events[currentEvent].loc.x = 0;
            events[currentEvent].loc.y = 0;
            continue;
        }
        
        if (currentEvent >= 0 && currentEvent < totalCount) {
            char* value = strchr(buffer, '=');
            if (value) {
                *value = '\0'; // Split at '='
                value++; // Move to value part
                
                if (strcmp(buffer, "DESCRIPTION") == 0) {
                    strncpy(events[currentEvent].description, value, 63);
                    events[currentEvent].description[63] = '\0'; // Ensure null termination
                } else if (strcmp(buffer, "LEVEL") == 0) {
                    int level = atoi(value);
                    events[currentEvent].level = (level >= static_cast<int>(EmergencyLevel::LOW) && level <= static_cast<int>(EmergencyLevel::HIGH)) ? static_cast<EmergencyLevel>(level) : EmergencyLevel::LOW;
                } else if (strcmp(buffer, "LOCATION_X") == 0) {
                    events[currentEvent].loc.x = atoi(value);
                } else if (strcmp(buffer, "LOCATION_Y") == 0) {
                    events[currentEvent].loc.y = atoi(value);
                }
            }
        }
    }
    
    file.close();
    return currentEvent + 1; // Return actual number of events loaded
}

// Search functions implementation
int searchEventsByLevel(const Event* events, int count, EmergencyLevel level, Event* results, int maxResults) {
    int found = 0;
    
    for (int i = 0; i < count && found < maxResults; i++) {
        if (events[i].level == level) {
            results[found++] = events[i];
        }
    }
    
    return found;
}

int searchEventsByDescription(const Event* events, int count, const char* description, Event* results, int maxResults) {
    int found = 0;
    
    for (int i = 0; i < count && found < maxResults; i++) {
        if (containsSubstring(events[i].description, description)) {
            results[found++] = events[i];
        }
    }
    
    return found;
}

int searchEventsByLocation(const Event* events, int count, int x, int y, int radius, Event* results, int maxResults) {
    int found = 0;
    
    for (int i = 0; i < count && found < maxResults; i++) {
        if (calculateDistance(events[i].loc.x, events[i].loc.y, x, y) <= radius) {
            results[found++] = events[i];
        }
    }
    
    return found;
}

int searchEventsInFile(const char* filename, EventSearchCriteria criteria, void* searchValue, Event* results, int maxResults) {
    // Read all events from file
    Event* allEvents = new Event[100]; // Assuming max 100 events
    int count = loadEventsFromFile(allEvents, 100, filename);
    
    if (count <= 0) {
        delete[] allEvents;
        return 0;
    }
    
    int found;
    
    // Search based on criteria
    switch (criteria) {
        case EventSearchCriteria::BY_LEVEL:
            found = searchEventsByLevel(allEvents, count, *(EmergencyLevel*)(searchValue), results, maxResults);
            break;
            
        case EventSearchCriteria::BY_DESCRIPTION:
            found = searchEventsByDescription(allEvents, count, (char*)(searchValue), results, maxResults);
            break;
            
        case EventSearchCriteria::BY_LOCATION: {
            int* loc = (int*)(searchValue);
            found = searchEventsByLocation(allEvents, count, loc[0], loc[1], loc[2], results, maxResults);
            break;
        }
        
        default:
            found = 0;
            break;
    }
    
    delete[] allEvents;
    return found;
}
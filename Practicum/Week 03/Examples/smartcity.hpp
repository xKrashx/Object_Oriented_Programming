#pragma once
#include "city_types.hpp"

struct Location {
    int x;
    int y;
};

struct BuildingStatus {
    unsigned int isOperational : 1;     // works or not
    unsigned int powerStatus : 2;       // level of power supply (0-3)
    unsigned int occupancy : 2;         // level of occupancy (0-3)
};

struct Building {
    char name[32];
    BuildingType type;    
    Location loc;
    BuildingStatus status;
};

struct Event {
    EmergencyLevel level; 
    Location loc;
    char description[64];
};

void printBuildingInfo(const Building& b);
void inputBuildingData(Building& b);
void printEventInfo(const Event& e);
void inputEventData(Event& e);

// New serialization/deserialization functions for events
bool saveEventToFile(const Event& event, const char* filename);
bool loadEventFromFile(Event& event, const char* filename);
bool saveEventsToFile(const Event* events, int count, const char* filename);
int loadEventsFromFile(Event* events, int maxCount, const char* filename);

// Event search criteria enum
enum class EventSearchCriteria {
    BY_LEVEL,
    BY_DESCRIPTION,
    BY_LOCATION
};

// Functions for event searching
int searchEventsByLevel(const Event* events, int count, EmergencyLevel level, Event* results, int maxResults);
int searchEventsByDescription(const Event* events, int count, const char* description, Event* results, int maxResults);
int searchEventsByLocation(const Event* events, int count, int x, int y, int radius, Event* results, int maxResults);
int searchEventsInFile(const char* filename, EventSearchCriteria criteria, void* searchValue, Event* results, int maxResults);
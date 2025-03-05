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


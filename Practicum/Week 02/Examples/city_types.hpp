#pragma once
#include <iostream>

enum class BuildingType {
    UNKNOWN,
    RESIDENTIAL,
    HOSPITAL,
    POLICE,
    FIRE_STATION
};

enum class EmergencyLevel {
    UNKNOWN,
    LOW,
    MEDIUM,
    HIGH
};

BuildingType getBuildingTypeFromUser();
EmergencyLevel getEmergencyLevelFromUser();
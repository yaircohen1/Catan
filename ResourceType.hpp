// coheny405@gmail.com
#pragma once
#include <string>

enum class ResourceType {
    SEABORDER,
    DESERT,
    BRICK,
    LUMBER,
    GRAIN,
    WOOL,
    ORE
};

std::string getResourceTypeName(ResourceType resourceType);
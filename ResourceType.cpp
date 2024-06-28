// coheny405@gmail.com
#include "ResourceType.hpp"

std::string getResourceTypeName(ResourceType resourceType) {
    switch (resourceType) {
        case ResourceType::SEABORDER:
            return "Sea Border";
        case ResourceType::DESERT:
            return "Desert";
        case ResourceType::LUMBER:
            return "Lumber";
        case ResourceType::BRICK:
            return "Brick";
        case ResourceType::GRAIN:
            return "Grain";
        case ResourceType::WOOL:
            return "Wool";
        case ResourceType::ORE:
            return "Ore";
        default:
            return "Unknown";
    }
}
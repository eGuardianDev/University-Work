#include "properties.hpp"

#include "random_numbers.hpp"
#include <iostream>

#include "visualization.hpp"

#include "entities.hpp"

int main(){

    Visuals visuals;

    // visuals.DrawCell(Config::World::GRID_SIZE_WIDTH/2,
        // Config::World::GRID_SIZE_HEIGHT/2, sf::Color::Red);

    std::vector<std::vector<Entities>> map(
        Config::World::GRID_SIZE_HEIGHT,
        std::vector<Entities>(
            Config::World::GRID_SIZE_WIDTH));

    map[0][0].type = 1;
    map[0][1].type = 2;
    
    while (visuals.Update()) {
        visuals.RerenderMap(map);
    }

    return 0;
}
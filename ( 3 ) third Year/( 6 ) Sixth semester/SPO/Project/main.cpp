#include "logic.hpp"
#include "properties.hpp"

#include "random_numbers.hpp"
#include <iostream>

#include "visualization.hpp"

#include "entities.hpp"

int main(){

    // Buffers
    std::vector<std::vector<Entities>> map(
        Config::World::GRID_SIZE_HEIGHT,
        std::vector<Entities>(
            Config::World::GRID_SIZE_WIDTH));
            
    // Helpers
    number_generator rng(Config::World::SEED);
    Visuals visuals;
    Logic logic(map, rng);

    // Initial
    logic.spawnInitial(map);
   
    // Loop
    // while (visuals.Update()) {
    //     logic.Step(map);
    //     visuals.RerenderMap(map);
    //     sf::sleep(sf::seconds(Config::World::WAIT_SECONDS_BEFORE_NEXT_STEP));
    // }

    while(true){
        logic.Step(map);
        // sf::sleep(sf::seconds(Config::World::WAIT_SECONDS_BEFORE_NEXT_STEP));
    }

    return 0;
}
#include "logic.hpp"
#include "properties.hpp"

#include "random_numbers.hpp"
#include <climits>
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
   
    
    if constexpr (Config::Debug::RUN_SIMULATIONS) {
        std::cout << "Starting simulations" << std::endl;
        
        // for(int i =0;i<)

    }
    // Loop
    int steps = Config::World::STEPS;

    if(steps == 0) steps = INT_MAX;
    while (visuals.IsOpen()) {

        bool shouldTakeStep = visuals.Update();

        if (shouldTakeStep) {
            
            if(steps <= 0){
                break;
            }
            steps--;
            logic.Step(map);
            sf::sleep(sf::seconds(Config::World::WAIT_SECONDS_BEFORE_NEXT_STEP));
        }
        visuals.RerenderMap(map);
    }


    std::cout << logic.averageTime() << std::endl;
    // while(true){
    //     logic.Step(map);
    //     // sf::sleep(sf::seconds(Config::World::WAIT_SECONDS_BEFORE_NEXT_STEP));
    // }

    return 0;
}
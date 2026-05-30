#include "properties.hpp"


#ifndef DUAL_BUFFER 
#include "1b-logic.hpp"
#else 
#include "logic.hpp"
#endif


#include "random_numbers.hpp"
#include <climits>
#include <iostream>

#include "visualization.hpp"

#include "entities.hpp"

int main(){

   
    
    if constexpr (Config::Debug::RUN_SIMULATIONS) {
        std::cout << "Starting simulations" << std::endl;
        
        int runs =  std::thread::hardware_concurrency();
        for(int i =runs;i>=1;--i){

            if(Config::World::GRID_SIZE_HEIGHT % i != 0) continue;
            if(Config::World::GRID_SIZE_WIDTH % i != 0) continue;

            for(int k = 0;k<5;++k){
                // Buffers
                std::vector<std::vector<Entities>> map(
                    Config::World::GRID_SIZE_HEIGHT,
                    std::vector<Entities>(
                        Config::World::GRID_SIZE_WIDTH));
                        
                // Helpers
                number_generator rng(Config::World::SEED);
                Logic logic(map, rng,i);

                // Initial
                logic.spawnInitial(map);

                int steps = Config::World::STEPS;
                if(steps == 0) steps = INT_MAX;
                while (steps > 0) {                    
                    steps--;
                    logic.Step(map);
                }
                std::cout << "Threads: " << i << " time: " << logic.averageTime() << std::endl;
            }

        }
        
    }else{        

        // Buffers
        std::vector<std::vector<Entities>> map(
            Config::World::GRID_SIZE_HEIGHT,
            std::vector<Entities>(
                Config::World::GRID_SIZE_WIDTH));
                
        // Helpers
        number_generator rng(Config::World::SEED);
        Logic logic(map, rng,1);

        // Initial
        logic.spawnInitial(map);
        Visuals visuals;
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
    }


    return 0;
}
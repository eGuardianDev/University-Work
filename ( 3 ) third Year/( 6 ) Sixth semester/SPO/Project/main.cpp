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
    std::cout << "======================" << std::endl;
    std::cout << "Hello-WaTor simulation" << std::endl;
    std::cout << " by Tsvetomir Staykov " << std::endl;
    std::cout << "======================" << std::endl;
    std::cout << "- Size: " << Config::World::GRID_SIZE_WIDTH << "x" << Config::World::GRID_SIZE_HEIGHT  << std::endl;
    std::cout << "- Steps: " << Config::World::STEPS << std::endl;
    std::cout << "- Starting fish density " << Config::Spawn::INITIAL_FISH_DENSITY  << std::endl;
    std::cout << "- Starting shark density " << Config::Spawn::INITIAL_SHARK_DENSITY  << std::endl << std::endl;
    
    std::cout << "Fish\n";
    std::cout << "- Breeding timer: " << Config::Fish::STARTING_BREED_TIMER  << std::endl << std::endl;
   
    std::cout << "Shark\n";
    std::cout << "- Starting energy: " << Config::Shark::STARTING_ENERGY  << std::endl;
    std::cout << "- Losing energy per step: " << Config::Shark::STEP_LOSE_ENERGY  << std::endl;
    std::cout << "- Eating energy gain: " << Config::Shark::EATING_GAIN_ENERGY  << std::endl;
    std::cout << "- Required energy for breeding: " << Config::Shark::BREED_ENERGY_REQUIRED  << std::endl << std::endl;
   
    
    if constexpr (Config::Debug::RUN_SIMULATIONS) {
        std::cout << "> Starting simulations" << std::endl;
        
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
                std::cout << " = Threads: " << i << " time: " << logic.averageTime() << std::endl;
            }

        }
        
    }else{        

        std::cout << "> Starting single simulation" << std::endl; 
        std::cout << "- Threads: " << Config::World::THREADS << std::endl; 


        // // Buffers
        std::vector<std::vector<Entities>> map(
            Config::World::GRID_SIZE_HEIGHT,
            std::vector<Entities>(
                Config::World::GRID_SIZE_WIDTH));
                
        // Helpers
        number_generator rng(Config::World::SEED);
        Logic logic(map, rng,1);

        // Initial
        logic.spawnInitial(map);

        
        if constexpr (Config::Debug::VISUALS) {
            std::cout << "- Visuals: Enabled" << std::endl; 
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
        }else{
            std::cout << "- Visuals: Disabled" << std::endl;
            int steps = Config::World::STEPS;
            if(steps == 0) steps = INT_MAX;
            while (steps > 0) {
                
                steps--;
                logic.Step(map);
                sf::sleep(sf::seconds(Config::World::WAIT_SECONDS_BEFORE_NEXT_STEP));
            }
        }



        std::cout << "\n ==  Done!  ==" << std::endl;
        std::cout << " + Ellapsed time: " << logic.total_time() << std::endl;
        std::cout << " + Average execution time between steps: " << logic.averageTime() << std::endl << std::endl;
    }


    return 0;
}
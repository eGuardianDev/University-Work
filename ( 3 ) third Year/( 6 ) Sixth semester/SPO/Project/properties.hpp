#ifndef SIM_PROPERTIES
#define SIM_PROPERTIES

#include <string>

struct Config{
    
    struct World {
        inline static constexpr float WAIT_SECONDS_BEFORE_NEXT_STEP = 1;
        inline static constexpr int GRID_SIZE_WIDTH = 10;
        inline static constexpr int GRID_SIZE_HEIGHT = 10;
        inline static constexpr int SEED = 1000;
        inline static const std::string TITLE_NAME = "Pixels";
    };

    struct Spawn {
        inline static constexpr float INITIAL_FISH_DENSITY = 0.4f;
        inline static constexpr float INITIAL_SHARK_DENSITY = 0.1f;
    };
    
    struct Fish {
        inline static constexpr int STARTING_BREED_TIMER = 10;
    };

    struct Shark {
        inline static constexpr int STARTING_ENERGY = 10;
        inline static constexpr int EATING_GAIN_ENERGY = 5;
        inline static constexpr int STEP_LOSE_ENERGY = 1;
        inline static constexpr int BREED_ENERGY_REQUIRED = 1;
    };

};


#endif // SIM_PROPERTIES
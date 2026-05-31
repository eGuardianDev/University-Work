#ifndef SIM_PROPERTIES
#define SIM_PROPERTIES

#include <SFML/Graphics/Color.hpp>
#include <string>

// #define DUAL_BUFFER 

struct Config{
    
    struct World {
        inline static constexpr float WAIT_SECONDS_BEFORE_NEXT_STEP = 0;
        inline static constexpr int GRID_SIZE_WIDTH = 500;
        inline static constexpr int GRID_SIZE_HEIGHT = 500;
        inline static constexpr int WINDOW_SIZE_WIDTH = 1000;
        inline static constexpr int WINDOW_SIZE_HEIGHT = 1000;
        inline static constexpr int SEED = 1235;
        inline static const std::string TITLE_NAME = "Pixels";
        inline static constexpr int THREADS = 8;
        inline static constexpr int STEPS = 1000;
    };

    struct Rendering{
        inline static const sf::Color EMPTY_COLOR = sf::Color::Black;
        inline static const sf::Color FISH_COLOR = sf::Color::Green;
        inline static const sf::Color SHARK_COLOR = sf::Color::Red;
        inline static constexpr int FRAME_LIMIT = 100000;
    };

    struct Debug{
        inline static constexpr bool COUNT_ANIMALS = false;
        inline static constexpr bool RECORD_TO_FILE = false;
        inline static constexpr bool RUN_SIMULATIONS = false;
        inline static constexpr bool VISUALS = true;
    };

    struct Spawn {
        inline static constexpr float INITIAL_FISH_DENSITY = 0.05f;
        inline static constexpr float INITIAL_SHARK_DENSITY = 0.05f;
    };
    
    struct Fish {
        inline static constexpr int STARTING_BREED_TIMER = 10;
    };

    struct Shark {
        inline static constexpr int STARTING_ENERGY = 10;
        inline static constexpr int EATING_GAIN_ENERGY = 15;
        inline static constexpr int STEP_LOSE_ENERGY = 1;
        inline static constexpr int BREED_ENERGY_REQUIRED = 90;
    };


    
};


#endif // SIM_PROPERTIES

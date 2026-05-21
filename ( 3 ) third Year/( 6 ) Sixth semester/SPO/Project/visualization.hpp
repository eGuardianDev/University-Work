#ifndef VISUALIZATION_HPP
#define VISUALIZATION_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Window/Keyboard.hpp>

#include "properties.hpp"

class Visuals{

    sf::RenderWindow window;
    Visuals():
    window(
        sf::VideoMode(
            Config::World::GRID_SIZE_WIDTH,
            Config::World::GRID_SIZE_HEIGHT),
            Config::World::TITLE_NAME){

    }
    
    void RerenderMap(
        std::vector<std::vector<int>> &map){
    }

    ~Visuals(){
        window.close();
    }
};



#endif // VISUALIZATION_HPP
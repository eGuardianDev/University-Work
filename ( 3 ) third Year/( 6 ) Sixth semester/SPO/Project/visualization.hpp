#ifndef VISUALIZATION_HPP
#define VISUALIZATION_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <stdexcept>

#include "properties.hpp"

#include "entities.hpp"

class Visuals{

    public:
    Visuals():
    window(
        sf::VideoMode(
        Config::World::WINDOW_SIZE_WIDTH,
        Config::World::WINDOW_SIZE_HEIGHT),
        Config::World::TITLE_NAME){
        window.setFramerateLimit(Config::Rendering::FRAME_LIMIT);
    }

    bool Update() {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed &&
                event.key.code == sf::Keyboard::Escape)
                window.close();
        }
        return window.isOpen();
    }

    void DrawCell(int gridX, int gridY, sf::Color color) {
        const float cellW = (float)Config::World::WINDOW_SIZE_WIDTH  / Config::World::GRID_SIZE_WIDTH;
        const float cellH = (float)Config::World::WINDOW_SIZE_HEIGHT / Config::World::GRID_SIZE_HEIGHT;

        sf::RectangleShape cell(sf::Vector2f(cellW, cellH));
        cell.setPosition(gridX * cellW, gridY * cellH);
        cell.setFillColor(color);
        window.draw(cell);
    }

    void RerenderMap(
        std::vector<std::vector<Entities>> &map){

        window.clear();
        
        for(int r =0; r < Config::World::GRID_SIZE_HEIGHT;++r){
            for(int c = 0; c<Config::World::GRID_SIZE_WIDTH;++c){
                Entities ent = map[r][c];
                switch(ent.type){
                    case 0:
                        DrawCell(c,r, Config::Rendering::EMPTY_COLOR);
                        break;
                    case 1:
                        DrawCell(c,r, Config::Rendering::FISH_COLOR);
                        break;
                    case 2:
                        DrawCell(c,r, Config::Rendering::SHARK_COLOR);
                        break;
                    default:
                        throw std::invalid_argument("Invalid type in cell");
                        break;
                }
            }
        }

        window.display();
    }
        
    ~Visuals(){
        window.close();
    }

    private:
    sf::RenderWindow window;
};



#endif // VISUALIZATION_HPP
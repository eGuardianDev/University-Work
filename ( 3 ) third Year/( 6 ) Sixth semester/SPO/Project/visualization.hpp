#ifndef VISUALIZATION_HPP
#define VISUALIZATION_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <stdexcept>

#include "properties.hpp"

#include "entities.hpp"
class Visuals {
public:
    Visuals():
    window(sf::VideoMode(
        Config::World::WINDOW_SIZE_WIDTH,
        Config::World::WINDOW_SIZE_HEIGHT),
        Config::World::TITLE_NAME),
    vertices(sf::Quads, 
        Config::World::GRID_SIZE_WIDTH * 
        Config::World::GRID_SIZE_HEIGHT * 4)  
    {
        window.setFramerateLimit(Config::Rendering::FRAME_LIMIT);

        cellW = (float)Config::World::WINDOW_SIZE_WIDTH  / Config::World::GRID_SIZE_WIDTH;
        cellH = (float)Config::World::WINDOW_SIZE_HEIGHT / Config::World::GRID_SIZE_HEIGHT;

        for(int r = 0; r < Config::World::GRID_SIZE_HEIGHT; r++) {
            for(int c = 0; c < Config::World::GRID_SIZE_WIDTH; c++) {
                int i = (r * Config::World::GRID_SIZE_WIDTH + c) * 4;
                vertices[i+0].position = sf::Vector2f(c * cellW,         r * cellH);
                vertices[i+1].position = sf::Vector2f((c+1) * cellW,     r * cellH);
                vertices[i+2].position = sf::Vector2f((c+1) * cellW, (r+1) * cellH);
                vertices[i+3].position = sf::Vector2f(c * cellW,     (r+1) * cellH);
            }
        }
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
    void RerenderMap(std::vector<std::vector<Entities>> &map) {
        for(int r = 0; r < Config::World::GRID_SIZE_HEIGHT; r++) {
            for(int c = 0; c < Config::World::GRID_SIZE_WIDTH; c++) {
                int i = (r * Config::World::GRID_SIZE_WIDTH + c) * 4;
                sf::Color color;
                switch(map[r][c].type) {
                    case 0: color = Config::Rendering::EMPTY_COLOR; break;
                    case 1: color = Config::Rendering::FISH_COLOR;  break;
                    case 2: color = Config::Rendering::SHARK_COLOR; break;
                    default: throw std::invalid_argument("Invalid type");
                }
                vertices[i+0].color = color;
                vertices[i+1].color = color;
                vertices[i+2].color = color;
                vertices[i+3].color = color;
            }
        }

        window.clear();
        window.draw(vertices);
        window.display();
    }

private:
    sf::RenderWindow window;
    sf::VertexArray vertices;
    float cellW, cellH;
};



#endif // VISUALIZATION_HPP
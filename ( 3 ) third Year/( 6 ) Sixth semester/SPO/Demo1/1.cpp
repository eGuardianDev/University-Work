#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <vector>

#include <iostream>

struct fish {
    sf::Color color;
};

#define map_size_width 1920
#define map_size_height 1080
#define map_size (map_size_height * map_size_width)

void put_fish( std::vector<fish>& map, std::vector<fish>& map2, int x,int y){


    int index = y * map_size_width + x;
    if(map[index].color != sf::Color::Green){
        map2[index].color = sf::Color::Green;
    }
}

int main() {
    std::vector<fish> map(map_size);
    std::vector<fish> map_2(map_size);

    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Pixels");

    // Set one "fish"
    map[1920 * 1080 /2 + 1920/2 ] = fish{sf::Color::Green};

    // Create full image
    sf::Image image;
    image.create(map_size_width, map_size_height, sf::Color::Black);

    // Convert map -> pixels
    for (int y = 0; y < map_size_height; ++y) {
        for (int x = 0; x < map_size_width; ++x) {
            int index = y * map_size_width + x;

            if (map[index].color == sf::Color::Green) {
                image.setPixel(x, y, sf::Color::Green);
            }
        }
    }

    // Upload once
    sf::Texture texture;
    texture.loadFromImage(image);

    sf::Sprite sprite(texture);

    int x = 0;
    int H = map_size_height;
    int W = map_size_width;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed)
                window.close();


        // mods here

        // 🧠 MODIFY IMAGE (CPU side)
        for (int y = 0; y < map_size_height; ++y) {
            for (int x = 0; x < map_size_width; ++x) {
                int index = y * map_size_width + x;
                if (map[index].color == sf::Color::Green) {
                    // std::cout << "updates: "<< x << ":" << y << std::endl;
                    if(!(y >= map_size_height)){
                        put_fish(map, map_2, x+1, y);
                    }
                    if(!(y < 0)){
                        put_fish(map, map_2, x-1, y);
                    }
                    if(!(x >= map_size_width)){
                        put_fish(map, map_2, x, y+1);
                    }
                    if(!(x < 0)){
                        put_fish(map, map_2, x, y-1);
                    }
                }
            }
        }
        std::swap(map, map_2);
        std::fill(map_2.begin(), map_2.end(), fish{sf::Color::Black});
        // 🧠 MODIFY IMAGE (CPU side)
        for (int y = 0; y < map_size_height; ++y) {
            for (int x = 0; x < map_size_width; ++x) {
                int index = y * map_size_width + x;
                if (map[index].color == sf::Color::Green) {
                    // std::cout << "updates: "<< x << ":" << y << std::endl;
                    image.setPixel(x, y, sf::Color::Green);
                }
            }
        }
        texture.update(image);

        window.clear();
        window.draw(sprite); // draw entire image at once
        window.display();

        sf::sleep(sf::milliseconds(1));
        // std::cout << "Making step" << std::endl;
    }

    return 0;
}
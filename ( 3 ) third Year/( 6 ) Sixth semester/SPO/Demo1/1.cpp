#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <cstdint>
#include <random>
#include <vector>

#include <iostream>


#define default_spawn_timer 5
#define default_despawn_timer 5

#define default_shark_energy 10
struct fish {
    int id = 0;
    sf::Color color;
    int spawn = default_spawn_timer;
    int despawn = default_despawn_timer;
    int energy = default_shark_energy;
};

#define map_size_width 25//1920/2
#define map_size_height 25//1080/2
#define map_size (map_size_height * map_size_width)



int main() {
    std::vector<fish> map(map_size);
    std::vector<fish> map_2(map_size);

    sf::RenderWindow window(sf::VideoMode(map_size_width, map_size_height), "Pixels");

    // Set one "fish"
    // map[1920 * 1080 /2 + 1920/2 ] = fish{1,sf::Color::Green};
    

    std::random_device rd1;              // real entropy (if available)
    std::mt19937 gen1(rd1());             // seed generator

    std::uniform_int_distribution<> dist1(1, 100);

    for(int x =0; x<map_size_width;++x){
        for(int y=0; y<map_size_height;++y){
            int index = y * map_size_width + x;
            int dir = dist1(gen1);
            if(dir == 1){
                map[index] = fish{index,sf::Color::Green};
            }else if(dir == 2){
                map[index] = fish{index,sf::Color::Red};
            }
        }
    }

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

    std::random_device rd;              // real entropy (if available)
    std::mt19937 gen(rd());             // seed generator

    std::uniform_int_distribution<> dist(1, 4);


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed)
                window.close();

        int count =0;

        // mods here

        for (int y = 0; y < map_size_height; ++y) {
            for (int x = 0; x < map_size_width; ++x) {
                int index = y * map_size_width + x;

                if (map[index].color == sf::Color::Green) {
                    
                    count++;

                    int dir = dist(gen);
                    
                    int old_index = index;

                    int counter = 0;
                    while(counter != 4){
                        switch(dir){
                            case 1:
                            index+=1;
                            break;
                            case 2:
                            index-=1;
                            break;
                            case 3:
                            index+= map_size_width;
                            break;
                            case 4:
                            index-= map_size_width;
                            break;
                        }

                        if(index <0) {
                            index += map_size - map_size_width;
                        }else if(index >= map_size - map_size_width){
                            index -= (map_size- map_size_width);
                        }

                        if(map[index].color == sf::Color::Red || map[index].color == sf::Color::Green || map_2[index].color == sf::Color::Green){
                            
                            index = old_index;
                            counter++;
                            dir+=1;
                            if(dir == 5){
                                dir = 1;
                            }
                        }else{
                            break;
                        }
                    }

                    
                    if(counter != 4){
                        map[old_index].spawn--;
                    }
                    if(index == old_index){
                        map[index].despawn--;
                    }else{
                        map[index].despawn = default_despawn_timer;
                    }
                    if(map[index].despawn > 0){
                        map_2[index] = map[old_index];
                    }
                    if(counter !=4){
                        if(index != old_index && map_2[index].spawn < 0){
                            map_2[old_index] = fish{map[old_index].id+1,sf::Color::Green};
                            map_2[index].spawn = default_spawn_timer;
                        }
                    }

                    
                }else if (map[index].color == sf::Color::Red){
                    map_2[index] = map[index];
                }
            }
        }

        std::swap(map, map_2);
        std::fill(map_2.begin(), map_2.end(), fish{0,sf::Color::Black});


        int count_of_fish =0, count_of_sharks =0;
        for (int y = 0; y < map_size_height; ++y) {
            for (int x = 0; x < map_size_width; ++x) {
                int index = y * map_size_width + x;
                if(map[index].color == sf::Color::Green){
                    // std::cout << "updates: "<< x << ":" << y << std::endl;
                    image.setPixel(x, y, sf::Color::Green);
                    count_of_fish++;
                }
                else if (map[index].color == sf::Color::Black){
                        image.setPixel(x, y, sf::Color::Black); 
                }else if (map[index].color == sf::Color::Red){
                    count_of_sharks++;
                    image.setPixel(x,y,sf::Color::Red);
                }
            }
        }
        std::cout << "fishes: " << count_of_fish << " sharks: " << count_of_sharks << std::endl;
        texture.update(image);

        window.clear();
        window.draw(sprite); // draw entire image at once
        window.display();

        // std::cout << "Currently " << count << " fishes" << std::endl;
        sf::sleep(sf::milliseconds(100));
        // std::cout << "Making step" << std::endl;
    }

    return 0;
}
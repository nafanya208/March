#include <SFML/Graphics.hpp>
#include "Field.h"
#include <string>
#include "Sprite.h"
#include "Archer.h"
#include <vector>
#include <set>
using namespace sf;

sf::Vector2f operator+(const sf::Vector2f& vec1, const sf::Vector2f& vec2) {
    return sf::Vector2f(vec1.x + vec2.x, vec1.y + vec2.y);
}

sf::Vector2f operator*(const sf::Vector2f& vec1, float second) {
    return sf::Vector2f(vec1.x * second, vec1.y * second);
}


void UpdateMovement(const std::set<sf::Keyboard::Key>& keys , Field& field) {
    
    sf::Vector2f direction(0, 0);

    if (keys.count(sf::Keyboard::D)) {
        direction.x += 1;
    }
    if (keys.count(sf::Keyboard::A)) {
        direction.x -= 1;
    }
    if (keys.count(sf::Keyboard::W)) {
        direction.y -= 1;
    }
    if (keys.count(sf::Keyboard::S)) {
        direction.y += 1;
    }
    

    field.hero.Move(direction);
    
    field.map_shift = field.map_shift - direction * field.hero.speed;
}


int main()
{
    std::vector<sf::Vector2f> buttons;
    RenderWindow window(VideoMode(800, 800), L"Новый проект", Style::Default);






    window.setVerticalSyncEnabled(true);

    RectangleShape shape(sf::Vector2f(300, 300));
    shape.setPosition(100, 100);
    shape.setFillColor(Color::Magenta);


    Field field(sf::Vector2f(800, 800));

    std::set<sf::Keyboard::Key> keys;

    /*std::string a = "C:/IT/SFML-2.6.2/March/March/March/archer.png";
    game::Sprite sprite(a);*/

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();

           

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::G) {
                    field.hero.Attack();
                }
                else {
                    keys.insert(event.key.code);
                }
            }
            
            if (event.type == sf::Event::KeyReleased) {

                keys.erase(event.key.code);
            }
        }
        

  
    UpdateMovement(keys, field);
    field.Step();
    window.clear(Color::Blue);
    field.Draw(window);
    //sprite.Draw(window);
    //window.draw(shape);
    window.display();
}
return 0;
}
   

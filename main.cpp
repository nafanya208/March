#include <SFML/Graphics.hpp>
#include "Field.h"
#include <string>
#include "Sprite.h"
#include "Archer.h"
#include <vector>
#include <set>
using namespace sf;

void UpdateMovement(const std::set<sf::Keyboard::Key>& keys , Hero& hero) {
    
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

    hero.Move(direction);
}


int main()
{
    std::vector<sf::Vector2f> buttons;
    RenderWindow window(VideoMode(800, 800), L"Новый проект", Style::Default);

    




    window.setVerticalSyncEnabled(true);

    RectangleShape shape(sf::Vector2f(300, 300));
    shape.setPosition(100, 100);
    shape.setFillColor(Color::Magenta);

    
    Field field(sf::Vector2f(800 , 800));

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

            //if (event.type == Event::KeyPressed) {
            //    if (event.key.code == sf::Keyboard::D) {
            //        /*field.hero.SetDirection(sf::Vector2f(1, 0));*/
            //        field.hero.direction.x += 1;
            //    }
            //    if (event.key.code == sf::Keyboard::A) {
            //        /*field.hero.SetDirection(sf::Vector2f(-1, 0));*/
            //        field.hero.direction.x -= 1;
            //    }
            //    if (event.key.code == sf::Keyboard::W) {
            //        /*field.hero.SetDirection(sf::Vector2f(0, -1));*/
            //        field.hero.direction.y -= 1;
            //    }
            //    if (event.key.code == sf::Keyboard::S) {
            //        /*field.hero.SetDirection(sf::Vector2f(0, 1));*/
            //        field.hero.direction.y += 1;
            //    }
            //
            //
            //
            //}
            //if (event.type == Event::KeyReleased) {
            //    if (event.key.code == sf::Keyboard::D) {
            //        field.hero.SetDirection(sf::Vector2f(0, 0));
            //    }
            //    if (event.key.code == sf::Keyboard::A) {
            //        field.hero.SetDirection(sf::Vector2f(0, 0));
            //    }
            //    if (event.key.code == sf::Keyboard::W) {
            //        field.hero.SetDirection(sf::Vector2f(0, 0));
            //    }
            //    if (event.key.code == sf::Keyboard::S) {
            //        field.hero.SetDirection(sf::Vector2f(0, 0));
            //    }
            //}

            if (event.type == sf::Event::KeyPressed) {
                keys.insert(event.key.code);
            }
            if (event.type == sf::Event::KeyReleased) {
                keys.erase(event.key.code);
            }
        }
        UpdateMovement(keys , field.hero);
        field.Step();
        window.clear(Color::White);
        field.Draw(window);
        //sprite.Draw(window);
        //window.draw(shape);
        window.display();
    }
    return 0;
}
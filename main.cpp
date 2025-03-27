#include <SFML/Graphics.hpp>
#include "Field.h"
#include <string>
#include "Sprite.h"
using namespace sf;

int main()
{

    RenderWindow window(VideoMode(400, 400), L"����� ������", Style::Default);

    window.setVerticalSyncEnabled(true);

    RectangleShape shape(sf::Vector2f(300, 300));
    shape.setPosition(100, 100);
    shape.setFillColor(Color::Magenta);


    Field field(sf::Vector2f(400 , 400));
    std::string a = "C:\IT\SFML-2.6.2\March\March\March\archer.png";
    game::Sprite sprite(a);
    
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        
        window.clear(Color::White);
        
        field.Draw(window);
        sprite.Draw(window);
        /*window.draw(shape);*/
        window.display();
    }
    return 0;
}
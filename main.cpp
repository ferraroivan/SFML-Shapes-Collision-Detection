#include <SFML/Graphics.hpp>
#include <iostream>

int main(int argc, char * argv[])
{

    // create a new window of size w*h pixels
    // top-left of the window is (0,0) and bottom-right is (w,h)
    const int wWidth = 800;
    const int wHeight = 600;
	sf::RenderWindow window(sf::VideoMode(wWidth, wHeight), "My window");
    window.setFramerateLimit(60);

    // rect1
    sf::Vector2f rectangle_position(50, 50);
    sf::Vector2f rect_size(100, 100);
    
    sf::RectangleShape rect;
    rect.setPosition(rectangle_position);
    rect.setSize(rect_size);
    rect.setFillColor(sf::Color::White);
    
    // rect2
    sf::Vector2f rectangle_position2(100, 40);
    sf::Vector2f rect_size2(80, 200);

    sf::RectangleShape rect2;
    rect2.setPosition(rectangle_position2);
    rect2.setSize(rect_size2);
    rect2.setFillColor(sf::Color::Red);

    // cirlce1
    sf::Vector2f circle_position(300, 400);

    sf::CircleShape circle;
    circle.setRadius(50);
    circle.setFillColor(sf::Color::Yellow);
    circle.setPosition(circle_position);
    float diameter_c1 = circle.getRadius() * 2;

    // circle2
    sf::Vector2f circle_position2(90, 300);

    sf::CircleShape circle2;
    circle2.setRadius(100);
    circle2.setFillColor(sf::Color::Green);
    circle2.setPosition(circle_position2);
    float diameter_c2 = circle2.getRadius() * 2;


    // X and Y velocity
    float xVelocityRect1 = 3;
    float yVelocityRect1 = 3;
    
    float xVelocityRect2 = 6;
    float yVelocityRect2 = 6;

    float xVelocityCircle1 = 8;
    float yVelocityCircle1 = 8;

    float xVelocityCircle2 = 4;
    float yVelocityCircle2 = 4;


    sf::Font myFont;
    if (!myFont.loadFromFile("Anonymous_font/Anonymous.ttf"))
    {
        std::cerr << "Could not load font!\n";
        exit(-1);
    }

    // rect1 text
    sf::Text text("RWhite", myFont, 24);
    text.setFillColor(sf::Color::Red);
    sf::FloatRect textBounds = text.getLocalBounds();
    text.setPosition(rect.getPosition().x + (rect.getSize().x - textBounds.width) / 2, 
                     rect.getPosition().y + (rect.getSize().y - textBounds.height) / 2);

    // rect2 text
    sf::Text text2("RRed", myFont, 24);
    text2.setFillColor(sf::Color::White);
    sf::FloatRect textBounds2 = text2.getLocalBounds();
    text2.setPosition(rect2.getPosition().x + (rect2.getSize().x - textBounds2.width) / 2, 
                      rect2.getPosition().y + (rect2.getSize().y - textBounds2.height) / 2);
    
    // circle1 text    
    sf::Text text3("CYellow", myFont, 12);
    sf::FloatRect textBounds3 = text3.getLocalBounds();
    text3.setFillColor(sf::Color::Black);
    text3.setPosition(circle.getPosition().x + (circle.getRadius() * 2 - textBounds3.width) / 2, 
                      circle.getPosition().y + (circle.getRadius() * 2 - textBounds3.height) / 2);
    
    // circle2 text
    sf::Text text4("CGreen", myFont, 24);
    sf::FloatRect textBounds4 = text4.getLocalBounds();
    text4.setFillColor(sf::Color::White);
    text4.setPosition(circle2.getPosition().x + (circle2.getRadius() * 2 - textBounds4.width) / 2, 
                      circle2.getPosition().y + (circle2.getRadius() * 2 - textBounds4.height) / 2);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
        // this event triggers when the window is closed
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        // Check collisions from the top-left corner of the rectangle (100 is the size of rect)
        if (rectangle_position.x < 0 || rectangle_position.x > 800 - 100) 
        {
            xVelocityRect1 *= -1;
        }
        if (rectangle_position.y < 0 || rectangle_position.y > 600 - 100) 
        {
            yVelocityRect1 *= -1;
        }

        // Collision detection rect2 
        if (rectangle_position2.x < 0 || rectangle_position2.x > 800 - 80)
        {
            xVelocityRect2 *= -1;
        }
        if (rectangle_position2.y < 0 || rectangle_position2.y > 600 - 200)
        {
            yVelocityRect2 *= -1;
        }

        // Collision detection circle1
        if (circle_position.x < 0 || circle_position.x  > 800 - diameter_c1)
        {
            xVelocityCircle1 *= -1;
        }
        if (circle_position.y < 0 || circle_position.y > 600 - diameter_c1)
        {
            yVelocityCircle1 *= -1;
        }

        // Collision detection circle2
        if (circle_position2.x < 0 || circle_position2.x > 800 - diameter_c2)
        {
            xVelocityCircle2 *= -1;
        }
        if (circle_position2.y < 0 || circle_position2.y > 600 - diameter_c2)
        {
            yVelocityCircle2 *= -1;
        }

        // Update Rect 1 
        rectangle_position.x += xVelocityRect1;
        rectangle_position.y += yVelocityRect1;
        rect.setPosition(rectangle_position);

        // Update text Rect 1
        text.setPosition(rect.getPosition().x + (rect.getSize().x - textBounds.width) / 2, 
                         rect.getPosition().y + (rect.getSize().y - textBounds.height) / 2);

        // Update Rect 2
        rectangle_position2.x += xVelocityRect2;
        rectangle_position2.y += yVelocityRect2;
        rect2.setPosition(rectangle_position2);

        // Update text Rect 2
        text2.setPosition(rect2.getPosition().x + (rect2.getSize().x - textBounds2.width) / 2, 
                         rect2.getPosition().y + (rect2.getSize().y - textBounds2.height) / 2);

        // Update Cirlce 1
        circle_position.x += xVelocityCircle1;
        circle_position.y += yVelocityCircle1;
        circle.setPosition(circle_position);        

        // Update text Circle 1
        text3.setPosition(circle.getPosition().x + (circle.getRadius() * 2 - textBounds3.width) / 2, 
                          circle.getPosition().y + (circle.getRadius() * 2 - textBounds3.height) / 2);        

        // Update Circle 2
        circle_position2.x += xVelocityCircle2;
        circle_position2.y += yVelocityCircle2;
        circle2.setPosition(circle_position2);

        // Update text Circle 2
        text4.setPosition(circle2.getPosition().x + (circle2.getRadius() * 2 - textBounds4.width) / 2, 
                          circle2.getPosition().y + (circle2.getRadius() * 2 - textBounds4.height) / 2);

        window.clear();

        window.draw(rect);
        window.draw(text);

        window.draw(rect2);
        window.draw(text2);

        window.draw(circle);
        window.draw(text3);

        window.draw(circle2);
        window.draw(text4);

        window.display();
    }
    
	return 0;
}


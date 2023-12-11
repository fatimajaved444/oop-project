//#include <SFML/Graphics.hpp>
//
//int main()
//{
//    sf::Font a;
//    a.loadFromFile("new.ttf");
//    // create the window
//    sf::RenderWindow window(sf::VideoMode(800, 600), "My flex");
//    sf::Text t;
//    t.setFont(a);
//    t.setFillColor(sf::Color::Blue);
//    t.setPosition(100, 300);
//    t.setCharacterSize(60);
//    t.setString("FLEX");
//
//    // run the program as long as the window is open
//    while (window.isOpen())
//    {
//        // check all the window's events that were triggered since the last iteration of the loop
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            // "close requested" event: we close the window
//            if (event.type == sf::Event::Closed)
//                window.close();
//        }
//
//        // clear the window with black color
//        window.clear(sf::Color::White);
//        window.draw(t);
//
//        // end the current frame
//        window.display();
//    }
//
//    return 0;
//}
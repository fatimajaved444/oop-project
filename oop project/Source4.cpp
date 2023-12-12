//#include<SFML/Graphics.hpp>
//int main()
//{
//    sf::Font a;
//    a.loadFromFile("arial.ttf");
//
//    // create the window
//    sf::RenderWindow window(sf::VideoMode(800, 900), "My flex");
//    sf::Text t, t1, t2, t3, t4, t31, t32, t33, t34, t35, t36, t37;
//    t.setFont(a);
//    t.setFillColor(sf::Color::Blue);
//    t.setPosition(300, 100);
//    t.setCharacterSize(60);
//    t.setString("FLEX");
//
//    t1.setFont(a);
//    t1.setFillColor(sf::Color::Blue);
//    t1.setPosition(250, 160);
//    t1.setCharacterSize(30);
//    t1.setString("academic portal");
//
//    t2.setFont(a);
//    t2.setFillColor(sf::Color::Black);
//    t2.setPosition(150, 245);
//    t2.setCharacterSize(20);
//    t2.setString("Roll No.:");
//
//    t3.setFont(a);
//    t3.setFillColor(sf::Color::Black);
//    t3.setPosition(130, 330);
//    t3.setCharacterSize(20);
//    t3.setString("Password:");
//
//    sf::RectangleShape rectangle(sf::Vector2f(300.f, 30.f));
//    rectangle.setFillColor(sf::Color::Yellow);
//    rectangle.setPosition(230.f, 250.f);
//
//    sf::RectangleShape rectangle1(sf::Vector2f(300.f, 30.f));
//    rectangle1.setFillColor(sf::Color::Yellow);
//    rectangle1.setPosition(230.f, 330.f);
//
//
//    t4.setFont(a);
//    t4.setFillColor(sf::Color::Red);
//    t4.setPosition(130, 430);
//    t4.setCharacterSize(17);
//    t4.setString("MAIN MENU:");
//
//    t31.setFont(a);
//    t31.setFillColor(sf::Color::Black);
//    t31.setPosition(130, 480);
//    t31.setCharacterSize(17);
//    t31.setString("1.ENROLLMENT:");
//
//    t32.setFont(a);
//    t32.setFillColor(sf::Color::Black);
//    t32.setPosition(130, 530);
//    t32.setCharacterSize(17);
//    t32.setString("COURSE REGISTRATION:");
//
//    t33.setFont(a);
//    t33.setFillColor(sf::Color::Black);
//    t33.setPosition(130, 580);
//    t33.setCharacterSize(17);
//    t33.setString("ATTENDANCE:");
//
//    t34.setFont(a);
//    t34.setFillColor(sf::Color::Black);
//    t34.setPosition(130, 630);
//    t34.setCharacterSize(17);
//    t34.setString("MARKS:");
//
//    t35.setFont(a);
//    t35.setFillColor(sf::Color::Black);
//    t35.setPosition(130, 680);
//    t35.setCharacterSize(17);
//    t35.setString("COURSE WITHDRAWAL:");
//
//    t36.setFont(a);
//    t36.setFillColor(sf::Color::Black);
//    t36.setPosition(130, 730);
//    t36.setCharacterSize(17);
//    t36.setString("EXIT:");
//
//
//    t37.setFont(a);
//    t37.setFillColor(sf::Color::Black);
//    t37.setPosition(130, 780);
//    t37.setCharacterSize(17);
//    t37.setString("PLEASE ENTER CHOICE:");
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
//        // clear the window with white color
//        window.clear(sf::Color::White);
//        window.draw(t);
//        window.draw(t1);
//        window.draw(t2);
//        window.draw(t3);
//        window.draw(rectangle);
//        window.draw(rectangle1);
//        window.draw(t4);
//        window.draw(t31);
//        window.draw(t32);
//        window.draw(t33);
//        window.draw(t34);
//        window.draw(t35);
//        window.draw(t36);
//        window.draw(t37);
//        // end the current frame
//        window.display();
//    }
//
//    return 0;
//}
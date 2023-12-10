//#include <SFML/Graphics.hpp>
//
//int main() {
//
//	sf::Font f;
//	f.loadFromFile("new.ttf");
//
//	// create the window
//	sf::RenderWindow window(sf::VideoMode(1300, 700), "Flex");
//	
//	sf::Text text,text1,text2,text3;
//	text.setFont(f);
//	text.setCharacterSize(100); 
//	text.setFillColor(sf::Color::Blue);
//	text.setPosition(500, 10);
//	text.setString("Flex");
//
//	text1.setFont(f);
//	text1.setCharacterSize(20);
//	text1.setFillColor(sf::Color::Blue);
//	text1.setPosition(520, 120);
//	text1.setString("Academic Portal");
//
//	text2.setFont(f);
//	text2.setCharacterSize(20);
//	text2.setFillColor(sf::Color::Black);
//	text2.setPosition(550, 180);
//	text2.setString("Sign In");
//
//	text3.setFont(f);
//	text3.setCharacterSize(20);
//	text3.setFillColor(sf::Color::Black);
//	text3.setPosition(350, 280);
//	text3.setString("Roll No.");
//
//
//
//		// run the program as long as the window is open
//		while (window.isOpen())
//		{
//			// check all the window's events that were triggered since the last iteration of the loop
//			sf::Event event;
//			while (window.pollEvent(event))
//			{
//				// "close requested" event: we close the window
//				if (event.type == sf::Event::Closed)
//					window.close();
//			}
//
//			// clear the window with black color
//			window.clear(sf::Color::White);
//
//			// draw everything here...
//			// window.draw(...);
//			window.draw(text);
//
//			window.draw(text1);
//
//			window.draw(text2);
//			window.draw(text3);
//
//			// end the current frame
//			window.display();
//			
//		}
//
//}

#include <SFML/Graphics.hpp>

int main() {

	sf::Font f;
	f.loadFromFile("new.ttf");

	// create the window
	sf::RenderWindow window(sf::VideoMode(1300, 700), "Flex");
	
	sf::Text text;
	text.setFont(f);
	text.setCharacterSize(100); 
	text.setFillColor(sf::Color::Blue);
	text.setPosition(500, 10);
	text.setString("Flex");

		// run the program as long as the window is open
		while (window.isOpen())
		{
			// check all the window's events that were triggered since the last iteration of the loop
			sf::Event event;
			while (window.pollEvent(event))
			{
				// "close requested" event: we close the window
				if (event.type == sf::Event::Closed)
					window.close();
			}

			// clear the window with black color
			window.clear(sf::Color::White);

			// draw everything here...
			// window.draw(...);
			window.draw(text);
			// end the current frame
			window.display();
			
		}



}

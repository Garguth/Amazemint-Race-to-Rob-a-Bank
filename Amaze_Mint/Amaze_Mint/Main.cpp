//#include "stdafx.h"
#include "Engine.h"
#include "Rays.h"
#include <SFML/Audio.hpp>
//  https://gamedevelopment.tutsplus.com/tutorials/how-to-create-a-custom-2d-physics-engine-the-basics-and-impulse-resolution--gamedev-6331
// for danny ^^
//
//
//
//
#define SHADER_FILENAME         "example_004.frag"

#define     WINDOW_WIDTH    256
#define     WINDOW_HEIGHT   256



int main()
{
	// _____________________
 // ::: Create window :::
	SoundBuffer SoundtrackBuffer;
	Sound soundtrackS;
	SoundtrackBuffer.loadFromFile("sound/2_Brothers_Song.wav");
	soundtrackS.setBuffer(SoundtrackBuffer);
	soundtrackS.play();
	soundtrackS.setLoop(true);
	if (false)
	{


		// Create a non resizable window
		sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML Shader Example", sf::Style::Titlebar | sf::Style::Close);


		// Create a window size texture and a sprite for the shader
		sf::Texture tex;
		tex.create(WINDOW_WIDTH, WINDOW_HEIGHT);
		sf::Sprite spr(tex);

		// Enable vertical sync. (vsync)
		window.setVerticalSyncEnabled(true);



		// ____________________
		// ::: Load texture :::

		// Create texture from PNG file
		sf::Texture texture;
		if (!texture.loadFromFile("graphics/sfml-icon-small.png"))
		{
			std::cerr << "Error while loading texture" << std::endl;
			return -1;
		}
		// Enable the smooth filter. The texture appears smoother so that pixels are less noticeable.
		texture.setSmooth(true);



		// _______________________________________
		// ::: Create sprite and apply texture :::

		// Create the sprite and apply the texture
		sf::Sprite sprite;
		sprite.setTexture(texture);
		sf::FloatRect spriteSize = sprite.getGlobalBounds();
		// Set origin in the middle of the sprite
		sprite.setOrigin(spriteSize.width / 2., spriteSize.height / 2.);



		// _______________
		// ::: Shaders :::

		// Check if shaders are available
		if (!sf::Shader::isAvailable())
		{
			std::cerr << "Shader are not available" << std::endl;
			return -1;
		}

		// Load shaders
		sf::Shader shader;
		if (!shader.loadFromFile(SHADER_FILENAME, sf::Shader::Fragment))
		{
			std::cerr << "Error while shaders" << std::endl;
			return -1;
		}




		// _________________
		// ::: Main loop :::

		sf::Clock time;
		while (window.isOpen())
		{
			// Process events
			sf::Event event;
			while (window.pollEvent(event))
			{
				// Close the window if a key is pressed or if requested
				if (event.type == sf::Event::Closed) window.close();

				// If escape is pressed, close the application
				if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) window.close();
			}

			// Set shader parameters
			//shader.setParameter("time", time.getElapsedTime().asSeconds());
			shader.setUniform("time", time.getElapsedTime().asSeconds());

			// Clear the window and apply grey background
			window.clear(sf::Color(0, 0, 0));

			// Draw the sprite and apply shader
			sprite.setPosition(window.getSize().x / 2., window.getSize().y / 2.);
			
			window.draw(sprite, &shader);

			// Update display and wait for vsync
			window.display();
		}
	}

	bool mamaCoco;
	mamaCoco = false;
	//race();



	// Declare an instance of Engine
	Engine engine;

	srand(time(0));
	// Start the engine
	while (mamaCoco == false)
	{
		engine.titleScreen();
		mamaCoco = engine.mamaCocoIsAlive;
	}
	engine.run(1);
	//engine.run(1);
	engine.clearMemory();
	engine.endScreen();
	// Quit in the usual way when the engine is stopped
	return 0;
}

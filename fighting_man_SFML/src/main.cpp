//  Main.cpp
//
//  Final project
//  CS6010 Fall 2022
//
//  Hunter game
//
//  Created by Yutian Qin and Nathan Pfau on 9/19/22.
//
//  Shooting type game that spawns in six space ships and once player has shot all ships they will respawn. Game
//  continues until the player closes the window.


#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "Bullet.hpp"
#include "Hunter.hpp"
#include "Enemy.hpp"


int main()
{
    // create the window and set window size based on horizontal and vertical pixel count
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Bird Shooter");
    // setting frame rate
    window.setFramerateLimit(45);
    
    
    sf::RectangleShape bg;             // creating shape for the background image
    sf::Vector2f bgPosition(0, 0);     // setting position for top left corner
    bg.setPosition(bgPosition);
    bg.setSize(sf::Vector2f(1280, 720));  // setting background size to be same as window size
    sf::Texture txtr;                     // creating texture for background
    if (!txtr.loadFromFile("nightsky.png")){
        std::cout << "Load fail" << std::endl;
    }
    txtr.loadFromFile("nightsky.png");      // loading in the background image
    bg.setTexture( &txtr );            // setting texture
    
    // creating objects and setting size for objects
    Hunter hunter(sf::Vector2f(150,150));
    Enemy enemy1 (sf::Vector2f(75,75));
    Enemy enemy2 (sf::Vector2f(75,75));
    Enemy enemy3 (sf::Vector2f(75,75));
    Enemy enemy4 (sf::Vector2f(75,75));
    Enemy enemy5 (sf::Vector2f(75,75));
    Enemy enemy6 (sf::Vector2f(75,75));
    
    // calling set texture member function for hunter and the enemy
    hunter.setTex();
    enemy1.setTex();
    enemy2.setTex();
    enemy3.setTex();
    enemy4.setTex();
    enemy5.setTex();
    enemy6.setTex();

    // creating vector for bullets
    std::vector<Bullet> bulletVec;
    
    // setting starting position for hunter and enemy
    hunter.setPos(sf::Vector2f(640, 570));
    enemy1.setPos(sf::Vector2f(500, 50));
    enemy2.setPos(sf::Vector2f(1200, 50));
    enemy3.setPos(sf::Vector2f(10, 490));
    enemy4.setPos(sf::Vector2f(1180, 490));
    enemy5.setPos(sf::Vector2f(500, 500));
    enemy6.setPos(sf::Vector2f(750, 50));
    
    //Gravity Variables:
    const int groudHeight = 570;
    const float gravitySpeed = 10;
    bool isJumping = false;
    
    
    
    // creating bool for the shooting event
    bool isFiring = false;
    
    // run the program as long as the window is open
    while (window.isOpen())
    {
        
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        
        // creating move speed variable for hunter movement
        float movespeed = 23;
        float jumpspeed = 15;
        
        // keyboard input for jump/fly, holding space will make hunter fly and single tap
        // will make hunter jump.
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            hunter.move({0, -jumpspeed});
            isJumping = true;
        }
        
        //move to the left
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
            hunter.move(sf::Vector2f(-movespeed , 0));
        }
        
        // move to the right
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
            hunter.move(sf::Vector2f( movespeed , 0));
        }
        
        while (window.pollEvent(event)){
            
            // resests isJumping
            if (event.type == sf::Event::KeyReleased) {
                isJumping = false;
            }
            
            if (event.type == sf::Event::Closed) window.close(); // exits program if window is closed
            
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) { // exits program if esc is pressed
                window.close();
            }
            
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){ // when enter is pressed isFiring is true
                isFiring = true;
            }
            
        }
        
        //Gravity Logic:
        if (hunter.getY() < groudHeight && isJumping == false) { hunter.move({0, gravitySpeed});
        }
        
        window.clear();
        
        window.draw(bg); // draws the background image
        
        
        //  if hunter position is out of bound of the window it will reset position to the other side of window
        if( hunter.getX() < 0){
            hunter.setPos(sf::Vector2f( 1280 , 570 ));
        }
        
        if( hunter.getX() > 1280){
            hunter.setPos(sf::Vector2f(0 , 570));
        }
        
        // if enter is pressed then a new bullet will be added to the bullet vector with specified size and starting
        // position will be in the middle of hunter's current position. then isFiring is switched back to false
        if (isFiring == true){
            Bullet newBullet(sf::Vector2f(10,20));
            newBullet.setPos((sf::Vector2f(hunter.getX()+ (hunter.getSize()/2), hunter.getY())));
            bulletVec.push_back(newBullet);
            isFiring = false;
        }
        
        // every bullet in vector will be drawn, will move up at specified speed, and will be checked against every
        // enemy to see if they have collided
        for (int i = 0; i < bulletVec.size(); i++){
            bulletVec[i].draw(window);
            bulletVec[i].fire(50);
            enemy1.checkColl(bulletVec[i]);
            enemy2.checkColl(bulletVec[i]);
            enemy3.checkColl(bulletVec[i]);
            enemy4.checkColl(bulletVec[i]);
            enemy5.checkColl(bulletVec[i]);
            enemy6.checkColl(bulletVec[i]);
        }
        
        // if all of the enemies are located outside of the screen they will be repositioned
        // to their original locations
        if (enemy1.getPos() > 20000 && enemy2.getPos() > 20000 && enemy3.getPos() > 20000 && enemy4.getPos() > 20000 && enemy5.getPos() > 20000 && enemy6.getPos() > 20000){
            enemy1.setPos(sf::Vector2f(500, 50));
            enemy2.setPos(sf::Vector2f(1200, 50));
            enemy3.setPos(sf::Vector2f(10, 490));
            enemy4.setPos(sf::Vector2f(1180, 490));
            enemy5.setPos(sf::Vector2f(500, 500));
            enemy6.setPos(sf::Vector2f(750, 50));
            enemy1.move();
            enemy2.move();
            enemy3.move();
            enemy4.move();
            enemy5.move();
            enemy6.move();
        }
        
        // drawing enemies and the hunter
        enemy1.draw(window);
        enemy2.draw(window);
        enemy3.draw(window);
        enemy4.draw(window);
        enemy5.draw(window);
        enemy6.draw(window);
        hunter.draw(window);
        
        
        // removees the bullets from vector once they are out of the screen
        bulletVec.erase(std::remove_if(bulletVec.begin(), bulletVec.end(), [&bulletVec](Bullet& b){return b.getTop() < 0;}), bulletVec.end());
        
        
        window.display();
        
    }

    return 0;
}

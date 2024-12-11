//  Enemy.hpp
//
//  Final project
//  CS6010 Fall 2022
//
//  Hunter game
//
//  Created by Yutian Qin and Nathan Pfau on 9/19/22.
//
//  helper functions for the enemy

#ifndef Enemy_hpp
#define Enemy_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "Bullet.hpp"
#include <iostream>

class Enemy{

private:
    // creating shape and textuure for the enemy and also setting speed in the x and y axis
    sf::RectangleShape enemy;
    sf::Texture texture;
    float xMove = 6;
    float yMove = 1.5;
    
public:
    // constructor that taking in a size from user
    Enemy(sf::Vector2f size){
        enemy.setSize(size);
    }
    
    // funtion to set a new position for the enemy
    void setPos(sf::Vector2f newPos){
        enemy.setPosition(newPos);
    }
    
    // Function that checks if the bullet and enemy have collided by checking if the bullet's
    // position is within the bounds of the enemy. If so then the enemy will be moved off
    // screen
    void checkColl(Bullet bullet){
        if(bullet.getRight() < enemy.getPosition().x + enemy.getSize().x &&
           bullet.getTop() < enemy.getPosition().y  &&
           bullet.getLeft() > enemy.getPosition().x)
        {
            enemy.setPosition(200000, 200000);
            enemy.move(0, 0);
        }
    }
    
    // funtion to draw the enemy
    void draw(sf::RenderWindow & window ){
        move();
        window.draw(enemy);
    }
    
    // function the get the x position of the enemy
    float getPos(){
        return enemy.getPosition().x;
    }
    
    // function that moves the enemies within the bounds of the screen. When the enemy hits
    // the bounds of the screen the move speed will be switched by multiplying by -1. Also
    // when the enemy hits the x screen boundaries the image will change so it looks like
    // it is moving in the correct direction.
    void move() {
        sf::Vector2f currentPos = enemy.getPosition();
        if (currentPos.x <= 0 ) {
            xMove *= -1;
            texture.loadFromFile("spaceship.png");
        }
        if(currentPos.x >= 1230){
            xMove *= -1;
            texture.loadFromFile("ssfliped.png");
        }
        if ( currentPos.y < 0 || currentPos.y > 500){
            yMove *= -1;
        }
        enemy.move(xMove, yMove);
        this->enemy.setTexture(&texture);
    }
    
    // function to set enemy texture 
    void setTex() {
        texture.loadFromFile("spaceship.png");
        this->enemy.setTexture(&texture);
    }
    
};



#endif /* Enemy_hpp */

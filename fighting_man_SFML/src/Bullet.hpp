//  Bullet.hpp
//
//  Final project
//  CS6010 Fall 2022
//
//  Hunter game
//
//  Created by Yutian Qin and Nathan Pfau on 9/19/22.
//
//  helper functions for the bullet

#ifndef Bullet_hpp
#define Bullet_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>

class Bullet{
private:
    // creating shape for the bullet
    sf::RectangleShape bullet;
    
public:
    
    // constructor that taking in a size from user and sets color to red
    Bullet(sf::Vector2f size){
        bullet.setSize(size);
        bullet.setFillColor(sf::Color::Red);
    }
    
    // function that sets speed in y direction when bullet is fired
    void fire(int speed){
        bullet.move(0 , - speed);
    }
    
    // get position of the right side
    int getRight(){
        return bullet.getPosition().x + bullet.getSize().x;
    }
    
    // get position of the left side
    int getLeft(){
        return bullet.getPosition().x;
    }
    
    // get position of the top
    int getTop(){
        return bullet.getPosition().y;
    }
    
    // get position of the bottom
    int getBottom(){
        return bullet.getPosition().y + bullet.getPosition().y;
    }
    
    // function to draw the bullet
    void draw(sf::RenderWindow & window ){
        window.draw(bullet);
    }
    
    // funciton to set a new position
    void setPos(sf::Vector2f newPos){
        bullet.setPosition(newPos);
    }
    
    
    
};


#endif /* Bullet_hpp */

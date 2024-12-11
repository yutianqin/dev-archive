//  Hunter.hpp
//
//  Final project
//  CS6010 Fall 2022
//
//  Hunter game
//
//  Created by Yutian Qin and Nathan Pfau on 9/19/22.
//
//  helper functions for the hunter

#ifndef Hunter_hpp
#define Hunter_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "Enemy.hpp"


class Hunter{
    
private:
    // creating shape and textuure for the hunter
    sf::RectangleShape hunter;
    sf::Texture texture;
    
    
public:
    // constructor that taking in a size from user
    Hunter(sf::Vector2f size){
        hunter.setSize(size);
    }
    
    // function that will move the enemy and when the hunter y pos is < 500 the png will
    // change 
    void move(sf::Vector2f dir){
        sf::Vector2f current = hunter.getPosition();
        hunter.move(dir);
        if (current.y < 500) {
            texture.loadFromFile("fly.png");
            
        }
        if (current.y > 500) {
            texture.loadFromFile("ground.png");
        }
        this->hunter.setTexture(&texture);
    }
    
    // function to get the x position
    int getX(){
        return hunter.getPosition().x;
    }
    
    // function to get the y position
    int getY(){
        return hunter.getPosition().y;
    }
    
    // function to get the size
    int getSize(){
        return hunter.getSize().x;
    }
    
    // function to draw the hunter
    void draw(sf::RenderWindow & window ){
        window.draw(hunter);
    }
    
    // funtion to set position
    void setPos(sf::Vector2f newPos){
        hunter.setPosition(newPos);
    }
    
    // function to set texture of hunter
    void setTex() {
        if (!texture.loadFromFile("ground.png")){
            std::cout << "Load fail" << std::endl;
        }
        texture.loadFromFile("ground.png");
        this->hunter.setTexture(&texture);
    }
    
};



#endif /* Hunter_hpp */

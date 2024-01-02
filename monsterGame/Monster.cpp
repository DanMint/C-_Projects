//
// Created by Daniel on 12/31/2023.
//

#include <iostream>
#include "Monster.h"


Monster::Monster(int health, int attackPower, int stamina, int staminaRegen, int position) {
    this->health = health;
    this->attackPower = attackPower;
    this->stamina = stamina;
    this->staminaRegen = staminaRegen;
    this->position = position;
}

void Monster:: get() const {
    std::cout << "Players health: " << health << std::endl;
    std::cout << "Players attack power: " << attackPower << std::endl;
    std::cout << "Players stamina: " << stamina << std::endl;
    std::cout << "Players position: " << position << std::endl;
}

void Monster::move(int enemyPosition) {
    std::cout << "Would you want to move left(0) or right(1): ";
    int where;
    std::cin >> where;

    if (where == 0)
        where = -1;
    else
        where = 1;

    int staminaLoss = -9;
    if (this->position + where == enemyPosition) {
        std::cout << "Cant be in the same place as enemy" << std::endl;
        return Monster::move(enemyPosition);
    }
    else if (this->position + where > 9 || this->position + where < 0) {
        std::cout << "Cant move there" << std::endl;
        return Monster::move(enemyPosition);
    }
    else if (this->stamina + staminaLoss < 0) {
        std::cout << "Not enough stamina" << std::endl;
        std::cout << "Resting" << std::endl;
        return;
    }
    this->position += where;
    this->stamina += staminaLoss;
}

void Monster::staminaRegenAfterMove() {
    if (this->stamina == 100)
        return;
    else if (this->stamina + this->staminaRegen > 100) {
        this->stamina = 100 ;
        return;
    }
    this->stamina += this->staminaRegen;
}

int Monster::getPos() const {return this->position;}

void Monster::reciveDemage(int demage) {
    this->health -= demage;
}

int Monster::getAttackPower() {return attackPower;}

int Monster::getHealth() {return health;}

int Monster::attack(int enemyPosition) {
    if (enemyPosition == (this->position + 1) || enemyPosition == (this->position - 1)) {
        if (this->stamina - 5 >= 0) {
            this->stamina -= 5;
            return 0;
        }
        else {
            std::cout << "cant attack due to low stamina thefore rest" << std::endl;
            return 1;
        }
    }
    std::cout << "You are too far from the enemy. Please get closer to the enemy" << std::endl;
    return 2;
}
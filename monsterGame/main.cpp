#include <iostream>
#include <random>
#include "player.h"
#include "Monster.h"
#include <vector>

int main() {
    std::cout << "Select the game mode: Easy(0), Average(1), Strong(2), Hard(3)" << std::endl;
    int chosen;
    std::cin >> chosen;
    int playerHealth, playerAttackPower, playerStamina, playerStaminaRegen, playerPosition;
    if (chosen == 0) {
        playerHealth = 100;
        playerAttackPower = 20;
        playerStamina = 80;
        playerStaminaRegen = 15;
        playerPosition = 3;
    }
    else if (chosen == 1) {
        playerHealth = 100;
        playerAttackPower = 15;
        playerStamina = 60;
        playerStaminaRegen = 15;
        playerPosition = 3;
    }

    else if (chosen == 2) {
        playerHealth = 100;
        playerAttackPower = 10;
        playerStamina = 40;
        playerStaminaRegen = 15;
        playerPosition = 3;
    }

    else {
        playerHealth = 100;
        playerAttackPower = 10;
        playerStamina = 80;
        playerStaminaRegen = 20;
        playerPosition = 3;
    }

    int monsterHealth, monsterAttackPower, monsterStamina, monsterStaminaRegen, monsterPosition;
    if (chosen == 0) {
        monsterHealth = 50;
        monsterAttackPower = 5;
        monsterStamina = 35;
        monsterStaminaRegen = 10;
        monsterPosition = 6;
    }
    else if (chosen == 1) {
        monsterHealth = 100;
        monsterAttackPower = 15;
        monsterStamina = 80;
        monsterStaminaRegen = 10;
        monsterPosition = 6;
    }

    else if (chosen == 2) {
        monsterHealth = 150;
        monsterAttackPower = 20;
        monsterStamina = 80;
        monsterStaminaRegen = 15;
        monsterPosition = 6;
    }

    else {
        monsterHealth = 1000;
        monsterAttackPower = 20;
        monsterStamina = 80;
        monsterStaminaRegen = 15;
        monsterPosition = 6;
    }

    player player1(playerHealth, playerAttackPower, playerStamina, playerStaminaRegen, playerPosition);
    Monster monster(monsterHealth, monsterAttackPower, monsterStamina, monsterStaminaRegen, monsterPosition);

    while (true) {
        std::vector<char> positionRepresentation = {'-', '-','-', '-','-', '-','-', '-','-', '-'};
        std::cout << "Player choose if you want to: move(0) or attack(1) ";
        int choice;
        std::cin >> choice;

        if (choice == 0) {
            player1.move(monster.getPos());
            positionRepresentation[player1.getPos()] = '0';
            positionRepresentation[monster.getPos()] = '*';
            for (const auto &el : positionRepresentation)
                std::cout << el << "";
            std::cout << std::endl;
            positionRepresentation[player1.getPos()] = '-';
            positionRepresentation[monster.getPos()] = '-';
        }
        else {
            if (player1.attack(monster.getPos()) == 0) {
                monster.reciveDemage(player1.getAttackPower());
                std::cout << "Current enemy health " << monster.getHealth() << std::endl;
                if (monster.getHealth() <= 0) {
                    std::cout << "Player won!" << std::endl;
                    break;
                }
            }
            else if(player1.attack(monster.getPos()) == 1) {
                std::cout << "resting" << std::endl;
            }
            else if(player1.attack(monster.getPos()) == 2) {
                player1.move(monster.getPos());
            }
        }

        std::cout << "Monster choose if you want to: move(0) or attack(1) ";
        std::cin >> choice;
        if (choice == 0) {
            monster.move(player1.getPos());
            positionRepresentation[player1.getPos()] = '0';
            positionRepresentation[monster.getPos()] = '*';
            for (const auto &el : positionRepresentation)
                std::cout << el << "";
            std::cout << std::endl;
            positionRepresentation[player1.getPos()] = '-';
            positionRepresentation[monster.getPos()] = '-';
        }
        else {
            if (monster.attack(player1.getPos()) == 0) {
                player1.reciveDemage(monster.getAttackPower());
                std::cout << "Current enemy health " << player1.getHealth() << std::endl;
                if (player1.getHealth() <= 0) {
                    std::cout << "Monster won!" << std::endl;
                    break;
                }
            }
            else if(monster.attack(player1.getPos()) == 1) {
                std::cout << "Resting" << std::endl;
            }
            else if(monster.attack(player1.getPos()) == 2) {
                monster.move(monster.getPos());
            }
        }
        player1.staminaRegenAfterMove();
        monster.staminaRegenAfterMove();
    }

    return 0;
}

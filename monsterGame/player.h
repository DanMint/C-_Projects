//
// Created by Daniel on 12/30/2023.
//

#ifndef MONSTERGAME_PLAYER_H
#define MONSTERGAME_PLAYER_H


class player {
public:
    player(int health, int attackPower, int stamina, int staminaRegen, int position);
    void get() const;
    void move(int enemyPosition);
    void staminaRegenAfterMove();
    int getPos () const;
    void reciveDemage(int demage);
    int getAttackPower();
    int getHealth();
    int attack(int enemyPosition);

private:
    int health;
    int attackPower;
    int stamina;
    int staminaRegen;
    int position;
};


#endif //MONSTERGAME_PLAYER_H

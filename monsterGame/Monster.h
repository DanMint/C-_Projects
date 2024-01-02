//
// Created by Daniel on 12/31/2023.
//

#ifndef MONSTERGAME_MONSTER_H
#define MONSTERGAME_MONSTER_H


class Monster {
public:
    Monster(int health, int attackPower, int stamina, int staminaRegen, int position);
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


#endif //MONSTERGAME_MONSTER_H

#ifndef ACTOR_H
#define ACTOR_H
#include <string>

class Actor {
    public:
        // Constructor
            Actor();

        // Getters
            std::string getName() const;
            double getXp() const;
            double getHp() const;

        // Predicates
            bool isPlayer() const;
            bool isAlly() const;
            bool isNeutral() const;
            bool isHostile() const;

        // Setters
            void setName(const std::string &name);
            void setPlayer(const bool isPlayer);
            void setAlly(const bool isAlly);
            void setNeutral(const bool isNeutral);
            void setHostile(const bool isHostile);

        // Actions
            void gainExp(const double xp);
            void loseExp(const double xp);
            void gainHp(const double hp);
            void loseHp(const double hp);

    private:
        // Members
            std::string name;
            double xp; // Experience points
            double hp; // Hit points
            bool player;
            bool ally;
            bool neutral;
            bool hostile;
};

#endif // ACTOR_H
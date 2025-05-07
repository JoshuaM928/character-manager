#include "../include/models/Actor.h"

// Constructor
        Actor::Actor()
            : name("__PlaceHolder__"), xp(0.0), hp(10.0),
            player(false), ally(false), neutral(true), 
            hostile(false) {
                // Intentionally left blank
        }

// Getters
        std::string Actor::getName() const {
            return this->name;
        }

        double Actor::getXp() const {
            return this->xp;
        }

        double Actor::getHp() const {
            return this->hp;
        }

// Predicates
        bool Actor::isPlayer() const {
            return this->player;
        }

        bool Actor::isAlly() const {
            return this->ally;
        }

        bool Actor::isNeutral() const {
            return this->neutral;
        }

        bool Actor::isHostile() const {
            return this->hostile;
        }

// Setters
        void Actor::setName(const std::string &name) {
            this->name = name;
        }

        void Actor::setPlayer(const bool isPlayer) {
            this->player = isPlayer;
        }

        void Actor::setAlly(const bool isAlly) {
            this->ally = isAlly;
        }

        void Actor::setNeutral(const bool isNeutral) {
            this->neutral = isNeutral;
        }

        void Actor::setHostile(const bool isHostile) {
            this->hostile = isHostile;
        }


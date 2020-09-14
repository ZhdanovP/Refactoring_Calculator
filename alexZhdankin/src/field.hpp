#ifndef MFIELD_HPP
#define MFIELD_HPP

#include "player.hpp"
#include <memory>

enum class FieldType
{
    PRISON,
    BANK,
	AUTO,
	FOOD,
	TRAVEL,
	CLOTHER
};

class Field
{
    public:
        static Field getField(std::string, FieldType);

        std::string getName() const { return name; }
        FieldType getType() const { return type; }
        int getPrice() const { return price; }
        int getRenta() const { return renta; }
        Player* getOwner() const { return owner; }

        void setOwner(Player* player) { owner = player; }

        bool operator==(const Field&) const;

    private:
        Field(std::string, FieldType, int, int);

        std::string name;
        Player* owner;
        FieldType type;

        int price;
        int renta;
};

#endif
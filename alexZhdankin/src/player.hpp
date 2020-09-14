#ifndef MPLAYER_HPP
#define MPLAYER_HPP

#include <string>

enum class FigureType
{
    Car,
    Dog,
    Shoe,
    Bike,
    Skate,
    Phone,
    Cup,
    Cake
};

class Player
{
    public:
        explicit Player(std::string, FigureType);

        FigureType getFigure() const { return figure; }
        int getCurrentMoney() const { return money; }
        std::string getName() const { return name; }

        int substractFromMoney(int moneyAmount);
        int addToMoney(int moneyAmount);

        bool operator==(const Player& rhs) const;

    private:
        std::string name;
        FigureType figure;
        int money;
};

#endif
#ifndef PLAYER_H
#define PLAYER_H

#include <string>
namespace player{

class Player
{
public:
    explicit Player(std::string name="", int balance=0);
    ~Player() = default;

    int getId() const;
    std::string getName() const;
    int getBalance() const;
    void changeBalance(int value);
    static void resetCounter();

private:
    std::string name_;
    int balance_;
    int id_;
    static int s_id_counter;
};
}

#endif // PLAYER_H
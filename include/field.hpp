#ifndef FIELD_H
#define FIELD_H

#include <string>
#include <iostream>

#include "player.hpp"

using namespace player;

class Field
{
public:
    
    Field(std::string n, int id=0, bool busy=false) :
		name_(n),
		player_id_(id),
		is_busy_(busy)
	{}

	bool operator==(const Field & other_company) const
	{
		return name_ == other_company.getName() && 
            player_id_ == other_company.getId() &&
            is_busy_ == other_company.IsBusy();
	}

	void Occupy(int id)
	{
		player_id_ = id;
		is_busy_ = true;
	}

	std::string getName() const
	{
		return name_;
	}

    int getId() const
    {
        return player_id_;
    }

    bool IsBusy() const
    {
        return is_busy_;
    }

    virtual bool OccupyByPlayer(Player* player, int price=0)
    {
        if (!getId())
		{
			player->changeBalance(-price);
			this->Occupy(player->getId());
            return true;
		}	
        return false;
    }

    virtual bool ExchangeBalance(Player* first_p, Player* second_p, int balance=0)
    {
		if (getId())
		{
			first_p->changeBalance(balance);
			second_p->changeBalance(-balance);
		}	
    }

private:
	std::string name_;
	int player_id_;
	bool is_busy_;
};


class AutoField : public Field
{
public:
    AutoField(std::string n, int id=0, bool busy=false) :
        Field(n, id, busy),
        buy_price_(500),
        renta_price_(250)
    {
    }
    ~AutoField() = default;

    virtual bool OccupyByPlayer(Player* player, int) override
    {
        return Field::OccupyByPlayer(player, buy_price_);
    }

    virtual bool ExchangeBalance(Player* first_p, Player* second_p, int) override
    {
        Field::ExchangeBalance(first_p, second_p, renta_price_);
    }

private:
    int buy_price_;
    int renta_price_;
};

class FoodField : public Field
{
public:
    FoodField(std::string n, int id=0, bool busy=false) :
        Field(n, id, busy),
        buy_price_(250)
    {
    }
    
    ~FoodField() = default;

    virtual void OccupyByPlayer(Player* player)
    {
        Field::OccupyByPlayer(player, buy_price_);
    }

private:
    int buy_price_;
};

class TravelField : public Field
{
public:
    TravelField(std::string n, int id=0, bool busy=false) :
        Field(n, id, busy),
        buy_price_(700),
        renta_price_(250)
    {
    }
    ~TravelField() = default;

    virtual bool OccupyByPlayer(Player* player, int) override
    {
        return Field::OccupyByPlayer(player, buy_price_);
    }

    virtual bool ExchangeBalance(Player* first_p, Player* second_p, int) override
    {
        return Field::ExchangeBalance(first_p, second_p, renta_price_);
    }

private:
    int buy_price_;
    int renta_price_;
};

class ClotherField : public Field
{
public:
    ClotherField(std::string n, int id=0, bool busy=false) :
        Field(n, id, busy),
        buy_price_(100),
        renta_price_(250)
    {
    }
    ~ClotherField() = default;

    virtual bool OccupyByPlayer(Player* player, int) override
    {
        return Field::OccupyByPlayer(player, buy_price_);
    }

    virtual bool ExchangeBalance(Player* first_p, Player* second_p, int) override
    {
        return Field::ExchangeBalance(first_p, second_p, renta_price_);
    }

private:
    int buy_price_;
    int renta_price_;
};

class PrisonField : public Field
{
public:
    PrisonField(std::string n, int id=0, bool busy=false) :
        Field(n, id, busy),
        renta_price_(-1000)
    {
    }
    ~PrisonField() = default;

    virtual bool ExchangeBalance(Player* first_p, Player* second_p, int) override
    {
        return Field::ExchangeBalance(first_p, second_p, renta_price_);
    }

private:
    int buy_price_;
    int renta_price_;
};

class BankField : public Field
{
public:
    BankField(std::string n, int id=0, bool busy=false) :
        Field(n, id, busy),
        renta_price_(-700)
    {
    }
    ~BankField() = default;

    virtual bool ExchangeBalance(Player* first_p, Player* second_p, int) override
    {
        return Field::ExchangeBalance(first_p, second_p, renta_price_);
    }

private:
    int buy_price_;
    int renta_price_;
};

#endif // FIELD_H
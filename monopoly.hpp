#ifndef MONOPOLY_HPP
#define MONOPOLY_HPP

#include <list>
#include <tuple>
#include <string>
#include <vector>
#include <optional>

class Monopoly
{
public:
    struct Player {
        std::string name;
        int money;
    };

	enum Type
	{
		AUTO,
		FOOD,
		TRAVEL,
		CLOTHER,
		PRISON,
		BANK
	};
    
    constexpr std::optional<int> price(Type t) {
        switch(t) {
            case AUTO: return 500;
            case FOOD: return 250;
            case TRAVEL: return 700;
            case CLOTHER: return 100;
//             case PRISON: return 1100;
//             case BANK: return 700;
            default: return {};
        }
    }

    struct field_t {
        std::string name;
        Type type;
        int owner;
    };

    [[deprecated("Use Monopoly(std::initializer_list<const char*>& names); instead.")]]
    Monopoly(std::string names[10],int);
    Monopoly(std::initializer_list<const char*>& names);

    std::list<Player> *	GetPlayersList();
	std::list<field_t> * GetFieldsList();
	std::list<field_t> Fields;
	std::list<Player> Players;
	Player  GetPlayerInfo(int);	 
	bool Buy(int p, field_t);
	field_t GetFieldByName(std::string) const;	
	bool Renta(int p, field_t c);
	
};

#endif

#ifndef MONOPOLY_HPP
#define MONOPOLY_HPP

#include <optional>
#include <string>
#include <tuple>
#include <vector>

enum class Industry { AUTO, FOOD, TRAVEL, CLOTHER, PRISON, BANK };

struct Field {
    std::string const     company;
    Industry const        type;
    std::optional<size_t> owner;
};

bool operator==(Field const& lhs, Field const& rhs);

struct Player {
    constexpr auto static kInitialMoney = 6000;

    std::string const name;
    std::int32_t      money{kInitialMoney};
};

class Monopoly {
public:
    Monopoly(std::vector<std::string> const& names);

    std::vector<Player> PlayersList() const;
    std::vector<Field>  FieldsList() const;
    Player              PlayerInfo(size_t const playerNumber) const;
    Field               FieldByName(const std::string& fieldName) const;

    bool Buy(size_t const player, Field const& purchasedField);
    bool Renta(size_t const renter, Field const& rentedField);

private:
    std::vector<Field>  mFields;
    std::vector<Player> mPlayers;
};

#endif

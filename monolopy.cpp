#include "monolopy.hpp"
#include <algorithm>

using namespace ::std;

bool
operator==(Field const& lhs, Field const& rhs)
{
    return std::tie(lhs.company, lhs.type, lhs.owner) == std::tie(rhs.company, rhs.type, rhs.owner);
}

namespace {

auto constexpr fieldPurchasePrice = [](auto const& purchasedField) {
    switch (purchasedField.type) {
    case Industry::AUTO:
        return 500;
    case Industry::FOOD:
        return 250;
    case Industry::TRAVEL:
        return 700;
    case Industry::CLOTHER:
        return 100;
    default:
        return 0;
    };
};

auto constexpr fieldRentPrice = [](auto const& rentedField) {
    switch (rentedField.type) {
    case Industry::AUTO:
        return 250;
    case Industry::TRAVEL:
        return 250;
    case Industry::CLOTHER:
        return 250;
    case Industry::PRISON:
        return 1000;
    case Industry::BANK:
        return 700;
    default:
        return 0;
    };
};

}  // namespace

Monopoly::Monopoly(std::vector<string> const& names)
  : mFields{{"Ford", Industry::AUTO},
            {"MCDonald", Industry::FOOD},
            {"Lamoda", Industry::CLOTHER},
            {"Air Baltic", Industry::TRAVEL},
            {"Nordavia", Industry::TRAVEL},
            {"MCDonald", Industry::FOOD},
            {"TESLA", Industry::AUTO}}
{
    constexpr auto kMaxPlayersNumber = 10;

    if (names.size() > kMaxPlayersNumber) {
        throw std::invalid_argument("Exceeding the number of players");
    }

    for (auto const& name : names) {
        mPlayers.push_back({name});
    }
}

std::vector<Player>
Monopoly::PlayersList() const
{
    return mPlayers;
}

std::vector<Field>
Monopoly::FieldsList() const
{
    return mFields;
}

Player
Monopoly::PlayerInfo(size_t const playerNumber) const
{
    return playerNumber <= mPlayers.size() ? mPlayers.at(playerNumber) : Player{};
}

bool
Monopoly::Buy(size_t const player, Field const& purchasedField)
{
    if (purchasedField.owner.has_value()) {
        return false;
    }
    if (player > mPlayers.size()) {
        return false;
    }
    auto fieldIterator = find_if(
        mFields.begin(), mFields.end(), [&purchasedField](auto const& field) { return field == purchasedField; });

    if (fieldIterator == mFields.end()) {
        return false;
    }

    auto const price = fieldPurchasePrice(purchasedField);
    if (price == 0) {
        return false;
    }

    mPlayers.at(player).money -= price;
    fieldIterator->owner = player;

    return true;
}

Field
Monopoly::FieldByName(std::string const& fieldName) const
{
    for (auto const& field : mFields) {
        if (field.company == fieldName) {
            return field;
        }
    }
    return {};
}

bool
Monopoly::Renta(size_t const renter, Field const& rentedField)
{
    if (!rentedField.owner.has_value()) {
        return false;
    }
    auto const price = fieldRentPrice(rentedField);
    if (price == 0) {
        return false;
    }

    if (renter > mPlayers.size() || *rentedField.owner > mPlayers.size()) {
        return false;
    }

    mPlayers.at(renter).money -= price;
    mPlayers.at(*rentedField.owner).money += price;

    return true;
}


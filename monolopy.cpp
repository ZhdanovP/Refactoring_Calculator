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
    case AUTO:
        return 500;
    case FOOD:
        return 250;
    case TRAVEL:
        return 700;
    case CLOTHER:
        return 100;
    default:
        return 0;
    };
};

auto constexpr fieldRentPrice = [](auto const& rentedField) {
    switch (rentedField.type) {
    case AUTO:
        return 250;
    case TRAVEL:
        return 250;
    case CLOTHER:
        return 250;
    case PRISON:
        return 1000;
    case BANK:
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
Monopoly::PlayersList()
{
    return mPlayers;
}

std::vector<Field>
Monopoly::FieldsList()
{
    return mFields;
}

Player
Monopoly::PlayerInfo(size_t const playerNumber)
{
    try {
        return mPlayers.at(playerNumber);
    }
    catch (std::out_of_range const& ex) {
        return {};
    }
}

bool
Monopoly::Buy(size_t const player, Field const& purchasedField)
{
    if (purchasedField.owner.has_value()) {
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

    try {
        mPlayers.at(player).money -= price;
    }
    catch (std::out_of_range const& ex) {
        return false;
    }

    (*fieldIterator).owner = player;

    return true;
}

Field
Monopoly::FieldByName(std::string const& fieldName)
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

    try {
        mPlayers.at(renter).money -= price;
        mPlayers.at(*rentedField.owner).money += price;
    }
    catch (std::out_of_range const& ex) {
        return false;
    }

    return true;
}

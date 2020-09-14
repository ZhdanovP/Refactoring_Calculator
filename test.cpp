#include "gtest/gtest.h"
#include "monolopy.hpp"

using namespace ::std;
namespace {

std::vector<string> const kPlayers{"Peter", "Ekaterina", "Alexander"};
}


TEST(LAB2, GetPlayersListReturnCorrectList)
{
    Monopoly monopoly(kPlayers);

    auto playersList = monopoly.PlayersList();
    int  i           = 0;
    for (auto c : playersList) {
        ASSERT_EQ(c.name, kPlayers[i++].c_str());
        ASSERT_EQ(c.money, 6000);
    }
    ASSERT_TRUE(i);
}

TEST(LAB2, MoreThenTenPlayersReturnException)
{
    auto constexpr maxPlayersNumber = 10;

    EXPECT_THROW(Monopoly monopoly(std::vector<string>(maxPlayersNumber + 1, "player")), std::invalid_argument);
}

TEST(LAB2, GetFieldsListReturnCorrectList)
{
    std::vector<Field> expectedCompanies{{"Ford", Industry::AUTO},
                                         {"MCDonald", Industry::FOOD},
                                         {"Lamoda", Industry::CLOTHER},
                                         {"Air Baltic", Industry::TRAVEL},
                                         {"Nordavia", Industry::TRAVEL},
                                         {"MCDonald", Industry::FOOD},
                                         {"TESLA", Industry::AUTO}};


    Monopoly monopoly(kPlayers);
    auto     actualCompanies = monopoly.FieldsList();
    int      i               = 0;
    for (auto x : actualCompanies) {
        ASSERT_EQ(x, expectedCompanies[i++]);
    }
    ASSERT_TRUE(i);
}


TEST(LAB2, PlayerBuyNoOwnedCompanies)
{
    Monopoly monopoly(kPlayers);
    auto     startFieldValue = monopoly.FieldByName("Ford");
    monopoly.Buy(1, startFieldValue);

    auto player = monopoly.PlayerInfo(1);
    ASSERT_EQ(player.money, 5500);
    auto afterFieldValue = monopoly.FieldByName("Ford");
    ASSERT_TRUE(afterFieldValue.owner != 0);
}

TEST(LAB2, PlayerInfoWithInvalidNumberReturnEmptyPlayer)
{
    Monopoly monopoly(kPlayers);
    auto     player = monopoly.PlayerInfo(kPlayers.size());

    ASSERT_TRUE(player.name.empty());
}

TEST(LAB2, InvalidNameFieldReturnEmptyField)
{
    Monopoly monopoly(kPlayers);
    auto     field = monopoly.FieldByName("INVALID");

    ASSERT_TRUE(field.company.empty());
}

TEST(LAB2, RentaShouldBeCorrectTransferMoney)
{
    Monopoly monopoly(kPlayers);
    auto     startFieldValue = monopoly.FieldByName("Ford");
    monopoly.Buy(1, startFieldValue);

    auto afterFieldValue = monopoly.FieldByName("Ford");
    monopoly.Renta(2, afterFieldValue);
    auto player1 = monopoly.PlayerInfo(1);
    ASSERT_EQ(player1.money, 5750);

    auto player2 = monopoly.PlayerInfo(2);
    ASSERT_EQ(player2.money, 5750);
}

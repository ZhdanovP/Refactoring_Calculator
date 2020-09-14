#include "gtest/gtest.h"
#include "../../src/monopoly.hpp"

#include <vector>
#include <iostream>

//using namespace ::std;

class LAB2 : public ::testing::Test
{
    public:
        void SetUp() override
        {
            Player player1{"Peter", FigureType::Car};
            Player player2{"Ekaterina", FigureType::Cake};
            Player player3{"Alexander", FigureType::Bike};
            playersList = {player1, player2, player3};
        }

        void TearDown() override {}
        std::vector<Player> playersList;
};

TEST_F(LAB2, GetPlayersListReturnCorrectList) 
{
    Monopoly monopoly(playersList);
    auto mPlayersList = monopoly.GetPlayersList();
    int i = 0;
    for (auto player : mPlayersList) {
        ASSERT_EQ(player, playersList[i++]);
    }
    ASSERT_TRUE(i);
}

TEST_F(LAB2, GetFieldsListReturnCorrectList) 
{
    std::vector<Field> fields;
    fields.push_back(Field::getField("Ford", FieldType::AUTO));
	fields.push_back(Field::getField("MCDonald", FieldType::FOOD));
	fields.push_back(Field::getField("Lamoda", FieldType::CLOTHER));
	fields.push_back(Field::getField("Air Baltic", FieldType::TRAVEL));
	fields.push_back(Field::getField("Nordavia", FieldType::TRAVEL));
	fields.push_back(Field::getField("Prison", FieldType::PRISON));
	fields.push_back(Field::getField("KFC", FieldType::FOOD));
	fields.push_back(Field::getField("TESLA", FieldType::AUTO));
    fields.push_back(Field::getField("Bank", FieldType::BANK));

    Monopoly monopoly(playersList);

    auto mFields = monopoly.GetFieldsList();
    int i = 0;
    for (auto field : mFields)
    {
        ASSERT_EQ(field, fields[i++]);
    }
    ASSERT_TRUE(i);
}

TEST_F(LAB2, SavingChangesForPlayerTest)
{
    Monopoly monopoly(playersList);

    auto testField = monopoly.GetField("Ford");
    auto testPlayer = monopoly.GetPlayer(FigureType::Car);
    monopoly.Buy(*testPlayer, *testField);

    testPlayer = monopoly.GetPlayer(FigureType::Car);
    ASSERT_EQ(testPlayer->getCurrentMoney(), 5500);
    ASSERT_EQ(testPlayer->getName(), testField->getOwner()->getName());
}

TEST_F(LAB2, PlayerBuyNoOwnedCompanies)
{
    Monopoly monopoly(playersList);

    auto testField = monopoly.GetField("Ford");
    auto testPlayer = monopoly.GetPlayer(FigureType::Car);
    monopoly.Buy(*testPlayer, *testField);

    ASSERT_EQ(testPlayer->getCurrentMoney(), 5500);
    ASSERT_EQ(testPlayer->getName(), testField->getOwner()->getName());
}

TEST_F(LAB2, RentaShouldBeCorrectTransferMoney)
{
    Monopoly monopoly(playersList);

    auto testField = monopoly.GetField("Ford");
    auto testPlayerOwner = monopoly.GetPlayer(FigureType::Car);
    monopoly.Buy(*testPlayerOwner, *testField);

    testField = monopoly.GetField("Ford");
    auto testPlayer = monopoly.GetPlayer(FigureType::Bike);
    monopoly.Renta(*testPlayer, *testField);

    auto playerFirst = monopoly.GetPlayer(FigureType::Car);
    ASSERT_EQ(playerFirst->getCurrentMoney(), 5750);

    auto playerSecond = monopoly.GetPlayer(FigureType::Bike);
    ASSERT_EQ(playerSecond->getCurrentMoney(), 5750);    
}

TEST_F(LAB2, GetRentaFromFieldOwnerTest)
{
    Monopoly monopoly(playersList);

    auto testField = monopoly.GetField("Ford");
    auto testPlayerOwner = monopoly.GetPlayer(FigureType::Car);
    monopoly.Buy(*testPlayerOwner, *testField);
    auto restMoney = testPlayerOwner->getCurrentMoney();
    monopoly.Renta(*testPlayerOwner, *testField);
    ASSERT_EQ(testPlayerOwner->getCurrentMoney(), restMoney); 
}

TEST_F(LAB2, PlayerPrisonTest)
{
    Monopoly monopoly(playersList);

    auto testField = monopoly.GetField("Prison");
    auto testPlayer = monopoly.GetPlayer(FigureType::Car);
    monopoly.Renta(*testPlayer, *testField);

    ASSERT_EQ(testPlayer->getCurrentMoney(), 5300);
}

TEST_F(LAB2, PlayerBankTest)
{
    Monopoly monopoly(playersList);

    auto testField = monopoly.GetField("Bank");
    auto testPlayer = monopoly.GetPlayer(FigureType::Car);
    monopoly.Renta(*testPlayer, *testField);

    ASSERT_EQ(testPlayer->getCurrentMoney(), 7000);
}
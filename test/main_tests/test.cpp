#include "monolopy.hpp"
#include "gtest/gtest.h"

using namespace ::std;

class LAB2 : public ::testing::Test
{
public:
    vector<string> players;
    Monopoly *monopoly;

    void SetUp(){
        Player::resetCounter();
        players = { "Peter","Ekaterina","Alexander" };
        monopoly = new Monopoly(players);            
    };
    void TearDown(){
        delete monopoly;
    }
};

TEST_F(LAB2, GetPlayersListReturnCorrectList) {       

    list<Player*> x = monopoly->GetPlayersList();
    int i = 0;
    for (auto c : x) {
        ASSERT_STREQ(c->getName().c_str(), players[i++].c_str());
        ASSERT_EQ(c->getBalance(), 6000);
    }
    ASSERT_TRUE(i);
}
TEST_F(LAB2, GetFieldsListReturnCorrectList) {    
    Field expectedCompanies[]{
        {AutoField("Ford")},
        {FoodField("MCDonald")},
        {ClotherField("Lamoda")},
        {TravelField("Air Baltic")},
        {TravelField("Nordavia")},
        {PrisonField("Prison")},
        {FoodField("MCDonald")},
        {AutoField("TESLA")}
    };
   std::list<Field*> actualCompanies = monopoly->GetFieldsList();
   int i = 0;
   for (auto &x : actualCompanies)
   {
       ASSERT_EQ(*x, expectedCompanies[i++]);
   }
   ASSERT_TRUE(i);   
}

TEST_F(LAB2, PlayerBuyNoOwnedCompanies)
{
    auto field = monopoly->GetFieldByName("Ford");
    monopoly->Buy(1, field);

    auto player = monopoly->GetPlayer(1);
    ASSERT_EQ(player->getBalance(), 5500);
    
    field = monopoly->GetFieldByName("Ford");
    ASSERT_TRUE(field->getId() != 0);    
}

TEST_F(LAB2, RentaShouldBeCorrectTransferMoney)
{
    auto field = monopoly->GetFieldByName("Ford");
    monopoly->Buy(1, field);

    field = monopoly->GetFieldByName("Ford");
    monopoly->Renta(2, field);
    auto player1 = monopoly->GetPlayer(1);
    ASSERT_EQ(player1->getBalance(), 5750);

    auto player2 = monopoly->GetPlayer(2);
    ASSERT_EQ(player2->getBalance(), 5750);    
}

TEST_F(LAB2, RentaTravelTransferMoney)
{
    auto field = monopoly->GetFieldByName("Air Baltic");
    monopoly->Buy(1, field);

    field = monopoly->GetFieldByName("Air Baltic");
    monopoly->Renta(2, field);
    auto player1 = monopoly->GetPlayer(1);
    ASSERT_EQ(player1->getBalance(), 5550);

    auto player2 = monopoly->GetPlayer(2);
    ASSERT_EQ(player2->getBalance(), 5750);    
}
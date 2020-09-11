#include "gtest/gtest.h"
#include "monopoly.hpp"
#include <initializer_list>

using namespace ::std;

TEST(LAB2, GetPlayersListReturnCorrectList) {
  auto players = { "Peter","Ekaterina","Alexander" };
  
  Monopoly monopoly(players);
  
  list<Monopoly::Player>* x = monopoly.GetPlayersList();
  auto p = players.begin();
  for (auto c : *x) {
    ASSERT_STREQ(c.name.c_str(), *(p++));
    ASSERT_EQ(c.money, 6000);
  }
}
TEST(LAB2, GetFieldsListReturnCorrectList) {
  Monopoly::field_t expectedCompanies[]{
    {"Ford",Monopoly::AUTO ,0},
    {"MCDonald",Monopoly::FOOD,0},
    {"Lamoda",Monopoly::CLOTHER,0},
    {"Air Baltic",Monopoly::TRAVEL,0},
    {"Nordavia",Monopoly::TRAVEL,0},
    {"Prison",Monopoly::PRISON,0},
    {"MCDonald",Monopoly::FOOD,0},
    {"TESLA",Monopoly::AUTO,0}
  };
  auto players = { "Peter","Ekaterina","Alexander" };
  
  Monopoly monopoly(players);
  auto actualCompanies = monopoly.GetFieldsList();
  int i = 0;
  for (auto x : *actualCompanies)
  {
    ASSERT_EQ(x, expectedCompanies[i++]);
  }
  ASSERT_TRUE(i);   
}

TEST(LAB2, PlayerBuyNoOwnedCompanies)
{
  auto players = { "Peter","Ekaterina","Alexander" };
  
  Monopoly monopoly(players);
  auto x = monopoly.GetFieldByName("Ford");
  monopoly.Buy(1, x);
  
  auto player = monopoly.GetPlayerInfo(1);
  ASSERT_EQ(player.money, 5500);
  x = monopoly.GetFieldByName("Ford");
  ASSERT_TRUE(x.owner != 0);
}

TEST(LAB2, RentaShouldBeCorrectTransferMoney)
{
  auto players = { "Peter","Ekaterina","Alexander" };
  Monopoly monopoly(players);
  auto x = monopoly.GetFieldByName("Ford");
  monopoly.Buy(1, x);
  
  x = monopoly.GetFieldByName("Ford");
  monopoly.Renta(2, x);
  auto player1 = monopoly.GetPlayerInfo(1);
  ASSERT_EQ(player1.money, 5750);
  
  auto player2 = monopoly.GetPlayerInfo(2);
  ASSERT_EQ(player2.money, 5750);    
}


bool operator==(const Monopoly::field_t& fst, const Monopoly::field_t& snd) {
  return
  fst.name == snd.name &&
  fst.type == snd.type &&
  fst.owner == snd.owner;
}

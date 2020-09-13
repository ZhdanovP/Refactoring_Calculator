#include "gtest/gtest.h"
#define private public
#define protected public
 
#include "player.hpp"
#include "fields.hpp"
#include "monolopy.hpp"
#include <set>


using namespace ::std;

TEST(LAB2, GetPlayersListReturnCorrectList) {
    string players[]{ "Peter","Ekaterina","Alexander" };
   
    Monopoly monopoly(players,3);

    int i = 0;
    for (const auto & [ namePlayer, player ]: monopoly.Players) {
        ASSERT_EQ(player->m_AccountReminder,6000);
        find_if(&players[0],&players[3], [namePlayer,&i](string val ){  if(val == namePlayer){ i++; return true;}  return false; });
    }

    ASSERT_EQ(i,3);
}

TEST(LAB2, GetFieldsListReturnCorrectList) {
            
      
std::unordered_map<std::string,std::shared_ptr<Field>> Fields ={
     {"TESLA",std::make_shared<Auto>()},
     {"Ford", std::make_shared<Auto>()},
     {"AlfaBank", std::make_shared<Bank>()},
     {"McDonalds", std::make_shared<Food>()},
     {"Tour",std::make_shared<Travel>()}
   };  
    

    string players[]{ "Peter","Ekaterina","Alexander" };
    Monopoly monopoly(players, 3);

   int i = 0;
   for (const auto & [ nameField, monopoly_field ]: monopoly.Fields)
   {
        auto field = Fields[nameField];  
      
        ASSERT_EQ(field->m_SellingPrise,monopoly_field->m_SellingPrise);

        if(auto rentalField = std::dynamic_pointer_cast<RentalField>(field) )
         {
            try{
               
                auto monopoly_rentalField = std::dynamic_pointer_cast<RentalField>(monopoly_field);
                ASSERT_TRUE(monopoly_rentalField);  
                ASSERT_EQ(monopoly_rentalField->m_RentalPrise,rentalField->m_RentalPrise);
            }
             catch(...)
              {
                FAIL();
              } 
         } 

       
        Fields.erase(nameField);   
   }

   ASSERT_FALSE(Fields.size());   
}

TEST(LAB2, PlayerBuyNoOwnedCompanies)
{
    string players[]{ "Peter","Ekaterina","Alexander" };

    Monopoly monopoly(players, 3);

    monopoly.Buy("Peter","Ford");

   ASSERT_EQ( monopoly.getPlayer("Peter")->m_AccountReminder,5500);
   ASSERT_EQ( std::dynamic_pointer_cast<RentalField>(monopoly.getField("Ford"))->m_Owner,monopoly.getPlayer("Peter")); 
}

TEST(LAB2, RentaShouldBeCorrectTransferMoney)
{
    string players[]{ "Peter","Ekaterina","Alexander" };
    Monopoly monopoly(players, 3);
    
    ASSERT_TRUE(monopoly.Buy("Peter","Ford"));
    monopoly.Rent("Ekaterina","Ford");

    ASSERT_EQ( monopoly.getPlayer("Ekaterina")->m_AccountReminder,5750);
    ASSERT_EQ( monopoly.getPlayer("Peter")->m_AccountReminder,5750);

}

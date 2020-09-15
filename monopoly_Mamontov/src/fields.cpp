#include "fields.hpp"
#include "player.hpp"


bool Field::buy(std::shared_ptr<Player> player){
   player->outcom(m_SellingPrise);   
   return true;
}

bool RentalField::buy(std::shared_ptr<Player> player){
     if(m_Owner)
     	   return false;

     m_Owner = player;

     return Field::buy(player); 
}

bool RentalField::sell(std::shared_ptr<Player> player){

	  if(m_Owner!=player)return false;

      player->income(m_SellingPrise);
      
      m_Owner = 0;

      return true;
}


bool RentalField::rent(std::shared_ptr<Player> player)
{
     if(!m_Owner || m_Owner==player)return false;
        
     m_Owner->income(m_RentalPrise);
      player->outcom(m_RentalPrise);

     return true;
}
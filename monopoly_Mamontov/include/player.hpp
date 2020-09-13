#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>

class Player
{
  public: 
     Player(int accountReminder):
     m_AccountReminder(accountReminder){};
  
    void income(int payment){ m_AccountReminder+=payment; }
    void outcom(int payment){ m_AccountReminder-=payment; }

  private:

  	 int  m_AccountReminder;   	
};

#endif
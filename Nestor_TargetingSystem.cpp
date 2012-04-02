#include "Nestor_TargetingSystem.h"
#include "../../AbstRaven_Bot.h"
#include "../../Raven_SensoryMemory.h"



//-------------------------------- ctor ---------------------------------------
//-----------------------------------------------------------------------------
Nestor_TargetingSystem::Nestor_TargetingSystem(AbstRaven_Bot* owner):
	AbstTargetingSystem(owner)
{}



//----------------------------- Update ----------------------------------------

//-----------------------------------------------------------------------------
void Nestor_TargetingSystem::Update()
{
  double ClosestDistSoFar = MaxDouble;
  m_pCurrentTarget       = 0;

  //grab a list of all the opponents the owner can sense
  std::list<AbstRaven_Bot*> SensedBots;
  SensedBots = m_pOwner->GetSensoryMem()->GetListOfRecentlySensedOpponents();
  
  std::list<AbstRaven_Bot*>::const_iterator curBot = SensedBots.begin();
  for (curBot; curBot != SensedBots.end(); ++curBot)
  {
    //make sure the bot is alive and that it is not the owner
    if ((*curBot)->isAlive() && (*curBot != m_pOwner) )
    {
      double dist = Vec2DDistanceSq((*curBot)->Pos(), m_pOwner->Pos());

      if (dist < ClosestDistSoFar)
      {
        ClosestDistSoFar = dist;
        m_pCurrentTarget = *curBot;
      }
    }
  }
}

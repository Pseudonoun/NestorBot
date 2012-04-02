#include "Nestor_BotSteeringBehaviors.h"
#include "../../AbstRaven_Bot.h"
#include "2d/Wall2D.h"
#include "2d/Transformations.h"
#include "misc/utils.h"
#include "misc/Cgdi.h"
#include "../../Raven_Game.h"
#include "2d/geometry.h"
#include "Nestor_BotScriptor.h"
#include "../../Raven_Map.h"

#include <cassert>


using std::string;
using std::vector;

/*

*/

//------------------------- ctor -----------------------------------------
//
//------------------------------------------------------------------------
Nestor_BotSteering::Nestor_BotSteering(Raven_Game* world, AbstRaven_Bot* agent): 
	AbstSteering(world, agent)
{
	Nestor_BotScriptor* myScript = Nestor_BotScriptor::Instance();
	m_dWeightSeparation = myScript->GetDouble("SeparationWeight");
    m_dWeightWander = myScript->GetDouble("WanderWeight");
    m_dWeightWallAvoidance = myScript->GetDouble("WallAvoidanceWeight");
    m_dViewDistance = myScript->GetDouble("ViewDistance");
	m_dWallDetectionFeelerLength = myScript->GetDouble("WallDetectionFeelerLength");
	m_Deceleration = normal;
    m_dWanderDistance = myScript->GetDouble("WanderDist");
    m_dWanderJitter = myScript->GetDouble("WanderJitterPerSec");
	m_dWanderRadius = myScript->GetDouble("WanderRad");
    m_dWeightSeek = myScript->GetDouble("SeekWeight");
    m_dWeightArrive = myScript->GetDouble("ArriveWeight");
	m_bCellSpaceOn = false;
    m_SummingMethod = prioritized;
	
	//stuff for the wander behavior
  double theta = RandFloat() * TwoPi;

  //create a vector to a target position on the wander circle
  m_vWanderTarget = Vector2D(m_dWanderRadius * cos(theta),
                              m_dWanderRadius * sin(theta));

}

//---------------------------------dtor ----------------------------------
Nestor_BotSteering::~Nestor_BotSteering(){}


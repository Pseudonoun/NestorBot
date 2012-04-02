#ifndef NESTORBOTMAKER_H
#define NESTORBOTMAKER_H
#pragma warning (disable:4786)

//------------------------------------------------------------------------
//
//  Name:   Nestor_BotMaker.h
//	Based on: Raven_BotMaker.h
//
//  Desc:   Factory class for Nestor_BotMaker. 
//
//	Authors: Team Nestor
//  Base Class Author: Robin Burke 2006 rburke@cs.depaul.edu
//
//------------------------------------------------------------------------

#include "../../BotMaker.h"
#include "../../AbstRaven_Bot.h"
#include "Nestor_Bot.h"
#include <string>
#include "../../Raven_Game.h"

class Nestor_BotMaker : public BotMaker {
private:
   Nestor_BotMaker();

   AbstRaven_Bot* makeBot(Raven_Game* world, Vector2D pos) const;
	
   // creation of static instance does automatic registration
    static const Nestor_BotMaker registerThis;
};
#endif
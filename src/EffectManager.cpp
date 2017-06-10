/*
 * EffectManager.cpp
 *
 *  Created on: Jun 5, 2017
 *      Author: arne
 */

#include "EffectManager.hpp"

EffectManager::EffectManager() {
	// TODO Auto-generated constructor stub

}


void EffectManager::addEffect(UpdateFunc updateFunc)
{
	if(numeffects < MAX_NUM_EFFECTS)
	{
		effects[numeffects] = updateFunc;
		++numeffects;
	}
	else
	{
		//FIXME assert abort
	}
}

void EffectManager::execute(uint8_t effectId, uint8_t dt, uint8_t speed, Led* leds, uint16_t numLeds)
{
	if(numeffects == 0)
		return;

	const uint8_t id = effectId % numeffects;
	effects[id](dt, speed, leds, numLeds);
}
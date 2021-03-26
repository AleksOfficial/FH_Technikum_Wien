#pragma once
#include "Object.h"
#include "enum_types.h"

class s_object;
enum class type;

class Pickups : public s_object
{
private:
	int n_magic_refill;
	int n_life_refill;
	int coin_reducer;
public:
	Pickups(float x, float y, type _type, olcSprite* _sprite, int map_width) :
		s_object(x, y, 0, _type, _sprite, map_width)
	{
		if (_type == type::e_magic_restore)
		{
			n_magic_refill = 35;
			n_life_refill = 0;
			coin_reducer = 0;
		}
		else if (_type == type::e_healthpack)
		{
			n_life_refill = 25;
			n_magic_refill = 0;
			coin_reducer = 0;

		}
		else
		{
			n_magic_refill = 0;
			n_life_refill = 0;
			coin_reducer = 1;
		}
	}

	void get_powerup(player & _player)
	{
		_player.n_lifepoints += n_life_refill;
		_player.n_magic_power += n_life_refill;
		_player.coins_left-= coin_reducer;
		disabled = true;
	}


};

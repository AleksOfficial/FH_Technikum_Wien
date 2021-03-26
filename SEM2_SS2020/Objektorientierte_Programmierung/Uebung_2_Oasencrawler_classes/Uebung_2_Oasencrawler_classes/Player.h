#pragma once
#include "enum_types.h"
#include "Object.h"
#include "Projectile.h"
class Projectile;
class s_object;
class oasencrawler;

class player : public s_object
{
public:
	
	int n_lifepoints;
	float f_angle; 
	float f_rotation;
	int n_magic_power;
	bool b_electrified;
	float f_electrify_time;
	float f_dmg;
	int coins_left;
	float f_max_stun_time;

public:
	//if I declare a variable, I have the issue "player doesn't have a default constructor
	//solved with pragma once
	player()
		: s_object( 2.0f, 4.0f, 5.0f, type::e_player,NULL, 32),
		n_lifepoints(100), f_angle(0), f_rotation(2.0f), n_magic_power(100), b_electrified(false),f_electrify_time(0), f_dmg(50.0f),
		coins_left(15), f_max_stun_time(2.6f)
	{
	}
	void reset()
	{
		f_x = 2.0f;
		f_y = 3.0f;
		f_angle = 0;
		n_lifepoints = 100;
		n_magic_power = 100;
		b_electrified = false;
		f_electrify_time = 0;
		coins_left = 15;
		disabled = false;
	}
	void rotate(float f_elapsed_time, float direction, std::wstring map)
	{
		f_angle += f_rotation * f_elapsed_time * direction;
	}
	void move_player(float f_elapsed_time, float direction, std::wstring map)
	{
		if (!b_electrified)
		{
			f_x += sinf(f_angle) * f_speed * f_elapsed_time * direction;
			f_y += cosf(f_angle) * f_speed * f_elapsed_time * direction;
			if (map[(int)f_x + (int)f_y * n_map_height] == '#')
			{
				f_x -= sinf(f_angle) * f_speed * f_elapsed_time * direction;
				f_y -= cosf(f_angle) * f_speed * f_elapsed_time * direction;
			}

		}
		else
		{
			f_electrify_time -= f_elapsed_time;
			if (f_electrify_time < 0)
				b_electrified = false;
		}
	}
	void strafe_player(float f_elapsed_time, char strafing, std::wstring map)
	{
		if (!b_electrified)
		{
			if (strafing == 'l')
			{
				f_x += cosf(f_angle) * f_speed * f_elapsed_time * (-1);
				f_y += sinf(f_angle) * f_speed * f_elapsed_time;
				if (map[(int)f_x + (int)f_y * n_map_height] == '#')
				{
					f_x -= cosf(f_angle) * f_speed * f_elapsed_time * (-1);
					f_y -= sinf(f_angle) * f_speed * f_elapsed_time;
				}
			}
			if (strafing == 'r')
			{
				f_x += cosf(f_angle) * f_speed * f_elapsed_time;
				f_y += sinf(f_angle) * f_speed * f_elapsed_time *(-1);
				if (map[(int)f_x + (int)f_y * n_map_height] == '#')
				{
					f_x -= cosf(f_angle) * f_speed * f_elapsed_time;
					f_y -= sinf(f_angle) * f_speed * f_elapsed_time * (-1);
				}
			}
		}
		else
		{
			if(b_electrified)
				f_electrify_time -= f_elapsed_time;
			
			if (f_electrify_time < 0)
			{
				b_electrified = false;
			}
				
		}
	}
	void buff_dmg(float amount)
	{
		f_dmg += amount;
	}
	void buff_stun(float amount)
	{
		 f_max_stun_time -= amount;
		 if (f_max_stun_time < 0.5f)
			 f_max_stun_time = 0.5f;
	}
	void buff_speed(float amount)
	{
		f_speed += amount;
		if (f_speed > 10.0f)
			f_speed = 10.0f;
	}
	//Projectile shoot(olcSprite*_sprite)
	bool shoot()
	{
		if (n_magic_power > 0)
		{
			n_magic_power -= 5;
			return true;


			//Projectile element(f_x, f_y, 8.5f, type::e_projectile_player, _sprite, n_map_height, vec_x, vec_y, f_dmg);
			//return element;
		}
		else
		{
			return false;
		}
	}
	void infinity_mode()
	{
		n_lifepoints = 9999999;
		n_magic_power = 99999999;
		f_dmg = 999999999;
	}
	int return_coins_left()
	{
		return coins_left;
	}
	void get_damage(float dmg)
	{
		n_lifepoints -= dmg;
		if (dmg == 0)
		{
			b_electrified = true;
			f_electrify_time = f_max_stun_time;
		}
		if (n_lifepoints < 0)
			disabled = true;
	}
};



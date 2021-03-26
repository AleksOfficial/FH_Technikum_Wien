#pragma once
#include "Object.h"
#include "enum_types.h"
#include "Enemy.h"

class s_object;
enum class type;
class Enemy;

class Projectile : public s_object
{
public:
	float f_x_speed;
	float f_y_speed;
	float f_dmg;
public:
	Projectile(float x, float y, float speed, type _type, olcSprite* _sprite, int map_height, float f_vec_x, float f_vec_y,float f_distance, float dmg)
		: s_object(x, y, speed, _type, _sprite, map_height)
	{
		if (f_distance == 0)
			f_distance = 1;

	f_x_speed = speed / f_distance * f_vec_x;
	f_y_speed = speed / f_distance * f_vec_y;
	f_dmg = dmg;
	}
	//yeah you too.
	/*
	void deal_closerange_dmg_player(player &my_player)
	{
		my_player.n_lifepoints -= f_dmg;
		if (f_dmg == 0)
		{
			my_player.f_electrify_time += 3.0f;
		}
			my_player.b_electrified = true;
		disabled = true;

	}
		*/
	void deal_closerange_dmg_enemy(std::list<Enemy> & enemylist)
	{
		for (auto& object : enemylist)
		{
			float f_vec_x = f_x - object.x_component();
			float f_vec_y = f_y - object.y_component();
			float f_distance_from_bullet = sqrtf(f_vec_x * f_vec_x + f_vec_y * f_vec_y);
			if (f_distance_from_bullet < 1.5f)
			{
				object.reduce_lifepoints(f_dmg);
				disabled = true;
				break;
			}

		}

	}
	void move(std::wstring map, float f_elapsed_time)
	{
		f_x += f_x_speed * f_elapsed_time;
		f_y += f_y_speed * f_elapsed_time;
		if (map[(int)f_x + (int)f_y * n_map_height] == '#')
			disabled = true;

	}


};
#pragma once
#include "Object.h"
#include "enum_types.h"
#include "Player.h"

class s_object;
enum class type;
class player;
class oasencrawler;

class Enemy : public s_object
{
private:
	int n_lifepoints;
	float f_current_cooldown;
	int n_cooldown;
	float f_dmg;
	float f_player_x;
	float f_player_y;
	float f_update_counter;
	float f_update_setter;
	int wall_hit;
	
public:
	Enemy(float x, float y, olcSprite* _sprite, type _type, float speed, int map_width, float strength, float player_x, float player_y)
		: s_object(x, y, speed, _type, _sprite, map_width), n_lifepoints(100 + (int)(100 * strength)),
		f_current_cooldown(0), n_cooldown(2), f_dmg(10 + (int)(15 * strength)), f_player_x(player_x), f_player_y(player_y), f_update_counter(0), f_update_setter((float)(rand()%5))
	{}


	void set_cooldown()
	{
			f_current_cooldown = n_cooldown;
	}
	void reduce_cooldown(float f_elapsed_time)
	{
		f_current_cooldown -= f_elapsed_time;
	}
	void update_position_player(float x, float y,float f_elapsed_time)
	{
		if (f_update_counter < 0)
		{
			f_player_x = x;
			f_player_y = y;
			f_update_counter = f_update_setter;
		}
		else
		{
			f_update_counter -= f_elapsed_time;
		}
		
	}
	

	//C2027 Verwendung des undefinierten Typs "player" obwohl es oben definiert is lel. can't be arsed anymore. pls work once ty
	//yeah f you too. stupid C2027 error
	/*
	void deal_closerange_dmg_player(player* _player)
	{
		_player->n_lifepoints -= f_dmg;
	}
	*/

	void move(wstring map, float f_elapsed_time)
	{
		float f_vec_x =  f_player_x-f_x;
		float f_vec_y = f_player_y - f_y;
		float f_distance_to_player = sqrt(f_vec_x * f_vec_x + f_vec_y * f_vec_y);
		int random_movement = rand() % 100;
		if (random_movement > 75)
			random_movement = 1;
		else
			random_movement = 0;
		if (random_movement)
		{
			int x = rand() % 2;
			if (x)
			{
				f_x +=  f_vec_y/f_distance_to_player * f_speed*f_elapsed_time;
				f_y +=  f_vec_x / f_distance_to_player * f_speed * (-1) * f_elapsed_time;
				if (f_x > n_map_height || f_y > n_map_height || f_x < 0 || f_y < 0)
				{
					f_x = n_map_height / 2.0f;
					f_y = n_map_height / 2.0f;
				}
				if (map[(int)f_x + (int)f_y * n_map_height] == '#')
				{
					f_x -= f_vec_y / f_distance_to_player * f_speed * (0.5 + f_elapsed_time);
						f_y -= f_vec_x / f_distance_to_player * f_speed * (0.5 + f_elapsed_time)*(-1);
				}

			}
			else
			{
				f_x += f_vec_y / f_distance_to_player * f_speed * (-1) * f_elapsed_time;
				f_y += f_vec_y / f_distance_to_player * f_speed * f_elapsed_time;
				if (f_x > n_map_height || f_y > n_map_height || f_x < 0 || f_y < 0)
				{
					f_x = n_map_height / 2.0f;
					f_y = n_map_height / 2.0f;
				}
				if (map[(int)f_x + (int)f_y * n_map_height] == '#')
				{
					f_x -= f_vec_y / f_distance_to_player * f_speed * (-1) * (0.5 + f_elapsed_time);
					f_y -= f_vec_x / f_distance_to_player * f_speed * (0.5 + f_elapsed_time);
				}

			}
		}
		else
		{
				f_x +=  f_vec_x / f_distance_to_player * f_speed * f_elapsed_time;
				f_y +=  f_vec_y / f_distance_to_player * f_speed * f_elapsed_time;
				if (f_x > n_map_height || f_y > n_map_height || f_x < 0 || f_y < 0)
				{
					f_x = n_map_height/2.0f;
					f_y = n_map_height/2.0f;
				}
				if (map[(int)f_x + (int)f_y * n_map_height] == '#')
				{
					f_x -= f_vec_x / f_distance_to_player * f_speed * (0.5+f_elapsed_time);
					f_y -= f_vec_y / f_distance_to_player * f_speed * (0.5+f_elapsed_time);
				}

		}

		/*
		if ((abs(f_vec_y) > abs(f_vec_x)) && random_movement > 0)
		{
			if (f_vec_y > 0)
			{
				f_y -= f_speed * f_elapsed_time  ;
				if (map[(int)f_x + (int)f_y * n_map_height] == '#' || map[(int)f_x + (int)f_y * n_map_height] == 'E')
					f_y += f_speed * f_elapsed_time ;
			}
			else
			{
				f_y += f_speed * f_elapsed_time* random_movement;
				if (map[(int)f_x + (int)f_y * n_map_height] == '#' || map[(int)f_x + (int)f_y * n_map_height] == 'E')
					f_y -= f_speed * f_elapsed_time ;
			}

		}
		else
		{
			if (f_vec_x > 0)
			{
				f_x -= f_speed * f_elapsed_time ;
				if (map[(int)f_x + (int)f_y * n_map_height] == '#' || map[(int)f_x + (int)f_y * n_map_height] == 'E')
					f_x += f_speed * f_elapsed_time;
			}
			else
			{
				f_x += f_speed * f_elapsed_time ;
				if (map[(int)f_x + (int)f_y * n_map_height] == '#' || map[(int)f_x + (int)f_y * n_map_height] == 'E')
					f_x -= f_speed * f_elapsed_time;
			}
		}*/
	}
	void reduce_lifepoints(float amount)
	{
		n_lifepoints -= amount;
		if (n_lifepoints < 0)
			disabled = true;

	}

	type return_objecttype()
	{
		return objecttype;
	}

	bool return_cooldown_state()
	{
		if (f_current_cooldown <= 0)
			return true;
		else
			return false;
	}
	float return_dmg()
	{
		return f_dmg;
	
	}


	
};
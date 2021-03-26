#pragma once
#include "enum_types.h"
#include "olcConsoleGameEngine.h"

class s_object
{
public:
	float f_x;
	float f_y;
	float f_speed;
	bool disabled;
	olcSprite* sprite;
	int n_map_height;
	//enum ? 
	type objecttype;
public:
	s_object(float x, float y, float speed,type _type,olcSprite * _sprite, int map_width)
		:f_x(x), f_y(y), f_speed(speed), disabled(false), objecttype(_type),sprite(_sprite), n_map_height(map_width)
	{
		
	}
	
public:
	float y_component()
	{
		return f_y;
	}
	float x_component()
	{
		return f_x;
	}
	bool return_disabled()
	{
		return disabled;
	}
	olcSprite* return_sprite()
	{
		return sprite;
	}
	type return_objecttype()
	{
		return objecttype;
	}

};
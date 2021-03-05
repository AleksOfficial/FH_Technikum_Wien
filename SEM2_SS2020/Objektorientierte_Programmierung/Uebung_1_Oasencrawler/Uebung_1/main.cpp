#include <iostream>
using namespace std;
#include <chrono>
#include <math.h>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>

#include "olcConsoleGameEngine.h"





class oasencrawler : public olcConsoleGameEngine
{
public:
	oasencrawler()
	{
		m_sAppName = L"Oasen Crawler - Finde die versteckten Relikte!";
		
	}

	void clear_screen()
	{
		for (int i = 0; i < m_nScreenHeight; i++)
			for (int j = 0; j < m_nScreenWidth; j++)
				Draw(1 + j, 1 + i, L' ');
	}
	void terminate_program()
	{
		//free all the stuff that's necessary
	}
	bool print_loss_screen()
	{
		clear_screen();
		wstring lose_text[8];
		lose_text[0] = L"$$\\     $$\\  $$$$$$\\  $$\\   $$\\       $$\\       $$$$$$\\   $$$$$$\\  $$$$$$$$\\ $$\\ ";
		lose_text[1] = L"\\$$\\   $$  |$$  __$$\\ $$ |  $$ |      $$ |     $$  __$$\\ $$  __$$\\ $$  _____|$$ |";
		lose_text[2] += L" \\$$\\ $$  / $$ /  $$ |$$ |  $$ |      $$ |     $$ /  $$ |$$ /  \\__|$$ |      $$ |";
		lose_text[3] += L"  \\$$$$  /  $$ |  $$ |$$ |  $$ |      $$ |     $$ |  $$ |\\$$$$$$\\  $$$$$\\    $$ |";
		lose_text[4] += L"   \\$$  /   $$ |  $$ |$$ |  $$ |      $$ |     $$ |  $$ | \\____$$\\ $$  __|   \\__|";
		lose_text[5] = L"    $$ |    $$ |  $$ |$$ |  $$ |      $$ |     $$ |  $$ |$$\\   $$ |$$ |          ";
		lose_text[6] = L"    $$ |     $$$$$$  |\\$$$$$$  |      $$$$$$$$\\ $$$$$$  |\\$$$$$$  |$$$$$$$$\\ $$\\ ";
		lose_text[7] = L"    \\__|     \\______/  \\______/       \\________|\\______/  \\______/ \\________|\\__|";
		for (int i = 0; i < 8; i++)
		{
			DrawString(n_map_width, n_map_height + i, lose_text[i]);
		}
		DrawString(n_map_width, n_map_height + 14, L"Try Again? Hit J, else hit Q the program");
		return true;
	}
	bool print_win_screen()
	{
		clear_screen();
		wstring lose_text[8];
		lose_text[0] = L" /$$     /$$ /$$$$$$  /$$   /$$       /$$      /$$ /$$$$$$ /$$   /$$ /$$"	 ;
		lose_text[1] = L"|  $$   /$$//$$__  $$| $$  | $$      | $$  /$ | $$|_  $$_/| $$$ | $$| $$"	 ;
		lose_text[2] = L" \\  $$ /$$/| $$  \\ $$| $$  | $$      | $$ /$$$| $$  | $$  | $$$$| $$| $$"	 ;
		lose_text[3] = L"  \\  $$$$/ | $$  | $$| $$  | $$      | $$/$$ $$ $$  | $$  | $$ $$ $$| $$"	 ;
		lose_text[4] = L"   \\  $$/  | $$  | $$| $$  | $$      | $$$$_  $$$$  | $$  | $$  $$$$|__/"	 ;
		lose_text[5] = L"    | $$   | $$  | $$| $$  | $$      | $$$/ \\  $$$  | $$  | $$\\  $$$"	 ;
		lose_text[6] = L"    | $$   |  $$$$$$/|  $$$$$$/      | $$/   \\  $$ /$$$$$$| $$ \\  $$ /$$"	 ;
		lose_text[7] = L"    |__/    \\______/  \\______/       |__/     \\__/|______/|__/  \\__/|__/"	 ;
		for (int i = 0; i < 8; i++)																 
		{
			DrawString(n_map_width, n_map_height + i, lose_text[i]);
		}
		DrawString(n_map_width, n_map_height + 14, L"Try Again? Hit J, else hit Q the program");
		return true;
	}

	virtual bool OnUserCreate()
	{
		//SET THE DEBUG MODE HERE
		// true = receive debug information like position, angle, amount of movement
		debug = true;
		map += L"################";//################";
		map += L"#......##......#";//#..............#";
		map += L"#..............#";//#..............#";
		map += L"#....##..##....#";//...............#";
		map += L"#..............#";//#..............#";
		map += L"#..............#";//#..............#";
		map += L"#...##....##...#";//#...##....##..##";
		map += L"#..............#";//#..............#";
		map += L"#..............#";//#..............#";
		map += L"#..##......##..#";//...............#";
		map += L"#......##......#";//...............#";
		map += L"#..............#";//#..........#####";
		map += L"#..............#";//#..............#";
		map += L"#....#####.....#";//#..........#####";
		map += L"#..............#";//#..............#";
		map += L"################";//######...#######";
/*		map += L"######...#############...#######";
		map += L"#..............##..............#";
		map += L"#..............##..............#";
		map += L"#.........#....##.....####.....#";
		map += L"#.........#....##..............#";
		map += L"#.........#....##..............#";
		map += L"#...##....#...###...##....##...#";
		map += L"#.........#....##..............#";
		map += L"###.......#....##..............#";
		map += L"#..............##..............#";
		map += L"###............##....######....#";
		map += L"#..............##..............#";
		map += L"#.........#....##..............#";
		map += L"#.........#....##..............#";
		map += L"#.........#....##.....#..#.....#";
		map += L"################################";
		*/
		my_player.f_player_x = 2.0f; //start_position x
		my_player.f_player_y = 4.0f; //start_position y
		my_player.f_player_a = 0;    //start angle
		my_player.lifepoints = 100;
		n_map_width = 16;
		n_map_height = 16;
		my_player.positions = new bool[n_map_height*n_map_width];
		sprite_zombie = new olcSprite(L"sprites/zombie.spr");
		sprite_pond = new olcSprite(L"sprites/pond.spr");
		sprite_treasure = new olcSprite(L"sprites/treasure.spr");
		f_depth_buffer = new float[ScreenWidth()];
		amount_relics = 0;
		list_objects = {};
		e_current_state = playing;
		
		
		//fill up the map with objects
		for(int i = 0; i<n_map_height;i++)
			for (int j = 0; j < n_map_width; j++)
			{
				int position = n_map_height * i + j;
				switch (map[position])
				{
					case'#':
						my_player.positions[n_map_height * i + j] = true;
						continue;
					case'.':
						my_player.positions[n_map_height * i + j] = false;
						int random = rand() %100+1; //return random int between 1-100 
						if (random < 41)
							continue;
						else if (random < 81)
						{
							//Trap spawn; could be an object, but it's more efficient this way

							int random2 = rand() % 100 + 1;
							if (random2 < 17)
							{
								map[position] = 'B';
							}
						}
						else if (random < 91)
						{
							// relic spawn; could be an object, but it's more efficient this way
							map[position] = 'R';
							list_objects.push_back({ (float)j,(float)i,sprite_treasure,0,0,false,0,0,relic });
							amount_relics++;

						}
						else
						{
							// Fountain spawn
							map[position] = 'F';
							list_objects.push_back({(float)j,(float)i,sprite_pond,0,-25,false,0,0,pond });
						}

						/*
						40 % Empty field
						40 % trap field -> 16% chance to be reducing LPs
						10 % relic
						10 % fountain - Restors LPs
						*/
				}
			}
		// add moving enemies
		for (int i = 0; i < 4; i++)
		{
			int n_x_pos= 0;
			int n_y_pos =0;
			bool wallspawn = false;
			while (n_y_pos < ((int)my_player.f_player_y+(n_map_width/2)) && !wallspawn)
			{
				wallspawn = true;
				n_x_pos = rand() % n_map_width;
				n_y_pos = rand() % n_map_height;
				if (map[n_x_pos + n_y_pos * n_map_width] == '#' || map[n_x_pos + n_y_pos * n_map_width] == 'F'|| map[n_x_pos + n_y_pos * n_map_width] == 'E')
					wallspawn = false;

			}
			list_objects.push_back({ (float)n_x_pos,(float)n_y_pos,sprite_zombie,2.5f,15,false,10,0,enemy });

		}

		return true;
	}
	virtual bool OnUserUpdate(float fElapsedTime)
	{
		if (e_current_state == playing)
		{


			if (m_keys[L'A'].bHeld)
				my_player.f_player_a -= f_rotation * fElapsedTime;
			if (m_keys[L'D'].bHeld)
				my_player.f_player_a += f_rotation * fElapsedTime;
			if (m_keys[L'W'].bHeld)
			{
				my_player.f_player_x += sinf(my_player.f_player_a) * f_speed * fElapsedTime;
				my_player.f_player_y += cosf(my_player.f_player_a) * f_speed * fElapsedTime;
				if (map[(int)my_player.f_player_y * n_map_width + my_player.f_player_x] == '#')
				{
					my_player.f_player_x -= sinf(my_player.f_player_a) * f_speed * fElapsedTime;
					my_player.f_player_y -= cosf(my_player.f_player_a) * f_speed * fElapsedTime;
				}
			}
			if (m_keys[L'S'].bHeld)
			{
				my_player.f_player_x -= sinf(my_player.f_player_a) * f_speed * fElapsedTime;
				my_player.f_player_y -= cosf(my_player.f_player_a) * f_speed * fElapsedTime;
				if (map[(int)my_player.f_player_y * n_map_width + my_player.f_player_x] == '#')
				{
					my_player.f_player_x += sinf(my_player.f_player_a) * f_speed * fElapsedTime;
					my_player.f_player_y += cosf(my_player.f_player_a) * f_speed * fElapsedTime;
				}
			}
			//Strafing
			if (m_keys[L'Q'].bHeld)
			{
				my_player.f_player_x += -cosf(my_player.f_player_a) * f_speed * fElapsedTime;
				my_player.f_player_y += sinf(my_player.f_player_a) * f_speed * fElapsedTime;
				if (map[(int)my_player.f_player_y * n_map_width + my_player.f_player_x] == '#')
				{
					my_player.f_player_x -= -cosf(my_player.f_player_a) * f_speed * fElapsedTime;
					my_player.f_player_y -= sinf(my_player.f_player_a) * f_speed * fElapsedTime;
				}
			}
			if (m_keys[L'E'].bHeld)
			{
				my_player.f_player_x += cosf(my_player.f_player_a) * f_speed * fElapsedTime;
				my_player.f_player_y += -sinf(my_player.f_player_a) * f_speed * fElapsedTime;
				if (map[(int)my_player.f_player_y * n_map_width + my_player.f_player_x] == '#')
				{
					my_player.f_player_x -= cosf(my_player.f_player_a) * f_speed * fElapsedTime;
					my_player.f_player_y -= -sinf(my_player.f_player_a) * f_speed * fElapsedTime;
				}
			}
			
				if (debug)
				{
					if (m_keys[L'C'].bHeld)
					{
						amount_relics = 0;
					}
				}
		}
		if (e_current_state == loss_win)
		{
			if (m_keys[L'J'].bHeld)
				OnUserCreate();
			if (m_keys[L'Q'].bHeld)
				terminate_program();
		}
		
		//Handle win/loss screens
		if (amount_relics == 0)
		{
			e_current_state = loss_win;
			print_win_screen();
			
		}
		else if (my_player.lifepoints < 0)
		{
			e_current_state = loss_win;
			print_loss_screen();
		}
		else
		{

		
		//handle input
		//Instead of using GetAsyncKeyState - use the command from the engine
			
		//Instead of defining screen_width - use the function provided by the GameEngine
		for (int x = 0; x < ScreenWidth(); x++)
		{
			//each col is a ray. The angle of every ray is calculated this way
			float ray_angle = (my_player.f_player_a - fFOV / 2.0f) + ((float)x / (float)ScreenWidth() * fFOV);

			float f_distance_to_wall = 0;
			bool b_hit_wall = false;
			bool b_boundary = false;

			float f_eye_x = sinf(ray_angle);
			float f_eye_y = cosf(ray_angle);
			int n_test_x;
			int n_test_y;



			//this might be more efficient, dunno how tho. maybe with some form of calculation of the total distance by using the position of the player?
			while (!b_hit_wall && f_distance_to_wall < f_depth)
			{
				f_distance_to_wall += 0.1f;

				n_test_x = (int)(my_player.f_player_x + f_eye_x * f_distance_to_wall);
				n_test_y = (int)(my_player.f_player_y + f_eye_y * f_distance_to_wall);

				//Ray is out of bounds
				if (n_test_x < 0 || n_test_x >= n_map_width || n_test_y < 0 || n_test_y >= n_map_height)
				{
					b_hit_wall = true;
					f_distance_to_wall = f_depth;
					
				}
				else
				{
					//Ray is within bounds -> check if it is hitting a wall
					if (map[n_test_y * n_map_width + n_test_x] == '#')
					{
						b_hit_wall = true;
						vector<pair<float, float>> p;//distance, dotproduct
						for (int tx = 0; tx < 2; tx++)
						{
							for (int ty = 0; ty < 2; ty++)
							{
								//I honestly didnt understand that completely.. sry

								float vy = (float)n_test_y + ty - my_player.f_player_y;
								float vx = (float)n_test_x + tx - my_player.f_player_x;
								float d = sqrt(vy * vy + vx * vx);
								float dot = (f_eye_x * vx / d) + (f_eye_y * vy / d);
								p.push_back(make_pair(d, dot));
							}
						}
						//sort pairs from closest to farthest
						sort(p.begin(), p.end(), [](const pair<float, float>& left, const pair<float, float>& right) {return left.first < right.first; });

						float f_bound = 0.01f;
						if (acos(p.at(0).second) < f_bound) b_boundary = true;
						if (acos(p.at(1).second) < f_bound) b_boundary = true;
						if (acos(p.at(2).second) < f_bound) b_boundary = true;

					}

				}
			}



			// Calculate distance to ceiling and floor
			int n_ceiling = (float)(ScreenHeight() / 2.0f) - (ScreenHeight() / (float)f_distance_to_wall);
			int n_floor = ScreenHeight() - n_ceiling;
			f_depth_buffer[x] = f_distance_to_wall;
			//define the shade of the wall at this specific col 
			short n_shade_wall = ' ';
			short n_shade_floor = ' ';
			if (f_distance_to_wall < f_depth / 4.0f) //wall is close 
				n_shade_wall = 0x2588;
			else if (f_distance_to_wall < f_depth / 3.0f)
				n_shade_wall = 0x2593;
			else if (f_distance_to_wall < f_depth / 2.0f)
				n_shade_wall = 0x2592;
			else if (f_distance_to_wall < f_depth) //wall is far
				n_shade_wall = 0x2591;

			if (b_boundary)
				n_shade_wall = ' ';


			for (int y = 0; y < ScreenHeight(); y++)
			{
				if (y <= n_ceiling)
					//screen[y * ScreenWidth() + x] = ' '; Handled by Game Engine function Draw .. I'll replace it on other areas but I'll comment it here
					Draw(x, y, L' ');
				else if (y > n_ceiling && y <= n_floor)
					Draw(x, y, n_shade_wall);
				else
				{
					float b = 1.0f - (((float)y - ScreenHeight() / 2.0f) / ((float)ScreenHeight() / 2.0f));
					if (b < 0.25)
					{
						n_shade_floor = '#';
						Draw(x, y, n_shade_floor,BG_LIGHTGREEN);
					}
					else if (b < 0.5)
					{
						n_shade_floor = 'x';
						Draw(x, y, n_shade_floor,BG_GREEN);
					}
					else if (b < 0.75)
					{
						n_shade_floor = '.';
						Draw(x, y, n_shade_floor, BG_DARK_GREENER);
					}
					else if (b < 0.9) {
						n_shade_floor = '-';
						Draw(x, y, n_shade_floor,BG_DARK_GREEN);
					}
					else
					{
						n_shade_floor = ' ';
						Draw(x, y, n_shade_floor);
					}
					

				}

			}
		}
		//Update & draw Objects
		for (auto& object : list_objects)
		{	
			//Calculating Vector components
			float f_vec_x = object.x - my_player.f_player_x;
			float f_vec_y = object.y - my_player.f_player_y;
			float f_distance_from_player = sqrtf(f_vec_x * f_vec_x + f_vec_y * f_vec_y);

			//Damage/heal management
			if (f_distance_from_player < 1.5f && !object.disabled)
			{
				object.disabled = true;
				if (object.objecttype == relic)
				{
					amount_relics--;
				}
				else
					my_player.lifepoints -= object.dmg;
			}

			//Enemy disabled handler
			if (object.disabled && object.objecttype == enemy)
			{
				if (object.n_current_cooldown >= (float)object.n_cooldown)
				{
					object.disabled = false;
					object.n_current_cooldown = 0;
				}
				else
				{
					object.n_current_cooldown += fElapsedTime;
						
				}
			}

			//Movement of enemy
			if (object.objecttype == enemy && !object.disabled)
			{
				random_movement = rand() % 100;
				if (random_movement > 80)
					random_movement = -1;
				else
					random_movement = 1;
				if ((abs(f_vec_y) > abs(f_vec_x)) && random_movement >0)
				{
					if (f_vec_y > 0)
					{
						object.y -= object.movement_speed * fElapsedTime*random_movement;
						if (map[(int)object.x + (int)object.y * n_map_height] == '#' || map[(int)object.x + (int)object.y * n_map_height] == 'E')
							object.y += object.movement_speed * fElapsedTime*random_movement;
					}
					else
					{
						object.y += object.movement_speed * fElapsedTime* random_movement;
						if (map[(int)object.x + (int)object.y * n_map_height] == '#' || map[(int)object.x + (int)object.y * n_map_height] == 'E')
							object.y -= object.movement_speed * fElapsedTime* random_movement;
					}

				}
				else
				{
					if (f_vec_x > 0)
					{
						object.x -= object.movement_speed * fElapsedTime* random_movement;
						if (map[(int)object.x + (int)object.y * n_map_height] == '#' || map[(int)object.x + (int)object.y * n_map_height] == 'E')
							object.x += object.movement_speed * fElapsedTime* random_movement;
					}
					else
					{
						object.x += object.movement_speed * fElapsedTime* random_movement;
						if (map[(int)object.x + (int)object.y * n_map_height] == '#' || map[(int)object.x + (int)object.y * n_map_height] == 'E')
							object.x -= object.movement_speed * fElapsedTime* random_movement;
					}
				}
			}
		

			//Can the object be seen?


			float f_eye_x = sinf(my_player.f_player_a);
			float f_eye_y = cosf(my_player.f_player_a);

			float f_object_angle = atan2f(f_eye_y, f_eye_x) - atan2f(f_vec_y, f_vec_x);
			if (f_object_angle < -3.14159f)
				f_object_angle += 2.0f * 3.14159f;
			if (f_object_angle > 3.14159f)
				f_object_angle -= 2.0f * 3.14159f;

			bool b_in_player_view = fabs(f_object_angle) < fFOV / 2.0f;

			if (b_in_player_view && f_distance_from_player >= 0.5f && f_distance_from_player < f_depth)
			{
				if ((object.objecttype == relic && !object.disabled) || (object.objecttype==pond && !object.disabled) || object.objecttype == enemy)
				{
					float f_object_ceiling = (float)(ScreenHeight() / 2.0) - ScreenHeight() / ((float)f_distance_from_player);
					float f_object_floor = ScreenHeight() - f_object_ceiling;
					float f_object_height = f_object_floor - f_object_ceiling;
					float f_object_aspect_ratio = (float)object.sprite->nHeight / (float)object.sprite->nWidth;
					float f_object_width = f_object_height / f_object_aspect_ratio;
					float f_middle_of_object = (0.5f * (f_object_angle / (fFOV / 2.0f)) + 0.5f) * (float)ScreenWidth();

					for (float lx = 0; lx < f_object_width; lx++)
					{
						for (float ly = 0; ly < f_object_height; ly++)
						{
							float f_sample_x = lx / f_object_width;
							float f_sample_y = ly / f_object_height;
							wchar_t c = object.sprite->SampleGlyph(f_sample_x, f_sample_y);
							int n_object_column = (int)(f_middle_of_object + lx - (f_object_width / 2.0f));
							if (n_object_column >= 0 && n_object_column < ScreenWidth())
								if (c != L' ' && f_depth_buffer[n_object_column] >= f_distance_from_player)
								{
									Draw(n_object_column, f_object_ceiling + ly, c, object.sprite->SampleColour(f_sample_x, f_sample_y));
									f_depth_buffer[n_object_column] = f_distance_from_player;
								}
						}
					}
				}
	
			}

		}

		//Update positions player has visited
		if (!my_player.positions[(int)my_player.f_player_x + (int)my_player.f_player_y * n_map_height] && map[(int)my_player.f_player_x + (int)my_player.f_player_y * n_map_height] == 'B')
			my_player.lifepoints -= 20;
		my_player.positions[(int)my_player.f_player_x + (int)my_player.f_player_y * n_map_height] = true;

		//Minimap stuff
		

		
		//Display Minimap
		for (int nx = 0; nx < n_map_width; nx++)
			for (int ny = 0; ny < n_map_height; ny++)
			{
				if (my_player.positions[ny * n_map_width + nx])
				{
					if (map[ny * n_map_width + nx] == '.')
					{
						Draw(nx + 1, ny + 1, map[ny * n_map_width + nx], FG_DARK_GREY);
					}
					if (map[ny * n_map_width + nx] == 'F')
					{
						Draw(nx + 1, ny + 1, map[ny * n_map_width + nx], FG_BLUE);
					}
					if (map[ny * n_map_width + nx] == 'B')
					{
						Draw(nx + 1, ny + 1, map[ny * n_map_width + nx], FG_MAGENTA);
					}
					else
					{
						Draw(nx + 1, ny + 1, map[ny * n_map_width + nx]);
					}
				}
				else
				{
					Draw(nx + 1, ny + 1, '?');
				}

				
			}
				
		Draw(1 + my_player.f_player_x, 1 + my_player.f_player_y, L'P',FG_GREEN);
		//Display Enemies on Minimap
		for (auto& object : list_objects)
		{
			if(object.dmg>0)
			Draw(1 + object.x, 1 + object.y, L'E',BG_RED);
		}
		
		//Display Player Information and remaining relics
		if (debug)
			DrawString(n_map_width + 4, 1, L"PLAYER DATA: POS_X: " + to_wstring(my_player.f_player_x) + L" POS Y: " + to_wstring(my_player.f_player_y) + L" ANGLE: " + to_wstring(my_player.f_player_a)+ L" Remaining Relics: "+ to_wstring(amount_relics)+L" Life Points: " + to_wstring(my_player.lifepoints));
		else
			DrawString(n_map_width + 4, 1, L"Remaining Relics: " + to_wstring(amount_relics)+L" Life Points: "+ to_wstring(my_player.lifepoints));
		

		return true;
	}
	}



private:
	/*Obsolete - the headerfile has distinct functions for those
	int n_screen_width = 120;
	int n_screen_height = 40;
	*/
	struct player
	{
		float f_player_x;
		float f_player_y;
		float f_player_a; // angle
		bool *positions;
		int lifepoints;
	};
	player my_player;
	bool debug; 
	int difficulty;
	wstring map;
	int n_map_height;
	int n_map_width;
	float* f_depth_buffer = nullptr;
	short info;
	enum gamestate { playing, loss_win };
	gamestate e_current_state;

	olcSprite* sprite_zombie;
	olcSprite* sprite_pond;
	olcSprite* sprite_treasure;
	enum type { enemy, pond, relic };
	struct s_object
	{
		//as game gets more complex, more features can be added
		float x;
		float y;
		olcSprite* sprite;
		float movement_speed;
		float dmg; //negative damage = heal
		bool disabled;
		int n_cooldown;
		float n_current_cooldown;
		type objecttype;
	};
	int amount_relics;
	list<s_object> list_objects;
	int random_movement;


	//const
	const float fFOV = (3.1451592f / 4.0f);
	const float f_depth = 16.0f;
	const float f_speed = 5.0f;
	const float f_rotation = 2.0f;

};

int main()
{
	oasencrawler game;


	game.ConstructConsole(180, 120, 8, 8);
	game.Start();
}







/* OLD MAIN*//*
int main()
{

	*****************CONSOLE FPS ENGINE BEGIN*****************

	//The Engine below would work just fine like this. however, to make it more pretty and draw sprites / objects, I'll use the olcconsoleEngine file from javidx9
	//He created the fps engine to begin with. so it's fine. I understand how it basically operates and how it creates the depth needed. I'll leave the original code in "original.cpp" file.
	//cout method is too slow to print an fps screen to the console. we need direct access to the console buffer

	//Create Screen Buffer Creates a screen in type of wchar_t

	 Obsolete - handled by the headerfile
	wchar_t* screen = new wchar_t[n_screen_width * n_screen_height];
	HANDLE h_console = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(h_console);
	DWORD dw_bytes_written = 0;



	//FPS
	//auto tp1 = chrono::system_clock::now(); - Handled by GameEngine
	//auto tp2 = chrono::system_clock::now(); - Handled by GameEngine
	//Locking into a certain amount of FPS - Handled by GameEngine
	/*	tp2 = chrono::system_clock::now();
		chrono::duration<float> elapsed_time = tp2 - tp1;
		tp1 = tp2;
		float fElapsedTime = elapsed_time.count();


	swprintf_s(screen, 41, L"X=%3.2f, Y=%3.2f, A= %3.2f FPS = %3.2f", my_player.f_player_x, my_player.f_player_y, my_player.f_player_a, 1.0f / fElapsedTime);

	screen[ScreenWidth() * n_screen_height - 1] = '\0';
	WriteConsoleOutputCharacter(h_console, screen, n_screen_height * ScreenWidth(), { 0,0 }, &dw_bytes_written);
	return 0;

	}

	*/
#include <iostream>
using namespace std;
#include <chrono>
#include <math.h>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>

#include "enum_types.h"
#include "Object.h"

#include "Player.h"
#include "Enemy.h"
#include "Projectile.h"
#include "Pickups.h"
#include "olcConsoleGameEngine.h"






class oasencrawler : public olcConsoleGameEngine
{
	
public:
	//define variables
	olcSprite* sprite_enemy_chaser;
	olcSprite* sprite_enemy_shooter;
	olcSprite* sprite_magicpond;
	olcSprite* sprite_bitcoin;
	olcSprite* sprite_healthpack;
	olcSprite* sprite_playershot;
	olcSprite* sprite_enemyshot_stun;
	olcSprite* sprite_enemyshot_damage;


	//Constructor
	oasencrawler()
	{
		m_sAppName = L"Oasen Crawler - Finde die versteckten Relikte!";
		
	}
	//Methods
	void clear_screen()
	{
		for (int i = 0; i < m_nScreenHeight; i++)
			for (int j = 0; j < m_nScreenWidth; j++)
				Draw(1 + j, 1 + i, L' ');
	}
	void terminate_program()
	{
		//free all the stuff that's necessary
		delete sprite_enemy_chaser;
		delete sprite_enemy_shooter;
		delete sprite_magicpond;
		delete sprite_bitcoin;
		delete sprite_healthpack;
		delete sprite_playershot;
		delete sprite_enemyshot_stun;
		delete sprite_enemyshot_damage;
		exit(0);
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
			DrawString((ScreenWidth()/2-38), (ScreenHeight()/4) + i, lose_text[i]);
		}
		DrawString((ScreenWidth() / 2 - 7), (ScreenHeight() / 4) + 12, L"Retry? Hit S! Quit -> Hit Q");
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
			DrawString((ScreenWidth() / 2 -38), (ScreenHeight() / 4) + i, lose_text[i]);
		}
		DrawString((ScreenWidth() / 2 - 30), (ScreenHeight() / 4) + 12, L"Choose Your Upgrade! (S -> Move Left, D -> Move Right, R -> Confirm, Q -> Quit)");
		draw_sword();
		draw_stun();
		draw_speed();
		draw_arrow(choice);
		return true;
	}
	void draw_sword()
	{
		wstring items[32];
		items[0] = L"           ,"  ;//               z$$$$$$$$P	       			   ####										   ";
		items[1] = L"          / \\";//	             z$$$$$$$$'					     ########      ####    ####					   ";
		items[2] = L"         {   }";//	            z$$$$$$$$'					    ###########   ######  ######				   ";
		items[3] = L"         p   !";//	           d$$$$$$$$'					   #############  ######  ###### ####			   ";
		items[4] = L"         ; : ;";//	          d$$$$$$$$'					   #############   ####    #### ######			   ";
		items[5] = L"         | : |";//	        .d$$$$$$$P						    ############                ######			   ";
		items[6] = L"         | : |";//	       .$$$$$$$$P						     ##########       #######     ###  ###		   ";
		items[7] = L"         l ; l";//	      .$$$$$$$$$.........				      ########   ################     #####		   ";
		items[8] = L"         l ; l";//	     .$$$$$$$$$$$$$$$$$$'				        ####    #####################  ###		   ";
		items[9] = L"         I ; I";//	    z$$$$$$$$$$$$$$$$$P'				               #######################			   ";
		items[10] =L"         I ; I";//	   -**********$$$$$$$P					              #########################			   ";
		items[11] =L"         I ; I";//	             d$$$$$$'					             ###########################		   ";
		items[12] =L"         I ; I";//	           .d$$$$$$'					             ############################		   ";
		items[13] =L"         d | b";//	          .$$$$$$P'						             ############################		   ";
		items[14] =L"         H | H";//	         z$$$$$$P						             ############################		   ";
		items[15] =L"         H | H";//	        d$$$$$$'						             ############################		   ";
		items[16] =L"         H I H";//	      .d$$$$$$'							              ###########################		   ";
		items[17] =L" ,;,     H I H     ,;,";//	     .$$$$$$$'					                    #####################		   ";
		items[18] =L";H@H;    ;_H_;,   ;H@H;";//		z$$$$$$$beeeeee			                        #################		   ";
		items[19] =L"`\\Y/d_,;|4H@HK|;,_b\\Y/'";//	   d$$$$$$$$$$$$$*		                              ###############		   ";
		items[20] =L" '\\;MMMMM$@@@$MMMMM;/'";//		  ^''''''''$$$$$'			                      ###############		   ";
		items[21] =L"   '~~~*;!8@8!;*~~~'";//	          d$$$*							                   ##############		   ";
		items[22] =L"          888";//	         d$$$'							                          ##############		   ";
		items[23] =L"          888";//	        d$$*							                          ##############		   ";
		items[24] =L"          888";//	       d$P'								                          ##############		   ";
		items[25] =L"          888";//	     .$$'								                        ###############			   ";
		items[26] =L"         d8@8b";//	    .$P'								                       ################			   ";
		items[27] =L"         O8@8O";//	   .$'									                      ################			   ";
		items[28] =L"         T808T";//	  .P'									                      ###############			   ";
		items[29] =L"          `~`";//	 .'     									                  ###############			   ";
		items[31] = L"     ATTACK BOOST"  ;// STUN TIME REDUCE                                            WALK SPEED BOOST";
		for (int i = 0; i < 32; i++)
		{
			DrawString((ScreenWidth() / 4-13), (ScreenHeight() / 2 + i), items[i], FG_RED);
		}
		
	}
	void draw_stun()
	{
		wstring items[32];
		items[0] = L"              z$$$$$$$$P";//       			   ####										   ";
		items[1] = L"             z$$$$$$$$'";//				     ########      ####    ####					   ";
		items[2] = L"            z$$$$$$$$'";//			    ###########   ######  ######				   ";
		items[3] = L"           d$$$$$$$$'";//			   #############  ######  ###### ####			   ";
		items[4] = L"          d$$$$$$$$'";//			   #############   ####    #### ######			   ";
		items[5] = L"        .d$$$$$$$P";//			    ############                ######			   ";
		items[6] = L"       .$$$$$$$$P";//			     ##########       #######     ###  ###		   ";
		items[7] = L"      .$$$$$$$$$.........";//			      ########   ################     #####		   ";
		items[8] = L"     .$$$$$$$$$$$$$$$$$$'";//			        ####    #####################  ###		   ";
		items[9] = L"    z$$$$$$$$$$$$$$$$$P'";//			               #######################			   ";
		items[10] = L"  -**********$$$$$$$P";//			              #########################			   ";
		items[11] = L"            d$$$$$$'";//			             ###########################		   ";
		items[12] = L"          .d$$$$$$'";//			             ############################		   ";
		items[13] = L"         .$$$$$$P'";//				             ############################		   ";
		items[14] = L"        z$$$$$$P";//			             ############################		   ";
		items[15] = L"       d$$$$$$'";//			             ############################		   ";
		items[16] = L"     .d$$$$$$'";//				              ###########################		   ";
		items[17] = L"    .$$$$$$$'";//	                    #####################		   ";
		items[18] = L"   z$$$$$$$beeeeee";//	                        #################		   ";
		items[19] = L"  d$$$$$$$$$$$$$*";//                          ###############		   ";
		items[20] = L" ^''''''''$$$$$'";//                      ###############		   ";
		items[21] = L"         d$$$*";//				                   ##############		   ";
		items[22] = L"        d$$$'";//			                          ##############		   ";
		items[23] = L"       d$$*";//			                          ##############		   ";
		items[24] = L"      d$P'";//				                          ##############		   ";
		items[25] = L"    .$$'";//			                        ###############			   ";
		items[26] = L"   .$P'";//			                       ################			   ";
		items[27] = L"  .$'";//			                      ################			   ";
		items[28] = L" .P'";//			                      ###############			   ";
		items[29] = L".'";//				                  ###############			   ";
		items[31] = L"  STUN TIME REDUCE        ";//                                    WALK SPEED BOOST";
		for (int i = 0; i < 32; i++)
		{
			DrawString((ScreenWidth()*2 / 4 - 13), (ScreenHeight() / 2 + i), items[i], FG_DARK_YELLOW);
		}

	}
	void draw_speed()
	{

		wstring items[32];
		items[0] = L"    ####";
		items[1] = L"  ########      ####    ####";
		items[2] = L" ###########   ######  ######";
		items[3] = L"#############  ######  ###### ####";
		items[4] = L"#############   ####    #### ######";
		items[5] = L" ############                ######";
		items[6] = L"  ##########       #######     ###  ###";
		items[7] = L"   ########   ################     #####";
		items[8] = L"     ####    #####################  ###";
		items[9] = L"            #######################";
		items[10] = L"          #########################";
		items[11] = L"          ###########################";
		items[12] = L"          ############################";
		items[13] = L"          ############################";
		items[14] = L"           ############################";
		items[15] = L"            ############################";
		items[16] = L"             ###########################";
		items[17] = L"                   #####################";
		items[18] = L"                       #################";
		items[19] = L"                         ###############";
		items[20] = L"                         ###############";
		items[21] = L"                          ##############";
		items[22] = L"                          ##############";
		items[23] = L"                          ##############";
		items[24] = L"                          ##############";
		items[25] = L"                         ###############";
		items[26] = L"                        ###############";
		items[27] = L"                       ################";
		items[28] = L"                      ###############";
		items[29] = L"                     ##############";
		for (int i = 0; i < 32; i++)
		{
			DrawString((ScreenWidth() *3/ 4 - 23), (ScreenHeight() / 2 + i), items[i], FG_BLUE);
		}
		DrawString((ScreenWidth() * 3 / 4 - 13), (ScreenHeight() / 2 + 31), L" WALK SPEED BOOST", FG_BLUE);
	}
	void draw_arrow(int choice)
	{
		wstring arrow[12];
		arrow[0] = L"        #";
		arrow[1] = L"       ###";
		arrow[2] = L"      #####";
		arrow[3] = L"     #######";
		arrow[4] = L"    #########";
		arrow[5] = L"       ###";
		arrow[6] = L"       ###";
		arrow[7] = L"       ###";
		arrow[8] = L"       ###";
		arrow[9] = L"       ###";
		arrow[10] = L"       ###";
		arrow[11] = L"       ###";
		for (int i = 0; i < 12; i++)
		{
			DrawString((ScreenWidth() * (choice+1) / 4 - 10), ScreenHeight() / 2 + 33+i, arrow[i]);
		}


	}
	void confirm(int choice)
	{
		if (e_current_state == win)
		{
			if (choice == 1)
				my_player.buff_dmg(15.0f);
			if (choice == 2)
				my_player.buff_stun(.1f);
			if (choice == 3)
				my_player.buff_speed(.5f);
		}
			list_enemies.remove_if([](Enemy& e) {return true; });
			list_projectiles.remove_if([](Projectile& e) {return true; });
			list_pickups.remove_if([](Pickups& e) {return true; });
			OnUserCreate();



		
	}

	void draw_stunned()
	{
		wstring stun_text[7];
		stun_text[0]=L"..######..########.##.....##.##....##.##....##.########.########.";
		stun_text[1]=L".##....##....##....##.....##.###...##.###...##.##.......##.....##";
		stun_text[2]=L".##..........##....##.....##.####..##.####..##.##.......##.....##";
		stun_text[3]=L"..######.....##....##.....##.##.##.##.##.##.##.######...##.....##";
		stun_text[4]=L".......##....##....##.....##.##..####.##..####.##.......##.....##";
		stun_text[5]=L".##....##....##....##.....##.##...###.##...###.##.......##.....##";
		stun_text[6]=L"..######.....##.....#######..##....##.##....##.########.########.";

		for (int i = 0; i < 7; i++)
		{
			DrawString(ScreenWidth() / 2-30, 3 + i, stun_text[i], FG_DARK_YELLOW);
		}
	}
	void handle_user_input(float fElapsedTime)
	{
		if (e_current_state == playing)
		{

			//handle input
			if (m_keys[L'A'].bHeld)
				my_player.rotate(fElapsedTime, -1, map);
			if (m_keys[L'D'].bHeld)
				my_player.rotate(fElapsedTime, 1, map);
			if (m_keys[L'W'].bHeld)
				my_player.move_player(fElapsedTime, 1, map);
			if (m_keys[L'S'].bHeld)
				my_player.move_player(fElapsedTime, -1, map);
			//Strafing
			if (m_keys[L'Q'].bHeld)
				my_player.strafe_player(fElapsedTime, 'l', map);
			if (m_keys[L'E'].bHeld)
				my_player.strafe_player(fElapsedTime, 'r', map);
			if (m_keys[L'F'].bReleased)
				if(my_player.shoot())
					list_projectiles.push_back({my_player.x_component(),my_player.y_component(),8.5f,type::e_projectile_player,sprite_playershot,n_map_height,sinf(my_player.f_angle),cosf(my_player.f_angle),1,my_player.f_dmg});
			if (debug)
			{
				if (m_keys[L'U'].bHeld)
				{
					my_player.infinity_mode();
				
				}
				if (m_keys[L'K'].bHeld)
				{
					my_player.coins_left -= 15;
				}

			}
		}
		if (e_current_state == win)
		{
			if (m_keys[L'A'].bReleased)
			{
				choice--;
				if (choice < 0)
					choice = 2;
			}
			if (m_keys[L'D'].bReleased) 
			{
				choice= (choice +1 )% 3;
			}
			if (m_keys[L'R'].bReleased)
			{
				confirm(choice);
			}
			if (m_keys[L'Q'].bReleased)
			{
				terminate_program();
			}
		}
		if (e_current_state == loss)
		{
			if (m_keys[L'Q'].bReleased)
			{
				terminate_program();
			}
			if (m_keys[L'S'].bReleased)
			{
				confirm(choice);
			}

		}
	}

	void define_sprites()
	{
		sprite_enemy_chaser = new olcSprite(L"sprites/enemy_runner.spr");
		sprite_enemy_shooter = new olcSprite(L"sprites/enemy_shooter.spr");
		sprite_magicpond = new olcSprite(L"sprites/pond.spr");
		sprite_bitcoin = new olcSprite(L"sprites/treasure.spr");
		sprite_healthpack = new olcSprite(L"sprites/healthpack.spr");
		sprite_playershot = new olcSprite(L"sprites/bullet_player.spr");
		sprite_enemyshot_stun = new olcSprite(L"sprites/bullet_electric.spr");
		sprite_enemyshot_damage = new olcSprite(L"sprites/bullet_enemy.spr");

	}
	virtual bool OnUserCreate()
	{
		//SET THE DEBUG MODE HERE
		// true = receive debug information like position, angle, amount of movement
		//huge bug found actually. If the map isn't symmetrical, then you have an issue with the #, cuz everywhere you check for the width instead of the height
		debug = true;

		map = L"";
		map += L"################################";
		map += L"#......##...............#.#....#";
		map += L"#.................##...........#";
		map += L"#....##..##.......##...........#";
		map += L"#..............................#";
		map += L"#................###...........#";
		map += L"#...##....##.....###...........#";
		map += L"#..............................#";
		map += L"#.......................###....#";
		map += L"#..##......##.......###........#";
		map += L"#......##......................#";
		map += L"#...............#..#...........#";
		map += L"#...............#..#...........#";
		map += L"#....#####......####...........#";
		map += L"#.......................#.#....#";
		map += L"######....................######";
		map += L"#..............................#";
		map += L"#..............................#";
		map += L"#..............................#";
		map += L"#.........#...........####.....#";
		map += L"#.........#....................#";
		map += L"#..............................#";
		map += L"#...##........##....##....##...#";
		map += L"#.........#....................#";
		map += L"#.........#....................#";
		map += L"#..............................#";
		map += L"#....................######....#";
		map += L"#..............................#";
		map += L"#.........#....................#";
		map += L"#.........#....................#";
		map += L"#.........#....................#";
		map += L"################################";
		

		n_map_width = 32;
		n_map_height = 32;
		/*Testing
		map += L"##########";
		map += L"#........#";
		map += L"#........#";
		map += L"#........#";
		map += L"#...##...#";
		map += L"#...##...#";
		map += L"#........#";
		map += L"#........#";
		map += L"#........#";
		map += L"##########";
		n_map_height = 10;
		n_map_width = 10;
		*/
		choice = 1;
		if(f_difficulty<0.2f)
			define_sprites();
		if (e_current_state == loss)
		{
			f_strength = 0;
			f_difficulty = 0;
		}
		my_player.reset();
		f_depth_buffer = new float[ScreenWidth()];
		list_enemies = {};
		list_projectiles = {};
		list_pickups = {};
		e_current_state = playing;
		f_difficulty += .2f;
		f_strength += 0.1f;
		if (f_difficulty > 1)
			f_difficulty = 1;
		
		//fill up the map with objects
		for(int i = 0; i<n_map_height;i++)
			for (int j = 0; j < n_map_width; j++)
			{
				int position = n_map_height * i + j;
				switch (map[position])
				{
					case'#':
						continue;
					case'.':
						//5% Spawnrate each for Magic Potion and Healthpack
						int random = rand() %100+1; //return random int between 1-100 
						if (random > 95)
						{
							//Magic-potion-spawn
							map[j + (i * n_map_height)] = L'M';
							list_pickups.push_back({ (float)j,  (float)i, type::e_magic_restore, sprite_magicpond, n_map_width });
						}
							
						else if (random > 91)
						{
							// health-spawn
							map[j + (i * n_map_height)] = L'H';
							list_pickups.push_back({ (float)j, (float)i, type::e_healthpack, sprite_healthpack, n_map_width });

						}
						
				}
			}
		// add Runner enemies
	
		for (int i = 0; i < f_difficulty*12; i++)
		{
			int n_x_pos= 1;
			int n_y_pos =1;
			bool wallspawn = true;
			while (n_y_pos < ((int)my_player.y_component()+(n_map_width/2)) || wallspawn || n_x_pos <5)
			{
				wallspawn = false;
				n_x_pos = rand() % n_map_width;
				n_y_pos = rand() % n_map_height;
				if (map[n_x_pos + n_y_pos * n_map_height] == '#')
					wallspawn = true;

			}
			list_enemies.push_back({ (float)n_x_pos, (float)(n_y_pos), sprite_enemy_chaser, type::e_enemy_runner, (float)(2.5 + (2.5 * f_difficulty)), n_map_width, f_strength,my_player.f_x, my_player.f_y });

		}
		// add shooter enemies
		for (int i = 0; i < f_difficulty * 6; i++)
		{
			int n_x_pos = 0;
			int n_y_pos = 0;
			bool wallspawn = true;
			while (n_y_pos < ((int)my_player.y_component() + (n_map_width / 2)) || wallspawn || n_x_pos<5)
			{
				wallspawn = false;
				n_x_pos = rand() % n_map_width;
				n_y_pos = rand() % n_map_height;
				if (map[n_x_pos + n_y_pos * n_map_height] == '#')
					wallspawn = true;

			}
			//Maybe its this?
			//Enemy enemy((float)n_x_pos, (float)(n_y_pos), sprite_enemy_shooter, type::e_enemy_shooter, (float)(1.5 + (1.5 * f_difficulty)), n_map_width, f_strength, my_player.f_x, my_player.f_y);
			//list_enemies.push_back(enemy);
			list_enemies.push_back({(float)n_x_pos,(float)( n_y_pos), sprite_enemy_shooter, type::e_enemy_shooter, (float)(1.5 + (1.5 * f_difficulty)), n_map_width, f_strength,my_player.f_x, my_player.f_y });

		}
		// add coins
		for(int i = 0; i<15;i++)
		{
			int n_x_pos = 0;
			int n_y_pos = 0;
			bool wallspawn = true;
			while (n_y_pos < ((int)my_player.y_component() + (n_map_width / 2)) || wallspawn)
			{
				wallspawn = false;
				n_x_pos = rand() % n_map_width;
				n_y_pos = rand() % n_map_height;
				if (map[n_x_pos + n_y_pos * n_map_height] == '#' )
					wallspawn = true;
			}
			//Here too.
			map[n_x_pos + n_y_pos * n_map_height] = L'B';
			list_pickups.push_back({ (float)n_x_pos, (float)n_y_pos, type::e_bitcoin, sprite_bitcoin, n_map_height });
		}

		return true;
	}
	virtual bool OnUserUpdate(float fElapsedTime)
	{
		handle_user_input(fElapsedTime); 
		
		//Handle win/loss screens
		if (my_player.return_coins_left() <= 0)
		{
			e_current_state = win;
			print_win_screen();
			
		}
		else if (my_player.return_disabled())
		{
			e_current_state = loss;
			print_loss_screen();
		}
		else
		{

		
		
			
		for (int x = 0; x < ScreenWidth(); x++)
		{
			//each col is a ray. The angle of every ray is calculated this way
			float ray_angle = (my_player.f_angle - f_FOV / 2.0f) + ((float)x / (float)ScreenWidth() * f_FOV);

			float f_distance_to_wall = 0;
			bool b_hit_wall = false;
			bool b_boundary = false;

			float f_eye_x = sinf(ray_angle);
			float f_eye_y = cosf(ray_angle);
			int n_test_x;
			int n_test_y;



			while (!b_hit_wall && f_distance_to_wall < f_depth)
			{
				f_distance_to_wall += 0.1f;

				n_test_x = (int)(my_player.x_component() + f_eye_x * f_distance_to_wall);
				n_test_y = (int)(my_player.y_component() + f_eye_y * f_distance_to_wall);

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

								float vy = (float)n_test_y + ty - my_player.y_component();
								float vx = (float)n_test_x + tx - my_player.x_component();
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
	//Draw Objects
		//Enemies
		for (auto& object : list_enemies)
		{
			//calculate vector components
			float f_vec_x = object.x_component() - my_player.x_component();
			float f_vec_y = object.y_component() - my_player.y_component();
			float f_distance_from_player = sqrtf(f_vec_x * f_vec_x + f_vec_y * f_vec_y);

			//Enemy closerange damage handler
			if (f_distance_from_player < 1.5f)
			{
				if (object.return_cooldown_state())
				{
					//object.deal_closerange_dmg_player(&my_player); f you . you don't work for no reason at all. everything you need to work is here. 
					my_player.get_damage(object.return_dmg());
					object.set_cooldown();
				}
				else
					object.reduce_cooldown(fElapsedTime);
					
			}
			//Update Memory of enemy
			object.update_position_player(my_player.f_x, my_player.f_y,fElapsedTime);

			//move_enemies
			object.move(map,fElapsedTime);

			//fire projectile
			if (object.return_objecttype() == type::e_enemy_shooter)
			{
				if (object.return_cooldown_state())
				{
					//I can just do this in the previous form man... 
					float random = rand() % 100;
					if(random>80)
						list_projectiles.push_back({ object.x_component(),object.y_component(), (float)(6.5+f_difficulty),type::e_projectile_enemy,sprite_enemyshot_stun,n_map_height,(-1)*f_vec_x, (-1) * f_vec_y,f_distance_from_player,0});
					else
						list_projectiles.push_back({ object.x_component(),object.y_component(),(float)(6.5 + f_difficulty), type::e_projectile_enemy,sprite_enemyshot_damage, n_map_height,(-1) * f_vec_x, (-1) * f_vec_y,f_distance_from_player,object.return_dmg()});
					object.set_cooldown();
				}
				else
					object.reduce_cooldown(fElapsedTime);
			}



			//Can the object be seen?
			float f_eye_x = sinf(my_player.f_angle);
			float f_eye_y = cosf(my_player.f_angle);

			float f_object_angle = atan2f(f_eye_y, f_eye_x) - atan2f(f_vec_y, f_vec_x);
			if (f_object_angle < -3.14159f)
				f_object_angle += 2.0f * 3.14159f;
			if (f_object_angle > 3.14159f)
				f_object_angle -= 2.0f * 3.14159f;
			
			bool b_in_player_view = fabs(f_object_angle) < f_FOV / 2.0f;

			if (b_in_player_view && f_distance_from_player >= 0.5f && f_distance_from_player < f_depth)
			{

				float f_object_ceiling = (float)(ScreenHeight() / 2.0) - ScreenHeight() / ((float)f_distance_from_player);
				float f_object_floor = ScreenHeight() - f_object_ceiling;
				float f_object_height = f_object_floor - f_object_ceiling;
				float f_object_aspect_ratio = (float)object.return_sprite()->nHeight / (float)object.return_sprite()->nWidth;
				float f_object_width = f_object_height / f_object_aspect_ratio;
				float f_middle_of_object = (0.5f * (f_object_angle / (f_FOV / 2.0f)) + 0.5f) * (float)ScreenWidth();

				for (float lx = 0; lx < f_object_width; lx++)
				{
					for (float ly = 0; ly < f_object_height; ly++)
					{
						float f_sample_x = lx / f_object_width;
						float f_sample_y = ly / f_object_height;
						wchar_t c = object.return_sprite()->SampleGlyph(f_sample_x, f_sample_y);
						int n_object_column = (int)(f_middle_of_object + lx - (f_object_width / 2.0f));
						if (n_object_column >= 0 && n_object_column < ScreenWidth())
							if (c != L' ' && f_depth_buffer[n_object_column] >= f_distance_from_player)
							{
								Draw(n_object_column, f_object_ceiling + ly, c, object.return_sprite()->SampleColour(f_sample_x, f_sample_y));
								f_depth_buffer[n_object_column] = f_distance_from_player;
							}
					}
				}


			}
			 
		}
		list_enemies.remove_if([](Enemy& e) {return e.return_disabled(); });

		//Projectiles
		for (Projectile& object : list_projectiles)
		{
			//calculate vector components
			float f_vec_x = object.x_component() - my_player.x_component();
			float f_vec_y = object.y_component() - my_player.y_component();
			float f_distance_from_player = sqrtf(f_vec_x * f_vec_x + f_vec_y * f_vec_y);
			if (object.return_objecttype() == type::e_projectile_player)
			{
						object.deal_closerange_dmg_enemy(list_enemies);
						if (object.return_disabled())
							continue;
				//move Projectile
				object.move(map, fElapsedTime);
			}
			else if (object.return_objecttype() == type::e_projectile_enemy)
			{
				// closerange damage handler
				if (f_distance_from_player < 1.5f)
				{
					{
						my_player.get_damage(object.f_dmg);
						object.disabled = true;
							continue;
					}

				}
				//move Projectile
				object.move(map, fElapsedTime);
			}



			//Can the object be seen?
			float f_eye_x = sinf(my_player.f_angle);
			float f_eye_y = cosf(my_player.f_angle);

			float f_object_angle = atan2f(f_eye_y, f_eye_x) - atan2f(f_vec_y, f_vec_x);
			if (f_object_angle < -3.14159f)
				f_object_angle += 2.0f * 3.14159f;
			if (f_object_angle > 3.14159f)
				f_object_angle -= 2.0f * 3.14159f;

			bool b_in_player_view = fabs(f_object_angle) < f_FOV / 2.0f;

			if (b_in_player_view && f_distance_from_player >= 0.5f && f_distance_from_player < f_depth)
			{

				float f_object_ceiling = (float)(ScreenHeight() / 2.0) - ScreenHeight() / ((float)f_distance_from_player);
				float f_object_floor = ScreenHeight() - f_object_ceiling;
				float f_object_height = f_object_floor - f_object_ceiling;
				float f_object_aspect_ratio = (float)object.return_sprite()->nHeight / (float)object.return_sprite()->nWidth;
				float f_object_width = f_object_height / f_object_aspect_ratio;
				float f_middle_of_object = (0.5f * (f_object_angle / (f_FOV / 2.0f)) + 0.5f) * (float)ScreenWidth();

				for (float lx = 0; lx < f_object_width; lx++)
				{
					for (float ly = 0; ly < f_object_height; ly++)
					{
						float f_sample_x = lx / f_object_width;
						float f_sample_y = ly / f_object_height;
						wchar_t c = object.return_sprite()->SampleGlyph(f_sample_x, f_sample_y);
						int n_object_column = (int)(f_middle_of_object + lx - (f_object_width / 2.0f));
						if (n_object_column >= 0 && n_object_column < ScreenWidth())
							if (c != L' ' && f_depth_buffer[n_object_column] >= f_distance_from_player)
							{
								Draw(n_object_column, f_object_ceiling + ly, c, object.return_sprite()->SampleColour(f_sample_x, f_sample_y));
								f_depth_buffer[n_object_column] = f_distance_from_player;
							}
					}
				}


			}

		}
		list_projectiles.remove_if([](Projectile& o) {return o.return_disabled(); });
		//Pickups
		for (auto& object : list_pickups)
		{
			//calculate vector components
			float f_vec_x = object.x_component() - my_player.x_component();
			float f_vec_y = object.y_component() - my_player.y_component();
			float f_distance_from_player = sqrtf(f_vec_x * f_vec_x + f_vec_y * f_vec_y);
			
			//on pickup Collision
			if (f_distance_from_player < 1.5f)
				{
					{
						object.get_powerup(my_player);
						map[((int)object.x_component() + (int)object.y_component() * n_map_height)] = L'.';
							continue;
					}

				}
				

			//Can the object be seen?
			float f_eye_x = sinf(my_player.f_angle);
			float f_eye_y = cosf(my_player.f_angle);

			float f_object_angle = atan2f(f_eye_y, f_eye_x) - atan2f(f_vec_y, f_vec_x);
			if (f_object_angle < -3.14159f)
				f_object_angle += 2.0f * 3.14159f;
			if (f_object_angle > 3.14159f)
				f_object_angle -= 2.0f * 3.14159f;

			bool b_in_player_view = fabs(f_object_angle) < f_FOV / 2.0f;

			if (b_in_player_view && f_distance_from_player >= 0.5f && f_distance_from_player < f_depth)
			{

				float f_object_ceiling = (float)(ScreenHeight() / 2.0) - ScreenHeight() / ((float)f_distance_from_player);
				float f_object_floor = ScreenHeight() - f_object_ceiling;
				float f_object_height = f_object_floor - f_object_ceiling;
				float f_object_aspect_ratio = (float)object.return_sprite()->nHeight / (float)object.return_sprite()->nWidth;
				float f_object_width = f_object_height / f_object_aspect_ratio;
				float f_middle_of_object = (0.5f * (f_object_angle / (f_FOV / 2.0f)) + 0.5f) * (float)ScreenWidth();

				for (float lx = 0; lx < f_object_width; lx++)
				{
					for (float ly = 0; ly < f_object_height; ly++)
					{
						float f_sample_x = lx / f_object_width;
						float f_sample_y = ly / f_object_height;
						wchar_t c = object.return_sprite()->SampleGlyph(f_sample_x, f_sample_y);
						int n_object_column = (int)(f_middle_of_object + lx - (f_object_width / 2.0f));
						if (n_object_column >= 0 && n_object_column < ScreenWidth())
							if (c != L' ' && f_depth_buffer[n_object_column] >= f_distance_from_player)
							{
								Draw(n_object_column, f_object_ceiling + ly, c, object.return_sprite()->SampleColour(f_sample_x, f_sample_y));
								f_depth_buffer[n_object_column] = f_distance_from_player;
							}
					}
				}


			}

		}
		list_pickups.remove_if([](Pickups &e) {return e.return_disabled(); });
		//Minimap stuff
		

		
		//Display Minimap
		for (int nx = 0; nx < n_map_width; nx++)
			for (int ny = 0; ny < n_map_height; ny++)
			{

					if (map[ny * n_map_height + nx] == '.')
					{
						Draw(nx + 1, ny + 1, map[ny * n_map_height + nx]);
					}
					else if(map[ny * n_map_height + nx] == '#') {
						Draw(nx + 1, ny + 1, map[ny * n_map_height + nx],BG_YELLOW);
					}
					else if (map[ny * n_map_height + nx] == 'H') {
						Draw(nx + 1, ny + 1, map[ny * n_map_height + nx], BG_GREEN);
					}
					else if (map[ny * n_map_height + nx] == 'M') {
						Draw(nx + 1, ny + 1, map[ny * n_map_height + nx], BG_BLUE);
					}
					else if (map[ny * n_map_height + nx] == 'B') {
						Draw(nx + 1, ny + 1, map[ny * n_map_height + nx], BG_DARK_YELLOW);
					}

			
			}
				
		Draw(1 + my_player.x_component(), 1 + my_player.y_component(), L'P',FG_GREEN);
		//Display Enemies on Minimap
		for (auto& object : list_enemies)
		{
			if (object.return_objecttype() == type::e_enemy_runner)
				Draw(1 + object.x_component(), 1 + object.y_component(), L'E',BG_RED);
			else 
				Draw(1 + object.x_component(), 1 + object.y_component(), L'S', BG_DARK_MAGENTA);
		}
		
		//Display Player Information and remaining relics
			DrawString(n_map_width + 4, 1, L"REMAINING BITCOINS: " + to_wstring(my_player.return_coins_left())+L" LIFE POINTS: "+ to_wstring(my_player.n_lifepoints) + L" MAGIC POWER: "+ to_wstring(my_player.n_magic_power));
			if (my_player.b_electrified)
			{
				draw_stunned();
			}
		

		return true;
	}
	}



private:
	
	bool debug; 
	float f_difficulty = 0;
	float f_strength = 0;
	wstring map;
	int n_map_height;
	int n_map_width;
	player my_player;
	float* f_depth_buffer = nullptr;
	enum gamestate { playing, loss, win };
	gamestate e_current_state;
	int game_menu;
	int choice;


	list<Enemy> list_enemies;
	list<Projectile> list_projectiles;
	list<Pickups> list_pickups;

	//const
	const float f_FOV = (3.1451592f / 4.0f);
	const float f_depth = 16.0f;

};


int main()
{
	oasencrawler game;


	game.ConstructConsole(180, 120, 8, 8);
	game.Start();
}

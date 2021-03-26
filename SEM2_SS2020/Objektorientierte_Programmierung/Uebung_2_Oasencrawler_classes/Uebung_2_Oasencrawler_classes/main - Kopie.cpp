#include <iostream>
using namespace std;
#include <Windows.h>
#include <chrono>
#include <math.h>
#include <vector>
#include <algorithm>
#include <utility>
int n_screen_width = 120;
int n_screen_height = 40;
enum orientation { N, O, S, W };

int n_map_height = 16;
int n_map_width = 16;

float fFOV = (3.1451592f / 4.0f);
float f_depth = 16.0f;



struct player
{
	float f_player_x;
	float f_player_y;
	float f_player_a; // angle
};


int main()
{
	player my_player;
	my_player.f_player_x = 8.0f;
	my_player.f_player_y = 8.0f;
	my_player.f_player_a = 0;
	/*****************CONSOLE FPS ENGINE BEGIN*****************/

	//The Engine below would work just fine like this. however, to make it more pretty and draw sprites / objects, I'll use the olcconsoleEngine file from javidx9
	//He created the fps engine to begin with. so it's fine. I understand how it basically operates and how it creates the depth needed. I'll leave the original code in "original.cpp" file.
	//cout method is too slow to print an fps screen to the console. we need direct access to the console buffer

	//Create Screen Buffer Creates a screen in type of wchar_t
	wchar_t* screen = new wchar_t[n_screen_width * n_screen_height];
	HANDLE h_console = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(h_console);
	DWORD dw_bytes_written = 0;


	wstring map;

	map += L"################";
	map += L"#..............#";
	map += L"#..............#";
	map += L"#.........##...#";
	map += L"#.........#....#";
	map += L"#.........#....#";
	map += L"#...##....######";
	map += L"#..............#";
	map += L"#..............#";
	map += L"#..............#";
	map += L"#..............#";
	map += L"#..............#";
	map += L"#..............#";
	map += L"#..............#";
	map += L"#..............#";
	map += L"################";
	//FPS
	auto tp1 = chrono::system_clock::now();
	auto tp2 = chrono::system_clock::now();

	//gameloop
	while (42)
	{
		//Locking into a certain amount of FPS

		tp2 = chrono::system_clock::now();
		chrono::duration<float> elapsed_time = tp2 - tp1;
		tp1 = tp2;
		float f_elapsed_time = elapsed_time.count();
		//handle input
		if (GetAsyncKeyState((unsigned short)'A') & 0x8000)
			my_player.f_player_a -= 1 * f_elapsed_time;
		if (GetAsyncKeyState((unsigned short)'D') & 0x8000)
			my_player.f_player_a += 1 * f_elapsed_time;
		if (GetAsyncKeyState((unsigned short)'W') & 0x8000)
		{
			my_player.f_player_x += sinf(my_player.f_player_a) * 5.0f * f_elapsed_time;
			my_player.f_player_y += cosf(my_player.f_player_a) * 5.0f * f_elapsed_time;
			if (map[(int)my_player.f_player_y * n_map_width + my_player.f_player_x] == '#')
			{
				my_player.f_player_x -= sinf(my_player.f_player_a) * 5.0f * f_elapsed_time;
				my_player.f_player_y -= cosf(my_player.f_player_a) * 5.0f * f_elapsed_time;
			}
		}
		if (GetAsyncKeyState((unsigned short)'S') & 0x8000)
		{
			my_player.f_player_x -= sinf(my_player.f_player_a) * 5.0f * f_elapsed_time;
			my_player.f_player_y -= cosf(my_player.f_player_a) * 5.0f * f_elapsed_time;
			if (map[(int)my_player.f_player_y * n_map_width + my_player.f_player_x] == '#')
			{
				my_player.f_player_x += sinf(my_player.f_player_a) * 5.0f * f_elapsed_time;
				my_player.f_player_y += cosf(my_player.f_player_a) * 5.0f * f_elapsed_time;
			}
		}
		//Strafing
		if (GetAsyncKeyState((unsigned short)'Q') & 0x8000)
		{
			my_player.f_player_x += -cosf(my_player.f_player_a) * 5.0f * f_elapsed_time;
			my_player.f_player_y += sinf(my_player.f_player_a) * 5.0f * f_elapsed_time;
			if (map[(int)my_player.f_player_y * n_map_width + my_player.f_player_x] == '#')
			{
				my_player.f_player_x -= -cosf(my_player.f_player_a) * 5.0f * f_elapsed_time;
				my_player.f_player_y -= sinf(my_player.f_player_a) * 5.0f * f_elapsed_time;
			}
		}
		if (GetAsyncKeyState((unsigned short)'E') & 0x8000)
		{
			my_player.f_player_x += cosf(my_player.f_player_a) * 5.0f * f_elapsed_time;
			my_player.f_player_y += -sinf(my_player.f_player_a) * 5.0f * f_elapsed_time;
			if (map[(int)my_player.f_player_y * n_map_width + my_player.f_player_x] == '#')
			{
				my_player.f_player_x -= cosf(my_player.f_player_a) * 5.0f * f_elapsed_time;
				my_player.f_player_y -= -sinf(my_player.f_player_a) * 5.0f * f_elapsed_time;
			}
		}



		for (int x = 0; x < n_screen_width; x++)
		{
			//each col is a ray. The angle of every ray is calculated this way
			float ray_angle = (my_player.f_player_a - fFOV / 2.0f) + ((float)x / (float)n_screen_width * fFOV);

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
			int n_ceiling = (float)(n_screen_height / 2.0f) - (n_screen_height / (float)f_distance_to_wall);
			int n_floor = n_screen_height - n_ceiling;

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


			for (int y = 0; y < n_screen_height; y++)
			{
				if (y <= n_ceiling)
					screen[y * n_screen_width + x] = ' ';
				else if (y > n_ceiling && y <= n_floor)
					screen[y * n_screen_width + x] = n_shade_wall;
				else
				{
					float b = 1.0f - (((float)y - n_screen_height / 2.0f) / ((float)n_screen_height / 2.0f));
					if (b < 0.25) n_shade_floor = '#';
					else if (b < 0.5) n_shade_floor = 'x';
					else if (b < 0.75) n_shade_floor = '.';
					else if (b < 0.9) n_shade_floor = '-';
					else n_shade_floor = ' ';
					screen[y * n_screen_width + x] = n_shade_floor;

				}

			}
		}
		swprintf_s(screen, 41, L"X=%3.2f, Y=%3.2f, A= %3.2f FPS = %3.2f", my_player.f_player_x, my_player.f_player_y, my_player.f_player_a, 1.0f / f_elapsed_time);
		for (int nx = 0; nx < n_map_width; nx++)
			for (int ny = 0; ny < n_map_height; ny++)
			{
				screen[(ny + 1) * n_screen_width + nx] = map[ny * n_map_height + nx];
			}
		screen[((int)my_player.f_player_y + 1) * n_screen_width + (int)my_player.f_player_x] = 'P';
		screen[n_screen_width * n_screen_height - 1] = '\0';
		WriteConsoleOutputCharacter(h_console, screen, n_screen_height * n_screen_width, { 0,0 }, &dw_bytes_written);
	}

	return 0;
}
/*
void generate_world()
{

		Leere Felder: 40%
		Gefahren: 40%
		"Brunnen": 10%
		Relikte : 10%
		aaa des is a dungeon crawler lel

}


void print_loss_screen()
{
	wstring lose_text;
	lose_text += L"$$\\     $$\\  $$$$$$\\  $$\\   $$\\       $$\\       $$$$$$\\   $$$$$$\\  $$$$$$$$\\ $$\\ ";
	lose_text += L"\\$$\\   $$  |$$  __$$\\ $$ |  $$ |      $$ |     $$  __$$\\ $$  __$$\\ $$  _____|$$ |";
	lose_text += L" \\$$\\ $$  / $$ /  $$ |$$ |  $$ |      $$ |     $$ /  $$ |$$ /  \\__|$$ |      $$ |";
	lose_text += L"  \\$$$$  /  $$ |  $$ |$$ |  $$ |      $$ |     $$ |  $$ |\\$$$$$$\\  $$$$$\\    $$ |";
	lose_text += L"   \\$$  /   $$ |  $$ |$$ |  $$ |      $$ |     $$ |  $$ | \\____$$\\ $$  __|   \\__|";
	lose_text += L"	$$ |    $$ |  $$ |$$ |  $$ |      $$ |     $$ |  $$ |$$\\   $$ |$$ |          ";
	lose_text += L"    $$ |     $$$$$$  |\\$$$$$$  |      $$$$$$$$\\ $$$$$$  |\\$$$$$$  |$$$$$$$$\\ $$\\ ";
	lose_text += L"    \\__|     \\______/  \\______/       \\________|\\______/  \\______/ \\________|\\__|";


}*/
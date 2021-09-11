#include <iostream>
#include <raylib.h>
#include <fstream>
using namespace std;
using std::cout; using std::cerr;
using std::endl; using std::string;
using std::ifstream;
int main()
{
	bool titlescreen = true;
	bool intro = true;
	std::string name;
	const int screenWidth = 800;
	const int screenHeight = 450;
	InitWindow(screenWidth, screenHeight, "Bad Ball Hitler (60 Target FPS)");
	InitAudioDevice();              // Initialize audio device
	Music music = LoadMusicStream("theme.mp3");
	Sound fxWav = LoadSound("border.wav");
	Sound fxlvlup = LoadSound("AUGUGHHGG.ogg");
	Sound fxlvldown = LoadSound("kraisofv.ogg");
	PlayMusicStream(music);
	ifstream my_file1("pretty pls.txt");
	if (!my_file1.is_open())
	{
		my_file1.open("pretty pls.txt");
		my_file1.close();
		ofstream mafile("pretty pls.txt");;
		mafile << 0;
	}
	ifstream myfile("pretty pls.txt");;
	int priorhs;
	myfile >> priorhs;
	int HS = priorhs;
	myfile.close();
	int score = 0;
	int fs = 0;
start:
	int ballb = 10;
	ofstream my_file("pretty pls.txt");
	if (score > HS)
	{
		my_file << score;
		my_file.close();
		ifstream myfile("pretty pls.txt");;
		myfile >> HS;
		myfile.close();
	}
	score = 0;
	int highscoretest = 0;
	float i;
	int o;
	bool ballbad = true;						//ball bad
	bool ball2bad = true;						//ball bad2
	bool ball3bad = true;						//ball bad3
	bool circle = 1;
	bool targetx = false;						//bad
	bool targety = false;						//bad
	bool target2x = false;						//bad2
	bool target2y = false;						//bad2
	bool target3x = false;						//bad3
	bool target3y = false;						//bad3
	bool collision = false;						//collision		
	Rectangle boxCollision = { 0 };				//collision
	Rectangle badboxcollision = { 0 };			//badcollision2
	Rectangle bad3boxcollision = { 0 };			//badcollision3
	bool badcollision = false;					//badcollision2
	bool bad3collision = false;					//badcollision3
	Rectangle bad2boxcollision = { 0 };			//badcollision2
	bool bad2collision = false;					//badcollision2
	float PositionX;
	float PositionY;
	Vector2 target = { GetRandomValue(690, 100), rand() % 330 + 100 };									//bad ball movement
	Vector2 target2 = { GetRandomValue(690, 100), rand() % 330 + 100 };									//bad 2 ball movement
	Vector2 target3 = { GetRandomValue(690, 100), rand() % 330 + 100 };									//bad 3 ball movement
	Vector2 ballPosition = { (float)screenWidth / 2, (float)screenHeight / 2 };							//ball spawn
	Vector2 hitlerball = { 100, 100 };																	//bad ball
	Vector2 eichmann = { 100, 100 };																	//bad 2 ball
	Vector2 hess = { 100, 100 };																		//bad 3 ball
	Vector2 ballPosition2 = { PositionX = rand() % 690 + 100, PositionY = rand() % 330 + 100 };			//ball eat spawn
	SetTargetFPS(60);																																	//build 2 versions (60 and 120 fps)  60 fps version 3 balls 120 = 2 balls
	float size = 5; //playable ball size
	Texture2D texture = LoadTexture("logo.png");
	while (!WindowShouldClose())
	{
		UpdateMusicStream(music);
		if (circle)
		{
			if (score == 9)
			{
				ballPosition2.x = 700;		//new position for eaten ball
				ballPosition2.y = 400;		//new position for eaten ball
			}
			else if (score == 19)
			{
				ballPosition2.x = 700;		//new position for eaten ball
				ballPosition2.y = 400;		//new position for eaten ball
			}
			else
			{
				ballPosition2.x = GetRandomValue(690, 100); //new position for eaten ball
				ballPosition2.y = rand() % 330 + 100;		//new position for eaten ball
			}
		}
		Rectangle boxA = { ballPosition.x, ballPosition.y, size * 2, size * 2};			//hitbox?  //collision
		Rectangle boxB = { ballPosition2.x, ballPosition2.y, size, size };				//hitbox?  //collision
		Rectangle boxC = { hitlerball.x, hitlerball.y, size, size };					//bad ball
		Rectangle boxD = { eichmann.x, eichmann.y, size + 10, size + 10 };				//bad 2 ball
		Rectangle boxE = { hess.x, hess.y, size + 20, size + 20 };						//bad 3 ball
		if (IsKeyDown(KEY_RIGHT)) ballPosition.x += 5.0f;				//controls
		else if (IsKeyDown(KEY_D)) ballPosition.x += 5.0f;
		if (IsKeyDown(KEY_LEFT)) ballPosition.x -= 5.0f;				//controls
		else if (IsKeyDown(KEY_A)) ballPosition.x -= 5.0f;
		if (IsKeyDown(KEY_UP)) ballPosition.y -= 5.0f;					//controls
		else if (IsKeyDown(KEY_W)) ballPosition.y -= 5.0f;
		if (IsKeyDown(KEY_DOWN)) ballPosition.y += 5.0f;				//controls
		else if (IsKeyDown(KEY_S)) ballPosition.y += 5.0f;
		if (IsKeyReleased(KEY_F))										//check if fps shoulf be displayed
		{
			if (fs == 0)
			{
				fs = fs + 1;
			}
			else if (fs == 1)
			{
				fs = fs - 1;
			}
		}
		if (ballbad)													//bad
		{
			Vector2 target = { GetRandomValue(690, 100), rand() % 330 + 100 };
			ballbad = false;
		}
		if (targetx == false)
		{
			if (hitlerball.x > target.x)
			{
				hitlerball.x -= 1; //1 is the speed
			}
			else if (hitlerball.x < target.x)
			{
				hitlerball.x += 1; //1 is the speed
			}
			else if (hitlerball.x == target.x)
			{
				targetx = true;
			}
		}
		if (targety == false)
		{
			if (hitlerball.y > target.y)
			{
				hitlerball.y -= 1; //1 is the speed
			}
			else if (hitlerball.y < target.y)
			{
				hitlerball.y += 1; //1 is the speed
			}
			else if (hitlerball.y == target.y)
			{
				targety = true;
			}
		}
		if (targetx || targety)
		{
			//Vector2 target = { GetRandomValue(690, 100), rand() % 330 + 100 };
			target.x = GetRandomValue(690, 100);
			target.y = rand() % 330 + 100;
			ballbad = true;
			targetx = false;
			targety = false;
		}
		if (score >= 10)
		{
			if (ball2bad)													//bad
			{
				if (score == 10)
				{
					Vector2 target2 = { 0, 0 };
				}
				else
				{
					Vector2 target2 = { GetRandomValue(690, 100), rand() % 330 + 100 };
				}
				ball2bad = false;
			}
			if (target2x == false)
			{
				if (eichmann.x > target2.x)
				{
					eichmann.x -= 1; //1 is the speed
				}
				else if (eichmann.x < target2.x)
				{
					eichmann.x += 1; //1 is the speed
				}
				else if (eichmann.x == target2.x)
				{
					target2x = true;
				}
			}
			if (target2y == false)
			{
				if (eichmann.y > target2.y)
				{
					eichmann.y -= 1; //1 is the speed
				}
				else if (eichmann.y < target2.y)
				{
					eichmann.y += 1; //1 is the speed
				}
				else if (eichmann.y == target2.y)
				{
					target2y = true;
				}
			}
			if (target2x || target2y)
			{
				//Vector2 target = { GetRandomValue(690, 100), rand() % 330 + 100 };
				target2.x = GetRandomValue(690, 100);
				target2.y = rand() % 330 + 100;
				ball2bad = true;
				target2x = false;
				target2y = false;
			}
		}
		if (score >= 20)
		{
			if (ball3bad)													//bad
			{
				if (score == 20)
				{
					Vector2 target3 = { 0, 0 };
				}
				else
				{
					Vector2 target3 = { GetRandomValue(690, 100), rand() % 330 + 100 };
				}
				ball3bad = false;
			}
			if (target3x == false)
			{
				if (hess.x > target3.x)
				{
					hess.x -= 1; //1 is the speed
				}
				else if (hess.x < target3.x)
				{
					hess.x += 1; //1 is the speed
				}
				else if (hess.x == target3.x)
				{
					target3x = true;
				}
			}
			if (target3y == false)
			{
				if (hess.y > target3.y)
				{
					hess.y -= 1; //1 is the speed
				}
				else if (hess.y < target3.y)
				{
					hess.y += 1; //1 is the speed
				}
				else if (hess.y == target3.y)
				{
					target3y = true;
				}
			}
			if (target3x || target3y)
			{
				//Vector2 target = { GetRandomValue(690, 100), rand() % 330 + 100 };
				target3.x = GetRandomValue(690, 100);
				target3.y = rand() % 330 + 100;
				ball3bad = true;
				target3x = false;
				target3y = false;
			}
		} 
		collision = CheckCollisionRecs(boxA, boxB);							//collision
		if (collision) boxCollision = GetCollisionRec(boxA, boxB);			//collision
		badcollision = CheckCollisionRecs(boxA, boxC);						//badcollision
		if (badcollision) badboxcollision = GetCollisionRec(boxA, boxC);	//badcollision
		if (score >= 10)
		{
			bad2collision = CheckCollisionRecs(boxA, boxD);						//badcollision2
			if (bad2collision) bad2boxcollision = GetCollisionRec(boxA, boxD);	//badcollision2
		}
		if (score >= 20)
		{
			bad3collision = CheckCollisionRecs(boxA, boxE);						//badcollision
			if (bad3collision) bad3boxcollision = GetCollisionRec(boxA, boxE);	//badcollision
		}
		int cringe = 0;
		int yoinks = 0;
		BeginDrawing();
		ClearBackground(RAYWHITE);
		while (titlescreen)
		{
			cringe++;
			if (cringe == 300)
			{
				UnloadTexture(texture);
				titlescreen = false;
				break;
			}
			BeginDrawing();
			DrawTexture(texture, screenWidth / 2 - texture.width / 2, screenHeight / 2 - texture.height / 2,  WHITE);
			EndDrawing();
		}
		while (intro)
		{
			if (yoinks == 1)
			{
				UnloadTexture(texture);
				intro = false;
				break;
			}
			BeginDrawing();
			DrawTexture(texture, screenWidth / 2 - texture.width / 2, screenHeight / 2 - texture.height / 2, WHITE);
			DrawText(TextFormat("W"), 100, 50, 100, LIGHTGRAY);
			DrawText(TextFormat("S"), 105, 130, 100, LIGHTGRAY);
			DrawText(TextFormat("A"), 30, 130, 100, LIGHTGRAY);
			DrawText(TextFormat("D"), 180, 130, 100, LIGHTGRAY);
			DrawText(TextFormat("U"), 600, 50, 100, LIGHTGRAY);
			DrawText(TextFormat("D"), 605, 130, 100, LIGHTGRAY);
			DrawText(TextFormat("L"), 530, 130, 100, LIGHTGRAY);
			DrawText(TextFormat("R"), 680, 130, 100, LIGHTGRAY);
			DrawText(TextFormat("PRESS SPACE TO PLAY"), screenWidth / 2 - 125, screenHeight / 2 + 100, 20, LIGHTGRAY);
			DrawText(TextFormat("F"), screenWidth / 2, screenHeight / 2 + 150, 20, LIGHTGRAY);
			DrawText(TextFormat("FOR FPS"), screenWidth / 2 - 42, screenHeight / 2 + 170, 20, LIGHTGRAY);
			if (IsKeyPressed(KEY_SPACE)) yoinks = 1;
			EndDrawing();
		}
		int fps = GetFPS();
		if (fs == 1)
		{
			DrawText(TextFormat("%02i", fps), screenWidth / 2 - 1, 430, 20, LIGHTGRAY);	//displays fps
		}
		if (ballPosition.x + size >= 800) 					//world boarder check, if true, equal opposite force as movement
		{
			ballPosition.x -= 10.0f;
			PlaySound(fxWav);
		}
		if (ballPosition.x - size <= 0) 					//world boarder check, if true, equal opposite force as movement
		{
			ballPosition.x += 10.0f;
			PlaySound(fxWav);
		}
		if (ballPosition.y + size >= 450)					//world boarder check, if true, equal opposite force as movement
		{
			ballPosition.y -= 10.0f;
			PlaySound(fxWav);
		}
		if (ballPosition.y - size <= 0)					//world boarder check, if true, equal opposite force as movement
		{
			ballPosition.y += 10.0f;
			PlaySound(fxWav);
		}
		DrawText(TextFormat("%03i", HS), screenWidth / 2 - 10, 0, 20, LIGHTGRAY);
		DrawText(TextFormat("%03i", score), screenWidth / 2 - 160, screenHeight / 2 - 100, 200, LIGHTGRAY);
		DrawCircleV(ballPosition, size, MAROON);			//draw playable ball
		DrawCircleV(hitlerball, size, BLACK);
		if (score >= 10)
		{
			DrawCircleV(eichmann, size + 10, BLACK);
		}
		if (score >= 20)
		{
			DrawCircleV(hess, size + 20, BLACK);
		}
		DrawCircleV(ballPosition2, ballb, BLUE);			//draw edible ball
		//DrawRectangle(ballPosition.x, ballPosition.y, size, size, MAROON);
		//DrawRectangle(ballPosition2.x, ballPosition2.y, 10, 10, BLUE);
		if (circle)		//prevents new coordinates for edible ball
		{
			circle = 0;
		}
		if (collision)
		{
			if (size != 30)								//and if belopw 10
			{
				size = size + 5;						//increase size untiil 10 times ball eaten
				highscoretest = highscoretest + 1;
			}
			if (highscoretest != 0)
			{
				score = score + 1;
			}
			PlaySound(fxlvlup);
			circle = 1;									//allow for new coordinates if ball eaten
		}
		if (badcollision)
		{
			PlaySound(fxlvldown);
			cout << "copyright PizzaWaifu\n";
			goto start;
		}
		if (bad2collision)
		{
			PlaySound(fxlvldown);
			cout << "copyright pizzuswaifu\n";
			goto start;
		}
		if (bad3collision)
		{
			PlaySound(fxlvldown);
			goto start;
		}
		EndDrawing();
	}
	UnloadMusicStream(music);   // Unload music stream buffers from RAM
	UnloadSound(fxWav);
	CloseAudioDevice();
	CloseWindow();
	ofstream mafile("pretty pls.txt");;
	mafile << HS;
	mafile.close();
	return 0;
}
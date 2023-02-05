// raylib [core] example - 3d camera first person
// Copyright (c) 2015-2022 Ramon Santamaria (@raysan5)

#include <raylib.h>
#include <pthread.h> // POSIX style threads management

#include <cube.h>
#include <cube_l.h>

#include <rectangle.h>
#include <rectangle_l.h>

#include <plane.h>
#include <text_area.h>

#include <scene.h>

int screenWidth = 800;
int screenHeight = 450;
const char *title = "raylib [core] example - 3d camera first person";

Camera camera = { 0 };

Color background_color;

struct list_cube *list_cube;
struct list_cube_l *list_cube_l;

struct list_rectangle *list_rectangle;
struct list_rectangle_l *list_rectangle_l;

struct list_plane *list_plane;
struct list_text_area *list_text_area;

// LATER 20230205 Do this configuration in Fexl.
void configure_scene(void)
	{
	InitWindow(screenWidth, screenHeight, title);

	// Define the camera to look into our 3d world (position, target, up vector)
	camera.position = (Vector3){ 4.0f, 2.0f, 4.0f };
	camera.target = (Vector3){ 0.0f, 1.8f, 0.0f };
	camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
	camera.fovy = 60.0f;
	camera.projection = CAMERA_PERSPECTIVE;

	// Set a first person camera mode
	SetCameraMode(camera, CAMERA_FIRST_PERSON);

	SetTargetFPS(60); // Set our game to run at 60 frames-per-second

	background_color = RAYWHITE;

	push_text_area(&list_text_area,
		"First person camera default controls:", 20, 20, 10, BLACK);
	push_text_area(&list_text_area,
		"- Move with keys: W, A, S, D", 40, 40, 10, DARKGRAY);
	push_text_area(&list_text_area,
		"- Mouse move to look around", 40, 60, 10, DARKGRAY);

	push_rectangle_l(&list_rectangle_l,
		10, 10, 220, 70, Fade(SKYBLUE, 0.5f), BLUE);

	if (0)
	{
	push_rectangle(&list_rectangle,
		100, 80, 80, 80, RED);
	}

	// Draw ground
	push_plane(&list_plane,
		(Vector3){ 0.0f, 0.0f, 0.0f },
		(Vector2){ 32.0f, 32.0f },
		LIGHTGRAY
		);

	// Draw a blue wall
	push_cube(&list_cube,
		(Vector3){ -16.0f, 2.5f, 0.0f },
		1.0f, 5.0f, 32.0f, BLUE
		);

	// Draw a green wall
	push_cube(&list_cube,
		(Vector3){ 16.0f, 2.5f, 0.0f },
		1.0f, 5.0f, 32.0f, LIME
		);

	// Draw a yellow wall
	push_cube(&list_cube,
		(Vector3){ 0.0f, 2.5f, 16.0f },
		32.0f, 5.0f, 1.0f, GOLD
		);

	{
	// Generate some random columns.
	for (int i = 0; i < 20; i++)
		{
		float height = (float)GetRandomValue(1, 12);

		Vector3 position = (Vector3)
			{
			(float)GetRandomValue(-15, 15),
			height/2.0f,
			(float)GetRandomValue(-15, 15)
			};

		Color color = (Color)
			{
			GetRandomValue(20, 255),
			GetRandomValue(10, 55),
			30, 255
			};

		push_cube_l(&list_cube_l,
			position, 2.0f, height, 2.0f,
			color, MAROON
			);
		}
	}
	}

void run_scene(void)
	{
	list_cube = 0;
	list_cube_l = 0;

	list_rectangle = 0;
	list_rectangle_l = 0;

	list_plane = 0;
	list_text_area = 0;

	configure_scene();

	while (!WindowShouldClose()) // Detect window close button or ESC key
		{
		UpdateCamera(&camera);
		BeginDrawing();

		ClearBackground(background_color);

		// Draw the 3D objects
		{
		BeginMode3D(camera);

		draw_list_cube(list_cube);
		draw_list_cube_l(list_cube_l);
		draw_list_plane(list_plane);

		EndMode3D();
		}

		// Draw the 2D objects
		{
		draw_list_rectangle(list_rectangle);
		draw_list_rectangle_l(list_rectangle_l);
		draw_list_text_area(list_text_area);
		}

		EndDrawing();
		}

	free_list_cube(list_cube);
	free_list_cube_l(list_cube_l);

	free_list_rectangle(list_rectangle);
	free_list_rectangle_l(list_rectangle_l);

	free_list_plane(list_plane);
	free_list_text_area(list_text_area);

	CloseWindow(); // Close window and OpenGL context
	}

#ifndef HEADER_H
#define HEADER_H

#include <SDL2/SDL.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdio.h>
#include <stdbool.h>
#include "upng.h"


/* Constants */

#define PI 3.14159265
#define TWO_PI 6.28318530

#define TILE_SIZE 64

#define MINIMAP_SCALE_FACTOR 0.25

#define SCREEN_WIDTH (MAP_NUM_COLS * TILE_SIZE)
#define SCREEN_HEIGHT (MAP_NUM_ROWS * TILE_SIZE)

#define FOV_ANGLE (60 * (PI / 180))

#define NUM_RAYS SCREEN_WIDTH

#define PROJ_PLANE ((SCREEN_WIDTH / 2) / tan(FOV_ANGLE / 2))

#define FPS 30
#define FRAME_TIME_LENGTH (1000 / FPS)

#define MAP_NUM_ROWS 13
#define MAP_NUM_COLS 20

#define NUM_TEXTURES 8

typedef uint32_t color_t;

/* Process Inputs */
void handleInput(void);
extern bool GameRunning;

/* Functions-variables-structs to draw */

bool initializeWindow(void);
void destroyWindow(void);
void clearColorBuffer(color_t color);
void render_game(void);
void renderColorBuffer(void);
void drawPixel(int x, int y, color_t color);
void drawRect(int x, int y, int width, int height, color_t color);
void drawLine(int x0, int y0, int x1, int y1, color_t color);

/* Functions-variables-structs to map */
bool DetectCollision(float x, float y);
bool isInsideMap(float x, float y);
void renderMap(void);
int getMapValue(int row, int col);

/* Functions-variables-structs to player */

/**
 * struct player_s - struct for the textures
 * @x: x coordinates
 * @y: y coordinates
 * @width: players width
 * @height: players height
 * @turnDirection: Turn Directions
 * @walkDirection: Walk Directions
 * @rotationAngle: player rotation angles
 * @walkSpeed: walking speed
 * @turnSpeed: turning speed
 */

typedef struct player_s
{
	float x;
	float y;
	float width;
	float height;
	int turnDirection;
	int walkDirection;
	float rotationAngle;
	float walkSpeed;
	float turnSpeed;
} player_t;

extern player_t player;

void movePlayer(float DeltaTime);
void renderPlayer(void);

/* Functions-variables-structs for ray */

/**
 * struct ray_s - struct for the textures
 * @rayAngle: ray angles
 * @wallHitX: wall hit x coordinates
 * @wallHitY: wall hit x coordinates
 * @distance: ditance to the walls
 * @wasHitVertical: verify hit verticals
 * @wallHitContent: wall hit contents
 */

typedef struct ray_s
{
	float rayAngle;
	float wallHitX;
	float wallHitY;
	float distance;
	bool wasHitVertical;
	int wallHitContent;
} ray_t;

extern ray_t rays[NUM_RAYS];

float distanceBetweenPoints(float x1, float y1, float x2, float y2);
bool isRayFacingUp(float angle);
bool isRayFacingDown(float angle);
bool isRayFacingLeft(float angle);
bool isRayFacingRight(float angle);
void castAllRays(void);
void castRay(float rayAngle, int stripId);
void renderRays(void);
void horzIntersection(float rayAngle);
void vertIntersection(float rayAngle);

/* Functions-variables-structs for textures */

/**
 * struct texture_s - struct for the textures
 * @width: texture widths
 * @height: texture heights
 * @texture_buffer: pointer to texture buffers
 * @upngTexture: pointer to upng buffers
 *
 */

typedef struct texture_s
{
	int width;
	int height;
	color_t *texture_buffer;
	upng_t *upngTexture;
} texture_t;

texture_t wallTextures[NUM_TEXTURES];

void WallTexturesready(void);
void freeWallTextures(void);

/* Functions-variables-structs for walls */

void renderWall(void);

#endif /*HEADER_H*/

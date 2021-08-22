#ifndef __BACKGROUND_H__
#define __BACKGROUND_H__

#include <SDL.h>
#include <SDL_image.h>
#include"sprite.h"
#include"vector.h"
#include "simple_logger.h"
#include "entity.h"

/**
*
*@brief The blueprint for a background object. Representing the top section of the screen in a mode 7 game. Scrolls left to right
*@param char the reference count of the specific background image
*@param Sprite_M the refrecnce to a Sprite object to be used
*/

typedef struct Background_M

{
	char bg_name[24];
	Entity_S* sky;
	void(*think) (struct Background_M* self); /**logic*<*/
	void(*update) (struct Background_M* self); /**physics*<*/

}Background_M;

/**
*
*@brief allocates a space in the master Sprite-List for a sprite of a given filename (PNG)? or BMP?? Also gives the BGobject a specific name
*@param filename: the name of the background associated with the entity
*@param SizeX: the final width of the background when it's drawn
*@param SizeY: the final height of the background when it's drawn
*@return Background_M: returns a Background_M object so that it can be saved for later. This is necessary to use backgroundDraw()
*/
Background_M backgroundLoad(const char* filename, int SizeX, int SizeY, Vector2D destpostion);

/**
*
*@brief frees the background object sprite

*/



void backgroundFree(Background_M* bg);

/**
*
*@brief draws the background object sprite

*/

//void backgroundDraw(Background_M* bg, SDL_Renderer* renderer, Vector2D destPosition, Vector2D imgPosition);//should this be a pinter function? or called by another pinter function?

void BGthink(Background_M* self);

void BGUpdate(Background_M* self);
#endif
/***************************************************************************
 *   Copyright (C) 2013 by James Holodnak                                  *
 *   jamesholodnak@gmail.com                                               *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

//hacked in sdl keys only!
#include <SDL/SDL.h>
#include "joypad0.h"
#include "system/input.h"

static u32 data;
static u8 counter;

static u8 read0()
{
	return(((data >> counter++) & 1) | 0x40);
}

static void strobe()
{
	data = 0;
	if(joykeys[SDLK_z]) data |= INPUT_A;
	if(joykeys[SDLK_x]) data |= INPUT_B;
	if(joykeys[SDLK_a]) data |= INPUT_SELECT;
	if(joykeys[SDLK_s]) data |= INPUT_START;
	if(joykeys[SDLK_UP]) data |= INPUT_UP;
	if(joykeys[SDLK_DOWN]) data |= INPUT_DOWN;
	if(joykeys[SDLK_LEFT]) data |= INPUT_LEFT;
	if(joykeys[SDLK_RIGHT]) data |= INPUT_RIGHT;
	counter = 0;
}

inputdev_t dev_joypad0 = {read0,0,strobe,0};

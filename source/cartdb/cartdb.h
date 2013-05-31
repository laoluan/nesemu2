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

#ifndef __cartdb_h__
#define __cartdb_h__

#include "types.h"

typedef struct cartinfo_s {
	struct cartinfo_s *next;
	char	*system;
	u32	crc;
	char	*sha1;
	int	dump;
	char	*dumper,*datedumped;
} cartinfo_t;

typedef struct game_s {
	struct game_s *next;
	struct cartinfo_t *child;
	struct {
		char	*name,*altname;
		char	*cls,*catalog,*publisher,*developer;
		char	*region;
		int	players;
		char	*date;
	} info;
} game_t;

typedef struct cartdb_s {
	char *version;
	char *author;
	char *timestamp;
} cartdb_t;

#endif

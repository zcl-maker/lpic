/*
   This file is part of LPIC++, a particle-in-cell code for
   simulating the interaction of laser light with plasma.

   Copyright (C) 1994-1997 Roland Lichters

   LPIC++ is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public License
   as published by the Free Software Foundation; either version 2
   of the License, or (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
*/

#ifndef PARALLEL_OR_PLAIN_H
#define PARALLEL_OR_PLAIN_H

// Variable LPIC_ENABLE_PARALLEL is set during configuration of the package
// If configure is called with option --enable-parallel
// it searches for the pvm header file and tries compiling a one-line
// program with a call to pvm_parent().
// If successful, LPIC_ENABLE_PARALLEL is defined in config.h.
#include <config.h>

#ifdef LPIC_PARALLEL
#define PARALLEL
//#define SLOW
#endif

#endif
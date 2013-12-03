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

//////////////////////////////////////////////////////////////////////////////////////////
//
// header file, input parameters to lpi.C
//
// last change: June 8 1997
//
//////////////////////////////////////////////////////////////////////////////////////////

#ifndef PARAMETER_H
#define PARAMETER_H

#include <common.h>
#include <error.h>
#include <fstream.h>
#include <iomanip.h>
#include <string.h>
#include <matrix.h>
#include <math.h>
#include <readfile.h>

class parameter  {

private:
  void      adjust_angle_write_steps( void );
  void      save( void );
  readfile  rf;
  int       Q_restart;

public:

  char      *my_name;                // command line input
  char      *input_file_name;        // command line input or default value
  int       domain_number;           // command line input or default value
  int       n_domains;               // namelist input
  char      *path;                   // namelist input
  char      *errname;                // file name for output of errors and comments
  char      *outname;                // file name for output of input

  int       nsp;                     // initial number of particle species
  int       spl;                     // number of cells per laser wave length
  int       spp;                     // number of time steps per period
  double    angle, Beta, Gamma;      // Lorentz transformation

  parameter(int argc, char **argv);

};

//////////////////////////////////////////////////////////////////////////////////////////
#endif






/*
 * OctoMap - An Efficient Probabilistic 3D Mapping Framework Based on Octrees
 * http://octomap.github.com/
 *
 * Copyright (c) 2009-2013, K.M. Wurm and A. Hornung, University of Freiburg
 * All rights reserved.
 * License (octovis): GNU GPL v2
 * http://www.gnu.org/licenses/old-licenses/gpl-2.0.txt
 *
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#include <QtGui>
#include <QApplication>
#include <octovis/ViewerGui.h>

int main(int argc, char *argv[]) {

  std::string filename = "";
  int sensor_model = 0;
  if (argc == 2) {
    filename = std::string(argv[1]);
  }
  else if (argc == 3) {
    filename = std::string(argv[1]);
    sensor_model = atof(argv[2]);
  }

  QApplication app(argc, argv);

  octomap::ViewerGui gui(filename);
  gui.show(); 
  return app.exec();
}

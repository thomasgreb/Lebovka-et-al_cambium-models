/*
 *
 *  This file is part of the Virtual Leaf.
 *
 *  VirtualLeaf is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  VirtualLeaf is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with the Virtual Leaf.  If not, see <http://www.gnu.org/licenses/>.
 *
 *  Copyright 2010 Roeland Merks.
 *
 */

#include <string>
#include <QString>
#include <QStringList>

static const std::string _module_id("$Id: miscq.cpp,v 15d600891648 2010/06/24 13:22:58 michael $");

// Returns the extension of a filename
QString getExtension(const QString fn)
{
  // split on dots
  QStringList parts = fn.split(".");

  // return last part, this should be the extension
  return QString(parts.last());
}

/* finis */

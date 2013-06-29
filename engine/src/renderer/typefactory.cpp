/* This source file is a part of the GePhex Project.

 Copyright (C) 2001-2004

 Georg Seidel <georg@gephex.org> 
 Martin Bayer <martin@gephex.org> 
 Phillip Promesberger <coma@gephex.org>
 
 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 2
 of the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.*/

#include "typefactory.h"
//#include "itype.h"

#include "interfaces/itypeclass.h"

#include <stdexcept>

namespace renderer
{

TypeFactory::TypeFactory() : typeClasses()
{
}

TypeFactory::~TypeFactory()
{
}

IType* TypeFactory::buildNew(int id) const
{
	ClassMap::const_iterator i = typeClasses.find(id);
	if (i == typeClasses.end())
	{
		throw std::runtime_error("unknown type ID");
	}

	return i->second->buildInstance();
}

void TypeFactory::registerTypeClass(int id, const ITypeClass& typeClass)
{
  ClassMap::const_iterator i = typeClasses.find(id);
  if (i != typeClasses.end())
    {
      throw std::runtime_error("type ID already exists");
    }
	
  typeClasses[id] = &typeClass;
}

} // end of namespace
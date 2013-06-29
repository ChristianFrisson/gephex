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

#ifndef INCLUDED_MIDI_IN_DRIVER_H
#define INCLUDED_MIDI_IN_DRIVER_H


class MidiInDriver
{
public:
  typedef int device_id_t;

  //static const device_id_t DEFAULT_DEVICE = 0;
  
  virtual ~MidiInDriver() {}
  virtual void open(device_id_t device) = 0;

  virtual void close() = 0;

  /**
   * Returns number of bytes that have been read.
   * data must be big enough to hold data_size bytes
   */
  virtual int read(unsigned char* data, int data_size) = 0;

  virtual bool is_open() const = 0;
};

#endif
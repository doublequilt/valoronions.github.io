////////////////////////////////////////////////////////////////////////////////////////
//
// Nestopia - NES/Famicom emulator written in C++
//
// Copyright (C) 2003-2008 Martin Freij
//
// This file is part of Nestopia.
//
// Nestopia is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// Nestopia is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Nestopia; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//
////////////////////////////////////////////////////////////////////////////////////////

#include <algorithm>
#include "NstCpu.hpp"
#include "NstSoundRenderer.hpp"

namespace Nes
{
	namespace Core
	{
		namespace Sound
		{
			#ifdef NST_MSVC_OPTIMIZE
			#pragma optimize("s", on)
			#endif

			Buffer::Buffer(uint bits)
			: output(new iword [SIZE])
			{
				Reset( true );
			}

			Buffer::~Buffer()
			{
				delete [] output;
			}

			void Buffer::Reset(bool clear)
			{
				pos = start = 0;
				history.pos = 0;

				std::fill( history.buffer, history.buffer+History::SIZE, iword(0) );

				if (clear)
					std::fill( output, output+SIZE, iword(0) );
			}

			#ifdef NST_MSVC_OPTIMIZE
			#pragma optimize("", on)
			#endif
		}
	}
}

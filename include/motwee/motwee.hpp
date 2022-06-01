/*
**  Copyright © 2009-2022 Ingo Ruhnke <grumbel@gmail.com>
**  All rights reserved.
**
**  Redistribution and use in source and binary forms, with or without
**  modification, are permitted provided that the following conditions
**  are met:
**
**  * Redistributions of source code must retain the above copyright
**    notice, this list of conditions and the following disclaimer.
**
**  * Redistributions in binary form must reproduce the above
**    copyright notice, this list of conditions and the following
**    disclaimer in the documentation and/or other materials provided
**    with the distribution.
**
**  * Neither the name of the author nor the names of contributors may
**    be used to endorse or promote products derived from this
**    software without specific prior written permission.
**
**  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND
**  CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
**  INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
**  MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
**  BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
**  EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
**  TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
**  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**  ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR
**  TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF
**  THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
**  SUCH DAMAGE.
*/

#ifndef HEADER_MOTWEE_MOTWEE_HPP
#define HEADER_MOTWEE_MOTWEE_HPP

#include "mode.hpp"

#include "back.hpp"
#include "bounce.hpp"
#include "circ.hpp"
#include "cubic.hpp"
#include "elastic.hpp"
#include "expo.hpp"
#include "linear.hpp"
#include "quad.hpp"
#include "quart.hpp"
#include "quint.hpp"
#include "sine.hpp"

namespace motwee {

inline float ease_in(Mode type, float progress, float x = 0.0f, float y = 0.0f)
{
  switch (type)
  {
    case Mode::BACK: return back::ease_in(progress);
    case Mode::BOUNCE: return bounce::ease_in(progress);
    case Mode::CIRC: return circ::ease_in(progress);
    case Mode::CUBIC: return cubic::ease_in(progress);
    case Mode::ELASTIC: return elastic::ease_in(progress, x, y);
    case Mode::EXPO: return expo::ease_in(progress);
    case Mode::LINEAR: return linear::ease_in(progress);
    case Mode::QUAD: return quad::ease_in(progress);
    case Mode::QUART: return quart::ease_in(progress);
    case Mode::QUINT: return quint::ease_in(progress);
    case Mode::SINE: return sine::ease_in(progress);
    default: return 0.0f;
  }
}

inline float ease_out(Mode type, float progress, float x = 0.0f, float y = 0.0f)
{
  switch (type)
  {
    case Mode::BACK: return back::ease_out(progress);
    case Mode::BOUNCE: return bounce::ease_out(progress);
    case Mode::CIRC: return circ::ease_out(progress);
    case Mode::CUBIC: return cubic::ease_out(progress);
    case Mode::ELASTIC: return elastic::ease_out(progress, x, y);
    case Mode::EXPO: return expo::ease_out(progress);
    case Mode::LINEAR: return linear::ease_out(progress);
    case Mode::QUAD: return quad::ease_out(progress);
    case Mode::QUART: return quart::ease_out(progress);
    case Mode::QUINT: return quint::ease_out(progress);
    case Mode::SINE: return sine::ease_out(progress);
    default: return 0.0f;
  }
}

inline float ease_in_out(Mode type, float progress, float x = 0.0f, float y = 0.0f)
{
  switch (type)
  {
    case Mode::BACK: return back::ease_in_out(progress);
    case Mode::BOUNCE: return bounce::ease_in_out(progress);
    case Mode::CIRC: return circ::ease_in_out(progress);
    case Mode::CUBIC: return cubic::ease_in_out(progress);
    case Mode::ELASTIC: return elastic::ease_in_out(progress, x, y);
    case Mode::EXPO: return expo::ease_in_out(progress);
    case Mode::LINEAR: return linear::ease_in_out(progress);
    case Mode::QUAD: return quad::ease_in_out(progress);
    case Mode::QUART: return quart::ease_in_out(progress);
    case Mode::QUINT: return quint::ease_in_out(progress);
    case Mode::SINE: return sine::ease_in_out(progress);
    default: return 0.0f;
  }
}

} // namespace motwee

#endif

/* EOF */

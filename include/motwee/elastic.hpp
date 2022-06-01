/*
**  Copyright © 2001 Robert Penner
**              2009-2022 Ingo Ruhnke <grumbel@gmail.com> (C++ port)
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

#ifndef HEADER_MOTWEE_ELASTIC_HPP
#define HEADER_MOTWEE_ELASTIC_HPP

#include <numbers>

#include "transform.hpp"

namespace motwee {

namespace elastic {

inline float ease_in(float progress, float a, float p)
{
  if (progress == 0)
  {
    return 0.0f;
  }
  else if (progress == 1)
  {
    return 1.0f;
  }
  else
  {
    if (p == 0.0f) {
      p = 0.3f;
    }

    float s;
    if (a == 0.0f || a < 1.0f)
    {
      a = 1.0f;
      s = p / 4.0f;
    }
    else
    {
      s = p / (2*std::numbers::pi_v<float>) * std::asin(1.0f / a);
    }

    progress -= 1.0f;

    return -(a * std::pow(2.0f , 10.0f * progress) * std::sin( (progress - s) * (2.0f * std::numbers::pi_v<float>) / p));
  }
}

inline float ease_out(float progress, float a, float p)
{
  return transform_to_out(ease_in, progress, a, p);
}

inline float ease_in_out(float progress, float a, float p)
{
  return transform_to_in_out(ease_in, progress, a, p);
}

} // namespace elastic

} // namespace motwee

#endif

/* EOF */

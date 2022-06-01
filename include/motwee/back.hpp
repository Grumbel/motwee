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

#ifndef HEADER_MOTWEE_BACK_HPP
#define HEADER_MOTWEE_BACK_HPP

namespace motwee {

namespace back {

/*
  t: progress, 0-1
  b: start position
  c: change in position (finish - b)
  d: duration
*/

inline float ease_in(float progress, float b, float c, float s = 1.70158f)
{
  return c * progress * progress * ((s + 1.0f) * progress - s) + b;
}

inline float ease_out(float progress, float b, float c, float s = 1.70158f)
{
  progress = progress - 1.0f;
  return c * (progress * progress * ((s + 1.0f) * progress + s) + 1) + b;
}

inline float ease_in_out(float progress, float b, float c, float s = 1.70158f)
{
  progress = progress / 2;

  s *= 1.525f;

  if (progress < 1)
  {
    return c/2*(progress * progress * ((s+1) * progress - s)) + b;
  }
  else
  {
    s *= 1.525f;
    progress -= 2;
    return c/2*(progress * progress *((s+1) * progress + s) + 2) + b;
  }
}

} // namespace back

} // namespace motwee

#endif

/* EOF */

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

#ifndef HEADER_MOTWEE_BOUNCE_HPP
#define HEADER_MOTWEE_BOUNCE_HPP

namespace motwee {

namespace bounce {

/*
  t: progress, 0-1
  b: start position
  c: change in position (finish - b)
  d: duration
*/

inline float ease_out(float t, float b, float c, float d)
{
  t  /=  d;
  if (t < (1/2.75f))
  {
    return c*(7.5625f*t*t) + b;
  }
  else if (t < (2/2.75f))
  {
    t-=1.5f/2.75f;
    return c*(7.5625f*t*t + .75f) + b;
  }
  else if (t < (2.5f/2.75f))
  {
    t-=(2.25f/2.75f);
    return c*(7.5625f*t*t + .9375f) + b;
  }
  else
  {
    t-=(2.625f/2.75f);
    return c*(7.5625f*t*t + .984375f) + b;
  }
}

inline float ease_in(float t, float b, float c, float d)
{
  return c - ease_out(d-t, 0, c, d) + b;
}

inline float ease_in_out(float t, float b, float c, float d)
{
  if (t < d/2)
  {
    return ease_in(t*2, 0, c, d) * .5f + b;
  }
  else
  {
    return ease_out(t*2-d, 0, c, d) * .5f + c*.5f + b;
  }
}

} // namespace bounce

} // namespace motwee

#endif

/* EOF */

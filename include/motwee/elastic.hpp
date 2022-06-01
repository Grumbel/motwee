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

namespace motwee {

namespace elastic {

/*
  t: progress, 0-1
  b: start position
  c: change in position (finish - b)
  d: duration
*/

inline float ease_in(float t, float b, float c, float d, float a, float p)
{
  if (t==0)
  {
    return b;
  }
  else
  {
    t /= d;

    if (t == 1)
    {
      return b+c;
    }
    else
    {
      if (p == 0.0f)
        p = d * 0.3f;

      float s;

      if (a == 0.0f || a < std::fabs(c))
      {
        a=c; s=p/4;
      }
      else
      {
        s = p/(2*std::numbers::pi_v<float>) * std::asin(c/a);
      }

      t-=1;

      return -(a*std::pow(2,10*t) * std::sin( (t*d-s)*(2*std::numbers::pi_v<float>)/p)) + b;
    }
  }
}

inline float ease_out(float t, float b, float c, float d, float a, float p)
{
  if (t==0)
  {
    return b;
  }
  else
  {
    t /= d;
    if (t==1)
    {
      return b+c;
    }
    else
    {
      if (p == 0.0f)
        p=d*.3f;

      float s;
      if (a == 0.0f || a < std::fabs(c))
      {
        a=c;
        s=p/4;
      }
      else
      {
        s = p/(2*std::numbers::pi_v<float>) * std::asin(c/a);
      }

      return (a*std::pow(2,-10*t) * std::sin( (t*d-s)*(2*std::numbers::pi_v<float>)/p ) + c + b);
    }
  }
}

inline float ease_in_out(float t, float b, float c, float d, float a, float p)
{
  t/=d/2;
  if (t==0)
  {
    return b;
  }
  else if (t==2)
  {
    return b+c;
  }
  else
  {
    if (p == 0.0f)
      p = d * (0.3f * 1.5f);

    float s;
    if (a == 0.0f || a < std::fabs(c))
    {
      a=c; s=p/4;
    }
    else
    {
      s = p/(2*std::numbers::pi_v<float>) * std::asin(c/a);
    }

    t-=1;

    if (t < 1)
    {
      return -.5f*(a*std::pow(2,10*t) * std::sin( (t*d-s)*(2*std::numbers::pi_v<float>)/p )) + b;
    }
    else
    {
      t-=1;
      return a*std::pow(2,-10*t) * std::sin( (t*d-s)*(2*std::numbers::pi_v<float>)/p )*.5f + c + b;
    }
  }
}

} // namespace elastic

} // namespace motwee

#endif

/* EOF */

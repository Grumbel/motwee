/*
**  Copyright © 2009-2022 Ingo Ruhnke <grumbel@gmail.com> (C++ port)
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

#ifndef HEADER_MOTWEE_TRANSFORM_HPP
#define HEADER_MOTWEE_TRANSFORM_HPP

namespace motwee {

template<typename F, typename... Args>
inline float transform_to_out(F f, float progress, Args... args) {
  return 1.0f - f(1.0f - progress, args...);
}

template<typename F, typename... Args>
inline float transform_to_inout(F f, float progress, Args... args) {
  if (progress < 0.5f) {
    return f(progress * 2.0f, args...) / 2.0f;
  } else {
    return 1.0f - f(2.0f - 2.0f * progress, args...) / 2.0f;
  }
}

/* Map value in range [0,1] to range [start, end] */
inline float map_to(float value, float start, float end)
{
  return value * (end - start) + start;
}

} // namespace motwee

#endif

/* EOF */

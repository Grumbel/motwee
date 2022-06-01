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

#ifndef HEADER_MOTWEE_MODE_HPP
#define HEADER_MOTWEE_MODE_HPP

#include <array>
#include <string_view>
#include <stdexcept>

namespace motwee {

enum class Mode
{
  BACK,
  BOUNCE,
  CIRC,
  CUBIC,
  ELASTIC,
  EXPO,
  LINEAR,
  QUAD,
  QUART,
  QUINT,
  SINE
};

std::array<char const*, 11> Mode_names = {
  "back",
  "bounce",
  "circ",
  "cubic",
  "elastic",
  "expo",
  "linear",
  "quad",
  "quart",
  "quint",
  "sine"
};

inline
Mode Mode_from_string(std::string_view text)
{
  for (size_t i = 0; i < Mode_names.size(); ++i) {
    if (text == Mode_names[i]) {
      return static_cast<Mode>(i);
    }
  }
  throw std::invalid_argument("unknown Mode name");
}

std::string_view Mode_to_string(Mode mode)
{
  size_t const idx = static_cast<size_t>(mode);
  if (idx > Mode_names.size()) {
    throw std::invalid_argument("invalid Mode value");
  }

  return Mode_names[idx];
}

} // namespace motwee

#endif

/* EOF */

#include <cstring>
#include <string>
#include <iostream>

#include <motwee/motwee.hpp>

enum class Direction {
  IN, OUT, INOUT
};

std::array<char const*, 3> Direction_names = {
  "in", "out", "inout"
};

/*
  b: start position
  c: change in position (finish - b)
  d: duration
*/

Direction Direction_from_string(std::string_view text)
{
  for (size_t i = 0; i < Direction_names.size(); ++i) {
    if (Direction_names[i] == text) {
      return static_cast<Direction>(i);
    }
  }
  throw std::invalid_argument("invalid Direction name");
}

int main(int argc, char** argv)
{
  if (argc < 2) {
    std::cerr << "Usage: " << argv[0] << " MODE[-in,-out,-inout] [b] [c] [d]" << std::endl;
    std::cerr << "\n";
    std::cerr << "Modes:";
    for (auto const& text : motwee::Mode_names) {
      std::cerr << " " << text;
    }
    std::cerr << "\n";
    return 0;
  }

  Direction direction = Direction::IN;
  motwee::Mode mode = motwee::Mode::BACK;
  if (argc > 1) {
    char const* sep = std::strchr(argv[1], '-');

    if (sep == nullptr) {
      mode = motwee::Mode_from_string(argv[1]);
    } else {
      mode = motwee::Mode_from_string(std::string_view(argv[1], sep));
      direction = Direction_from_string(sep + 1);
    }
  }

  float b = 0.0f;
  if (argc > 2) {
    b = std::stof(argv[2]);
  }

  float c = 1.0f;
  if (argc > 3) {
    c = std::stof(argv[3]);
  }

  float d = 1.0f;
  if (argc > 4) {
    c = std::stof(argv[4]);
  }

  //for(float progress = 0.0f; progress < 1.0f; progress += 0.01f) {
  for(float progress = 0.0f; progress < 1.0f; progress += 0.01f) {
    float value;
    switch (direction)
    {
      case Direction::IN:
        value = motwee::ease_in(mode, progress, b, c, d);
        break;

      case Direction::OUT:
        value = motwee::ease_out(mode, progress, b, c, d);
        break;

      case Direction::INOUT:
        value = motwee::ease_in_out(mode, progress, b, c, d);
        break;
    }

    std::cout << progress << " " << value << std::endl;
  }

  return 0;
}

/* EOF */

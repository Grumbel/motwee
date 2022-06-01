#include <iostream>

#include <motwee/motwee.hpp>

int main()
{
  for(float i = 0.0f; i < 1.0f; i += 0.01f) {
    std::cout << motwee::circ::ease_in_out(i, 1.0f, 1.0f, 1.0f) << std::endl;
  }

  return 0;
}

/* EOF */

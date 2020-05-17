#include <cstdint>
#include <iostream>

int main()
{
  constexpr std::uint_fast8_t option_viewed{0x01};
  constexpr std::uint_fast8_t option_edited{0x02};
  constexpr std::uint_fast8_t option_favorited{0x04};
  constexpr std::uint_fast8_t option_shared{0x08};
  constexpr std::uint_fast8_t option_deleted{0x80};

  std::uint_fast8_t myArticleFlags{ };

  // set article as viewed
  myArticleFlags |= option_viewed;

  // test whether article is deleted
  std::cout << "The article is " << ((myArticleFlags & option_deleted) ? "deleted" : "not deleted") << '\n';

  // reset article from favorited
  myArticleFlags &= ~option_favorited;

  return 0;
}

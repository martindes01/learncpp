# [0.12 — Configuring your compiler: Choosing a language standard](https://www.learncpp.com/cpp-tutorial/configuring-your-compiler-choosing-a-language-standard/)

## Setting a language standard in g++

### For GCC/G++ users

For GCC/G++, you can pass compiler flags `-std=c++11`, `-std=c++14`, `-std=c++17`, or `-std=c++2a` to enable C++11/14/17/2a support respectively.

## Testing your compiler

After you enabled C++17 or higher, you should be able to compile the following code without any warnings or errors.

```cpp
#include <array>
#include <iostream>
#include <string_view>
#include <tuple>
#include <type_traits>

namespace a::b::c
{
	inline constexpr std::string_view str{ "hello" };
}

template <class... T>
std::tuple<std::size_t, std::common_type_t<T...>> sum(T... args)
{
	return { sizeof...(T), (args + ...) };
}

int main()
{
	auto [iNumbers, iSum]{ sum(1, 2, 3) };
	std::cout << a::b::c::str << ' ' << iNumbers << ' ' << iSum << '\n';

	std::array arr{ 1, 2, 3 };

	std::cout << std::size(arr) << '\n';

	return 0;
}
```

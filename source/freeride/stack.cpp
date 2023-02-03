#include <freeride/stack.hpp>

namespace freeride {

Stack::Stack(SizeType pages) noexcept
    : detail::StackBase{pages} {
}

}  // namespace freeride
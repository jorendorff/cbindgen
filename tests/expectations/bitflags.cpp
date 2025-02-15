#include <cstdarg>
#include <cstdint>
#include <cstdlib>
#include <ostream>
#include <new>

/// Constants shared by multiple CSS Box Alignment properties
///
/// These constants match Gecko's `NS_STYLE_ALIGN_*` constants.
struct AlignFlags {
  uint8_t bits;

  explicit operator bool() const {
    return !!bits;
  }
  AlignFlags operator~() const {
    return {static_cast<decltype(bits)>(~bits)};
  }
  AlignFlags operator|(const AlignFlags& other) const {
    return {static_cast<decltype(bits)>(this->bits | other.bits)};
  }
  AlignFlags& operator|=(const AlignFlags& other) {
    *this = (*this | other);
    return *this;
  }
  AlignFlags operator&(const AlignFlags& other) const {
    return {static_cast<decltype(bits)>(this->bits & other.bits)};
  }
  AlignFlags& operator&=(const AlignFlags& other) {
    *this = (*this & other);
    return *this;
  }
  AlignFlags operator^(const AlignFlags& other) const {
    return {static_cast<decltype(bits)>(this->bits ^ other.bits)};
  }
  AlignFlags& operator^=(const AlignFlags& other) {
    *this = (*this ^ other);
    return *this;
  }
};
/// 'auto'
constexpr static const AlignFlags AlignFlags_AUTO = AlignFlags{ /* .bits = */ (uint8_t)0 };
/// 'normal'
constexpr static const AlignFlags AlignFlags_NORMAL = AlignFlags{ /* .bits = */ (uint8_t)1 };
/// 'start'
constexpr static const AlignFlags AlignFlags_START = AlignFlags{ /* .bits = */ (uint8_t)(1 << 1) };
/// 'end'
constexpr static const AlignFlags AlignFlags_END = AlignFlags{ /* .bits = */ (uint8_t)(1 << 2) };
constexpr static const AlignFlags AlignFlags_ALIAS = AlignFlags{ /* .bits = */ (uint8_t)(AlignFlags_END).bits };
/// 'flex-start'
constexpr static const AlignFlags AlignFlags_FLEX_START = AlignFlags{ /* .bits = */ (uint8_t)(1 << 3) };
constexpr static const AlignFlags AlignFlags_MIXED = AlignFlags{ /* .bits = */ (uint8_t)(((1 << 4) | (AlignFlags_FLEX_START).bits) | (AlignFlags_END).bits) };
constexpr static const AlignFlags AlignFlags_MIXED_SELF = AlignFlags{ /* .bits = */ (uint8_t)(((1 << 5) | (AlignFlags_FLEX_START).bits) | (AlignFlags_END).bits) };

struct DebugFlags {
  uint32_t bits;

  explicit operator bool() const {
    return !!bits;
  }
  DebugFlags operator~() const {
    return {static_cast<decltype(bits)>(~bits)};
  }
  DebugFlags operator|(const DebugFlags& other) const {
    return {static_cast<decltype(bits)>(this->bits | other.bits)};
  }
  DebugFlags& operator|=(const DebugFlags& other) {
    *this = (*this | other);
    return *this;
  }
  DebugFlags operator&(const DebugFlags& other) const {
    return {static_cast<decltype(bits)>(this->bits & other.bits)};
  }
  DebugFlags& operator&=(const DebugFlags& other) {
    *this = (*this & other);
    return *this;
  }
  DebugFlags operator^(const DebugFlags& other) const {
    return {static_cast<decltype(bits)>(this->bits ^ other.bits)};
  }
  DebugFlags& operator^=(const DebugFlags& other) {
    *this = (*this ^ other);
    return *this;
  }
};
/// Flag with the topmost bit set of the u32
constexpr static const DebugFlags DebugFlags_BIGGEST_ALLOWED = DebugFlags{ /* .bits = */ (uint32_t)(1 << 31) };

extern "C" {

void root(AlignFlags flags, DebugFlags bigger_flags);

} // extern "C"

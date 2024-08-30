# pragma once
# include "Defined.hpp"

namespace num
{
    [[nodiscard]]
    constexpr int8 operator ""_i8(long double n) noexcept;

    [[nodiscard]]
    constexpr int8 operator ""_i8(unsigned long long n) noexcept;

    [[nodiscard]]
    constexpr int16 operator ""_i16(long double n) noexcept;

    [[nodiscard]]
    constexpr int16 operator ""_i16(unsigned long long n) noexcept;

    [[nodiscard]]
    constexpr int32 operator ""_i32(long double n) noexcept;

    [[nodiscard]]
    constexpr int32 operator ""_i32(unsigned long long n) noexcept;

    [[nodiscard]]
    constexpr int64 operator ""_i64(long double n) noexcept;

    [[nodiscard]]
    constexpr int64 operator ""_i64(unsigned long long n) noexcept;

    [[nodiscard]]
    constexpr uint8 operator ""_u8(long double n) noexcept;

    [[nodiscard]]
    constexpr uint8 operator ""_u8(unsigned long long n) noexcept;

    [[nodiscard]]
    constexpr uint16 operator ""_u16(long double n) noexcept;

    [[nodiscard]]
    constexpr uint16 operator ""_u16(unsigned long long n) noexcept;

    [[nodiscard]]
    constexpr uint32 operator ""_u32(long double n) noexcept;

    [[nodiscard]]
    constexpr uint32 operator ""_u32(unsigned long long n) noexcept;

    [[nodiscard]]
    constexpr uint64 operator ""_u64(long double n) noexcept;

    [[nodiscard]]
    constexpr uint64 operator ""_u64(unsigned long long n) noexcept;

    [[nodiscard]]
    constexpr float32 operator ""_f32(long double n) noexcept;

    [[nodiscard]]
    constexpr float32 operator ""_f32(unsigned long long n) noexcept;

    [[nodiscard]]
    constexpr float64 operator ""_f64(long double n) noexcept;

    [[nodiscard]]
    constexpr float64 operator ""_f64(unsigned long long n) noexcept;
}

# include "inline/Literals.ipp"

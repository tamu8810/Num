# pragma once
# include "Numeric.hpp"

namespace num
{
    /// @brief 符号付き 8bit 整数型
    using int8 = Numeric<std::int8_t>;

    /// @brief 符号付き 16bit 整数型
    using int16 = Numeric<std::int16_t>;

    /// @brief 符号付き 32bit 整数型
    using int32 = Numeric<std::int32_t>;

    /// @brief 符号付き 64bit 整数型
    using int64 = Numeric<std::int64_t>;

    /// @brief 符号無し 8bit 整数型
    using uint8 = Numeric<std::uint8_t>;

    /// @brief 符号無し 16bit 整数型
    using uint16 = Numeric<std::uint16_t>;

    /// @brief 符号無し 32bit 整数型
    using uint32 = Numeric<std::uint32_t>;

    /// @brief 符号無し 64bit 整数型
    using uint64 = Numeric<std::uint64_t>;

    /// @brief 32bit 浮動小数点数型
    using float32 = Numeric<float>;

    /// @brief 64bit 浮動小数点数型
    using float64 = Numeric<double>;

    /// @brief 符号付きサイズ型
    using isize = int64;

    /// @brief 符号無しサイズ型
    using usize = uint64;
}

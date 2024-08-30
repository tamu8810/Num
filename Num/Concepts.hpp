# pragma once
# include "details/Concepts.hpp"

namespace num
{
    template <details::Concept::Arithmetic Type>
    class Numeric;

    namespace Concept
    {
        /// @brief 符号付き整数型コンセプト
        /// @tparam Type 判定する型
        template <class Type>
        concept SignedIntegral = std::same_as<Type, Numeric<std::int8_t>>  ||
                                 std::same_as<Type, Numeric<std::int16_t>> ||
                                 std::same_as<Type, Numeric<std::int32_t>> ||
                                 std::same_as<Type, Numeric<std::int64_t>>;

        /// @brief 符号無し整数型コンセプト
        /// @tparam Type 判定する型
        template <class Type>
        concept UnsignedIntegral = std::same_as<Type, Numeric<std::uint8_t>>  ||
                                   std::same_as<Type, Numeric<std::uint16_t>> ||
                                   std::same_as<Type, Numeric<std::uint32_t>> ||
                                   std::same_as<Type, Numeric<std::uint64_t>>;

        /// @brief 整数型コンセプト
        /// @tparam Type 判定する型
        template <class Type>
        concept Integral = SignedIntegral<Type> || UnsignedIntegral<Type>;

        /// @brief 浮動小数点数型コンセプト
        /// @tparam Type 判定する型
        template <class Type>
        concept FloatingPoint = std::same_as<Type, Numeric<float>> || std::same_as<Type, Numeric<double>>;

        /// @brief 数値型コンセプト
        /// @tparam Type 判定する型
        template <class Type>
        concept Arithmetic = Integral<Type> || FloatingPoint<Type>;
    }
}

# pragma once
# include <concepts>

namespace num::details::Concept
{
    template <class Type>
    concept SignedIntegral = std::same_as<Type, std::int8_t>  ||
                             std::same_as<Type, std::int16_t> ||
                             std::same_as<Type, std::int32_t> ||
                             std::same_as<Type, std::int64_t>;

    template <class Type>
    concept UnsignedIntegral = std::same_as<Type, std::uint8_t>  ||
                               std::same_as<Type, std::uint16_t> ||
                               std::same_as<Type, std::uint32_t> ||
                               std::same_as<Type, std::uint64_t>;

    template <class Type>
    concept Integral = SignedIntegral<Type> || UnsignedIntegral<Type>;

    template <class Type>
    concept FloatingPoint = std::same_as<Type, float> || std::same_as<Type, double>;

    template <class Type>
    concept Arithmetic = Integral<Type> || FloatingPoint<Type>;

    template <class Lhs, class Rhs>
    concept SingedIntAndUnsignedInt = (SignedIntegral<Lhs> && UnsignedIntegral<Rhs>) ||
                                      (SignedIntegral<Rhs> && UnsignedIntegral<Lhs>);
}

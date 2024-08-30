# pragma once
# include "Concepts.hpp"

namespace num::details
{
    template <Concept::Arithmetic Lhs, Concept::Arithmetic Rhs>
    class AutoCast_impl final
    {
        static constexpr bool m_NotMixedSignIntegrals = not Concept::SingedIntAndUnsignedInt<Lhs, Rhs>;

        static_assert(m_NotMixedSignIntegrals, "符号付整数型と符号無し整数型が混在しています。型を推測できません。");

        using greater_t = std::conditional_t<sizeof(Lhs) >= sizeof(Rhs), Lhs, Rhs>;

    public:

        using auto_t = std::conditional_t<
            (Concept::Integral<Lhs> && Concept::Integral<Rhs>) ||
            (Concept::FloatingPoint<Lhs> && Concept::FloatingPoint<Rhs>),
            greater_t,
            std::conditional_t<Concept::FloatingPoint<Lhs>, Lhs, Rhs>
        >;
    };

    template <Concept::Arithmetic Lhs, Concept::Arithmetic Rhs>
    using auto_t = typename AutoCast_impl<Lhs, Rhs>::auto_t;
}

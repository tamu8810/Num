# pragma once

namespace num
{
    template <details::Concept::Arithmetic Type>
    inline constexpr Numeric<Type>::Numeric() noexcept
        : value{ 0 } {}

    template <details::Concept::Arithmetic Type>
    template <details::Concept::Arithmetic Other>
    inline constexpr Numeric<Type>::Numeric(Numeric<Other> other) noexcept
        : value{ static_cast<Type>(other.value) } {}

    template <details::Concept::Arithmetic Type>
    template <details::Concept::Arithmetic Other>
    inline constexpr Numeric<Type>::Numeric(Other other) noexcept
        : value{ static_cast<Type>(other) } {}

    template <details::Concept::Arithmetic Type>
    template <details::Concept::Arithmetic Other>
    constexpr Numeric<Type>& Numeric<Type>::operator =(Numeric<Other> other) noexcept
    {
        value = static_cast<Type>(other.value);

        return *this;
    }

    template <details::Concept::Arithmetic Type>
    template <details::Concept::Arithmetic Other>
    constexpr Numeric<Type>& Numeric<Type>::operator =(Other other) noexcept
    {
        value = static_cast<Type>(other);

        return *this;
    }

    template <details::Concept::Arithmetic Type>
    inline constexpr Numeric<Type> Numeric<Type>::operator +() const noexcept
    {
        return *this;
    }

    template <details::Concept::Arithmetic Type>
    inline constexpr Numeric<Type> Numeric<Type>::operator -() const noexcept
    {
        return Numeric{ -value };
    }

    template <details::Concept::Arithmetic Type>
    inline constexpr Numeric<Type>& Numeric<Type>::operator ++() noexcept
    {
        ++value;

        return *this;
    }

    template <details::Concept::Arithmetic Type>
    inline constexpr Numeric<Type>& Numeric<Type>::operator --() noexcept
    {
        --value;

        return *this;
    }

    template <details::Concept::Arithmetic Type>
    inline constexpr Numeric<Type> Numeric<Type>::operator ++(int) noexcept
    {
        Numeric tmp{ *this };

        ++value;

        return tmp;
    }

    template <details::Concept::Arithmetic Type>
    inline constexpr Numeric<Type> Numeric<Type>::operator --(int) noexcept
    {
        Numeric tmp{ *this };

        --value;

        return tmp;
    }

    template <details::Concept::Arithmetic Type>
    template <details::Concept::Arithmetic Other>
    inline constexpr Numeric<Type>::operator Numeric<Other>() const noexcept
    {
        return Numeric<Other>{ value };
    }

    template <details::Concept::Arithmetic Type>
    template <details::Concept::Arithmetic Other>
    inline constexpr Numeric<Type>::operator Other() const noexcept
    {
        return static_cast<Other>(value);
    }

    template <details::Concept::Arithmetic Type>
    template <details::Concept::Arithmetic Other>
    inline constexpr Numeric<Type>& Numeric<Type>::operator +=(Numeric<Other> other) noexcept
    {
        value += static_cast<Type>(other.value);

        return *this;
    }

    template <details::Concept::Arithmetic Type>
    template <details::Concept::Arithmetic Other>
    inline constexpr Numeric<Type>& Numeric<Type>::operator -=(Numeric<Other> other) noexcept
    {
        value -= static_cast<Type>(other.value);

        return *this;
    }

    template <details::Concept::Arithmetic Type>
    template <details::Concept::Arithmetic Other>
    inline constexpr Numeric<Type>& Numeric<Type>::operator *=(Numeric<Other> other) noexcept
    {
        value *= static_cast<Type>(other.value);

        return *this;
    }

    template <details::Concept::Arithmetic Type>
    template <details::Concept::Arithmetic Other>
    inline constexpr Numeric<Type>& Numeric<Type>::operator /=(Numeric<Other> other) noexcept
    {
        value /= static_cast<Type>(other.value);

        return *this;
    }

    template <details::Concept::Arithmetic Type>
    template <details::Concept::Arithmetic Other>
    inline constexpr Numeric<Type>& Numeric<Type>::operator %=(Numeric<Other> other) noexcept
    {
        value %= static_cast<Type>(other.value);

        return *this;
    }

    template <details::Concept::Arithmetic Type>
    template <details::Concept::Arithmetic Other>
    inline constexpr Numeric<Type>& Numeric<Type>::operator +=(Other other) noexcept
    {
        value += static_cast<Type>(other);

        return *this;
    }

    template <details::Concept::Arithmetic Type>
    template <details::Concept::Arithmetic Other>
    inline constexpr Numeric<Type>& Numeric<Type>::operator -=(Other other) noexcept
    {
        value -= static_cast<Type>(other);

        return *this;
    }

    template <details::Concept::Arithmetic Type>
    template <details::Concept::Arithmetic Other>
    inline constexpr Numeric<Type>& Numeric<Type>::operator *=(Other other) noexcept
    {
        value *= static_cast<Type>(other);

        return *this;
    }

    template <details::Concept::Arithmetic Type>
    template <details::Concept::Arithmetic Other>
    inline constexpr Numeric<Type>& Numeric<Type>::operator /=(Other other) noexcept
    {
        value /= static_cast<Type>(other);

        return *this;
    }

    template <details::Concept::Arithmetic Type>
    template <details::Concept::Arithmetic Other>
    inline constexpr Numeric<Type>& Numeric<Type>::operator %=(Other other) noexcept
    {
        value %= static_cast<Type>(other);

        return *this;
    }

    template <details::Concept::Arithmetic Lhs, details::Concept::Arithmetic Rhs>
    inline constexpr auto operator +(Numeric<Lhs> lhs, Numeric<Rhs> rhs) noexcept
    {
        return Numeric<details::auto_t>{ lhs.value + rhs.value };
    }

    template <details::Concept::Arithmetic Lhs, details::Concept::Arithmetic Rhs>
    inline constexpr auto operator -(Numeric<Lhs> lhs, Numeric<Rhs> rhs) noexcept
    {
        return Numeric<details::auto_t>{ lhs.value - rhs.value };
    }

    template <details::Concept::Arithmetic Lhs, details::Concept::Arithmetic Rhs>
    inline constexpr auto operator *(Numeric<Lhs> lhs, Numeric<Rhs> rhs) noexcept
    {
        return Numeric<details::auto_t>{ lhs.value * rhs.value };
    }

    template <details::Concept::Arithmetic Lhs, details::Concept::Arithmetic Rhs>
    inline constexpr auto operator /(Numeric<Lhs> lhs, Numeric<Rhs> rhs) noexcept
    {
        return Numeric<details::auto_t>{ lhs.value / rhs.value };
    }

    template <details::Concept::Arithmetic Lhs, details::Concept::Arithmetic Rhs>
    inline constexpr auto operator %(Numeric<Lhs> lhs, Numeric<Rhs> rhs) noexcept
    {
        return Numeric<details::auto_t>{ lhs.value % rhs.value };
    }

    template <details::Concept::Arithmetic Lhs, details::Concept::Arithmetic Rhs>
    inline constexpr auto operator +(Lhs lhs, Numeric<Rhs> rhs) noexcept
    {
        return Numeric<details::auto_t>{ lhs + rhs.value };
    }

    template <details::Concept::Arithmetic Lhs, details::Concept::Arithmetic Rhs>
    inline constexpr auto operator -(Lhs lhs, Numeric<Rhs> rhs) noexcept
    {
        return Numeric<details::auto_t>{ lhs - rhs.value };
    }

    template <details::Concept::Arithmetic Lhs, details::Concept::Arithmetic Rhs>
    inline constexpr auto operator *(Lhs lhs, Numeric<Rhs> rhs) noexcept
    {
        return Numeric<details::auto_t>{ lhs * rhs.value };
    }

    template <details::Concept::Arithmetic Lhs, details::Concept::Arithmetic Rhs>
    inline constexpr auto operator /(Lhs lhs, Numeric<Rhs> rhs) noexcept
    {
        return Numeric<details::auto_t>{ lhs / rhs.value };
    }

    template <details::Concept::Arithmetic Lhs, details::Concept::Arithmetic Rhs>
    inline constexpr auto operator %(Lhs lhs, Numeric<Rhs> rhs) noexcept
    {
        return Numeric<details::auto_t>{ lhs % rhs.value };
    }

    template <details::Concept::Arithmetic Lhs, details::Concept::Arithmetic Rhs>
    inline constexpr auto operator +(Numeric<Lhs> lhs, Rhs rhs) noexcept
    {
        return Numeric<details::auto_t>{ lhs.value + rhs };
    }

    template <details::Concept::Arithmetic Lhs, details::Concept::Arithmetic Rhs>
    inline constexpr auto operator -(Numeric<Lhs> lhs, Rhs rhs) noexcept
    {
        return Numeric<details::auto_t>{ lhs.value - rhs };
    }

    template <details::Concept::Arithmetic Lhs, details::Concept::Arithmetic Rhs>
    inline constexpr auto operator *(Numeric<Lhs> lhs, Rhs rhs) noexcept
    {
        return Numeric<details::auto_t>{ lhs.value * rhs };
    }

    template <details::Concept::Arithmetic Lhs, details::Concept::Arithmetic Rhs>
    inline constexpr auto operator /(Numeric<Lhs> lhs, Rhs rhs) noexcept
    {
        return Numeric<details::auto_t>{ lhs.value / rhs };
    }

    template <details::Concept::Arithmetic Lhs, details::Concept::Arithmetic Rhs>
    inline constexpr auto operator %(Numeric<Lhs> lhs, Rhs rhs) noexcept
    {
        return Numeric<details::auto_t>{ lhs.value % rhs };
    }

    template <details::Concept::Arithmetic Lhs, details::Concept::Arithmetic Rhs>
    inline constexpr bool operator ==(Numeric<Lhs> lhs, Numeric<Rhs> rhs) noexcept
    {
        if constexpr (details::Concept::SingedIntAndUnsignedInt<Lhs, Rhs>)
        {
            return std::cmp_equal(lhs.value, rhs.value);
        }
        else
        {
            return lhs.value == rhs.value;
        }
    }

    template <details::Concept::Arithmetic Lhs, details::Concept::Arithmetic Rhs>
    inline constexpr bool operator !=(Numeric<Lhs> lhs, Numeric<Rhs> rhs) noexcept
    {
        if constexpr (details::Concept::SingedIntAndUnsignedInt<Lhs, Rhs>)
        {
            return std::cmp_not_equal(lhs.value, rhs.value);
        }
        else
        {
            return lhs.value != rhs.value;
        }
    }

    template <details::Concept::Arithmetic Lhs, details::Concept::Arithmetic Rhs>
    inline constexpr bool operator <(Numeric<Lhs> lhs, Numeric<Rhs> rhs) noexcept
    {
        if constexpr (details::Concept::SingedIntAndUnsignedInt<Lhs, Rhs>)
        {
            return std::cmp_less(lhs.value, rhs.value);
        }
        else
        {
            return lhs.value < rhs.value;
        }
    }

    template <details::Concept::Arithmetic Lhs, details::Concept::Arithmetic Rhs>
    inline constexpr bool operator >(Numeric<Lhs> lhs, Numeric<Rhs> rhs) noexcept
    {
        if constexpr (details::Concept::SingedIntAndUnsignedInt<Lhs, Rhs>)
        {
            return std::cmp_greater(lhs.value, rhs.value);
        }
        else
        {
            return lhs.value > rhs.value;
        }
    }

    template <details::Concept::Arithmetic Lhs, details::Concept::Arithmetic Rhs>
    inline constexpr bool operator <=(Numeric<Lhs> lhs, Numeric<Rhs> rhs) noexcept
    {
        if constexpr (details::Concept::SingedIntAndUnsignedInt<Lhs, Rhs>)
        {
            return std::cmp_less_equal(lhs.value, rhs.value);
        }
        else
        {
            return lhs.value <= rhs.value;
        }
    }

    template <details::Concept::Arithmetic Lhs, details::Concept::Arithmetic Rhs>
    inline constexpr bool operator >=(Numeric<Lhs> lhs, Numeric<Rhs> rhs) noexcept
    {
        if constexpr (details::Concept::SingedIntAndUnsignedInt<Lhs, Rhs>)
        {
            return std::cmp_greater_equal(lhs.value, rhs.value);
        }
        else
        {
            return lhs.value >= rhs.value;
        }
    }

    template <details::Concept::Arithmetic Lhs, details::Concept::Arithmetic Rhs>
    inline constexpr auto operator <=>(Numeric<Lhs> lhs, Numeric<Rhs> rhs) noexcept
    {
        if constexpr (details::Concept::SingedIntAndUnsignedInt<Lhs, Rhs>)
        {
            if constexpr (details::Concept::SignedIntegral<Lhs>)
            {
                return (lhs.value < 0) ? std::strong_ordering::less : (static_cast<Rhs>(lhs.value) <=> rhs.value);
            }
            else
            {
                return (rhs.value < 0) ? std::strong_ordering::less : (lhs.value <=> static_cast<Lhs>(rhs.value));
            }
        }
        else
        {
            return lhs.value <=> rhs.value;
        }
    }

    template <details::Concept::Arithmetic Lhs, details::Concept::Arithmetic Rhs>
    inline constexpr bool operator ==(Lhs lhs, Numeric<Rhs> rhs) noexcept
    {
        if constexpr (details::Concept::SingedIntAndUnsignedInt<Lhs, Rhs>)
        {
            return std::cmp_equal(lhs, rhs.value);
        }
        else
        {
            return lhs == rhs.value;
        }
    }

    template <details::Concept::Arithmetic Lhs, details::Concept::Arithmetic Rhs>
    inline constexpr bool operator !=(Lhs lhs, Numeric<Rhs> rhs) noexcept
    {
        if constexpr (details::Concept::SingedIntAndUnsignedInt<Lhs, Rhs>)
        {
            return std::cmp_not_equal(lhs, rhs.value);
        }
        else
        {
            return lhs != rhs.value;
        }
    }

    template <details::Concept::Arithmetic Lhs, details::Concept::Arithmetic Rhs>
    inline constexpr bool operator <(Lhs lhs, Numeric<Rhs> rhs) noexcept
    {
        if constexpr (details::Concept::SingedIntAndUnsignedInt<Lhs, Rhs>)
        {
            return std::cmp_less(lhs, rhs.value);
        }
        else
        {
            return lhs < rhs.value;
        }
    }

    template <details::Concept::Arithmetic Lhs, details::Concept::Arithmetic Rhs>
    inline constexpr bool operator >(Lhs lhs, Numeric<Rhs> rhs) noexcept
    {
        if constexpr (details::Concept::SingedIntAndUnsignedInt<Lhs, Rhs>)
        {
            return std::cmp_greater(lhs, rhs.value);
        }
        else
        {
            return lhs > rhs.value;
        }
    }

    template <details::Concept::Arithmetic Lhs, details::Concept::Arithmetic Rhs>
    inline constexpr bool operator <=(Lhs lhs, Numeric<Rhs> rhs) noexcept
    {
        if constexpr (details::Concept::SingedIntAndUnsignedInt<Lhs, Rhs>)
        {
            return std::cmp_less_equal(lhs, rhs.value);
        }
        else
        {
            return lhs <= rhs.value;
        }
    }

    template <details::Concept::Arithmetic Lhs, details::Concept::Arithmetic Rhs>
    inline constexpr bool operator >=(Lhs lhs, Numeric<Rhs> rhs) noexcept
    {
        if constexpr (details::Concept::SingedIntAndUnsignedInt<Lhs, Rhs>)
        {
            return std::cmp_greater_equal(lhs, rhs.value);
        }
        else
        {
            return lhs >= rhs.value;
        }
    }

    template <details::Concept::Arithmetic Lhs, details::Concept::Arithmetic Rhs>
    inline constexpr auto operator <=>(Lhs lhs, Numeric<Rhs> rhs) noexcept
    {
        if constexpr (details::Concept::SingedIntAndUnsignedInt<Lhs, Rhs>)
        {
            if constexpr (details::Concept::SignedIntegral<Lhs>)
            {
                return (lhs < 0) ? std::strong_ordering::less : (static_cast<Rhs>(lhs) <=> rhs.value);
            }
            else
            {
                return (rhs.value < 0) ? std::strong_ordering::less : (lhs <=> static_cast<Lhs>(rhs.value));
            }
        }
        else
        {
            return lhs <=> rhs.value;
        }
    }

    template <details::Concept::Arithmetic Lhs, details::Concept::Arithmetic Rhs>
    inline constexpr bool operator ==(Numeric<Lhs> lhs, Rhs rhs) noexcept
    {
        if constexpr (details::Concept::SingedIntAndUnsignedInt<Lhs, Rhs>)
        {
            return std::cmp_equal(lhs.value, rhs);
        }
        else
        {
            return lhs.value == rhs;
        }
    }

    template <details::Concept::Arithmetic Lhs, details::Concept::Arithmetic Rhs>
    inline constexpr bool operator !=(Numeric<Lhs> lhs, Rhs rhs) noexcept
    {
        if constexpr (details::Concept::SingedIntAndUnsignedInt<Lhs, Rhs>)
        {
            return std::cmp_not_equal(lhs.value, rhs);
        }
        else
        {
            return lhs.value != rhs;
        }
    }

    template <details::Concept::Arithmetic Lhs, details::Concept::Arithmetic Rhs>
    inline constexpr bool operator <(Numeric<Lhs> lhs, Rhs rhs) noexcept
    {
        if constexpr (details::Concept::SingedIntAndUnsignedInt<Lhs, Rhs>)
        {
            return std::cmp_less(lhs.value, rhs);
        }
        else
        {
            return lhs.value < rhs;
        }
    }

    template <details::Concept::Arithmetic Lhs, details::Concept::Arithmetic Rhs>
    inline constexpr bool operator >(Numeric<Lhs> lhs, Rhs rhs) noexcept
    {
        if constexpr (details::Concept::SingedIntAndUnsignedInt<Lhs, Rhs>)
        {
            return std::cmp_greater(lhs.value, rhs);
        }
        else
        {
            return lhs.value > rhs;
        }
    }

    template <details::Concept::Arithmetic Lhs, details::Concept::Arithmetic Rhs>
    inline constexpr bool operator <=(Numeric<Lhs> lhs, Rhs rhs) noexcept
    {
        if constexpr (details::Concept::SingedIntAndUnsignedInt<Lhs, Rhs>)
        {
            return std::cmp_less_equal(lhs.value, rhs);
        }
        else
        {
            return lhs.value <= rhs;
        }
    }

    template <details::Concept::Arithmetic Lhs, details::Concept::Arithmetic Rhs>
    inline constexpr bool operator >=(Numeric<Lhs> lhs, Rhs rhs) noexcept
    {
        if constexpr (details::Concept::SingedIntAndUnsignedInt<Lhs, Rhs>)
        {
            return std::cmp_greater_equal(lhs.value, rhs);
        }
        else
        {
            return lhs.value >= rhs;
        }
    }

    template <details::Concept::Arithmetic Lhs, details::Concept::Arithmetic Rhs>
    inline constexpr auto operator <=>(Numeric<Lhs> lhs, Rhs rhs) noexcept
    {
        if constexpr (details::Concept::SingedIntAndUnsignedInt<Lhs, Rhs>)
        {
            if constexpr (details::Concept::SignedIntegral<Lhs>)
            {
                return (lhs.value < 0) ? std::strong_ordering::less : (static_cast<Rhs>(lhs.value) <=> rhs);
            }
            else
            {
                return (rhs < 0) ? std::strong_ordering::less : (lhs.value <=> static_cast<Lhs>(rhs));
            }
        }
        else
        {
            return lhs.value <=> rhs;
        }
    }

    template <details::Concept::Arithmetic Type>
    template <Concept::Arithmetic Other>
    inline constexpr Other Numeric<Type>::as() const noexcept
    {
        return static_cast<Other>(*this);
    }

    template <details::Concept::Arithmetic Type>
    inline constexpr Numeric<Type> Numeric<Type>::Min() noexcept
    {
        return Numeric<Type>{ std::numeric_limits<Type>::min() };
    }

    template <details::Concept::Arithmetic Type>
    inline constexpr Numeric<Type> Numeric<Type>::Max() noexcept
    {
        return Numeric<Type>{ std::numeric_limits<Type>::max() };
    }
}

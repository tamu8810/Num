# pragma once
# include <istream>
# include <ostream>
# include <string>
# include <format>
# include "details/AutoCast.hpp"
# include "Concepts.hpp"

namespace num
{
    /// @brief 基本数値型ラッパー
    /// @tparam Type 要素の数値型
    template <details::Concept::Arithmetic Type>
    class Numeric final
    {
    public:

        /// @brief 要素の型
        using value_type = Type;

        /// @brief 要素へのポインタ型
        using pointer = value_type*;

        /// @brief 要素への const ポインタ型
        using const_pointer = const value_type*;

        /// @brief 要素への参照型
        using reference = value_type&;

        /// @brief 要素への const 参照型
        using const_reference = const value_type&;

        /// @brief 値
        value_type value;

        /// @brief 値を 0 で初期化します。
        [[nodiscard]]
        constexpr Numeric() noexcept;

        /// @brief 他の Numeric から値をコピーして初期化します。
        /// @tparam Other 他の Numeric の数値型
        /// @param other 他の Numeric
        template <details::Concept::Arithmetic Other>
        [[nodiscard]]
        constexpr Numeric(Numeric<Other> other) noexcept;

        /// @brief 基本数値型から値をコピーして初期化します。
        /// @tparam Other 基本数値型の型
        /// @param other 基本数値型
        template <details::Concept::Arithmetic Other>
        [[nodiscard]]
        constexpr Numeric(Other other) noexcept;

        template <details::Concept::Arithmetic Other>
        constexpr Numeric& operator =(Numeric<Other> other) noexcept;

        template <details::Concept::Arithmetic Other>
        constexpr Numeric& operator =(Other other) noexcept;

        [[nodiscard]]
        constexpr Numeric operator +() const noexcept;

        [[nodiscard]]
        constexpr Numeric operator -() const noexcept;

        constexpr Numeric& operator ++() noexcept;

        constexpr Numeric& operator --() noexcept;

        constexpr Numeric operator ++(int) noexcept;

        constexpr Numeric operator --(int) noexcept;

        template <details::Concept::Arithmetic Other>
        [[nodiscard]]
        explicit constexpr operator Numeric<Other>() const noexcept;

        template <details::Concept::Arithmetic Other>
        [[nodiscard]]
        explicit constexpr operator Other() const noexcept;

        template <details::Concept::Arithmetic Other>
        constexpr Numeric& operator +=(Numeric<Other> other) noexcept;

        template <details::Concept::Arithmetic Other>
        constexpr Numeric& operator -=(Numeric<Other> other) noexcept;

        template <details::Concept::Arithmetic Other>
        constexpr Numeric& operator *=(Numeric<Other> other) noexcept;

        template <details::Concept::Arithmetic Other>
        constexpr Numeric& operator /=(Numeric<Other> other) noexcept;

        template <details::Concept::Arithmetic Other>
        constexpr Numeric& operator %=(Numeric<Other> other) noexcept;

        template <details::Concept::Arithmetic Other>
        constexpr Numeric& operator +=(Other other) noexcept;

        template <details::Concept::Arithmetic Other>
        constexpr Numeric& operator -=(Other other) noexcept;

        template <details::Concept::Arithmetic Other>
        constexpr Numeric& operator *=(Other other) noexcept;

        template <details::Concept::Arithmetic Other>
        constexpr Numeric& operator /=(Other other) noexcept;

        template <details::Concept::Arithmetic Other>
        constexpr Numeric& operator %=(Other other) noexcept;

        /// @brief 指定した数値型にキャストします。
        /// @tparam Other キャスト後の型
        /// @return キャストした結果
        template <Concept::Arithmetic Other>
        [[nodiscard]]
        constexpr Other as() const noexcept;

        /// @brief 型の最小値を返します。
        /// @return 型の最小値
        [[nodiscard]]
        static constexpr Numeric Min() noexcept;

        /// @brief 型の最大値を返します。
        /// @return 型の最大値
        [[nodiscard]]
        static constexpr Numeric Max() noexcept;

        template <class CharType>
        friend std::basic_istream<CharType>& operator >>(std::basic_istream<CharType>& input, Numeric& value)
        {
            return input >> value.value;
        }

        template <class CharType>
        friend std::basic_ostream<CharType>& operator <<(std::basic_ostream<CharType>& output, Numeric value)
        {
            return output << value.value;
        }
    };

    template <details::Concept::Arithmetic Lhs, details::Concept::Arithmetic Rhs>
    [[nodiscard]]
    constexpr auto operator +(Numeric<Lhs> lhs, Numeric<Rhs> rhs) noexcept;

    template <details::Concept::Arithmetic Lhs, details::Concept::Arithmetic Rhs>
    [[nodiscard]]
    constexpr auto operator -(Numeric<Lhs> lhs, Numeric<Rhs> rhs) noexcept;

    template <details::Concept::Arithmetic Lhs, details::Concept::Arithmetic Rhs>
    [[nodiscard]]
    constexpr auto operator *(Numeric<Lhs> lhs, Numeric<Rhs> rhs) noexcept;

    template <details::Concept::Arithmetic Lhs, details::Concept::Arithmetic Rhs>
    [[nodiscard]]
    constexpr auto operator /(Numeric<Lhs> lhs, Numeric<Rhs> rhs) noexcept;

    template <details::Concept::Arithmetic Lhs, details::Concept::Arithmetic Rhs>
    [[nodiscard]]
    constexpr auto operator %(Numeric<Lhs> lhs, Numeric<Rhs> rhs) noexcept;

    template <details::Concept::Arithmetic Lhs, details::Concept::Arithmetic Rhs>
    [[nodiscard]]
    constexpr auto operator +(Lhs lhs, Numeric<Rhs> rhs) noexcept;

    template <details::Concept::Arithmetic Lhs, details::Concept::Arithmetic Rhs>
    [[nodiscard]]
    constexpr auto operator -(Lhs lhs, Numeric<Rhs> rhs) noexcept;

    template <details::Concept::Arithmetic Lhs, details::Concept::Arithmetic Rhs>
    [[nodiscard]]
    constexpr auto operator *(Lhs lhs, Numeric<Rhs> rhs) noexcept;

    template <details::Concept::Arithmetic Lhs, details::Concept::Arithmetic Rhs>
    [[nodiscard]]
    constexpr auto operator /(Lhs lhs, Numeric<Rhs> rhs) noexcept;

    template <details::Concept::Arithmetic Lhs, details::Concept::Arithmetic Rhs>
    [[nodiscard]]
    constexpr auto operator %(Lhs lhs, Numeric<Rhs> rhs) noexcept;

    template <details::Concept::Arithmetic Lhs, details::Concept::Arithmetic Rhs>
    [[nodiscard]]
    constexpr auto operator +(Numeric<Lhs> lhs, Rhs rhs) noexcept;

    template <details::Concept::Arithmetic Lhs, details::Concept::Arithmetic Rhs>
    [[nodiscard]]
    constexpr auto operator -(Numeric<Lhs> lhs, Rhs rhs) noexcept;

    template <details::Concept::Arithmetic Lhs, details::Concept::Arithmetic Rhs>
    [[nodiscard]]
    constexpr auto operator *(Numeric<Lhs> lhs, Rhs rhs) noexcept;

    template <details::Concept::Arithmetic Lhs, details::Concept::Arithmetic Rhs>
    [[nodiscard]]
    constexpr auto operator /(Numeric<Lhs> lhs, Rhs rhs) noexcept;

    template <details::Concept::Arithmetic Lhs, details::Concept::Arithmetic Rhs>
    [[nodiscard]]
    constexpr auto operator %(Numeric<Lhs> lhs, Rhs rhs) noexcept;

    template <details::Concept::Arithmetic Lhs, details::Concept::Arithmetic Rhs>
    [[nodiscard]]
    constexpr bool operator ==(Numeric<Lhs> lhs, Numeric<Rhs> rhs) noexcept;

    template <details::Concept::Arithmetic Lhs, details::Concept::Arithmetic Rhs>
    [[nodiscard]]
    constexpr bool operator !=(Numeric<Lhs> lhs, Numeric<Rhs> rhs) noexcept;

    template <details::Concept::Arithmetic Lhs, details::Concept::Arithmetic Rhs>
    [[nodiscard]]
    constexpr bool operator <(Numeric<Lhs> lhs, Numeric<Rhs> rhs) noexcept;

    template <details::Concept::Arithmetic Lhs, details::Concept::Arithmetic Rhs>
    [[nodiscard]]
    constexpr bool operator >(Numeric<Lhs> lhs, Numeric<Rhs> rhs) noexcept;

    template <details::Concept::Arithmetic Lhs, details::Concept::Arithmetic Rhs>
    [[nodiscard]]
    constexpr bool operator <=(Numeric<Lhs> lhs, Numeric<Rhs> rhs) noexcept;

    template <details::Concept::Arithmetic Lhs, details::Concept::Arithmetic Rhs>
    [[nodiscard]]
    constexpr bool operator >=(Numeric<Lhs> lhs, Numeric<Rhs> rhs) noexcept;

    template <details::Concept::Arithmetic Lhs, details::Concept::Arithmetic Rhs>
    [[nodiscard]]
    constexpr auto operator <=>(Numeric<Lhs> lhs, Numeric<Rhs> rhs) noexcept;

    template <details::Concept::Arithmetic Lhs, details::Concept::Arithmetic Rhs>
    [[nodiscard]]
    constexpr bool operator ==(Lhs lhs, Numeric<Rhs> rhs) noexcept;

    template <details::Concept::Arithmetic Lhs, details::Concept::Arithmetic Rhs>
    [[nodiscard]]
    constexpr bool operator !=(Lhs lhs, Numeric<Rhs> rhs) noexcept;

    template <details::Concept::Arithmetic Lhs, details::Concept::Arithmetic Rhs>
    [[nodiscard]]
    constexpr bool operator <(Lhs lhs, Numeric<Rhs> rhs) noexcept;

    template <details::Concept::Arithmetic Lhs, details::Concept::Arithmetic Rhs>
    [[nodiscard]]
    constexpr bool operator >(Lhs lhs, Numeric<Rhs> rhs) noexcept;

    template <details::Concept::Arithmetic Lhs, details::Concept::Arithmetic Rhs>
    [[nodiscard]]
    constexpr bool operator <=(Lhs lhs, Numeric<Rhs> rhs) noexcept;

    template <details::Concept::Arithmetic Lhs, details::Concept::Arithmetic Rhs>
    [[nodiscard]]
    constexpr bool operator >=(Lhs lhs, Numeric<Rhs> rhs) noexcept;

    template <details::Concept::Arithmetic Lhs, details::Concept::Arithmetic Rhs>
    [[nodiscard]]
    constexpr auto operator <=>(Lhs lhs, Numeric<Rhs> rhs) noexcept;

    template <details::Concept::Arithmetic Lhs, details::Concept::Arithmetic Rhs>
    [[nodiscard]]
    constexpr bool operator ==(Numeric<Lhs> lhs, Rhs rhs) noexcept;

    template <details::Concept::Arithmetic Lhs, details::Concept::Arithmetic Rhs>
    [[nodiscard]]
    constexpr bool operator !=(Numeric<Lhs> lhs, Rhs rhs) noexcept;

    template <details::Concept::Arithmetic Lhs, details::Concept::Arithmetic Rhs>
    [[nodiscard]]
    constexpr bool operator <(Numeric<Lhs> lhs, Rhs rhs) noexcept;

    template <details::Concept::Arithmetic Lhs, details::Concept::Arithmetic Rhs>
    [[nodiscard]]
    constexpr bool operator >(Numeric<Lhs> lhs, Rhs rhs) noexcept;

    template <details::Concept::Arithmetic Lhs, details::Concept::Arithmetic Rhs>
    [[nodiscard]]
    constexpr bool operator <=(Numeric<Lhs> lhs, Rhs rhs) noexcept;

    template <details::Concept::Arithmetic Lhs, details::Concept::Arithmetic Rhs>
    [[nodiscard]]
    constexpr bool operator >=(Numeric<Lhs> lhs, Rhs rhs) noexcept;

    template <details::Concept::Arithmetic Lhs, details::Concept::Arithmetic Rhs>
    [[nodiscard]]
    constexpr auto operator <=>(Numeric<Lhs> lhs, Rhs rhs) noexcept;
}

template <num::details::Concept::Arithmetic Type>
struct std::formatter<num::Numeric<Type>> : std::formatter<std::string>
{
    template <class FormatContext>
    auto format(num::Numeric<Type> value, FormatContext& ctx) const
    {
        return std::formatter<std::string>::format(std::to_string(value.value), ctx);
    }
};

# include "inline/Numeric.ipp"

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasano <shunkotkg0141@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 08:26:13 by sasano            #+#    #+#             */
/*   Updated: 2025/06/05 17:45:09 by sasano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

// Default constructor
Fixed::Fixed() : _value(0)
{
    return ;
}

// Copy constructor
Fixed::Fixed(Fixed const & src)
{
    *this = src;
    return ;
}

// 整数を固定小数点値に変換するコンストラクタ
Fixed::Fixed(int const value)
{
    this->_value = value << Fixed::_fractionalBits;
    return ;
}

// 浮動小数点数を固定小数点値に変換するコンストラクタ
Fixed::Fixed(float const value)
{
    this->_value = roundf(value * (1 << Fixed::_fractionalBits));
    return ;
}

// Destructor
Fixed::~Fixed()
{
    return ;
}

Fixed & Fixed::operator=(Fixed const & src)
{
    if (this != &src)
        this->_value = src.getRawBits();
    return *this;
}

bool Fixed::operator>(Fixed const & src)
{
    return this->toFloat() > src.toFloat();
}

bool Fixed::operator<(Fixed const & src)
{
    return this->toFloat() < src.toFloat();
}

bool Fixed::operator>=(Fixed const & src)
{
    return this->toFloat() >= src.toFloat();
}

bool Fixed::operator<=(Fixed const & src)
{
    return this->toFloat() <= src.toFloat();
}

bool Fixed::operator==(Fixed const & src)
{
    return this->toFloat() == src.toFloat();
}

bool Fixed::operator!=(Fixed const & src)
{
    return this->toFloat() != src.toFloat();
}

Fixed Fixed::operator+(Fixed const & src)
{
    return (Fixed(this->toFloat() + src.toFloat()));
}

Fixed Fixed::operator-(Fixed const & src)
{
    return (Fixed(this->toFloat() - src.toFloat()));
}

Fixed Fixed::operator*(Fixed const & src)
{
    return (Fixed(this->toFloat() * src.toFloat()));
}

Fixed Fixed::operator/(Fixed const & src)
{
    return (Fixed(this->toFloat() / src.toFloat()));
}

// 前置インクリメント
Fixed& Fixed::operator++(void) {
    this->_value++;  // 内部の値を増加
    return *this;    // 更新後の自分自身を参照として返す
}

// 後置インクリメント
Fixed Fixed::operator++(int) {
    Fixed tmp(*this);  // 現在の値を一時保存
    ++(*this);         // 前置インクリメントを呼び出す
    return tmp;        // 更新前の値を返す
}

// 前置デクリメント
Fixed& Fixed::operator--(void) {
    this->_value--;  // 内部の値を減少
    return *this;    // 更新後の自分自身を参照として返す
}

// 後置デクリメント
Fixed Fixed::operator--(int) {
    Fixed tmp(*this);  // 現在の値を一時保存
    --(*this);         // 前置デクリメントを呼び出す
    return tmp;        // 更新前の値を返す
}

int Fixed::getRawBits(void) const
{
    return this->_value;
}

void Fixed::setRawBits(int const raw)
{
    this->_value = raw;
    return ;
}

// 固定小数点値を浮動小数点数に変換する関数
float Fixed::toFloat( void ) const
{
    return (float)this->_value / (1 << Fixed::_fractionalBits);
}

// 固定小数点値を整数値に変換する関数
int Fixed::toInt( void ) const
{
    return this->_value >> Fixed::_fractionalBits;
}

// 演算子のオーバーロード
std::ostream & operator<<(std::ostream & o, Fixed const & src)
{
    o << src.toFloat();
    return o;
}

Fixed & Fixed::min(Fixed & a, Fixed & b)
{
    if (a.toFloat() <= b.toFloat())
        return a;
    else
        return b;
}

Fixed & Fixed::max(Fixed & a, Fixed & b)
{
    if (a.toFloat() >= b.toFloat())
        return a;
    else
        return b;
}

Fixed const & Fixed::min(Fixed const & a, Fixed const & b)
{
    if (a.toFloat() <= b.toFloat())
        return a;
    else
        return b;
}
Fixed const & Fixed::max(Fixed const & a, Fixed const & b)
{
    if (a.toFloat() >= b.toFloat())
        return a;
    else
        return b;
}

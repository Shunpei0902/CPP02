/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasano <shunkotkg0141@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 08:26:13 by sasano            #+#    #+#             */
/*   Updated: 2025/01/18 22:05:45 by sasano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

// Default constructor
Fixed::Fixed() : _value(0)
{
    std::cout << "Default constructor called" << std::endl;
    return ;
}

// Copy constructor
Fixed::Fixed(Fixed const & src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
    return ;
}

// 整数を固定小数点値に変換するコンストラクタ
Fixed::Fixed(int const value)
{
    std::cout << "Int constructor called" << std::endl;
    this->_value = value << Fixed::_fractionalBits;
    return ;
}

// 浮動小数点数を固定小数点値に変換するコンストラクタ
Fixed::Fixed(float const value)
{
    std::cout << "Float constructor called" << std::endl;
    this->_value = roundf(value * (1 << Fixed::_fractionalBits));
    return ;
}

// Destructor
Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
    return ;
}

Fixed & Fixed::operator=(Fixed const & src)
{
    std::cout << "Assignation operator called" << std::endl;
    if (this != &src)
        this->_value = src.getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->_value;
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
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
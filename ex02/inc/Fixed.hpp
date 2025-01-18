/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasano <shunkotkg0141@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 10:54:52 by sasano            #+#    #+#             */
/*   Updated: 2025/01/18 23:08:31 by sasano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed 
{
    private:
        int _value;
        static const int _fractionalBits;

    public:
        
        Fixed();
        Fixed(Fixed const & src);
        Fixed(int const value);
        Fixed(float const value);
        ~Fixed();
        Fixed & operator=(Fixed const & src);
        bool operator>(Fixed const & src);
        bool operator<(Fixed const & src);
        bool operator>=(Fixed const & src);
        bool operator<=(Fixed const & src);
        bool operator==(Fixed const & src);
        bool operator!=(Fixed const & src);
        Fixed operator+(Fixed const & src);
        Fixed operator-(Fixed const & src);
        Fixed operator*(Fixed const & src);
        Fixed operator/(Fixed const & src);
        Fixed &operator++(void);
        Fixed operator++(int);
        Fixed &operator--(void);
        Fixed operator--(int);

        int getRawBits(void) const;
        void setRawBits(int const raw);

        float toFloat( void ) const;
        int toInt( void ) const;

        static  Fixed & min(Fixed & a, Fixed & b);
        static  Fixed & max(Fixed & a, Fixed & b);
        static  const Fixed & min(Fixed const & a, Fixed const & b);
        static  const Fixed & max(Fixed const & a, Fixed const & b);
};

std::ostream & operator<<(std::ostream & o, Fixed const & src);
#endif

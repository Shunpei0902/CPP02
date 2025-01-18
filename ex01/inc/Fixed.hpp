/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasano <shunkotkg0141@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 10:54:52 by sasano            #+#    #+#             */
/*   Updated: 2025/01/18 22:02:52 by sasano           ###   ########.fr       */
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

        int getRawBits(void) const;
        void setRawBits(int const raw);

        float toFloat( void ) const;
        int toInt( void ) const;
};

std::ostream & operator<<(std::ostream & o, Fixed const & src);
#endif

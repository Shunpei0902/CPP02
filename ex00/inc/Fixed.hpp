/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasano <shunkotkg0141@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 10:54:52 by sasano            #+#    #+#             */
/*   Updated: 2025/06/05 17:57:25 by sasano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed 
{
    private:
        int _value;
        static const int _fractionalBits;

    public:
        
        Fixed();
        Fixed(Fixed const & src);
        ~Fixed();
        Fixed & operator=(Fixed const & src);

        int getRawBits(void) const;
        void setRawBits(int const raw);
};

#endif

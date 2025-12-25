/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 05:08:37 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/12/25 14:33:52 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
#include <ostream>

class Fixed {
    private:
        int rawBits;
        static const int fractionalBits = 8;
    public:
        Fixed();
        ~Fixed();
        Fixed(const Fixed &);
        Fixed &operator=(const Fixed &);
        Fixed(const int n);
        Fixed(const float f);
        bool operator>(const Fixed &) const;
        bool operator<(const Fixed &) const;
        bool operator>=(const Fixed &) const;
        bool operator<=(const Fixed &) const;
        bool operator==(const Fixed &) const;
        bool operator!=(const Fixed &) const;

        Fixed operator+(const Fixed &) const;
        Fixed operator-(const Fixed &) const;
        Fixed operator*(const Fixed &) const;
        Fixed operator/(const Fixed &) const;

        Fixed &operator++();
        Fixed operator++(int);
        Fixed &operator--();
        Fixed operator--(int);

        static Fixed& min(Fixed &a, Fixed &b);
        static const Fixed &min(const Fixed &a, const Fixed &b);
        static Fixed &max(Fixed &a, Fixed &b);
        static const Fixed &max(const Fixed &a, const Fixed &b);
        
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;
};

std::ostream &operator<<(std::ostream &os, const Fixed &f);

#endif
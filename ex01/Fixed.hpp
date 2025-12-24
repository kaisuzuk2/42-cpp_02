/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-24 05:08:37 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025-12-24 05:08:37 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed {
    private:
        int rawBits;
        static const int fractionalBits = 8;
    public:
        Fixed();
        ~Fixed();
        Fixed(const Fixed &);
        Fixed &operator=(const Fixed &);
        int getRawBits(void) const;
        void setRawBits(int const raw);
};

#endif
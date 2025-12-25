/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-24 05:14:19 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025-12-24 05:14:19 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(): rawBits(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &inst) {
    std::cout << "Copy constructor called" << std::endl;
    *this = inst;
}

Fixed &Fixed::operator=(const Fixed &rhs) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs) {
        this->rawBits = rhs.getRawBits();
    }
    return (*this);
}

Fixed::Fixed(const int n) {
    this->rawBits = n << fractionalBits;
}

Fixed::Fixed(const float f) {
    this->rawBits = static_cast<int>(roundf(f * (1 << fractionalBits)));
}

int Fixed::getRawBits() const {
    return (this->rawBits);
}

void Fixed::setRawBits(int const raw) {
    this->rawBits = raw;
}

int Fixed::toInt() const {
    return (this->getRawBits() >> this->fractionalBits);
}

float Fixed::toFloat() const {
    return (static_cast<float>(this->getRawBits()) / (1 << this->fractionalBits));
}

std::ostream &operator<<(std::ostream &os, const Fixed &f) {
    os << f.toFloat();
    return (os);
}
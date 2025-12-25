/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 05:14:19 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/12/25 14:42:21 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(): rawBits(0) {}

Fixed::~Fixed() {}

Fixed::Fixed(const Fixed &inst) {
    *this = inst;
}

Fixed &Fixed::operator=(const Fixed &rhs) {
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

bool Fixed::operator>(const Fixed &rhs) const {
    return (this->getRawBits() > rhs.getRawBits());
}

bool Fixed::operator<(const Fixed &rhs) const {
    return (this->getRawBits() < rhs.getRawBits());
}

bool Fixed::operator>=(const Fixed &rhs) const {
    return (this->getRawBits() >= rhs.getRawBits());
}

bool Fixed::operator<=(const Fixed &rhs) const {
    return (this->getRawBits() <= rhs.getRawBits());
}

bool Fixed::operator==(const Fixed &rhs) const {
    return (this->getRawBits() == rhs.getRawBits());
}

bool Fixed::operator!=(const Fixed &rhs) const {
    return (this->getRawBits() != rhs.getRawBits());
}

Fixed Fixed::operator+(const Fixed &rhs) const {
    Fixed tmp;
    
    tmp.setRawBits(this->getRawBits() + rhs.getRawBits());
    return (tmp);
}

Fixed Fixed::operator-(const Fixed &rhs) const {
    Fixed tmp;
    
    tmp.setRawBits(this->getRawBits() - rhs.getRawBits());
    return (tmp);
}

Fixed Fixed::operator*(const Fixed &rhs) const {
    Fixed tmp;
    long long a;
    long long b;

    a = this->getRawBits();
    b = rhs.getRawBits();
    tmp.setRawBits(static_cast<int>((a * b) >> fractionalBits));
    return (tmp);
}

Fixed Fixed::operator/(const Fixed &rhs) const {
    Fixed tmp; 
    long long a;
    long long b;

    a = this->getRawBits();
    b = rhs.getRawBits();
    if (b == 0)
    {
        tmp.setRawBits(0);
        return (tmp);
    }
    tmp.setRawBits((a << this->fractionalBits) / b);
    return (tmp);
}

Fixed &Fixed::operator++() {
    this->setRawBits(this->getRawBits() + 1);
    return (*this);
}

Fixed Fixed::operator++(int) {
    Fixed tmp (*this);

    this->setRawBits(this->getRawBits() + 1);
    return (tmp);
}

Fixed &Fixed::operator--() {
    this->setRawBits(this->getRawBits() - 1);
    return (*this);
}

Fixed Fixed::operator--(int) {
    Fixed tmp(*this);

    this->setRawBits(this->getRawBits() - 1);
    return (tmp);
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
    return (a > b ? b : a);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
    return (a > b ? b : a);
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
    return (a > b ? a : b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
    return (a > b ? a : b);
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
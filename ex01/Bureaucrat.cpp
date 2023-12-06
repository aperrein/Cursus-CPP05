/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 10:29:47 by aperrein          #+#    #+#             */
/*   Updated: 2023/10/23 10:29:49 by aperrein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string n, unsigned int g): _name(n), _grade(g)
{
    if (g < 1)
        throw GradeTooHighException();
    if (g > 150)
        throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat()
{

}

Bureaucrat::Bureaucrat(Bureaucrat const & copy): _name(copy.getName())
{
    *this = copy;
}

Bureaucrat &        Bureaucrat::operator=(Bureaucrat const & rhs)
{
    this->_grade = rhs.getGrade();
    return (*this);
}

std::string             Bureaucrat::getName() const
{
    return (this->_name);
}

unsigned int            Bureaucrat::getGrade() const
{
    return (this->_grade);
}

void                    Bureaucrat::increment()
{
    if (this->_grade - 1 < 1)
        throw GradeTooHighException();
    this->_grade -= 1;
}

void                    Bureaucrat::decrement()
{
    if (this->_grade + 1 > 150)
        throw GradeTooLowException();
    this->_grade += 1;
}

std::ostream &      operator<<(std::ostream & o, Bureaucrat const & b)
{
    o << "Bureaucrat " << b.getName() << " has a grade " << b.getGrade() << "." << std::endl;
    return (o);
}

char const *        Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Bureaucrat's grade is too high");
}

char const *        Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Bureaucrat's grade is too low");
}

void                Bureaucrat::signForm(Form & f) const
{
    try
    {
        f.beSigned(*this);
        std::cout << this->_name << " signed " << f.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << this->_name << " couldn't sign " << f.getName() << " because " << e.what() << std::endl;
    }
    
}
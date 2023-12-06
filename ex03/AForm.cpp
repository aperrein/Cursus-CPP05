/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:43:11 by aperrein          #+#    #+#             */
/*   Updated: 2023/10/25 10:05:38 by aperrein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(std::string n,unsigned int s, unsigned int e): _name(n), _signed(false), _gradSign(s),
_gradExec(e)
{
    if (s < 1 | e < 1)
        throw GradeTooHighException();
    if (s > 150 | e > 150)
        throw GradeTooLowException();
}

AForm::~AForm()
{

}

AForm::AForm(AForm const & copy): _name(copy.getName()), _gradSign(copy.getGradSign()),
_gradExec(copy.getGradExec())
{
    *this = copy;
}

AForm &      AForm::operator=(AForm const & rhs)
{
    this->_signed = rhs.getSigned();
    return (*this);
}

std::string             AForm::getName() const
{
    return (this->_name);
}

bool                    AForm::getSigned() const
{
    return (this->_signed);
}

unsigned int            AForm::getGradSign() const
{
    return (this->_gradSign);
}

unsigned int            AForm::getGradExec() const
{
    return (this->_gradExec);
}

void                    AForm::beSigned(Bureaucrat const & b)
{
    if (b.getGrade() > this->_gradSign)
        throw GradeTooLowException();
    this->_signed = true;
}


std::ostream &      operator<<(std::ostream & o, AForm const & f)
{
    std::string    s;

    if (f.getSigned())
        s = " is signed.";
    else
        s = " is not signed.";

    o << "AForm " << f.getName() << s << std::endl;
    o << "It requires grade " << f.getGradSign() << " to be signed and grade " << f.getGradExec();
    o << " to be executed." << std::endl;
    return (o);
}

char const *        AForm::GradeTooHighException::what() const throw()
{
    return ("Grade is too high");
}

char const *        AForm::GradeTooLowException::what() const throw()
{
    return ("Grade is too low");
}

char const *        AForm::NotSigned::what() const throw()
{
    return ("it's not signed");
}

void                AForm::tryExecute(Bureaucrat const & executor) const
{
    if (!this->_signed)
        throw NotSigned();
    else if(executor.getGrade() > this->_gradExec)
        throw GradeTooLowException();
    this->execute(executor);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:43:11 by aperrein          #+#    #+#             */
/*   Updated: 2023/10/23 13:43:13 by aperrein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(std::string n,unsigned int s, unsigned int e): _name(n), _signed(false), _gradSign(s),
_gradExec(e)
{
    if (s < 1 | e < 1)
        throw GradeTooHighException();
    if (s > 150 | e > 150)
        throw GradeTooLowException();
}

Form::~Form()
{

}

Form::Form(Form const & copy): _name(copy.getName()), _gradSign(copy.getGradSign()),
_gradExec(copy.getGradExec())
{
    *this = copy;
}

Form &      Form::operator=(Form const & rhs)
{
    this->_signed = rhs.getSigned();
    return (*this);
}

std::string             Form::getName() const
{
    return (this->_name);
}

bool                    Form::getSigned() const
{
    return (this->_signed);
}

unsigned int            Form::getGradSign() const
{
    return (this->_gradSign);
}

unsigned int            Form::getGradExec() const
{
    return (this->_gradExec);
}

void                    Form::beSigned(Bureaucrat const & b)
{
    if (b.getGrade() > this->_gradSign)
        throw GradeTooLowException();
    this->_signed = true;
}


std::ostream &      operator<<(std::ostream & o, Form const & f)
{
    std::string    s;

    if (f.getSigned())
        s = " is signed.";
    else
        s = " is not signed.";

    o << "Form " << f.getName() << s << std::endl;
    o << "It requires grade " << f.getGradSign() << " to be signed and grade " << f.getGradExec();
    o << " to be executed." << std::endl;
    return (o);
}

char const *        Form::GradeTooHighException::what() const throw()
{
    return ("Grade is too high");
}

char const *        Form::GradeTooLowException::what() const throw()
{
    return ("Grade is too low");
}
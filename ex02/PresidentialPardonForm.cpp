/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 10:04:27 by aperrein          #+#    #+#             */
/*   Updated: 2023/10/25 10:04:29 by aperrein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string t): AForm("presidential pardon", 25, 5),
_target(t)
{
    //std::cout << this->getName() << this->getGradSign() << this->getGradExec() << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & copy):
AForm(copy)
{
    *this = copy;
}

PresidentialPardonForm &     PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs)
{
    this->_target = rhs.getTarget();
    return (*this);
}

std::string             PresidentialPardonForm::getTarget() const
{
    return (this->_target);
}

void                    PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
    (void)executor;  
}

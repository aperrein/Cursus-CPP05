/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 10:04:00 by aperrein          #+#    #+#             */
/*   Updated: 2023/10/25 10:04:01 by aperrein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string t): AForm("robotomy request", 72, 45),
_target(t)
{
    //std::cout << this->getName() << this->getGradSign() << this->getGradExec() << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & copy):
AForm(copy)
{
    *this = copy;
}

RobotomyRequestForm &     RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs)
{
    this->_target = rhs.getTarget();
    return (*this);
}

std::string             RobotomyRequestForm::getTarget() const
{
    return (this->_target);
}

void                    RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    
    int     random = rand() % 2;

    std::cout << "|||||| Some drilling noises ||||||" << std::endl;

    if (random)
        std::cout << "\033[32m" << this->_target << " has been robotomized." << "\033[0m" << std::endl;
    else
        std::cout << "\033[31m" << "Robotomy on " << this->_target << " failed." << "\033[0m" << std::endl;
    (void)executor;  
}

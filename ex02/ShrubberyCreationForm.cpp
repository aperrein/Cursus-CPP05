/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 10:03:29 by aperrein          #+#    #+#             */
/*   Updated: 2023/10/25 10:03:31 by aperrein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string t): AForm("Shrubbery creation", 145, 137),
_target(t)
{
    //std::cout << this->getName() << this->getGradSign() << this->getGradExec() << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & copy):
AForm(copy)
{
    *this = copy;
}

ShrubberyCreationForm &     ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs)
{
    this->_target = rhs.getTarget();
    return (*this);
}

std::string             ShrubberyCreationForm::getTarget() const
{
    return (this->_target);
}

void                    ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    std::string         tree =
    "    ###    \n"
    "   #o###   \n"
    " #####o### \n"
    "#o#|#|#/###\n"
    " ###||/#o# \n"
    "  # }|{  # \n"
    "    }|{    \n";

    (void)executor;

    std::ofstream   ofs((this->_target + "_shrubbery").c_str() );
    if (!ofs.is_open())
	{
		std::cout << "Coulnd't open the output file" << std::endl;
		return ;
	}
    ofs << tree;
}
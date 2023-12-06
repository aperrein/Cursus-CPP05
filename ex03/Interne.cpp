/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Interne.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 11:47:19 by aperrein          #+#    #+#             */
/*   Updated: 2023/10/26 11:47:24 by aperrein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Interne.hpp"

Interne::Interne()
{}

Interne::~Interne()
{}

Interne::Interne(Interne const & copy)
{
    *this = copy;
}

Interne &       Interne::operator=(Interne const & rhs)
{
    (void)rhs;
    return (*this);
}

char const *        Interne::FormNotExist::what() const throw()
{
    return (" form doesn't exist");
}

AForm *             Interne::makeForm(std::string f, std::string t) const
{
    AForm*  (Interne::*member_fonction[3])(std::string t) const = \
        {&Interne::makePardon, &Interne::makeRobotomy, &Interne::makeShrubbery};

    std::string     form[3] = {"presidential pardon", "robotomy request", "Shrubbery creation"};

    int i = 0;
    while (i < 3)
    {
        if (form[i] == f)
            return ((this->*(member_fonction[i]))(t));
        i++;
    }
    std::cout << f;
    throw Interne::FormNotExist();
    return (0);
}

AForm *             Interne::makeShrubbery(std:: string t) const
{
    AForm *     f = new ShrubberyCreationForm(t);
    std::cout << "Intern creates " << f->getName() << std::endl;
    return (f);
}

AForm *             Interne::makePardon(std:: string t) const
{
    AForm *     f = new PresidentialPardonForm(t);
    std::cout << "Intern creates " << f->getName() << std::endl;
    return (f);
}

AForm *             Interne::makeRobotomy(std:: string t) const
{
    AForm *     f = new RobotomyRequestForm(t);
    std::cout << "Intern creates " << f->getName() << std::endl;
    return (f);
}
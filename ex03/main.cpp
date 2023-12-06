/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 10:55:55 by aperrein          #+#    #+#             */
/*   Updated: 2023/10/25 10:55:57 by aperrein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Interne.hpp"

int     main(void)
{
    srand(time(NULL));
    try
    {  
        Bureaucrat      worst("worst", 149);
        Bureaucrat      middle("middle", 40);
        Bureaucrat      best("best", 2);

        ShrubberyCreationForm   test("tester");
        RobotomyRequestForm     rob1("rob1");
        RobotomyRequestForm     rob2("rob2");
        RobotomyRequestForm     rob3("rob3");
        PresidentialPardonForm  pres1("pres1");

        Interne     someRandomIntern;


        worst.signForm(test);
        worst.executeForm(test);
        middle.signForm(test);
        middle.executeForm(test);
        std::cout << std::endl;

        best.signForm(rob1);
        best.signForm(rob2);
        best.signForm(rob3);
        best.executeForm(rob1);
        best.executeForm(rob2);
        best.executeForm(rob3);
        std::cout << std::endl;

        best.signForm(pres1);
        best.executeForm(pres1);
        std::cout << std::endl;

        AForm*   rrf;

        rrf = someRandomIntern.makeForm("robotomy request", "Correcteur");
        best.signForm(*rrf);
        best.executeForm(*rrf);
        delete rrf;
        std::cout << std::endl;

        rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
        best.signForm(*rrf);
        best.executeForm(*rrf);
        delete rrf;
        std::cout << std::endl;

        rrf = someRandomIntern.makeForm("Shrubbery creation", "home");
        best.signForm(*rrf);
        best.executeForm(*rrf);
        delete rrf;
        std::cout << std::endl;

        rrf = someRandomIntern.makeForm("wrong request", "Bender");
        best.signForm(*rrf);
        best.executeForm(*rrf);
        delete rrf;

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }




    return(0);
}

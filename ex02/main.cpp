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
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }




    return(0);
}

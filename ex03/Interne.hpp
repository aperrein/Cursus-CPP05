/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Interne.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 11:47:10 by aperrein          #+#    #+#             */
/*   Updated: 2023/10/26 11:47:12 by aperrein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNE_HPP
# define INTERNE_HPP

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Interne
{
private:
        AForm *         makeShrubbery(std::string t) const;
        AForm *         makePardon(std::string t) const;
        AForm *         makeRobotomy(std::string t) const;

public:
        Interne();
        ~Interne();
        Interne(Interne const & copy);
        Interne &   operator=(Interne const & rhs);

        AForm *     makeForm(std::string f, std::string t) const;

    class FormNotExist : public std::exception
    {
    public:
            virtual char const  *what() const throw();
    };

};

#endif

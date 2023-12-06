/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:43:06 by aperrein          #+#    #+#             */
/*   Updated: 2023/10/25 10:06:18 by aperrein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <fstream>
# include <exception>
# include <cstdlib>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
        std::string const       _name;
        bool                    _signed;
        unsigned int const      _gradSign;
        unsigned int const      _gradExec;
        AForm();

public:
        AForm(std::string n,unsigned int s, unsigned int e);
        virtual ~AForm();
        AForm(AForm const & copy);
        AForm &      operator=(AForm const & rhs);

        std::string         getName() const;
        bool                getSigned() const;
        unsigned int        getGradSign() const;
        unsigned int        getGradExec() const;

        void                beSigned(Bureaucrat const & b);

        void                tryExecute(Bureaucrat const & executor) const;
        virtual void        execute(Bureaucrat const & executor) const = 0;

    class GradeTooHighException : public std::exception {
    public:
            virtual char const  *what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
            virtual char const  *what() const throw();
    };

    class NotSigned : public std::exception {
    public:
            virtual char const  *what() const throw();
    };
};

std::ostream &      operator<<(std::ostream & o, AForm const & f);
#endif

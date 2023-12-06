/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 10:03:35 by aperrein          #+#    #+#             */
/*   Updated: 2023/10/25 10:03:40 by aperrein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
            std::string         _target;
            ShrubberyCreationForm();

public:
            ShrubberyCreationForm(std::string t);
            ~ShrubberyCreationForm();
            ShrubberyCreationForm(ShrubberyCreationForm const & copy);
            ShrubberyCreationForm &     operator=(ShrubberyCreationForm const & rhs);

            std::string         getTarget() const;

            void                execute(Bureaucrat const & executor) const;
};

#endif
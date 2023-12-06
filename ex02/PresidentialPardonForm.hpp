/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 10:04:35 by aperrein          #+#    #+#             */
/*   Updated: 2023/10/25 10:04:37 by aperrein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
            std::string         _target;
            PresidentialPardonForm();

public:
            PresidentialPardonForm(std::string t);
            ~PresidentialPardonForm();
            PresidentialPardonForm(PresidentialPardonForm const & copy);
            PresidentialPardonForm &     operator=(PresidentialPardonForm const & rhs);

            std::string         getTarget() const;

            void                execute(Bureaucrat const & executor) const;
};

#endif

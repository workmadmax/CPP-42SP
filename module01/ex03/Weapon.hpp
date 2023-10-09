/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:02:30 by madmax42          #+#    #+#             */
/*   Updated: 2023/10/09 16:35:59 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class	Weapon
{
	private:
		std::string	_type;

	public:
		//constructor and destructor
		Weapon();
		Weapon(std::string type);
		~Weapon();

		//getters and setters
		const std::string& getType(void);
		void				setType(std::string type);
};

#endif
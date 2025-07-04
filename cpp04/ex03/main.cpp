/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 10:11:48 by julien            #+#    #+#             */
/*   Updated: 2025/07/04 08:27:53 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "AMateria.hpp"

int main(void)
{
    {
        std::cout << "------------------------- SUBJECT TESTS ------------------------" << std::endl;
        std::cout << "----------------------------- BEGIN ----------------------------" << std::endl;
        IMateriaSource  *src = new MateriaSource();
        std::cout << std::endl;

        AMateria    *tmp_ice = new Ice();
        std::cout << std::endl;
        src->learnMateria(tmp_ice);
        std::cout << std::endl;
        delete(tmp_ice);
        std::cout << std::endl;

        AMateria    *tmp_cure = new Cure();
        std::cout << std::endl;
        src->learnMateria(tmp_cure);
        std::cout << std::endl;
        delete(tmp_cure);
        std::cout << std::endl;

        ICharacter  *me = new Character("me");
        std::cout << std::endl;

        AMateria    *tmp;

        tmp = src->createMateria("ice");
        std::cout << std::endl;
        me->equip(tmp);
        std::cout << std::endl;
        tmp = src->createMateria("cure");
        std::cout << std::endl;
        me->equip(tmp);
        std::cout << std::endl;

        ICharacter  *bob = new Character("bob");
        std::cout << std::endl;
        
        me->use(0, *bob);
        std::cout << std::endl;
        me->use(1, *bob);
        std::cout << std::endl;

        delete(bob);
        std::cout << std::endl;
        delete(me);
        std::cout << std::endl;
        delete(src);
        std::cout << std::endl;
        std::cout << "------------------------- SUBJECT TESTS ------------------------" << std::endl;
        std::cout << "------------------------------ END -----------------------------" << std::endl;
        std::cout << std::endl;
    }
    {
        std::cout << "------------------------ MY TESTS BEGIN ------------------------" << std::endl;
        {
            std::cout << "----- MY TESTS FOR MATERIA CREATION (STACK) AND CLONE (HEAP) BEGIN -----" << std::endl;
            std::cout << "----------------- MATERIA CREATION (STACK) -----------------" << std::endl;
            
            Ice     ice;
            std::cout << std::endl;

            std::cout << "Ice type is : " << ice.getType() << std::endl;
            std::cout << std::endl;

            Cure    cure;
            std::cout << std::endl;
            
            std::cout << "Cure type is : " << cure.getType() << std::endl;
            std::cout << std::endl;

            std::cout << "----------------- MATERIA CLONE (HEAP) -----------------" << std::endl;
            AMateria*   ice_clone = ice.clone();
            std::cout << std::endl;

            if (ice_clone)
                std::cout << "Ice clone type is : " << ice_clone->getType() << std::endl;
            else
                std::cout << "Ice clone failed" << std::endl;
            std::cout << std::endl;

            AMateria*   cure_clone = cure.clone();
            std::cout << std::endl;

            if (cure_clone)
                std::cout << "Cure clone type is : " << cure_clone->getType() << std::endl;
            else
                std::cout << "Cure clone failed" << std::endl;
            std::cout << std::endl;

            delete(ice_clone);
            std::cout << std::endl;
            delete(cure_clone);
            std::cout << std::endl;
            std::cout << "----- MY TESTS FOR MATERIA CREATION (STACK) AND CLONE (HEAP) END -----" << std::endl;
        }
        {
            std::cout << "----- MY TESTS FOR CHARACTER CREATION, EQUIP, UNEQUIP, AND USE MATERIA BEGIN -----" << std::endl;
            ICharacter  *me = new Character("me");
            std::cout << std::endl;

            std::cout << me->getName() << " tries to use an empty slot (0), nothing must happen" << std::endl;
            me->use(0, *me);
            std::cout << std::endl;

            AMateria    *ice = new Ice();
            std::cout << std::endl;
            me->equip(ice);
            std::cout << std::endl;
            me->equip(new Cure());
            std::cout << std::endl;

            std::cout << me->getName() << " tries to use an invalid slot (-1), nothing must happen" << std::endl;
            me->use(-1, *me);
            std::cout << std::endl;

            std::cout << me->getName() << " use Ice (slot 0)" << std::endl;
            me->use(0, *me);
            std::cout << std::endl;
            std::cout << me->getName() << " use Cure (slot 1)" << std::endl;
            me->use(1, *me);
            std::cout << std::endl;

            me->unequip(0);
            std::cout << std::endl;

            std::cout << "Delete Ice Materia" << std::endl;
            delete(ice);
            std::cout << std::endl;

            std::cout << me->getName() << " tries to use an empty (unequiped) slot (0), nothing must happen" << std::endl;
            me->use(0, *me);
            std::cout << std::endl;

            std::cout << me->getName() << " tries to unequip an invalid slot (-1), nothing must happen" << std::endl;
            me->unequip(-1);
            std::cout << std::endl;

            std::cout << me->getName() << " tries to unequip an invalid slot (10), nothing must happen" << std::endl;
            me->unequip(10);
            std::cout << std::endl;
            
            std::cout << me->getName() << " tries to unequip an empty slot (2), nothing must happen" << std::endl;
            me->use(2, *me);
            std::cout << std::endl;
            
            std::cout << me->getName() << " tries to unequip an already unequiped slot (0), nothing must happen" << std::endl;
            me->unequip(0);
            std::cout << std::endl;

            std::cout << me->getName() << " equip Cure in the first empty slot (0)" << std::endl;
            me->equip(new Cure());
            std::cout << std::endl;

            std::cout << me->getName() << " use Cure (slot 0)" << std::endl;
            me->use(0, *me);
            std::cout << std::endl;

            std::cout << me->getName() << " equip Ice in the first empty slot (2)" << std::endl;
            me->equip(new Ice());
            std::cout << std::endl;

            std::cout << me->getName() << " use Ice (slot 2)" << std::endl;
            me->use(2, *me);
            std::cout << std::endl;

            std::cout << me->getName() << " tries to equip a null Materia in the first empty slot (3), nothing must happen" << std::endl;
            me->equip(0);
            std::cout << std::endl;

            std::cout << me->getName() << " equip Cure in the first empty slot (3)" << std::endl;
            std::cout << "inventory will be full now" << std::endl;
            me->equip(new Cure());
            std::cout << std::endl;

            AMateria* ice_materia = new Ice();
            std::cout << std::endl;

            std::cout << me->getName() << " tries to equip a Materia but the inventory is already full, nothing must happen" << std::endl;
            me->equip(ice_materia);
            std::cout << std::endl;
            delete(ice_materia);
            std::cout << std::endl;

            delete(me);
            std::cout << std::endl;
            std::cout << "----- MY TESTS FOR CHARACTER CREATION, EQUIP, UNEQUIP AND USE MATERIA END -----" << std::endl;   
        }
        {
            std::cout << "----- MY TESTS FOR MATERIASOURCE BEGIN -----" << std::endl;
            std::cout << "----- MY TESTS FOR EMPTY MATERIASOURCE BEGIN -----" << std::endl;
            {
                IMateriaSource  *src = new MateriaSource();
                std::cout << std::endl;

                std::cout << "Trying to create an Ice Materia with an empty MateriaSource" << std::endl;
                AMateria* ice = src->createMateria("ice");
                if (ice == 0)
                std::cout << std::endl;
                    std::cout << "Ice Materia creation failed" << std::endl;
                std::cout << std::endl;

                std::cout << "Trying to create a Cure Materia with an empty MateriaSource" << std::endl;
                AMateria* cure = src->createMateria("cure");
                std::cout << std::endl;
                if (cure == 0)
                    std::cout << "Cure Materia creation failed" << std::endl;
                std::cout << std::endl;
                delete(src);
            }
            std::cout << "----- MY TESTS FOR EMPTY MATERIASOURCE END -----" << std::endl;
            std::cout << "----- MY TESTS FOR ICE MATERIASOURCE BEGIN -----" << std::endl;
            {
                std::cout << std::endl;
                IMateriaSource  *src = new MateriaSource();
                std::cout << std::endl;

                Ice             ice_template;
                std::cout << std::endl;

                src->learnMateria(&ice_template);
                std::cout << std::endl;

                std::cout << "Trying to create a Cure Materia with a MateriaSource with only 'Ice' learned" << std::endl;
                AMateria*       cure = src->createMateria("cure");
                std::cout << std::endl;
                if (cure == 0)
                    std::cout << "Cure Materia creation failed" << std::endl;
                std::cout << std::endl;

                std::cout << "Trying to create an Ice Materia with a MateriaSource with only 'Ice' learned" << std::endl;
                AMateria*       ice = src->createMateria("ice");
                std::cout << std::endl;
                if (ice && ice->getType() == "ice")
                    std::cout << "Ice Materia creation successfull" << std::endl;
                std::cout << std::endl;

                delete(ice);
                delete(src);
            }
            std::cout << "----- MY TESTS FOR ICE MATERIASOURCE END -----" << std::endl;
            std::cout << "----- MY TESTS FOR CURE MATERIASOURCE BEGIN -----" << std::endl;
            {
                std::cout << std::endl;
                IMateriaSource  *src = new MateriaSource();
                std::cout << std::endl;

                Cure             cure_template;
                std::cout << std::endl;

                src->learnMateria(&cure_template);
                std::cout << std::endl;

                std::cout << "Trying to create an Ice Materia with a MateriaSource with only 'Cure' learned" << std::endl;
                AMateria*       ice = src->createMateria("ice");
                if (ice == 0)
                    std::cout << "Ice Materia creation failed" << std::endl;
                std::cout << std::endl;

                std::cout << "Trying to create a Cure Materia with a MateriaSource with only 'Cure' learned" << std::endl;
                AMateria*       cure = src->createMateria("cure");
                std::cout << std::endl;
                if (cure && cure->getType() == "cure")
                    std::cout << "Cure Materia creation successfull" << std::endl;
                std::cout << std::endl;

                delete(cure);
                delete(src);
            }
            std::cout << "----- MY TESTS FOR CURE MATERIASOURCE END -----" << std::endl;
            std::cout << "----- MY TESTS FOR ICE AND CURE MATERIASOURCE WITH FIRE BEGIN -----" << std::endl;
            {
                std::cout << std::endl;
                IMateriaSource  *src = new MateriaSource();
                std::cout << std::endl;

                Ice             ice_template;
                std::cout << std::endl;
                src->learnMateria(&ice_template);
                std::cout << std::endl;

                Cure            cure_template;
                std::cout << std::endl;
                src->learnMateria(&cure_template);
                std::cout << std::endl;

                std::cout << "Trying to create a Fire Materia with a MateriaSource with 'Ice' and 'Cure' learned" << std::endl;
                AMateria        *fire = src->createMateria("fire");
                if (fire == 0)
                    std::cout << "Fire Materia creation failed" << std::endl;
                std::cout << std::endl;

                delete(src);
            }
            std::cout << "----- MY TESTS FOR ICE AND CURE MATERIASOURCE WITH FIRE END -----" << std::endl;
            std::cout << "----- MY TESTS FOR FULL MATERIASOURCE WITH DUPLICATE BEGIN -----" << std::endl;
            {
                std::cout << std::endl;
                IMateriaSource  *src = new MateriaSource();
                std::cout << std::endl;

                Ice             ice_template;
                std::cout << std::endl;

                Cure            cure_template;
                std::cout << std::endl;

                src->learnMateria(&ice_template);
                std::cout << std::endl;
                src->learnMateria(&cure_template);
                std::cout << std::endl;
                src->learnMateria(&ice_template);
                std::cout << std::endl;
                src->learnMateria(&cure_template);
                std::cout << std::endl;

                std::cout << "Trying to learn a 5th Materia, nothing must happen" << std::endl;
                src->learnMateria(&ice_template);
                std::cout << std::endl;

                AMateria*       ice = src->createMateria("ice");
                std::cout << std::endl;
                if (ice && ice->getType() == "ice")
                    std::cout << "Ice Materia creation successfull" << std::endl;
                std::cout << std::endl;

                AMateria*       cure = src->createMateria("cure");
                std::cout << std::endl;
                if (cure && cure->getType() == "cure")
                    std::cout << "Cure Materia creation successfull" << std::endl;
                std::cout << std::endl;

                delete(ice);
                delete(cure);
                delete(src);
            }
            std::cout << "----- MY TESTS FOR FULL MATERIASOURCE WITH DUPLICATE END -----" << std::endl;
            std::cout << "----- MY TESTS FOR MATERIASOURCE END -----" << std::endl;
            std::cout << "----- MY TESTS FOR INTERACTION (2 CHARACTERS) BEGIN -----" << std::endl;
            {
                std::cout << std::endl;
                IMateriaSource  *src = new MateriaSource();
                std::cout << std::endl;

                AMateria    *tmp_ice = new Ice();
                std::cout << std::endl;
                src->learnMateria(tmp_ice);
                std::cout << std::endl;
                delete(tmp_ice);
                std::cout << std::endl;

                AMateria    *tmp_cure = new Cure();
                std::cout << std::endl;
                src->learnMateria(tmp_cure);
                std::cout << std::endl;
                delete(tmp_cure);
                std::cout << std::endl;

                ICharacter  *me = new Character("me");
                std::cout << std::endl;

                ICharacter  *bob = new Character("bob");
                std::cout << std::endl;

                AMateria    *ice = src->createMateria("ice");
                me->equip(ice);
                std::cout << std::endl;

                delete(src);
                std::cout << std::endl;

                me->use(0, *bob);
                std::cout << std::endl;

                me->unequip(0);
                std::cout << std::endl;

                bob->equip(ice);
                std::cout << std::endl;

                bob->use(0, *me);
                std::cout << std::endl;

                delete(me);
                delete(bob);
            }
            std::cout << "----- MY TESTS FOR INTERACTION (2 CHARACTERS) END -----" << std::endl;
            std::cout << "----- MY TESTS FOR CHARACTER DEEP COPY BEGIN -----" << std::endl;
            {
                {
                    Character  *me = new Character("me");
                    std::cout << std::endl;

                    AMateria    *ice = new Ice();
                    std::cout << std::endl;

                    me->equip(ice);
                    me->equip(new Cure());

                    Character  *copy = new Character(*me);

                    std::cout << "me :" << std::endl;
                    std::cout << *me << std::endl;
                    std::cout << "copy :" << std::endl;
                    std::cout << *copy << std::endl;

                    me->unequip(0);
                    std::cout << std::endl;
                    
                    std::cout << "me :" << std::endl;
                    std::cout << *me << std::endl;
                    std::cout << "copy :" << std::endl;
                    std::cout << *copy << std::endl;

                    delete(me);
                    std::cout << std::endl;

                    copy->use(0, *copy);
                    copy->use(1, *copy);
                    std::cout << std::endl;

                    delete(ice);
                    delete(copy);
                }
                {
                    std::cout << std::endl;
                    Character   *me = new Character("me");
                    me->equip(new Ice());
                    std::cout << std::endl;

                    std::cout << "me :" << std::endl;
                    std::cout << *me << std::endl;

                    *me = *me;
                    std::cout << std::endl;

                    Character   *bob = new Character("bob");
                    bob->equip(new Cure());

                    std::cout << "bob :" << std::endl;
                    std::cout << *bob << std::endl;

                    *bob = *me;
                    std::cout << std::endl;

                    std::cout << "me :" << std::endl;
                    std::cout << *me << std::endl;
                    std::cout << std::endl;
                    std::cout << "bob :" << std::endl;
                    std::cout << *bob << std::endl;
                    
                    delete(me);

                    bob->use(0, *bob);

                    delete(bob);
                }
            }
            std::cout << "----- MY TESTS FOR CHARACTER DEEP COPY END -----" << std::endl;
            std::cout << "----- MY TESTS FOR MATERIASOURCE DEEP COPY BEGIN -----" << std::endl;
            {
                MateriaSource   *src1 = new MateriaSource();
                std::cout << std::endl;
                AMateria        *tmp_ice = new Ice();
                std::cout << std::endl;
                
                src1->learnMateria(tmp_ice);
                std::cout << std::endl;
                delete(tmp_ice);
                std::cout << std::endl;
    
                MateriaSource   *src2 = new MateriaSource(*src1);
                std::cout << std::endl;
                
                AMateria        *tmp_cure = new Cure();
                std::cout << std::endl;
                
                src1->learnMateria(tmp_cure);
                std::cout << std::endl;
                delete(tmp_cure);
                std::cout << std::endl;

                AMateria    *src2_ice = src2->createMateria("ice");
                std::cout << std::endl;
                if (src2_ice && src2_ice->getType() == "ice")
                    std::cout << "Ice Materia creation successfull for src2" << std::endl;
                std::cout << std::endl;

                AMateria    *src2_cure = src2->createMateria("cure");
                std::cout << std::endl;
                if (src2_cure == 0)
                    std::cout << "Cure Materia creation failed for src2" << std::endl;
                std::cout << std::endl;
                
                MateriaSource   *src3 = new MateriaSource();
                std::cout << std::endl;
                
                std::cout << "*src3 = *src1" << std::endl;
                *src3 = *src1;

                std::cout << "delete(src1)" << std::endl;
                delete(src1);
    
                AMateria    *src3_ice = src3->createMateria("ice");
                if (src3_ice && src3_ice->getType() == "ice")
                    std::cout << "Ice Materia creation successfull for src3" << std::endl;
                std::cout << std::endl;

                AMateria    *src3_cure = src3->createMateria("cure");
                if (src3_cure && src3_cure->getType() == "cure")
                    std::cout << "Cure Materia creation successfull for src3" << std::endl;
                std::cout << std::endl;

                std::cout << "*src3 = *src3" << std::endl;
                *src3 = *src3;
                
                AMateria    *src3_ice_2 = src3->createMateria("ice");
                if (src3_ice_2 && src3_ice_2->getType() == "ice")
                    std::cout << "Ice Materia creation successfull for src3" << std::endl;
                std::cout << std::endl;
                
                delete(src2);
                delete(src3);
                delete(src2_ice);
                delete(src3_ice);
                delete(src3_cure);
                delete(src3_ice_2);
            }
            std::cout << "----- MY TESTS FOR MATERIASOURCE DEEP COPY END -----" << std::endl;
        }
        std::cout << "------------------------- MY TESTS END -------------------------" << std::endl;
    }
    return (0);
}

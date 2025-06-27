#include "DiamondTrap.hpp"
#include <iostream>

void print_header(const std::string& title)
{
    std::cout << "\n\n--- " << title << " ---" << std::endl;
}

int main(void)
{
    print_header("1. CONSTRUCTION & INITIAL STATE");

    std::cout << "\n--> Creating DiamondTrap 'DI4M-TP'..." << std::endl;
    DiamondTrap dt1("DI4M-TP");
    std::cout << dt1;

    std::cout << "\n--> Creating a default DiamondTrap..." << std::endl;
    DiamondTrap dt_default;
    std::cout << dt_default;


    print_header("2. CORE FUNCTIONALITY & PROOF OF CONCEPT");

    std::cout << "\n--> Testing whoAmI() to check names..." << std::endl;
    dt1.whoAmI();

    std::cout << "\n--> Testing DiamondTrap's attack() (delegates to ScavTrap)..." << std::endl;
    dt1.attack("a training dummy");
    std::cout << dt1;

    std::cout << "\n--> Testing unique parent functions..." << std::endl;
    std::cout << "Calling guardGate() from ScavTrap part:" << std::endl;
    dt1.guardGate();
    std::cout << "\nCalling highFivesGuys() from FragTrap part:" << std::endl;
    dt1.highFivesGuys();
    std::cout << dt1;

    std::cout << "\n--> Testing inherited ClapTrap functions..." << std::endl;
    dt1.takeDamage(20);
    dt1.beRepaired(10);
    std::cout << dt1;


    print_header("3. COPY SEMANTICS (ORTHODOX CANONICAL FORM)");

    std::cout << "\n--> Testing Copy Constructor: creating 'dt_copy' from 'dt1'..." << std::endl;
    DiamondTrap dt_copy(dt1);
    std::cout << "\nOriginal 'dt1':\n" << dt1;
    std::cout << "Copied 'dt_copy' (should be identical):\n" << dt_copy;

    std::cout << "\n--> Modifying the copy 'dt_copy'..." << std::endl;
    dt_copy.takeDamage(5);
    std::cout << "Original 'dt1' after modifying copy (should be unchanged):\n" << dt1;
    std::cout << "Copied 'dt_copy' after being modified:\n" << dt_copy;

    std::cout << "\n--> Testing Assignment Operator: assigning 'dt1' to 'dt_default'..." << std::endl;
    std::cout << "'dt_default' before assignment:\n" << dt_default;
    dt_default = dt1; // Assignment happens here
    std::cout << "'dt_default' after assignment (should now match 'dt1'):\n" << dt_default;


    print_header("4. EDGE CASE: ENERGY DEPLETION");

    std::cout << "\n--> Creating 'dt_energy_test' to deplete its energy..." << std::endl;
    DiamondTrap dt_energy_test("ENERGY-BOT");
    unsigned int energy = dt_energy_test.getEnergyPoints();
    std::cout << "Starting with " << energy << " energy points. Attacking until empty..." << std::endl;
    for (unsigned int i = 0; i < energy; ++i)
    {
        dt_energy_test.attack("the void");
    }
    std::cout << "\n--> 'ENERGY-BOT' has 0 energy points. All actions should now fail..." << std::endl;
    dt_energy_test.attack("a ghost");
    dt_energy_test.beRepaired(10);
    dt_energy_test.guardGate();
    dt_energy_test.highFivesGuys();


    print_header("5. EDGE CASE: HIT POINTS DEPLETION");
    
    std::cout << "\n--> Creating 'dt_ko_test' to deplete its hit points..." << std::endl;
    DiamondTrap dt_ko_test("KO-BOT");
    std::cout << "Taking more damage than total health..." << std::endl;
    dt_ko_test.takeDamage(101);
    std::cout << "\n--> 'KO-BOT' has 0 hit points. All actions should fail..." << std::endl;
    dt_ko_test.attack("a memory");
    dt_ko_test.beRepaired(10);
    dt_ko_test.takeDamage(10); // Should say it's already dead


    print_header("6. DESTRUCTION");
    std::cout << "--> End of main function. Destructors will be called for all objects." << std::endl;
    
    return 0;
}
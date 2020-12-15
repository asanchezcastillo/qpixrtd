// C++ includes
#include <iostream>
#include <string>
#include <vector>

#include "Qpix/Structures.h"

namespace Qpix
{
    // sort the elctrons by pixel index
    bool Electron_Pix_Sort(ELECTRON one, ELECTRON two)
    {
        return (one.Pix_ID < two.Pix_ID);
    }//Electron_Pix_Sort

    //sort the electrons in a pixel by time
    bool Pixel_Time_Sorter(Qpix::ELECTRON const& lhs, Qpix::ELECTRON const& rhs) 
    {
        return lhs.time < rhs.time;
    }//Pixel_Time_Sorter

    // setup the default Qpix paramaters
    void set_Qpix_Paramaters(Qpix_Paramaters * Qpix_params)
    {
        Qpix_params->Wvalue = 23.6; // in eV
        //E_vel = 0.1648; //cm/mus
        // Qpix_params->E_vel = 1.648e-4; // cm/ns
        Qpix_params->E_vel = 164800.0; // cm/s

        // Qpix_params->DiffusionL = 6.8223 * 1e-9;  //cm**2/ns
        // Qpix_params->DiffusionT = 13.1586 * 1e-9; //cm**2/ns
        Qpix_params->DiffusionL = 6.8223  ;  //cm**2/s
        Qpix_params->DiffusionT = 13.1586 ; //cm**2/s
        // Qpix_params->Life_Time = 100000000; // in ns
        Qpix_params->Life_Time = 0.1; // in s
        // Read out plane size in cm
        Qpix_params->Readout_Dim = 100;
        Qpix_params->Pix_Size = 0.4;
        // Number of electrons for reset
        Qpix_params->Reset = 6250;
        // time in ns
        // Qpix_params->Sample_time = 10;
        // Qpix_params->Buffer_time = 1e8;
        Qpix_params->Sample_time = 10e-9;
        Qpix_params->Buffer_time = 1;
        Qpix_params->Dead_time = 0;
        Qpix_params->Charge_loss = false;
        Qpix_params->Recombination = true;
    }//set_Qpix_Paramaters

    // A nice printing function 
    void print_Qpix_Paramaters(Qpix_Paramaters * Qpix_params)
    {
        std::cout << "*******************************************************" << std::endl;
        std::cout << "Liquid Argon Paramaters" << std::endl;
        std::cout << "*******************************************************" << std::endl;
        std::cout   << "W value                    = " << Qpix_params->Wvalue << " [eV] \n"
                    << "Dirft velocity             = " << Qpix_params->E_vel<< " [cm/s] \n"
                    << "Longitidunal diffusion     = " << Qpix_params->DiffusionL<< " [cm^2/s] \n"
                    << "Transverse diffusion       = " << Qpix_params->DiffusionT<< " [cm^2/s] \n"
                    << "Electron life time         = " << Qpix_params->Life_Time<< " [s] \n"
                    << "Readout dimensions         = " << Qpix_params->Readout_Dim<< " [cm] \n"
                    << "Pixel size                 = " << Qpix_params->Pix_Size<< " [cm] \n"
                    << "Reset threshold            = " << Qpix_params->Reset<< " [electrons] \n"
                    << "Sample time                = " << Qpix_params->Sample_time<< " [s] \n"
                    << "Buffer window              = " << Qpix_params->Buffer_time<< " [s] \n"
                    << "Dead time                  = " << Qpix_params->Dead_time<< " [s] "
                    << std::endl;
        if (Qpix_params->Charge_loss)
        {std::cout << "Charge loss                = " << "YES" << " [yes/no] " << std::endl;}
        else{std::cout << "Charge loss                = " << "NO" << " [yes/no] " << std::endl;}
        if (Qpix_params->Recombination)
        {std::cout << "Recombination                = " << "YES" << " [yes/no] " << std::endl;}
        else{std::cout << "Recombination                = " << "NO" << " [yes/no] " << std::endl;}
        
        std::cout << "*******************************************************" << std::endl;
    }//print_Qpix_Paramaters






}
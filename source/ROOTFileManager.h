// -----------------------------------------------------------------------------
//  ROOTFileManager.h
//
//  Class definition of the ROOT file manager
//   * Author: Everybody is an author!
//   * Creation date: 31 August 2020
// -----------------------------------------------------------------------------

#ifndef ROOTFileManager_h
#define ROOTFileManager_h 1

// Q-Pix includes
#include "Random.h"
#include "Structures.h"

// ROOT includes
#include "TROOT.h"
#include "TFile.h"
#include "TTree.h"
#include "TBranch.h"

// C++ includes
#include <map>
#include <set>

#include "SemiAnalyticalModel.h"
#include "SimPhotons.h"
#include "PropagationTimeModel.h"


#include <iostream>
#include <vector>
#include <string>
#include <fstream>



namespace Qpix {

    class ROOTFileManager {

        public:

            ROOTFileManager(std::string const&, std::string const&);
            ~ROOTFileManager();

            unsigned int NumberEntries();
            void EventFill();
            void EventReset();
            void Save();

            void AddMetadata(Qpix::Qpix_Paramaters * const);
            double Modified_Box(double dEdx);
            double Birks_Model(double dEdx, double const EField);
            double EscapingEFraction(const double dEdx) const;
            double FieldCorrection(double const EF, double const dEdx) const;
            void Get_Event(int, Qpix::Qpix_Paramaters *, std::vector< Qpix::ELECTRON > &);
            void AddEvent(std::vector<Qpix::Pixel_Info> const);
            void SavePhotons(std::vector<SimPhotons> photonHitCollection);
            void ReadJson();


        private:

            TFile * tfile_;
            TTree * ttree_;

            //--------------------------------------------------
            // new branch variables
            //--------------------------------------------------

            std::vector< int > pixel_x_;
            std::vector< int > pixel_y_;
            std::vector< double > hit_NElectron_;
            std::vector< double > hit_NPhoton_;
            std::vector< std::vector < double > > pixel_reset_;
            std::vector< std::vector < double > > pixel_tslr_;
            // std::vector< std::vector< std::vector < int > > > pixel_reset_truth_track_id_;
            // std::vector< std::vector< std::vector < double > > > pixel_reset_truth_weight_;
            std::vector< std::vector< std::vector < int > > > pixel_reset_truth_track_id_;
            std::vector< std::vector< std::vector < int > > > pixel_reset_truth_weight_;

            TBranch * tbranch_x_;
            TBranch * tbranch_y_;
            TBranch * tbranch_reset_;
            TBranch * tbranch_tslr_;
            TBranch * tbranch_reset_truth_track_id_;
            TBranch * tbranch_reset_truth_weight_;
            TBranch * tbranch_nelectrons_;
            TBranch * tbranch_nphotons_;
            TBranch * tbranch_savedphotons_;

            //--------------------------------------------------
            // existing branch variables
            //--------------------------------------------------

            int run_;
            int event_;
            int number_particles_;
            int number_hits_;
            double energy_deposit_;
            bool detector_configuration_;

            std::vector< int >    * particle_track_id_;
            std::vector< int >    * particle_parent_track_id_;
            std::vector< int >    * particle_pdg_code_;
            std::vector< double > * particle_mass_;
            std::vector< double > * particle_charge_;
            std::vector< int >    * particle_process_key_;
            std::vector< int >    * particle_total_occupancy_;

            std::vector< double > * particle_initial_x_;
            std::vector< double > * particle_initial_y_;
            std::vector< double > * particle_initial_z_;
            std::vector< double > * particle_initial_t_;

            std::vector< double > * particle_initial_px_;
            std::vector< double > * particle_initial_py_;
            std::vector< double > * particle_initial_pz_;
            std::vector< double > * particle_initial_energy_;

            std::vector< int >    * hit_track_id_;
            std::vector< double > * hit_start_x_;
            std::vector< double > * hit_start_y_;
            std::vector< double > * hit_start_z_;
            std::vector< double > * hit_start_t_;
            std::vector< double > * hit_end_x_;
            std::vector< double > * hit_end_y_;
            std::vector< double > * hit_end_z_;
            std::vector< double > * hit_end_t_;
            std::vector< double > * hit_length_;
            std::vector< double > * hit_energy_deposit_;
            std::vector< int >    * hit_process_key_;

            //--------------------------------------------------
            // metadata
            //--------------------------------------------------

            TTree * metadata_;

            double w_value_;
            double drift_velocity_;
            double longitudinal_diffusion_;
            double transverse_diffusion_;
            double electron_lifetime_;
            double readout_dimensions_;
            double pixel_size_;
            int    reset_threshold_;
            int    sample_time_;
            int    buffer_window_;
            int    dead_time_;
            int    charge_loss_;

            TBranch * tbranch_w_value_;
            TBranch * tbranch_drift_velocity_;
            TBranch * tbranch_longitudinal_diffusion_;
            TBranch * tbranch_transverse_diffusion_;
            TBranch * tbranch_electron_lifetime_;
            TBranch * tbranch_readout_dimensions_;
            TBranch * tbranch_pixel_size_;
            TBranch * tbranch_reset_threshold_;
            TBranch * tbranch_sample_time_;
            TBranch * tbranch_buffer_window_;
            TBranch * tbranch_dead_time_;
            TBranch * tbranch_charge_loss_;

            //--------------------------------------------------
            // initialize
            //--------------------------------------------------
            void initialize(std::string const&, std::string const&);
            void InitializeLight();
            //--------------------------------------------------
            // set branch addresses
            //--------------------------------------------------
            void set_branch_addresses(TTree *);
            //--------------------------------------------------
            // light simulation objets
            //--------------------------------------------------
            json SimulationParameters;
            bool SimulateLight;
            bool SimulateCharge;
            bool UseModifiedBox;
            bool LArQLCorrections;
            unsigned int fNOpChannels;
            double fLarqlChi0A;
            double fLarqlChi0B;
            double fLarqlChi0C;
            double fLarqlChi0D;
            double fLarqlAlpha;
            double fLarqlBeta;
            double fRecombinationA;
            double fRecombinationK;
            double fWion;
            double fWph;
            double EField ;
            std::unique_ptr<PropagationTimeModel> PropTime;
            std::unique_ptr<SemiAnalyticalModel> semi;
            std::unique_ptr<std::vector<SimPhotons>> photonCol{new std::vector<SimPhotons>{}};
            std::vector<SimPhotons> photonHitCollection{*photonCol};
            std::vector<std::vector<double>> SavedPhotons;
    };

}
#endif

#ifndef EcalBarrelMonitorClient_H
#define EcalBarrelMonitorClient_H

/*
 * \file EcalBarrelMonitorClient.h
 *
 * $Date: 2005/11/09 19:08:11 $
 * $Revision: 1.2 $
 * \author G. Della Ricca
 *
*/

#include "FWCore/Framework/interface/Frameworkfwd.h"
#include <FWCore/Framework/interface/EDAnalyzer.h>

#include <FWCore/Framework/interface/Event.h>
#include <FWCore/Framework/interface/MakerMacros.h>

#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "DQMServices/Core/interface/DaqMonitorBEInterface.h"
#include "DQMServices/Daemon/interface/MonitorDaemon.h"
#include "FWCore/ServiceRegistry/interface/Service.h"

#include <DQM/EcalBarrelMonitorClient/interface/EBLaserClient.h>
#include <DQM/EcalBarrelMonitorClient/interface/EBPedestalClient.h>

#include "CalibCalorimetry/EcalDBInterface/interface/EcalCondDBInterface.h"
#include "CalibCalorimetry/EcalDBInterface/interface/RunTag.h"
#include "CalibCalorimetry/EcalDBInterface/interface/RunIOV.h"

#include "TROOT.h"
#include "TThread.h"

#include <memory>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include <csignal>

using namespace cms;
using namespace std;

class EcalBarrelMonitorClient: public edm::EDAnalyzer{

public:

/// Constructor
EcalBarrelMonitorClient(const edm::ParameterSet& ps);

/// Destructor
virtual ~EcalBarrelMonitorClient();

protected:

/// Analyze
void analyze(const edm::Event& e, const edm::EventSetup& c);

// BeginJob
void beginJob(const edm::EventSetup& c);

// EndJob
virtual void endJob(void);

// BeginRun
void beginRun(const edm::EventSetup& c);

// EndRun
virtual void endJob(void);

private:

int ievt_;
int jevt_;

MonitorUserInterface* mui_;

EcalCondDBInterface* econn_;

string location_;
string runtype_;
run_t run_;

EBLaserClient* laser_client_;
EBPedestalClient* pedestal_client_;

int exit_now;

};

DEFINE_FWK_MODULE(EcalBarrelMonitorClient)

#endif

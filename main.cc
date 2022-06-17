#include "ExG4DetectorConstruction01.hh"
#include "ExG4PhysicsList00.hh"
#include "ExG4ActionInitialization01.hh"
#include "G4RunManagerFactory.hh"
#include "G4UImanager.hh"


int main()
{
    // construct the default run manager
    auto runManager = G4RunManagerFactory::CreateRunManager();
    
    // set mandatory initialization classes
    runManager->SetUserInitialization(new ExG4DetectorConstruction01);
    runManager->SetUserInitialization(new ExG4PhysicsList00);
    runManager->SetUserInitialization(new ExG4ActionInitialization01);
    
    // initialize G4 kernel
    runManager->Initialize();
    
    // get the pointer to the UI manager and set verbosities
    G4UImanager* UI = G4UImanager::GetUIpointer();
    UI->ApplyCommand("/event/verbose 1");
    UI->ApplyCommand("/run/verbose 1");
    UI->ApplyCommand("/tracking/verbose 1");
    
    // start a run
    int numberOfEvent = 3;
    runManager->BeamOn(numberOfEvent);
    
    // job termination
    delete runManager;
    return 0;
}
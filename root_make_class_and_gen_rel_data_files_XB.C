#include <iostream>
#include <fstream>
using namespace std;

// This code is for XB only

void root_make_class_and_gen_rel_data_files_XB(const char * rootFile) {
  // Read root file and make the h102-class
  TFile *a=TFile::Open(rootFile);
  TTree *h102=NULL;
  a->GetObject("h102",h102);
  h102->MakeClass();

  // Overwrite h102.C // More like open file for h102?
  ofstream h102file("h102.C",ios::trunc);
  ifstream h102backupfile("h102_backup_gunedep_rel_XB.C");
  string line;

  // Build h102 from h102_backup line by line?
  if ( h102file.is_open() && h102backupfile.is_open() ){
    while ( getline(h102backupfile,line) ){
      h102file << line << '\n';
    }
    h102file.close();
    h102backupfile.close();
  }
  else printf("%s","Unable to open files...");

  // Generate data files 	
  gROOT->ProcessLine(".L h102.C");  // Load a macro called "h102" into this session (can now use h102)
  gROOT->ProcessLine("h102 t");     // 
  gROOT->ProcessLine("t.Loop()");  
}

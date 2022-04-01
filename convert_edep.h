//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Mar 31 20:21:01 2022 by ROOT version 6.24/02
// from TTree h102/collect hit tree
// found on file: ./root/mult1ev100cluster10.root
//////////////////////////////////////////////////////////

#ifndef convert_edep_h
#define convert_edep_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class convert_edep {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   UInt_t          eventno;
   UInt_t          seed1;
   UInt_t          seed2;
   UInt_t          gunn;
   Float_t         gunt[1];   //[gunn]
   Float_t         gunx[1];   //[gunn]
   Float_t         guny[1];   //[gunn]
   Float_t         gunz[1];   //[gunn]
   Float_t         gunpx[1];   //[gunn]
   Float_t         gunpy[1];   //[gunn]
   Float_t         gunpz[1];   //[gunn]
   Float_t         gunT[1];   //[gunn]
   Int_t           gunpdg[1];   //[gunn]
   Float_t         gunedepXB[1];   //[gunn]
   Float_t         XBsumE;
   UInt_t          XBn;
   Float_t         XBt[10];   //[XBn]
   Float_t         XBe[10];   //[XBn]
   UInt_t          XBi[10];   //[XBn]

   // List of branches
   TBranch        *b_eventno;   //!
   TBranch        *b_seed1;   //!
   TBranch        *b_seed2;   //!
   TBranch        *b_gunn;   //!
   TBranch        *b_gunt;   //!
   TBranch        *b_gunx;   //!
   TBranch        *b_guny;   //!
   TBranch        *b_gunz;   //!
   TBranch        *b_gunpx;   //!
   TBranch        *b_gunpy;   //!
   TBranch        *b_gunpz;   //!
   TBranch        *b_gunT;   //!
   TBranch        *b_gunpdg;   //!
   TBranch        *b_gunedepXB;   //!
   TBranch        *b_XBsumE;   //!
   TBranch        *b_XBn;   //!
   TBranch        *b_XBt;   //!
   TBranch        *b_XBe;   //!
   TBranch        *b_XBi;   //!

   convert_edep(const char *filename);
   virtual ~convert_edep();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
  
 public:
  const char *_filename;
};

#endif

#ifdef convert_edep_cxx
convert_edep::convert_edep(const char *filename) : fChain(0) 
{
  TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject(filename);
  if (!f || !f->IsOpen()) {
    f = new TFile(filename);
  }
  TTree *tree;
  f->GetObject("h102",tree);
  Init(tree);
  _filename = strdup(filename);
  
  this->Loop();
  exit(0);
}

convert_edep::~convert_edep()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t convert_edep::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t convert_edep::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void convert_edep::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("eventno", &eventno, &b_eventno);
   fChain->SetBranchAddress("seed1", &seed1, &b_seed1);
   fChain->SetBranchAddress("seed2", &seed2, &b_seed2);
   fChain->SetBranchAddress("gunn", &gunn, &b_gunn);
   fChain->SetBranchAddress("gunt", gunt, &b_gunt);
   fChain->SetBranchAddress("gunx", gunx, &b_gunx);
   fChain->SetBranchAddress("guny", guny, &b_guny);
   fChain->SetBranchAddress("gunz", gunz, &b_gunz);
   fChain->SetBranchAddress("gunpx", gunpx, &b_gunpx);
   fChain->SetBranchAddress("gunpy", gunpy, &b_gunpy);
   fChain->SetBranchAddress("gunpz", gunpz, &b_gunpz);
   fChain->SetBranchAddress("gunT", gunT, &b_gunT);
   fChain->SetBranchAddress("gunpdg", gunpdg, &b_gunpdg);
   fChain->SetBranchAddress("gunedepXB", gunedepXB, &b_gunedepXB);
   fChain->SetBranchAddress("XBsumE", &XBsumE, &b_XBsumE);
   fChain->SetBranchAddress("XBn", &XBn, &b_XBn);
   fChain->SetBranchAddress("XBt", XBt, &b_XBt);
   fChain->SetBranchAddress("XBe", XBe, &b_XBe);
   fChain->SetBranchAddress("XBi", XBi, &b_XBi);
   Notify();
}

Bool_t convert_edep::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void convert_edep::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t convert_edep::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef convert_edep_cxx

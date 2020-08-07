#include "tdrstyle.C"

void makePlot(TFile * f_s, TFile *f_b, TString name, TString ytitle, TString xtitle, float x1, float y1, float x2, float y2){

  TH1F * h_s = (TH1F*) f_s->Get(Form("%s", name.Data()));
  TH1F * h_b = (TH1F*) f_b->Get(Form("%s", name.Data()));

  TCanvas * c = new TCanvas(Form("c_%s",name.Data()),"c",1);
  h_b->Sumw2();
  h_s->Sumw2();
  h_b->Scale(1.0/h_b->Integral());
  h_s->Scale(1.0/h_s->Integral());
  h_b->SetLineColor(2);
  h_b->SetStats(0);
  h_b->SetTitle("");
  double max_h_b = h_b->GetMaximum();
  double max_h_s = h_s->GetMaximum();
  double max = max_h_b;
  if( max_h_s > max_h_b) max = max_h_s; 
  h_b->SetMaximum(max+0.04);
  h_b->Draw("HIST");
  h_b->GetXaxis()->SetTitle(Form("%s",xtitle.Data()));
  h_b->GetYaxis()->SetTitle(Form("%s",ytitle.Data()));
  h_s->SetLineColor(4);
  h_s->Draw("SameHIST");

  TLegend * l = new TLegend(x1,y1,x2,y2);
  l->AddEntry(h_s,"LQ","L");
  l->AddEntry(h_b,"ttbar","L");
  l->SetTextSize(0.04);
  l->SetFillColor(0);
  l->SetLineColor(0);
  l->Draw();

  c->Print(Form("%s.pdf",name.Data()));

}


void plots(){

  setTDRStyle();

  TFile * f_signal = new TFile("out_signal.root");
  TFile * f_ttbar = new TFile("out_BG.root");

  makePlot(f_signal, f_ttbar, "h_nMuon", "Normalized Entries","Muon Multiplicity", 0.7, 0.75, 0.85, 0.9);
  makePlot(f_signal, f_ttbar, "h_nJet", "Normalized Entries","Jet Multiplicity (T)", 0.7, 0.75, 0.85, 0.9);
  makePlot(f_signal, f_ttbar, "h_nbJet", "Normalized Entries","b Jet Multiplicity (M)", 0.7, 0.75, 0.85, 0.9);
  makePlot(f_signal, f_ttbar, "h_ncJet", "Normalized Entries","c Jet Multiplicity", 0.3, 0.75, 0.45, 0.9);
  makePlot(f_signal, f_ttbar, "h_muon_pt", "Normalized Entries","Muon Pt", 0.7, 0.75, 0.45, 0.9);
  makePlot(f_signal, f_ttbar, "h_muon_eta", "Normalized Entries","Muon eta", 0.7, 0.75, 0.45, 0.9);
  makePlot(f_signal, f_ttbar, "h_tau_pt", "Normalized Entries","Tauon Pt", 0.7, 0.75, 0.45, 0.9);
  makePlot(f_signal, f_ttbar, "h_tau_eta", "Normalized Entries","Tauon eta", 0.7, 0.75, 0.45, 0.9);
  makePlot(f_signal, f_ttbar, "h_jet_pt", "Normalized Entries","Jet Pt", 0.7, 0.75, 0.45, 0.9);
  makePlot(f_signal, f_ttbar, "h_jet_eta", "Normalized Entries","Jet eta", 0.7, 0.75, 0.45, 0.9);
  makePlot(f_signal, f_ttbar, "h_bjet_pt", "Normalized Entries","b Jet Pt", 0.7, 0.75, 0.45, 0.9);
  makePlot(f_signal, f_ttbar, "h_bjet_eta", "Normalized Entries","b Jet eta", 0.7, 0.75, 0.45, 0.9);
  makePlot(f_signal, f_ttbar, "h_cjet_pt", "Normalized Entries","c Jet Pt", 0.7, 0.75, 0.45, 0.9);
  makePlot(f_signal, f_ttbar, "h_cjet_eta", "Normalized Entries","c Jet eta", 0.7, 0.75, 0.45, 0.9);
}

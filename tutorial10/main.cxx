#include "Circle.h"
#include "GeometryIO.h"
#include "Rectangle.h"
#include "parse_csv.h"
#include <iostream>
#include <TCanvas.h>
#include <TH1D.h>
int main() {
  const std::string csv_file{"rectangle_dimensions.csv"};
  auto rectangles{parse_rectangles(csv_file)};
  auto canvas{new TCanvas{}};
  auto histogram = new TH1D{"rectangle_areas", "Rectangle areas", 100, 0, 20};
  for (auto rectangle : rectangles) {
    histogram->Fill(rectangle.area());
  }
  histogram->Draw("E");
  canvas->SaveAs("Rectangles.pdf");
}
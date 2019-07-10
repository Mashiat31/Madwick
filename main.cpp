/*


 * main.cpp
 *
 *  Created on: Jul 10, 2019
 *      Author: Asus
 */


#include <iostream>
#include <fstream>
#include "csv.h"

using namespace std;

int main() {
  io::CSVReader<7> in("test.csv");
  in.read_header(io::ignore_missing_column, "Time stamp(ms)", "Ax", "Ay", "Az", "Gx", "Gy", "Gz");
  int timestamp; double ax, ay, az, gx, gy, gz;

  ofstream output_file;
  output_file.open("result.csv");
  output_file << "roll,pitch,yaw\n";
  while(in.read_row(timestamp, ax, ay, az, gx, gy, gz)) {
    output_file << ax << "," << gx << "," << gz << endl;
  }
  output_file.close();

  return 0;
}



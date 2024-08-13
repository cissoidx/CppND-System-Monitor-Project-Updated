#include "format.h"

#include <string>

using std::string;
using std::to_string;

// TODO: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
// REMOVE: [[maybe_unused]] once you define the function
string Format::ElapsedTime(long seconds) {
  int hh;
  int mm;
  int ss;
  string min_str;
  string sec_str;
  string format_time;
  hh = seconds / 3600;
  mm = (seconds - hh * 3600) / 60;
  ss = seconds - hh * 3600 - mm * 60;
  min_str = to_string(mm);
  min_str.insert(0, 2 - min_str.length(), '0');
  sec_str = to_string(ss);
  sec_str.insert(0, 2 - sec_str.length(), '0');
  format_time = to_string(hh) + ":" + min_str + ":" + sec_str;
  return format_time;
}
#include <string>

#include "format.h"

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
    string format_time;
    hh = seconds / 3600;
    mm = (seconds - hh*3600) / 60;
    ss = seconds - hh*3600 - mm*60;
    if (mm<10)
        {min_str = "0"+to_string(mm);}
    else 
        {min_str = to_string(mm);}
    format_time = to_string(hh)+":"+min_str+":"+to_string(ss);
    return format_time;
}
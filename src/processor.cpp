#include "processor.h"
#include "linux_parser.h"

using std::stol;

// TODO: Return the aggregate CPU utilization
float Processor::Utilization() {
    float CPU_Percentage;
    long PrevIdle;
    long Idle;
    long PrevNonIdle;
    long NonIdle;
    long PrevTotal;
    long Total;
    long totald;
    long idled;

    auto vvalue = LinuxParser::CpuUtilization();
    guest_nice = stol(vvalue.back());
    vvalue.pop_back();
    guest = stol(vvalue.back());
    vvalue.pop_back();
    steal = stol(vvalue.back());
    vvalue.pop_back();
    softirq = stol(vvalue.back());
    vvalue.pop_back();
    irq = stol(vvalue.back());
    vvalue.pop_back();
    iowait = stol(vvalue.back());
    vvalue.pop_back();
    idle = stol(vvalue.back());
    vvalue.pop_back();
    system = stol(vvalue.back());
    vvalue.pop_back();
    nice = stol(vvalue.back());
    vvalue.pop_back();
    user = stol(vvalue.back());
    vvalue.pop_back();

    // cpu utilization calculation
    PrevIdle = previdle + previowait;
    Idle = idle + iowait;
    PrevNonIdle = prevuser + prevnice + prevsystem + previrq + prevsoftirq + prevsteal;
    NonIdle = user + nice + system + irq + softirq + steal;
    PrevTotal = PrevIdle + PrevNonIdle;
    Total = Idle + NonIdle;
    totald = Total - PrevTotal;
    idled = Idle - PrevIdle;
    CPU_Percentage = float(totald - idled)/float(totald);

    // for next round
    prevuser = user;
    prevnice = nice;
    prevsystem = system;
    previdle = idle;
    previowait = iowait;
    previrq = irq;
    prevsoftirq = softirq;
    prevsteal = steal;
    prevguest = guest;
    prevguest_nice = guest_nice;

    // stable solution
    // CPU_Percentage = float(LinuxParser::ActiveJiffies())/float(LinuxParser::Jiffies());
    return CPU_Percentage;
}
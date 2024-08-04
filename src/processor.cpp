#include "processor.h"
#include "linux_parser.h"

using std::stoi;

// TODO: Return the aggregate CPU utilization
float Processor::Utilization() {
    float CPU_Percentage;
    int PrevIdle;
    int Idle;
    int PrevNonIdle;
    int NonIdle;
    int PrevTotal;
    int Total;
    int totald;
    int idled;

    auto vvalue = LinuxParser::CpuUtilization();
    guest_nice = stoi(vvalue.back());
    vvalue.pop_back();
    guest = stoi(vvalue.back());
    vvalue.pop_back();
    steal = stoi(vvalue.back());
    vvalue.pop_back();
    softirq = stoi(vvalue.back());
    vvalue.pop_back();
    irq = stoi(vvalue.back());
    vvalue.pop_back();
    iowait = stoi(vvalue.back());
    vvalue.pop_back();
    idle = stoi(vvalue.back());
    vvalue.pop_back();
    system = stoi(vvalue.back());
    vvalue.pop_back();
    nice = stoi(vvalue.back());
    vvalue.pop_back();
    user = stoi(vvalue.back());
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
    return CPU_Percentage;
}
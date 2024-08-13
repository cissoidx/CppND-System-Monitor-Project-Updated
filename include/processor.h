#ifndef PROCESSOR_H
#define PROCESSOR_H

class Processor {
 public:
  float Utilization();  // TODO: See src/processor.cpp

  // TODO: Declare any necessary private members
 private:
  long prevuser = 0;
  long user = 0;
  long prevnice = 0;
  long nice = 0;
  long prevsystem = 0;
  long system = 0;
  long previdle = 0;
  long idle = 0;
  long previowait = 0;
  long iowait = 0;
  long previrq = 0;
  long irq = 0;
  long prevsoftirq = 0;
  long softirq = 0;
  long prevsteal = 0;
  long steal = 0;
  long prevguest = 0;
  long guest = 0;
  long prevguest_nice = 0;
  long guest_nice = 0;
};

#endif
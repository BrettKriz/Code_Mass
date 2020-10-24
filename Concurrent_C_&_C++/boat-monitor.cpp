#include "boat-monitor.h"

boat_monitor::boat_monitor(char *Name) : Monitor(Name, 0) 
{
    //togo = runs;
    full = false;
    reset();
}
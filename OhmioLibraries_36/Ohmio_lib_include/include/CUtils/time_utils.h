#pragma once

#include <time.h>

typedef struct timespec Time;

Time time_add(Time t1, Time t2);

Time time_diff(Time t1, Time t2);

double get_seconds(Time t);



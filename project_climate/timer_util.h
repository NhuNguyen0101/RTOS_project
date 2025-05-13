#ifndef TIMER_UTIL_H
#define TIMER_UTIL_H
void Timer_Init();
void Timer_Tick();   // called each 1 ms from TIMER_ISR task
void Timer_Run();    // legacy no‑op
#endif

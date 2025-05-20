# RTOS_project
Pham Quang Dung write this code

#code structure
project_climate/
│
├── src/
│   ├── project_climate.ino                    
│   ├── config.h
│
│   ├── scheduler/                   ← Your custom scheduler
│   │   ├── schedule.c
│   │   └── schedule.h
│
│   ├── platform/                    ← System-level services
│   │   ├── timer_util.cpp
│   │   ├── timer_util.h
│   │   ├── led_blinky.cpp
│   │   └── led_blinky.h
│
│   ├── sensors/                     ← Sensor abstraction
│   │   ├── htsensor.cpp
│   │   └── htsensor.h
│
│   ├── control/                     ← Application logic
│   │   ├── light_control.cpp
│   │   └── light_control.h
│
│   ├── devices/                     ← Actuators
│   │   ├── cooler.cpp
│   │   ├── cooler.h
│   │   ├── heater.cpp
│   │   ├── heater.h
│   │   ├── humidifier.cpp
│   │   ├── humidifier.h
│   │   └── led_codec.h
│
│   └── tasks/                       ← Named RTOS tasks
│       ├── read_sensors.cpp        ← extract from main.ino
│       └── read_sensors.h
│
├── lib/                             ← External libraries (managed by IDE)
│   ├── DHT/                         ← Contains DHT.cpp/.h
│   ├── Adafruit_Sensor/            ← Contains Adafruit_Sensor.cpp/.h
│   └── DHT_U/                       ← Contains DHT_U.cpp/.h
│
├── docs/                            ← Diagrams
│   ├── block_diagram.png
│   ├── fsm_diagram.png
│   └── timing_diagram.png
│
├── .gitignore
└── README.md

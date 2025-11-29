#  ENSF 337 Term Project
Flight Management Application System (FMAS)

Group Members
	•	David Onofeghara
	•	Anes Khacha
	•	Alexander Gamble

Project Description 
	Flight Management Application System (FMAS)

Project Structure 


Task Division  

| Component              | Description                               | Assigned To |
| ---------------------- | ----------------------------------------- | ----------- |
| Flight class           | All flight attributes + passenger linking | David   |
| Passenger class        | Passenger attributes & validation         | David   |
| SeatMap                | Rendering seat matrix                     | Alex    |
| Menu                   | Main UI, input, navigation                | Alex    |
| FileManager            | File loading/saving                       | Anes    |
| FlightManager          | Core controller linking UI & Data         | Anes    |
| main.cpp               | Entry point                               | Alex    |
| Integration            | Build, headers, linking                   | Anes    |
///////////////////////////////////////////////////////////////////////////////////////

project/
│
├── src/
│   ├── main.cpp
│   ├── Menu.cpp
│   ├── Flight.cpp
│   ├── Passenger.cpp
│   ├── FlightManager.cpp
│   ├── FileManager.cpp
│   ├── SeatMap.cpp
├── include/
│   ├── Menu.h
│   ├── Flight.h
│   ├── Passenger.h
│   ├── FlightManager.h
│   ├── FileManager.h
│   ├── SeatMap.h
│
├── data/
│   ├── flights.txt
│   └── passengers.txt
│
├── bin/
│   └── a.exe (or a.out)
│
├── docs/
│   ├── flowchart.pdf
│   ├── class_diagram.pdf
│   ├── division_of_work.pdf
│
└── README.md







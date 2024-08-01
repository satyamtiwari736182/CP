Types of problems:
[1] Next Greatest Elements
[2] Largest Area Histogram - 2
[3] Remove Outermost Parentheses
[4] Score of Prarentheses
[5] Basic Calculator III


### Classes, Interfaces and Enumerations
The Direction enum represents the possible directions of elevator movement (UP or DOWN).
The Request class represents a user request for an elevator, containing the source floor and destination floor.
The Elevator class represents an individual elevator in the system. It has a capacity limit and maintains a list of 4. requests. The elevator processes requests concurrently and moves between floors based on the requests.
The ElevatorController class manages multiple elevators and handles user requests. It finds the optimal elevator to serve a request based on the proximity of the elevators to the requested floor.
The ElevatorSystem class is the entry point of the application and demonstrates the usage of the elevator system.
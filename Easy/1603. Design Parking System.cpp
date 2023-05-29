class ParkingSystem {
public:
    int availableSpaces[3]; // Array to store the available spaces for each car type

    ParkingSystem(int big, int medium, int small) {
        availableSpaces[0] = big; // Initializing the number of available spaces for big cars
        availableSpaces[1] = medium; // Initializing the number of available spaces for medium cars
        availableSpaces[2] = small; // Initializing the number of available spaces for small cars
    }
    
    bool addCar(int carType) {
        if (carType < 1 || carType > 3) {
            return false; // Invalid car type
        }
        
        if (availableSpaces[carType - 1] > 0) { // If there is an available space for the given car type
            availableSpaces[carType - 1]--; // Decrease the count of available spaces for the car type
            return true; // Car can be parked
        }  
        else {
            return false; // No available space for the car type, cannot be parked
        }
    }
};

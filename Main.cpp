#include <iostream>
#include <vector>
#include <map>

class Vehicle {
public:
    int id;
    int posX;
    int posY;
    int prevPosX;
    int prevPosY;

    Vehicle() : id(0), posX(0), posY(0), prevPosX(0), prevPosY(0) {}
    Vehicle(int id, int posX, int posY) : id(id), posX(posX), posY(posY), prevPosX(posX), prevPosY(posY) {}
};

class Board {
public:
    int size;
    std::map<int, Vehicle> vehicles;
    std::vector<std::vector<char>> collisionMap;

    Board(int size) : size(size), collisionMap(size, std::vector<char>(size, '.')) {}

    void checkCollision(Vehicle &vehicle) {
        for (auto it = vehicles.begin(); it != vehicles.end(); ) {
            if (it->second.id != vehicle.id && it->second.posX == vehicle.posX && it->second.posY == vehicle.posY) {
                std::cout << "Wykryto kolizje!\n";
                collisionMap[vehicle.posY][vehicle.posX] = 'X';
                vehicles.erase(it++);
                vehicles.erase(vehicle.id);
                break;
            } else {
                ++it;
            }
        }
    }
    
    void moveVehicle(int id, int deltaX, int deltaY) {
        if (vehicles.find(id) != vehicles.end()) {
            Vehicle &vehicle = vehicles[id];
            vehicle.prevPosX = vehicle.posX;
            vehicle.prevPosY = vehicle.posY;
            vehicle.posX = (vehicle.posX + deltaX + size) % size;
            vehicle.posY = (vehicle.posY + deltaY + size) % size;
            if (collisionMap[vehicle.posY][vehicle.posX] == 'X') {
                vehicles.erase(id);
            } else {
                checkCollision(vehicle);
            }
        }
    }

    void addVehicle(int id, int posX, int posY) {
        if (vehicles.find(id) == vehicles.end() && posX < size && posY < size) {
            Vehicle newVehicle(id, posX, posY);
            checkCollision(newVehicle);
            if (vehicles.find(id) == vehicles.end()) {
                vehicles[id] = newVehicle;
            }
        }
    }

    void printBoard() {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                bool found = false;
                for (const auto &pair : vehicles) {
                    if (pair.second.posX == j && pair.second.posY == i) {
                        std::cout << pair.first;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    if (collisionMap[i][j] == 'X') {
                        std::cout << collisionMap[i][j];
                        collisionMap[i][j] = '.'; // Reset the collision map at this position
                    } else {
                        std::cout << '.';
                    }
                }
            }
            std::cout << "\n";
        }
    }
};

int main() {
    int boardSize;
    std::cout << "Podaj rozmiar planszy: ";
    std::cin >> boardSize;
    Board board(boardSize);

    std::cout << "\nInstrukcje:\n";
    std::cout << "Aby przesunac wszystkie pojazdy o jeden krok w prawo i w dol, wpisz 'move'.\n";
    std::cout << "Aby dodac pojazd, wpisz 'add', a nastepnie ID pojazdu, pozycje X i pozycje Y (np. 'add 1 0 0').\n";
    std::cout << "Aby zakonczyc, wpisz 'quit'.\n\n";

    std::string command;
    while (std::cin >> command) {
        if (command == "move") {
            for (auto &pair : board.vehicles) {
                board.moveVehicle(pair.first, 1, 1);
            }
        } else if (command == "add") {
            int id, posX, posY;
            std::cin >> id >> posX >> posY;
            board.addVehicle(id, posX, posY);
        } else if (command == "quit") {
            break;
        }
        board.printBoard();
    }

    return 0;
}
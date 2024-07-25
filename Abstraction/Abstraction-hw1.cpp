#inlcude <iostream>

class Object{
public:
    std::string getObjectName() const;
    bool getIsValuable();
    void setObjectName(std::string objectName);
    void setObjectValuability(bool isValuable);
private:
    std::string objectName;
    bool isValuable;
};

Object::Object()
{
    std::string objectName = "";
    isValuable = false;
}
Object::Object(bool isValuable, std::string objectName)
{
    this->objectName = objectName;
    this->isValuable = isValuable;
}
std::string Object::getObjectName() const
{
    return objectName;
}

class Room{
public:
    double getAreaOfRoom() const;
    std::string getRoomName() const;
    int getNumberOfObjects() const;
    void setX_length(double x_length);
    void setY_length(double y_length);
    void setZ_length(double z_length);
    void setRoomName(std::string roomName);
    void addObject(Object obj);
private:
    double x_length;
    double y_length;
    double z_length;
    std::string roomName;
    std::vector<Object> objects;
};

Room::Room(){
    x_length = y_length = z_length = 0;
}
Room::Room(double x_length, double y_length, double z_length,
           std::string roomName){
    this->x_length = x_length;
    this->y_length = y_length;
    this->z_length = z_length;
    this->roomName = roomName;
}

double Room::getAreaOfRoom() const
{
    return x_length*y_length*z_length;
}

class Home{
public:
    double getWidth() const;
    double getHeight() const;
    int getNumberOfFloors() const;
    void setWidth(double width);
    void setHeight(double height);
    void setNumberOfFloors(int floors);
    int getNumberOfRooms() const;
    void addRoom(Room room);
    std::vector<Room> getRooms() const;
private:
    double width;
    double height;
    int floors;
    std::vector<Room> rooms;
};


Home::Home(){
    width = height = 0;
    floors = 0;
}
Home::Home(double width, double height, int floors){
    this->width = width;
    this->height = height;
    this->floors = floors;
}
double Home::getHeight() const{
    return height;
}
double Home::getWidth() const{
    return width;
}
int Home::getNumberOfFloors() const{
    return floors;
}

void Home::addRoom(Room room)
{
    rooms.push_back(room);
}

std::vector<Room> Home::getRooms() const{
    return std::vector<Room> rooms;
}

int main()
{
    Object obj(true, "Diamond");
    Room r1(10, 10, 10, "BedRoom");
    Home h1(10, 10 ,1);
    r1.addObject(obj);
    h1.addRoom(r1);
}

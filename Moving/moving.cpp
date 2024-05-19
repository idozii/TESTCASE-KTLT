#include "moving.h"

int distance(const Position &pos1, const Position &pos2){
    return abs(pos1.getRow() - pos2.getRow()) + abs(pos1.getCol() - pos2.getCol());
}
const Position Position::npos = Position(-1, -1);
/*
 * CLASS: MapElement
 */
MapElement::MapElement(ElementType in_type)
{
    // TODO: constructor
    type = in_type;
}

MapElement::~MapElement() {}

ElementType MapElement::getType() const
{
    // TODO: get
    return type;
}
/*
 * CLASS: Path
 */
Path::Path()
    : MapElement(PATH) {
        this->type = PATH;
    }
/*
 * CLASS: Wall
 */
Wall::Wall()
    : MapElement(WALL) {
        this->type = WALL;
    }
/*
 * CLASS: FakeWall
 */
FakeWall::FakeWall(int in_req_exp)
    : MapElement(ElementType::FAKE_WALL)
{
    // TODO: constructor
    req_exp = in_req_exp;
    this->type = FAKE_WALL;
}
int FakeWall::getReqExp() const
{
    // TODO: get
    return req_exp;
}
/*
 * CLASS: Position
 */

Position::Position(int r, int c)
{
    // TODO: constructor
    this->r = r;
    this->c = c;
}
Position::Position(const string &str_pos)
{
    // TODO: constructor
    this->r = stoi(str_pos.substr(1, str_pos.find(",")-1));
    this->c = stoi(str_pos.substr(str_pos.find(",")+1, str_pos.find(")")-1));
}
int Position::getRow() const
{
    // TODO: get
    return this->r;
}
int Position::getCol() const
{
    // TODO: get
    return this->c;
}
void Position::setRow(int r)
{
    // TODO: set
    this->r = r;
}
void Position::setCol(int c)
{
    // TODO: set
    this->c = c;
}
string Position::str() const
{
    // TODO: trả về chuỗi "(<r>,<c>)"
    return "(" + to_string(r) + "," + to_string(c) + ")";
}
bool Position::isEqual(Position position) const
{
    // TODO: so sánh tọa độ với Position khác
    if(this->r == position.getRow() && this->c == position.getCol()) return true;
    return false;
}

/*
 * CLASS: MovingObject
 */
MovingObject::MovingObject(int index, const Position pos, Map *map, const string &name)
{
    // TODO: constructor
    this->index = index;
    this->pos = pos;
    this->map = map;
    this->name = name;
}
Position MovingObject::getCurrentPosition() const
{
    // TODO: get
    return this->pos;
}
int MovingObject::getExp() const {
    return this->exp;
}
/*
 * CLASS: Character kế thừa class MovingObject
 */
Character::Character(int index, const Position pos, Map *map, const string &name)
    : MovingObject(
          // TODO: constructor class cha
          index, pos, map, name
      )
{
    // TODO: constructor
}
/*
 * CLASS: Sherlock kế thừa class Character
 */

Sherlock::Sherlock(int index, const string &moving_rule, const Position &init_pos, Map *map, int init_hp, int init_exp)
    : Character(
          // TODO: constructor class cha
          index, pos, map, "Sherlock"
      )
{
    // TODO: constructor
    this->moving_rule = moving_rule;
    this->HP = init_hp;
    this->EXP = init_exp;
    this->index_moving_rule = 0;
}

Position Sherlock::getNextPosition()
{
    // TODO: tính vị trí tiếp theo dựa theo nước đi kế tiếp
    Position next_pos = pos;
    if(moving_rule.length() == 0) return Position::npos;
    if (moving_rule[index_moving_rule] == 'U'){
        next_pos.setRow(next_pos.getRow() - 1);
    }
    else if (moving_rule[index_moving_rule] == 'L'){
        next_pos.setCol(next_pos.getCol() - 1);
    }
    else if (moving_rule[index_moving_rule] == 'D'){
        next_pos.setRow(next_pos.getRow() + 1);
    }
    else if (moving_rule[index_moving_rule] == 'R'){
        next_pos.setCol(next_pos.getCol() + 1);
    }
    index_moving_rule++;
    if (index_moving_rule == moving_rule.length()){
        index_moving_rule = 0;
    }
    if (map != NULL && map->isValid(next_pos, this)) return next_pos;
    else return Position::npos;
}
void Sherlock::move()
{
    // TODO: di chuyển đến vị trí tiếp theo và cập nhật nước đi tiếp theo
    Position next_pos = getNextPosition();
    if (next_pos.isEqual(Position::npos)) return;
    pos = next_pos;  
}
string Sherlock::str() const
{
    //  TODO: trả về chuỗi "Sherlock[index=<index>;pos=<pos>;moving_rule=<moving_rule>]"
    return "Sherlock[index=" + to_string(index) + ";pos=" + pos.str() + ";moving_rule=" + moving_rule + "]";
}

MovingObjectType Sherlock::getObjectType() const
{
    // TODO: get
    return MovingObjectType::SHERLOCK;
}

int Sherlock::getHP() const
{
    // TODO: get
    return this->HP;
}
int Sherlock::getEXP() const
{
    // TODO: get
    return this->EXP;
}
void Sherlock::setHP(int hp)
{
    // TODO: set
    this->HP = hp;
}

void Sherlock::setEXP(int exp)
{
    // TODO: set
    this->EXP = exp;
}
/*
 * CLASS: Watson kế thừa class Character
 */

Watson::Watson(int index, const string &moving_rule, const Position &init_pos, Map *map, int init_hp, int init_exp)
    : Character(
          // TODO: constructor class cha
          index, pos, map, "Watson"
      )
{
    // TODO: constructor
    this->moving_rule = moving_rule;
    this->HP = init_hp;
    this->EXP = init_exp;
    this->index_moving_rule = 0;
}

Position Watson::getNextPosition()
{
    // TODO: tính vị trí tiếp theo dựa theo nước đi kế tiếp
    Position next_pos = pos;
    if(moving_rule.length() == 0) return Position::npos;
    if (moving_rule[index_moving_rule] == 'U'){
        next_pos.setRow(next_pos.getRow() - 1);
    }
    else if (moving_rule[index_moving_rule] == 'L'){
        next_pos.setCol(next_pos.getCol() - 1);
    }
    else if (moving_rule[index_moving_rule] == 'D'){
        next_pos.setRow(next_pos.getRow() + 1);
    }
    else if (moving_rule[index_moving_rule] == 'R'){
        next_pos.setCol(next_pos.getCol() + 1);
    }
    index_moving_rule++;
    if (index_moving_rule == moving_rule.length()){
        index_moving_rule = 0;
    }
    if (map != NULL && map->isValid(next_pos, this)) return next_pos;
    else return Position::npos;
}

void Watson::move()
{
    // TODO: di chuyển đến vị trí tiếp theo và cập nhật nước đi tiếp theo
    Position next_pos = getNextPosition();
    if (next_pos.isEqual(Position::npos)) return;
    pos = next_pos;
}
string Watson::str() const
{
    //  TODO: trả về chuỗi "Watson[index=<index>;pos=<pos>;moving_rule=<moving_rule>]"
    return "Watson[index=" + to_string(index) + ";pos=" + pos.str() + ";moving_rule=" + moving_rule + "]";
}

MovingObjectType Watson::getObjectType() const
{
    // TODO: get
    return MovingObjectType::WATSON;
}

int Watson::getHP() const
{
    // TODO: get
    return HP;
}

int Watson::getEXP() const
{
    // TODO: get
    return EXP;
}

void Watson::setHP(int hp)
{
    // TODO: set
    this->HP = hp;
}

void Watson::setEXP(int exp)
{
    // TODO: set
    this->EXP = exp;
}
/*
 * CLASS: Map
 */
Map::Map(int num_rows, int num_cols, int num_walls, Position *array_walls, int num_fake_walls, Position *array_fake_walls)
{
    // TODO: constructor
    this->num_rows = num_rows;
    this->num_cols = num_cols;
    map = new MapElement **[num_rows];
    for (int i = 0; i < num_rows; i++){
        map[i] = new MapElement *[num_cols];
        for (int j = 0; j < num_cols; j++){
            map[i][j] = new Path();
            for (int k = 0; k < num_walls; k++){
                if (array_walls[k].getRow() == i && array_walls[k].getCol() == j){
                    map[i][j] = new Wall();
                }
            }
            for (int k = 0; k < num_fake_walls; k++){
                if (array_fake_walls[k].getRow() == i && array_fake_walls[k].getCol() == j){
                    map[i][j] = new FakeWall((i * 257 + j * 139 + 89) % 900 + 1);
                }
            }
        }
    }
    for(int i = 0; i < num_walls; i++){
        for(int j = 0; j < num_fake_walls; j++){
            if(array_walls[i].getRow() == array_fake_walls[j].getRow() && array_walls[i].getCol() == array_fake_walls[j].getCol()){
                map[array_walls[i].getRow()][array_walls[i].getCol()] = new Wall();
            }
        }
    }
}
Map::~Map()
{
    // TODO: destructor
    for (int i = 0; i < num_rows; i++){
        for (int j = 0; j < num_cols; j++){
            delete map[i][j];
        }
        delete[] map[i];
    }
    delete[] map;
}

int Map::getNumRows() const
{
    // TODO: get
    return num_rows;
}
int Map::getNumCols() const
{
    // TODO: get
    return num_cols;
}
ElementType Map::getElementType(int i, int j) const
{
    // TODO: get
    return map[i][j]->getType();
}
bool Map::isValid(const Position pos, MovingObject *mv_obj) const
{
    // TODO: kiểm tra đối tượng có thể di chuyển vào vị trí hay không
    if ( (pos.getRow()) < 0 || pos.getRow() >= num_rows || pos.getCol() < 0 || pos.getCol() >= num_cols ) {
        return false;
    }
    if ( getElementType(pos.getRow(), pos.getCol()) == FAKE_WALL ) {
        if(mv_obj != NULL) {
            if(mv_obj->getObjectType() == SHERLOCK || mv_obj->getObjectType() == CRIMINAL || mv_obj->getObjectType() == ROBOT) return true;
            else if(mv_obj->getObjectType() == WATSON){
                if(mv_obj->getExp()>((pos.getRow()*257+pos.getCol()*139+89)%900+1)) return true;
                else return false;
            }
        }
        return false;
    }
    if (getElementType(pos.getRow(), pos.getCol()) == PATH) {
        return true;
    }
    return false;
}
/*
 * CLASS: Criminal kế thừa class Character
 */

Criminal::Criminal(int index, const Position &init_pos, Map *map, Sherlock *sherlock, Watson *watson)
    : Character(
          // TODO: constructor class cha
            index, pos, map, "Criminal"
      )
{
    // TODO: constructor
    this->sherlock = sherlock;
    this->watson = watson;
    this->count = 0;
}
bool Criminal::isCreatedRobotNext() const {
    if (getCount() % 3 == 0 && getCount()>0) return true;
    return false;
}
Position Criminal::getNextPosition()
{
    // TODO: tính vị trí tiếp theo dựa theo nước đi kế tiếp
    Position next_pos = pos;
    int max_distance = -1;
    Position arr[4];
    arr[0] = Position(pos.getRow() - 1, pos.getCol());
    arr[1] = Position(pos.getRow(), pos.getCol() - 1);
    arr[2] = Position(pos.getRow() + 1, pos.getCol());
    arr[3] = Position(pos.getRow(), pos.getCol() + 1);
    for (int i = 0; i < 4; i++){
        if (map != NULL && map->isValid(arr[i], this)){
            if(sherlock != NULL && watson != NULL) {
                int distance = abs(arr[i].getRow() - sherlock->getCurrentPosition().getRow()) + abs(arr[i].getCol() - sherlock->getCurrentPosition().getCol()) + abs(arr[i].getRow() - watson->getCurrentPosition().getRow()) + abs(arr[i].getCol() - watson->getCurrentPosition().getCol());
                if (distance > max_distance){
                    max_distance = distance;
                    next_pos = arr[i];
                }
                else if (distance == max_distance){
                    continue;
                }
            }
        }
    }
    return next_pos;
}
void Criminal::move()
{
    // TODO: di chuyển đến vị trí tiếp theo và cập nhật nước đi tiếp theo
    Position next_pos = getNextPosition();
    if (next_pos.isEqual(Position::npos)) return;
    pos = next_pos;
    count++;
}

string Criminal::str() const
{
    // TODO: trả về chuỗi "Criminal[index=<index>;pos=<pos>]"
    return "Criminal[index=" + to_string(index) + ";pos=" + pos.str() + "]";
}

MovingObjectType Criminal::getObjectType() const
{
    // TODO: get
    return MovingObjectType::CRIMINAL;
}
int Criminal::getCount() const
{
    // TODO: get
    return count;
}

/*
 * CLASS: Robot kế thừa class MovingObject
 */
Robot::Robot(int index, const Position &pos, Map *map, RobotType robot_type, Criminal *criminal, const string &name)
    : MovingObject(
          // TODO: constructor class cha
          index, pos, map, name
      )
{
    // TODO: constructor
    this->robot_type = robot_type;
    this->criminal = criminal;
}
Robot *Robot::create(int index, Map *map, Criminal *criminal, Sherlock *sherlock, Watson *watson)
{
    // TODO: trả về đối tượng class kế thừa từ Robot phù hợp
    if(criminal->isCreatedRobotNext()){
        return new RobotC(index, criminal->getCurrentPosition(), map, C, criminal);
    }    
    else if(distance(criminal->getCurrentPosition(), sherlock->getCurrentPosition()) > distance(criminal->getCurrentPosition(), watson->getCurrentPosition())){
        return new RobotS(index, criminal->getCurrentPosition(), map, S, criminal, sherlock);
    }
    else if(distance(criminal->getCurrentPosition(), sherlock->getCurrentPosition()) < distance(criminal->getCurrentPosition(), watson->getCurrentPosition())){
        return new RobotW(index, criminal->getCurrentPosition(), map, W, criminal, watson);
    }
    else if(distance(criminal->getCurrentPosition(), sherlock->getCurrentPosition()) == distance(criminal->getCurrentPosition(), watson->getCurrentPosition())){
        return new RobotSW(index, criminal->getCurrentPosition(), map, SW, criminal, sherlock, watson);
    }
    else return NULL;
}
MovingObjectType Robot::getObjectType() const
{
    // TODO: get
    return MovingObjectType::ROBOT;
}
/*
 *CLASS: RobotC kế thừa class Robot
 */
RobotC::RobotC(int index, const Position &init_pos, Map *map, RobotType robot_type, Criminal *criminal)
    : Robot(
          // TODO: constructor class cha
          index, init_pos, map, robot_type, criminal, "RobotC"
      )
{
    // TODO: constructor
    // TODO: Thêm thuộc tính nextPosition khởi tạo bằng vị trí tiếp theo của criminal
    nextPosition = criminal->getNextPosition();
}

int RobotC::getDistance(Sherlock *sherlock)
{
    // TODO: get
    return distance(pos, sherlock->getCurrentPosition());
}

int RobotC::getDistance(Watson *watson)
{
    // TODO: get
    return distance(pos, watson->getCurrentPosition());
}
// TODO implement các phương thức getNextPosition, move, str, getType, getDistance
Position RobotC::getNextPosition()
{
    // TODO: tìm vị trí liền truoc của Criminal
    Position next_pos = pos;
    if (nextPosition.isEqual(Position::npos)) return next_pos;
    if (nextPosition.getRow() == pos.getRow() - 1){
        next_pos.setRow(next_pos.getRow() + 1);
    }
    else if (nextPosition.getCol() == pos.getCol() - 1){
        next_pos.setCol(next_pos.getCol() + 1);
    }
    else if (nextPosition.getRow() == pos.getRow() + 1){
        next_pos.setRow(next_pos.getRow() - 1);
    }
    else if (nextPosition.getCol() == pos.getCol() + 1){
        next_pos.setCol(next_pos.getCol() - 1);
    }
    return next_pos;
}
void RobotC::move()
{
    // TODO: di chuyển theo Criminal
    Position next_pos = getNextPosition();
    if (next_pos.isEqual(Position::npos)) return;
    pos = next_pos;
}
string RobotC::str() const
{
    // TODO: trả về chuỗi "Robot[pos=<pos>;type=C;dist=<distance>]"
    return "Robot[pos=" + pos.str() + ";type=C;dist=" + to_string(getDistance()) + "]";
}
int RobotC::getDistance() const
{
    // TODO: get
    return distance(pos, criminal->getCurrentPosition());
}
RobotType RobotC::getType() const
{
    // TODO: get
    return robot_type;
}
/*
 * CLASS: RobotW kế thừa class Robot
 */

RobotW::RobotW(int index, const Position &init_pos, Map *map, RobotType robot_type, Criminal *criminal, Watson *watson)
    : Robot(
          // TODO: constructor class cha
          index, init_pos, map, robot_type, criminal, "RobotW"
      )
{
    // TODO: constructor
    this->watson = watson;
}

Position RobotW::getNextPosition()
{
    // TODO: tìm vị trí tiếp theo gần Watson nhất
    Position next_pos = pos;
    int min_distance = 1000000;
    Position arr[4];
    arr[0] = Position(pos.getRow() - 1, pos.getCol());
    arr[1] = Position(pos.getRow(), pos.getCol() - 1);
    arr[2] = Position(pos.getRow() + 1, pos.getCol());
    arr[3] = Position(pos.getRow(), pos.getCol() + 1);
    for (int i = 0; i < 4; i++){
        if (map != NULL && map->isValid(arr[i], this)){
            int distance = abs(arr[i].getRow() - watson->getCurrentPosition().getRow()) + abs(arr[i].getCol() - watson->getCurrentPosition().getCol());
            if (distance < min_distance){
                min_distance = distance;
                next_pos = arr[i];
            }
            else if (distance == min_distance){
                continue;
            }
        }
    }
    return next_pos;
}

void RobotW::move()
{
    // TODO: di chuyển về phía Watson
    Position next_pos = getNextPosition();
    if (next_pos.isEqual(Position::npos)) return;
    pos = next_pos;
}

string RobotW::str() const
{
    // TODO: trả về chuỗi "Robot[pos=<pos>;type=W;dist=<distance>]"
    return "Robot[pos=" + pos.str() + ";type=W;dist=" + to_string(getDistance()) + "]";
}

RobotType RobotW::getType() const
{
    // TODO: get
    return robot_type;
}

int RobotW::getDistance() const
{
    // TODO: get
    return distance(pos, watson->getCurrentPosition());
}
/*
 * CLASS: RobotS kế thừa class Robot
 */
RobotS::RobotS(int index, const Position &init_pos, Map *map, RobotType robot_type, Criminal *criminal, Sherlock *sherlock)
    : Robot(
          // TODO: constructor class cha
          index, init_pos, map, robot_type, criminal, "RobotS"
      )
{
    // TODO: constructor
    this->sherlock = sherlock;
}

Position RobotS::getNextPosition()
{
    // TODO: tìm vị trí tiếp theo gần Sherlock nhất
    Position next_pos = pos;
    int min_distance = 1000000;
    Position arr[4];
    arr[0] = Position(pos.getRow() - 1, pos.getCol());
    arr[1] = Position(pos.getRow(), pos.getCol() - 1);
    arr[2] = Position(pos.getRow() + 1, pos.getCol());
    arr[3] = Position(pos.getRow(), pos.getCol() + 1);
    for (int i = 0; i < 4; i++){
        if (map != NULL && map->isValid(arr[i], this)){
            int distance = abs(arr[i].getRow() - sherlock->getCurrentPosition().getRow()) + abs(arr[i].getCol() - sherlock->getCurrentPosition().getCol());
            if (distance < min_distance){
                min_distance = distance;
                next_pos = arr[i];
            }
            else if (distance == min_distance){
                continue;
            }
        }
    }
    return next_pos;
}
void RobotS::move()
{
    // TODO: di chuyển về phía Sherlock
    Position next_pos = getNextPosition();
    if (next_pos.isEqual(Position::npos)) return;
    pos = next_pos;
}

string RobotS::str() const
{
    // TODO: trả về chuỗi "Robot[pos=<pos>;type=S;dist=<distance>]"
    return "Robot[pos=" + pos.str() + ";type=S;dist=" + to_string(getDistance()) + "]";
}

RobotType RobotS::getType() const
{
    // TODO: get
    return robot_type;
}

int RobotS::getDistance() const
{
    // TODO: get
    return distance(pos, sherlock->getCurrentPosition());
}
/*
 * CLASS: RobotSW kế thừa class Robot
 */
RobotSW::RobotSW(int index, const Position &init_pos, Map *map, RobotType robot_type, Criminal *criminal, Sherlock *sherlock, Watson *watson)
    : Robot(
          // TODO: constructor class cha
          index, init_pos, map, robot_type, criminal, "RobotSW"
      )
{
    // TODO: constructor
    this->sherlock = sherlock;
    this->watson = watson;
}

// TODO implement các phương thức getNextPosition, move, str, getType, getDistance
Position RobotSW::getNextPosition()
{
    // TODO: tìm vị trí tổng giá trị khoảng cách Sherlock và Watson nhỏ nhất
    Position next_pos = pos;
    int min_distance = 1000000;
    Position arr[4];
    arr[0] = Position(pos.getRow() - 1, pos.getCol());
    arr[1] = Position(pos.getRow(), pos.getCol() - 1);
    arr[2] = Position(pos.getRow() + 1, pos.getCol());
    arr[3] = Position(pos.getRow(), pos.getCol() + 1);
    for (int i = 0; i < 4; i++){
        if (map != NULL && map->isValid(arr[i], this)){
            int distance = abs(arr[i].getRow() - sherlock->getCurrentPosition().getRow()) + abs(arr[i].getCol() - sherlock->getCurrentPosition().getCol()) + abs(arr[i].getRow() - watson->getCurrentPosition().getRow()) + abs(arr[i].getCol() - watson->getCurrentPosition().getCol());
            if (distance < min_distance){
                min_distance = distance;
                next_pos = arr[i];
            }
            else if (distance == min_distance){
                continue;
            }
        }
    }
    return next_pos;
}
string RobotSW::str() const
{
    // TODO: trả về chuỗi "Robot[pos=<pos>;type=S;dist=<distance>]"
    return "Robot[pos=" + pos.str() + ";type=SW;dist=" + to_string(getDistance()) + "]";
}
RobotType RobotSW::getType() const
{
    // TODO: get
    return robot_type;
}
int RobotSW::getDistance() const
{
    // TODO: get tổng khoảng cách đến Sherlock và Watson
    return distance(pos, sherlock->getCurrentPosition()) + distance(pos, watson->getCurrentPosition());
}
void RobotSW::move()
{
    // TODO: di chuyển đến gần cả Sherlock và Watson
    Position next_pos = getNextPosition();
    if (next_pos.isEqual(Position::npos)) return;
    pos = next_pos;
}
/*
 * CLASS: ArrayMovingObject
 */

ArrayMovingObject::ArrayMovingObject(int capacity)
{
    // TODO: constructor
    this->capacity = capacity;
    count = 0;
    arr_mv_objs = new MovingObject *[capacity];
    for(int i = 0; i < capacity; i++){
        arr_mv_objs[i] = NULL;
    }
}
ArrayMovingObject::~ArrayMovingObject()
{
    // TODO: destructor
    if(arr_mv_objs != NULL){
        delete[] arr_mv_objs;
        arr_mv_objs = NULL;
    }
}
bool ArrayMovingObject::isFull() const
{
    // TODO: kiểm tra số lượng đối tượng đã đầy hay chưa
    if(count >= capacity) return true;
    return false;
}
bool ArrayMovingObject::add(MovingObject *mv_obj)
{
    // TODO: thêm đối tượng mới vào cuối mảng đối tượng
    if(isFull()) return false;
    arr_mv_objs[count] = mv_obj;
    count++;
    return true;
}
MovingObject *ArrayMovingObject::get(int index) const
{
    // TODO: trả về đối tượng có index tương ứng
    if(index < 0 || index >= count) return NULL;
    return arr_mv_objs[index];
}

int ArrayMovingObject::size() const
{
    // TODO: trả về số lượng đối tượng trong mảng
    return count;
}

string ArrayMovingObject::str() const
{
    // TODO: trả về chuỗi biểu diễn mảng
    string array;
    array = "ArrayMovingObject[count=" + to_string(count) + ";capacity=" + to_string(capacity) + ';';
    for (int i = 0; i < count; i++)
    {
        array += get(i)->str();
        if (i < count - 1)
            array += ';';
    }
    array += ']';
    return array;
}
/*
 * CLASS: Configuration
 */
Configuration::Configuration(const string &filepath)
{
    //    TODO: constructor
    string line;
    ifstream ifs(filepath);
    for (int i = 0; i < 15 && !ifs.eof(); i++)
    {
        ifs >> line;
        if (line.find("MAP_NUM_ROWS") == 0)
        {
            map_num_rows = stoi(line.substr(13, line.length() - 13));
            configString[0][0] = "MAP_NUM_ROWS=";
            configString[1][0] = to_string(map_num_rows);
        }
        else if (line.find("MAP_NUM_COLS") == 0)
        {
            map_num_cols = stoi(line.substr(13, line.length() - 13));
            configString[0][1] = "MAP_NUM_COLS=";
            configString[1][1] = to_string(map_num_cols);
        }
        else if (line.find("MAX_NUM_MOVING_OBJECTS") == 0)
        {
            max_num_moving_objects = stoi(line.substr(23, line.length() - 23));
            configString[0][2] = "MAX_NUM_MOVING_OBJECTS=";
            configString[1][2] = to_string(max_num_moving_objects);
        }
        else if (line.find("ARRAY_WALLS") == 0)
        {
            num_walls = (line.length() - 13) / 6;
            configString[0][3] = "NUM_WALLS=";
            configString[1][3] = to_string(num_walls);
            configString[0][4] = "ARRAY_WALLS=";
            configString[1][4] = line.substr(12, line.length() - 12);
            arr_walls = new Position[num_walls];
            for (int k = 0; k < num_walls; k++)
            {
                char c;
                int temp1, temp2;
                istringstream temp(line.substr(14 + k * 6, 3));
                temp >> temp1 >> c >> temp2;
                arr_walls[k] = Position(temp1, temp2);
            }
        }
        else if (line.find("ARRAY_FAKE_WALLS") == 0)
        {
            num_fake_walls = (line.length() - 18) / 6;
            configString[0][5] = "NUM_FAKE_WALLS=";
            configString[1][5] = to_string(num_fake_walls);
            configString[0][6] = "ARRAY_FAKE_WALLS=";
            configString[1][6] = line.substr(17, line.length() - 17);
            arr_fake_walls = new Position[num_fake_walls];
            for (int k = 0; k < num_fake_walls; k++)
            {
                char c;
                int temp1, temp2;
                istringstream temp(line.substr(19 + k * 6, 3));
                temp >> temp1 >> c >> temp2;
                arr_fake_walls[k] = Position(temp1, temp2);
            }
        }
        else if (line.find("SHERLOCK_MOVING_RULE") == 0)
        {
            sherlock_moving_rule = line.substr(21, line.length() - 21);
            configString[0][7] = "SHERLOCK_MOVING_RULE=";
            configString[1][7] = sherlock_moving_rule;
        }
        else if (line.find("SHERLOCK_INIT_POS") == 0)
        {
            configString[0][8] = "SHERLOCK_INIT_POS=";
            configString[1][8] = line.substr(18, line.length() - 18);
            char c;
            int temp1, temp2;
            istringstream temp(line.substr(19, 3));
            temp >> temp1 >> c >> temp2;
            sherlock_init_pos = Position(temp1, temp2);
        }
        else if (line.find("SHERLOCK_INIT_HP") == 0)
        {
            sherlock_init_hp = stoi(line.substr(17, line.length() - 17));
            configString[0][9] = "SHERLOCK_INIT_HP=";
            configString[1][9] = to_string(sherlock_init_hp);
        }
        else if (line.find("SHERLOCK_INIT_EXP") == 0)
        {
            sherlock_init_exp = stoi(line.substr(18, line.length() - 18));
            configString[0][10] = "SHERLOCK_INIT_EXP=";
            configString[1][10] = to_string(sherlock_init_exp);
        }
        else if (line.find("WATSON_MOVING_RULE") == 0)
        {
            watson_moving_rule = line.substr(19, line.length() - 19);
            configString[0][11] = "WATSON_MOVING_RULE=";
            configString[1][11] = watson_moving_rule;
        }
        else if (line.find("WATSON_INIT_POS") == 0)
        {
            configString[0][12] = "WATSON_INIT_POS=";
            configString[1][12] = line.substr(16, line.length() - 16);
            char c;
            int temp1, temp2;
            istringstream temp(line.substr(17, 3));
            temp >> temp1 >> c >> temp2;
            watson_init_pos = Position(temp1, temp2);
        }
        else if (line.find("WATSON_INIT_HP") == 0)
        {
            watson_init_hp = stoi(line.substr(15, line.length() - 15));
            configString[0][13] = "WATSON_INIT_HP=";
            configString[1][13] = to_string(watson_init_hp);
        }
        else if (line.find("WATSON_INIT_EXP") == 0)
        {
            watson_init_exp = stoi(line.substr(16, line.length() - 16));
            configString[0][14] = "WATSON_INIT_EXP=";
            configString[1][14] = to_string(watson_init_exp);
        }
        else if (line.find("CRIMINAL_INIT_POS") == 0)
        {
            configString[0][15] = "CRIMINAL_INIT_POS=";
            configString[1][15] = line.substr(18, line.length() - 18);
            char c;
            int temp1, temp2;
            istringstream temp(line.substr(19, 3));
            temp >> temp1 >> c >> temp2;
            criminal_init_pos = Position(temp1, temp2);
        }
        else if (line.find("NUM_STEPS") == 0)
        {
            num_steps = stoi(line.substr(10, line.length() - 10));
            configString[0][16] = "NUM_STEPS=";
            configString[1][16] = to_string(num_steps);
        }
    }
}

Configuration::~Configuration()
{
    // TODO: destructor
    if (arr_walls != NULL)
    {
        delete[] arr_walls;
        arr_walls = NULL;
    }
    if (arr_fake_walls != NULL)
    {
        delete[] arr_fake_walls;
        arr_fake_walls = NULL;
    }
}
string Configuration::str() const
{
    // TODO: trả về chuỗi mô tả file
    string arr;
    arr = configString[0][0] + configString[1][0] + "\n";
    for (int i = 1; i < 17; i++)
    {
        arr += configString[0][i] + configString[1][i] + "\n";
    }
    return "Configuration[\n" + arr + ']';
}
/*
 * CLASS: StudyPinkProgram
 */
StudyPinkProgram::StudyPinkProgram(const string &config_file_path)
{
    config = new Configuration(config_file_path);
    map = new Map(config->map_num_rows, config->map_num_cols, config->num_walls, config->arr_walls, config->num_fake_walls, config->arr_fake_walls);
    arr_mv_objs = new ArrayMovingObject(config->max_num_moving_objects);
    sherlock = new Sherlock(1, config->sherlock_moving_rule, config->sherlock_init_pos, map, config->sherlock_init_hp, config->sherlock_init_exp);
    watson = new Watson(2, config->watson_moving_rule, config->watson_init_pos, map, config->watson_init_hp, config->watson_init_exp);
    criminal = new Criminal(0, config->criminal_init_pos, map, sherlock, watson);

    arr_mv_objs->add(criminal);
    arr_mv_objs->add(sherlock);
    arr_mv_objs->add(watson);
}
StudyPinkProgram::~StudyPinkProgram()
{
    // TODO: hủy những đối tượng cấp phát
    // * Nếu thực hiện hủy toàn bộ trong ArrayMovingObject thì không cần delete criminal, sherlock và watson
    // delete map;
    // delete config;
    // delete arr_mv_objs;
}
void StudyPinkProgram::printMap(ofstream &OUTPUT, int roundSize) const
{
    for (int i = -1; i < config->map_num_cols; i++)
    {
        if (i == -1)
            OUTPUT << setw(5) << ""
                   << "|";
        else
            OUTPUT << setw(5) << i << "|";
    }
    OUTPUT << endl;
    for (int i = 0; i < config->map_num_rows; i++)
    {
        OUTPUT << setw(5) << i << "|";
        for (int j = 0; j < config->map_num_cols; j++)
        {
            int idx = map->getElementType(i, j);
            string nameElement[3] = {"     ", "IIIII", "-----"};
            string nameChar[4] = {"S", "W", "C", "R"};
            string robotName[4] = {"c", "s", "w", "2"};
            string cellValue = nameElement[idx];
            Position charPos(i, j);
            for (int k = 0; k < roundSize; k++)
            {
                if (arr_mv_objs->get(k)->getCurrentPosition().isEqual(charPos))
                {
                    if (cellValue == "     " || cellValue == "-----" || cellValue == "IIIII")
                        cellValue = "";
                    idx = arr_mv_objs->get(k)->getObjectType();
                    if (idx == 3)
                    {
                        MovingObject *temp = arr_mv_objs->get(k);
                        cellValue += robotName[dynamic_cast<Robot *>(temp)->getType()];
                        continue;
                    }
                    cellValue += nameChar[idx];
                }
            }
            if (!(cellValue == "     " || cellValue == "-----" || cellValue == "IIIII"))
                cellValue = "(" + cellValue + ")";
            OUTPUT << setw(5) << cellValue << "|";
        }
        OUTPUT << endl;
    }
}
void StudyPinkProgram::run(ofstream &OUTPUT)
{
    if (!OUTPUT.is_open())
    {
        cout << "Can't open file" << endl;
        return;
    }
    OUTPUT << config->str() << endl;
    for (int istep = 0; istep < config->num_steps; ++istep)
    {
        OUTPUT << "__________________NEW STEP__________________" << endl;
        MovingObject *robot = nullptr;
        int roundSize = arr_mv_objs->size();
        for (int i = 0; i < roundSize; ++i)
        {

            OUTPUT << "ROUND : " << istep << " - TURN : " << i << endl;
            stringstream ss(arr_mv_objs->str());
            string lineArr = "";
            getline(ss, lineArr, 'C');
            OUTPUT << lineArr << "]" << endl;
            getline(ss, lineArr, ']');
            OUTPUT << "\tC" << lineArr.substr(1) << "]" << endl;
            while (getline(ss, lineArr, ']'))
            {
                if (lineArr.length() > 0)
                    OUTPUT << "\t" << lineArr.substr(1) << "]" << endl;
            }
            if (i == 0)
                OUTPUT << "Criminal current count : " << criminal->getCount() << endl;
            if (i == 1)
                OUTPUT << "Sherlock move direction : " << config->sherlock_moving_rule[istep % config->sherlock_moving_rule.length()] << endl;
            if (i == 2)
                OUTPUT << "Watson move direction : " << config->watson_moving_rule[istep % config->watson_moving_rule.length()] << endl;

            if (arr_mv_objs->get(i)->getObjectType() == MovingObjectType::CRIMINAL)
            {
                robot = Robot::create(arr_mv_objs->size(), map, criminal, sherlock, watson);
            }
            arr_mv_objs->get(i)->move();
            if (i == 0)
                OUTPUT << "Criminal count after moving : " << criminal->getCount() << endl;

            printMap(OUTPUT, roundSize);
            OUTPUT << "*********************************************************" << endl;
        }
        if (robot != nullptr)
        {
            if (criminal->getCount() % 3 == 0 && criminal->getCount() > 0)
            {
                string robotType[4] = {"C", "S", "W", "SW"};
                OUTPUT << "Robot " << robotType[dynamic_cast<Robot *>(robot)->getType()] << " has been created" << endl;
                arr_mv_objs->add(robot);
            }
            else
            {
                delete robot;
            }
        }
    }
}
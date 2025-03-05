#include "Player.hpp"
#include <exception>
#include <stdexcept>
#include <vector>

Inventory::Inventory():ressources(std::vector<int>()) {
	
}
Inventory::~Inventory() {

}
int &Inventory::operator[](ressource_t index) {
	return ressources[index];
}
const int &Inventory::operator[](ressource_t index) const {
	return ressources[index];
}

Player::Player(uint32_t x, uint32_t y, team_t team):
	_id(Player::getNextId()),
	_x(x), _y(y),
	_level(0),
	_orientation(NORTH), //TODO 
	_life_state(EGG_HATCHING),
	_time_to_die(TIME_TO_LIVE_AT_LAYING),
	_team_index(team),
	_inventory(Inventory())
{
}

id_zap_t Player::nb_of_elements = 0;

void Player::getPosition(uint32_t &x, uint32_t &y) const {
	x = _x;
	y = _y;
}

Player::orientation_t Player::getOrientation(void) const {
	return _orientation;
}

Player::life_state_e Player::getLifeState(void) const {
	return _life_state;
}

const Inventory &Player::getInventory(void) const {
	return _inventory;
}

id_zap_t Player::getId(void) const {
	return _id;
}

uint32_t Player::getLevel(void) const {
	return _level;
}

team_t Player::getTeam(void) const {
	return _team_index;
}

void Player::advance(void) {
	switch (_orientation) {
		case NORTH: { _x -= 1; return ; }
		case SOUTH: { _x += 1; return ; }
		case WEST: { _y += 1; return ; }
		case EAST: { _y -= 1; return ; }
		default: {throw std::runtime_error("Bad orientation input.\n");}
	}
}

void Player::turnRight(void) {
	_orientation += 1;
	_orientation %= 4;
}

void Player::turnLeft(void) {
	_orientation += 3;
	_orientation %= 4;
}

void Player::beKicked(orientation_t orientation) {
	switch (orientation) {
		case NORTH: { _x += 1; return ; }
		case SOUTH: { _x -= 1; return ; }
		case WEST: { _y -= 1; return ; }
		case EAST: { _y += 1; return ; }
		default: {throw std::runtime_error("Bad orientation input.\n");}
	}
}

void Player::takeItem(ressource_t index) {
	if (index == 0) {
		_time_to_die += TIME_FOR_ONE_FOOD_UNIT;
	}
}

bool Player::loseItem(ressource_t index) {
	if (_inventory[index] > 0) {
		_inventory[index] -= 1;
		return true;
	}
	return false;
}

void Player::hatch(void) {
	if (_life_state == EGG_HATCHING)
		_life_state = EGG_HATCHED;
}

void Player::raiseToLife(void) {
	if (_life_state == EGG_HATCHED)
		_life_state = LIVING;
}

void Player::tickIncrementation(size_t time) {
	_time_to_die -= time;
}

void Player::levelUp(void) {
	_level += 1;
}

id_zap_t Player::getNextId(void) {
	Player::nb_of_elements += 1;
	return nb_of_elements;
}

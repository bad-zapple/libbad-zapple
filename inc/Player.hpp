#ifndef PLAYER_HPP
# define PLAYER_HPP

#include <cstddef>
#include <cstdint>

// #include "Inventory.hpp"
//
#ifndef INVENTORY_HPP //TODO suppress with Inventory comming
class Inventory {
};
#endif //INVENTORY_HPP

class Inventory;

typedef int ressource_t;
typedef int team_t;

class Player
{
		public:
	typedef enum player_orientation {
		NORTH,
		EAST,
		SOUTH,
		WEST,
	} orientation_e;

	typedef enum life_state {
		EGG_HACTHING,
		EGG_HATCHED,
		LIVING,
		DEAD,
	} life_state_e;

		private:
	uint32_t x;
	uint32_t y;
	uint16_t level;
	orientation_e orientation;
	life_state_e life_state; 
	size_t time_to_die;
	team_t team_index;
	Inventory inventory;

		public:

	/* Constructor */

	Player();
	~Player();

	/* Getter and setter */

	void get_position(uint32_t &_x, uint32_t &_y) const;
	orientation_e get_orientation(void) const;
	life_state_e get_life_state(void) const;
	const Inventory &get_inventory(void) const;
	uint32_t get_level(void) const;
	
	/* Map interaction */

	void advance(void);
	void turn_right(void);
	void turn_left(void);
	void be_kicked(orientation_e orientation);

	/* Item interaction */

	void take_item(ressource_t index);
	bool lose_item(ressource_t index);

	/* Life state interaction */

	void hatch(void);
	void increase_time(void);

	/* Level interaction */

	void level_up(void);
};

#endif

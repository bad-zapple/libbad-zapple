#ifndef ZAP_PLAYER_HPP
# define ZAP_PLAYER_HPP

#include <cstddef>
#include <cstdint>
#include <vector>

namespace zap
{

class Inventory;

typedef unsigned int ressource_t;
typedef int team_t;
typedef int id_zap_t;

class Inventory {
		public:
	Inventory();
	~Inventory();
	int &operator[](ressource_t index);
	const int &operator[](ressource_t index) const;
		private:
	std::vector<int> ressources;
};

#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

#define TIME_FOR_ONE_FOOD_UNIT 126
#define TIME_TO_LIVE_AT_LAYING 1260

class Player
{
		public:
	typedef char orientation_t;

	typedef enum life_state {
		EGG_HATCHING,
		EGG_HATCHED,
		LIVING,
		DEAD,
	} life_state_e;

	static id_zap_t nb_of_elements;

		private:
	id_zap_t _id;
	uint32_t _x;
	uint32_t _y;
	uint32_t _level;
	orientation_t _orientation;
	life_state_e _life_state; 
	size_t _time_to_die;
	team_t _team_index;
	Inventory _inventory;

		public:


	/* Constructor */

	Player(uint32_t x, uint32_t y, team_t team);
	~Player();

	/* Getter and setter */

	void getPosition(uint32_t &x, uint32_t &y) const;
	orientation_t getOrientation(void) const;
	life_state_e getLifeState(void) const;
	const Inventory &getInventory(void) const;
	uint32_t getLevel(void) const;
	team_t getTeam(void) const;
	id_zap_t getId(void) const;

	
	/* Map interaction */

	void advance(void);
	void turnRight(void);
	void turnLeft(void);
	void beKicked(orientation_t orientation);

	/* Item interaction */

	void takeItem(ressource_t index);
	bool loseItem(ressource_t index);

	/* Life state interaction */

	void hatch(void);
	void raiseToLife(void);
	void tickIncrementation(size_t time);

	/* Level interaction */

	void levelUp(void);

	/* Id interaction */

	static id_zap_t getNextId(void);

};

}; /* namespace zap */

#endif

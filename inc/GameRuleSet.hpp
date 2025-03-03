#ifndef GAMERULESET_HPP
# define GAMERULESET_HPP

# include <cstddef>
# include <string>
# include <vector>

class GameRuleSet {
	private:
		size_t map_h;
		size_t map_w;
		size_t tick_speed;
		std::vector<std::string> stones;
		std::vector<std::string> teams;
		size_t max_clients_by_team;
		size_t number_of_team;
		size_t max_clients;
		ActionSpeed actions_speed;
};

#endif


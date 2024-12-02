#ifndef GAMERULESET_HPP
# define GAMERULESET_HPP

# include <cstddef>
# include <tuple>
# include <vector>

class Stones;

class GameRuleSet {
	private:
		std::tuple<std::size_t, std::size_t> _map_dimensions;
		size_t tick_speed_by_sec;
		std::vector<StoneDescriptor> stones;
		size_t max_clients_by_team;
		size_t number_of_team;
		size_t max_clients;
		size_t max_food;
		size_t time_to_die;
		size_t time_to


}













#endif 

#ifndef GAMERULESET_HPP
# define GAMERULESET_HPP

# include <cstddef>
# include <cstdint>
# include <string>
# include <vector>

# include "ActionDurationSet.hpp"

class GameRuleSet {
		public:

		private:
	uint32_t map_w;
	uint32_t map_h;
	size_t tick_speed;
	std::vector<std::string> stones;

	std::vector<std::string> teams;
	size_t number_of_team;

	size_t max_clients_by_team;
	size_t max_clients;

	ActionDurationSet durations;

	std::string serialized_config;

		public:

	GameRuleSet(const std::string &serialized_config);
	~GameRuleSet();

	const std::string &get_serialized_config() const ;
};

#endif


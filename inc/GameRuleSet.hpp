#ifndef GAMERULESET_HPP
# define GAMERULESET_HPP

# include <cstddef>
# include <string>
# include <vector>

// # include "ActionSpeed.hpp" insert here or


class GameRuleSet {
	public:
		GameRuleSet(const std::string &serialized_config);
		~GameRuleSet();

		const std::string &get_serialized_config() const ;

	private:
		size_t map_w;
		size_t map_h;
		size_t tick_speed;
		std::vector<std::string> stones;
		std::vector<std::string> teams;
		size_t max_clients_by_team;
		size_t number_of_team;
		size_t max_clients;
		std::string serialized_config;
//		ActionSpeed actions_speed; TODO uncomment when  Action Speed will be created
//
};

#endif


#ifndef GAMERULESET_HPP
# define GAMERULESET_HPP

# include <cstddef>
# include <string>
# include <vector>

// # include "ActionSpeed.hpp" insert here or


class GameRuleSet {
	public:
		GameRuleSet(std::string serialized_config);
		~GameRuleSet();

		std::string get_serialized_config() const ;

	private:
		const size_t map_h;
		const size_t map_w;
		const size_t tick_speed;
		const std::vector<std::string> stones;
		const std::vector<std::string> teams;
		const size_t max_clients_by_team;
		const size_t number_of_team;
		const size_t max_clients;
		const std::string serialized_config;
//		ActionSpeed actions_speed; TODO uncomment when  Action Speed will be created
//
};

#endif


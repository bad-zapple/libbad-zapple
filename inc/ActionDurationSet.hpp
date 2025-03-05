#ifndef ZAP_ACTIONDURATIONSET_HPP
# define ZAP_ACTIONDURATIONSET_HPP

# include <cstddef>
# include <string>

namespace zap
{

class ActionDurationSet {
		private:
	size_t tt_advance;
	size_t tt_turn;

	size_t tt_see;

	size_t tt_kick;
	size_t tt_incantate;

	size_t tt_take;
	size_t tt_put_down;

	size_t tt_broadcast;
	size_t tt_get_unused_connections;

	size_t tt_egg_layed;
	size_t tt_egg_hatched;
	size_t tt_egg_rotten;
		
		public:
	ActionDurationSet(const std::string &config);

	size_t get_tt_advance() const;
	size_t get_tt_turn() const;

	size_t get_tt_see() const;

	size_t get_tt_kick() const;
	size_t get_tt_incantate() const;

	size_t get_tt_take() const;
	size_t get_tt_put_down() const;

	size_t get_tt_broadcast() const;
	size_t get_tt_get_unused_connections() const;

	size_t get_tt_egg_layed() const;
	size_t get_tt_egg_hatched() const;
	size_t get_tt_egg_rotten() const;
};

}; /* namespace zap */

#endif

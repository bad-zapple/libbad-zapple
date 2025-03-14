#ifndef ZAP_WORLD_HPP
# define ZAP_WORLD_HPP

# include <cstdint>
# include <vector>
# include <string>

# include <GameRuleSet.hpp>
# include <Player.hpp>

namespace zap
{

class World
{
		public:
	class Cell
	{
			private:
		std::vector<uint32_t> inventory;
	
			public:
		Cell();
		Cell(size_t inventorySize);
		~Cell();

		std::string getViewContent() const;
		const std::vector<uint32_t>& getRawContent() const;
		bool placeItem(ressource_t itemid);
		bool pickItem(ressource_t itemid);
	};

		private:
	Cell *cells;
	uint32_t width;
	uint32_t height;

		public:
	World(const GameRuleSet& config);
	~World();

	const Cell& getCell(int32_t x, int32_t y) const;
	Cell& getCell(int32_t x, int32_t y);
	void getDimensions(uint32_t &w, uint32_t &h) const;
	std::string getPlayerView(const Player& viewer) const;
};

}; /* namespace zap */

#endif
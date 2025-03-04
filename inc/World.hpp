#ifndef WORLD_HPP
# define WORLD_HPP

# include <cstdint>
# include <vector>
# include <string>

# include <GameRuleSet.hpp>
# include <Player.hpp>

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

		std::string GetViewContent() const;
		const std::vector<uint32_t>& GetRawContent() const;
		bool PlaceItem(uint32_t itemid);
		bool PickItem(uint32_t itemid);
	};

		private:
	Cell *cells;
	uint32_t width;
	uint32_t height;

		public:
	World(const GameRuleSet& config);
	~World();

	const Cell& GetCell(int32_t x, int32_t y) const;
	Cell& GetCell(int32_t x, int32_t y);
	void GetDimensions(uint32_t &w, uint32_t &h) const;
	std::string GetPlayerView(const Player& viewer) const;
};

#endif
#ifndef WORLD_HPP
# define WORLD_HPP

# include <stdint.h>
# include <vector>
# include <string>

class World
{
		public:
	class Cell
	{
			private:
		std::vector<int> inventory;
	
			public:
		Cell();
		~Cell();

		std::string GetViewContent() const;
		const std::vector<int>& GetRawContent() const;
		void PlaceItem(int itemid);
		int PickItem(int itemid);
	};

		private:
	uint32_t width;
	uint32_t height;

		public:
	World();
	~World();

	const Cell& GetCell(uint32_t x, uint32_t y) const;
	Cell& GetCell(uint32_t x, uint32_t y);
	void GetDimensions(uint32_t &w, uint32_t &h) const;

	/*
		ViewIterator built with Direction+Depth(player level),
			which will automatically map the view cone to implement "VOIR"
	*/
};

#endif
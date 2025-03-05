#include <World.hpp>

World::Cell::Cell() { }

World::Cell::Cell(size_t inventorySize)
{ 
	inventory.resize(inventorySize);
}

World::Cell::~Cell() { }

std::string World::Cell::getViewContent() const
{
	std::string output;

	for (size_t i = 0; i < inventory.size(); i++)
	{
		for (size_t j = 0; j < inventory[i]; j++)
		{
			output += "placeholder";
			output += ' ';
		}
	}
	if (!output.empty()) /* Remove trailing space */
		output.pop_back();
	return output;
}

const std::vector<uint32_t>& World::Cell::getRawContent() const
{
	return inventory;
}

bool World::Cell::placeItem(ressource_t itemid)
{
	if (itemid >= inventory.size())
		return false;

	inventory[itemid]++;
	return true;
}

bool World::Cell::pickItem(ressource_t itemid)
{
	if (itemid >= inventory.size())
		return false;

	if (!inventory[itemid])
		return false;
	
	inventory[itemid]--;
	return true;
}

/* MISSING: config.width/height/resourceCount */
World::World(const GameRuleSet& config) : cells(nullptr), width(16), height(16)
{
	cells = new Cell[width * height];
	std::fill(cells, cells + width * height, Cell(7));
	(void)config;
	
	/* World generation */
}

World::~World()
{
	delete[] cells;
}

const World::Cell& World::getCell(int32_t x, int32_t y) const
{
	while (x < 0)
		x += width;
	while (y < 0)
		y += height;
	x = x % width;
	y = y % height;
	return cells[y * width + x];
}

World::Cell& World::getCell(int32_t x, int32_t y)
{
	while (x < 0)
		x += width;
	while (y < 0)
		y += height;
	x = x % width;
	y = y % height;
	return cells[y * width + x];
}

void World::getDimensions(uint32_t &w, uint32_t &h) const
{
	w = width;
	h = height;
}

std::string World::getPlayerView(const Player& viewer) const
{
	Player::orientation_t orient;
	uint32_t x;
	uint32_t y;
	int level = 3; //Placeholder
	std::string output = "{";
	bool horizontal = false;
	int dir = 1;

	orient = viewer.getOrientation();
	horizontal = (orient == WEST || orient == EAST);
	if (orient == NORTH || orient == WEST)
		dir = -1;
	viewer.getPosition(x, y);
	for (int i = 0; i < level + 1; i++)
	{
		for (int j = -i; j <= i; j++)
		{
			// output += playersFound;
			if (horizontal)
				output += getCell(x + i * dir, y + j * dir).getViewContent();
			else
				output += getCell(x + j * -dir, y + i * dir).getViewContent();
			output += ", ";
		}
	}
	output.pop_back(); /* Remove trailing comma space */
	output.pop_back();
	output += '}';
	return output;
}
config: {
	map: {x: 50, y: 50},
	stones: ["linemate", "deraumere", "sibur", "mendiane", "phiras", "thystame"],
	levels: {
		1: [1,1,0,0,0,0,0],
		2: [2,1,1,1,0,0,0],
		3: [2,2,0,1,0,2,0],
		4: [4,1,1,2,0,1,0],
		5: [4,1,2,1,3,0,0],
		6: [6,1,2,3,0,1,0],
		7: [6,2,2,2,2,2,1],
	},
	teams: [
		{
			name: "reds",
			number: 2,
		},
		{
			name: "yellow",
			number: 2,
		},
		{
			name: "blue",
			number: 2,
		},
	],
	actions: {
		advance: {name: "avance", ticks: 7},
		turn_r: {name: "droite", ticks: 7},
		turn_l: {name: "gauche", ticks: 7},
		see: {name: "voir", ticks: 7},
		inventory: {name: "inventaire", ticks: 1},
		take: {name: "prend", ticks: 7},
		put: {name: "pose", ticks: 7},
		kick: {name: "expulse", ticks: 7},
		broadcast: {name: "brodcast", ticks: 7},
		incantation: {name: "incantation", ticks: 300},
		fork: {name: "fork", ticks: 42},
		connect: {name: "connect_nbr", ticks: 0},
	}
},

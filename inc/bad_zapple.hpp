#ifndef BAD_ZAPPLE_HPP
# define BAD_ZAPPLE_HPP

class TestObj
{
		private:
	int value;

		public:
	TestObj();
	~TestObj();
	int val() const;
	void val(int _val);
};

#endif

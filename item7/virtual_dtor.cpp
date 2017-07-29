class TimeKeeper
{
	public:
		TimeKeeper();
		virtual ~TimeKeeper();
};

class AtomicClock : public TimeKeeper {};
class WaterClock : public TimeKeeper {};
class WristWatch : public TimeKeeper {};


class computer
{
	public:
		computer(int player, int *board, int length);
		~computer();
		int playsCount();
		int play();

	private:
		int playedListLength; //Number of positions stored in list
		int playedListIndex;  //Current number of actual plays stored
		int *playedList;      //List of positions already played

		int player;      //Assigned player
		int *board;      //Pointer to board
		int boardLength; //Length of board

		void addtoPlayedList(int);
};

class computer
{
	public:
		computer(int player, int *board, int length);
		~computer();
		int numberofPlacesPlayed();
		int play();

	private:
		int playedListLength; //Number of positions stored in list
		int playedListIndex;
		int *playedList;      //List of positions already played

		int player;      //Assigned player
		int *board;      //Pointer to board
		int boardLength; //Length of board

		void addtoPlayedList(int);
};

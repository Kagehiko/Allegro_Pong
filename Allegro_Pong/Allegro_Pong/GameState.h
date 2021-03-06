#ifndef ALLEGRO_PONG_GAMESTATE_HEADER
#define ALLEGRO_PONG_GAMESTATE_HEADER

#include "ProjectHeader.h"
#include "ClassesForGameStates.h"


//All possible game states
enum GameStatesEnum {
	STATE_MAIN_MENU,
	STATE_IN_GAME,
	STATE_QUIT
};

class GameState {
	public:
		
		//Virtual destructor (necessary to make sure that derived classes implement their own destructors)
		virtual ~GameState() {};

		//Virtual game loop functions
		virtual void handle_events() = 0;
		virtual void logic() = 0;
		virtual void render() = 0;
		virtual GameStatesEnum get_next_state() = 0;

};

class MainMenu : public GameState {
	public:

		//Constructor and destructor functions
		MainMenu();
		~MainMenu();

		//Game loop functions
		void handle_events();
		void logic();
		void render();
		GameStatesEnum get_next_state();

	private:
		int mouse_x, mouse_y;
		bool actions[2];
		ALLEGRO_FONT *font;
		ALLEGRO_EVENT_QUEUE* mouse_event_queue;
		GuiButton play_button, exit_button;
};

class InGame : public GameState {
	public:

		//Constructor and destructor functions
		InGame();
		~InGame();

		//Game loop functions
		void handle_events();
		void logic();
		void render();
		GameStatesEnum get_next_state();

	private:

		Ball ball;
		PlayerPaddle playerpaddle;
		CPUPaddle cpupaddle;
		int playerscore;
		int cpuscore;
		ALLEGRO_EVENT_QUEUE* keyboard_event_queue;
		bool actions[3];
		ALLEGRO_FONT *font;
		void scored();
};


//Function that changes the GameState based on what the next state is
GameStatesEnum  change_gameloop_state(GameState* GameLoop, GameStatesEnum next_state);





#endif
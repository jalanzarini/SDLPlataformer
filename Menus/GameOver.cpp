#include "GameOver.hpp"
#include "Game.hpp"

#include <fstream>
using namespace std;

namespace Menus
{
    GameOver::GameOver(EventManager* ev, Game* gm):
    Menu(ev, gm),
    points(910, 450, 100, 125),
    name(660, 600, 600, 100)
    {
        sprite.setSprite("assets/Menu/gameoverbg.jpg", 0, 0, 1920, 1080, 1);

        playAgain.setButton(770, 800, 381, 100);
        playAgain.setSprite("assets/Menu/playagain.png", 0, 0, 381, 100, 1);

        mainMenu.setButton(780, 900, 360, 100);
        mainMenu.setSprite("assets/Menu/mainmenu.png", 0, 0, 360, 100, 1);

        input.setButton(560, 600, 800, 100);

        name.setMessage("Enter name");
    }

    GameOver::~GameOver()
    {
        events = nullptr;
    }

    void GameOver::setPoints(int p)
    {
        pts = p;
        points.setMessage(to_string(p));
    }

    void GameOver::update()
    {   
        if(isButtonClicked(input))
        {
            getInput();
        }

        if (isButtonClicked(playAgain))
        {
            game->setGameState(0);
            game->resetLevels();
        }

        if (isButtonClicked(mainMenu))
        {
            game->setGameState(-2);
            game->resetLevels();
            name.setMessage("Enter name");

        }
    }

    void GameOver::getInput()
    {
        bool quit = false;

        SDL_Event e;

        SDL_Color textColor = { 255, 191, 0, 0xFF };

        string inputText = "";

        SDL_StartTextInput();

        while(!quit)
        {
            bool renderText = false;

            while(SDL_PollEvent(&e) != 0)
            {
                if(e.type == SDL_KEYDOWN)
                {
                    if( e.key.keysym.sym == SDLK_BACKSPACE && inputText.length() > 0 )
                    {
                        inputText.pop_back();
                        renderText = true;
                    } 
                    else if( e.key.keysym.sym == SDLK_RETURN && inputText.length() > 0)
                    {
                        ofstream arq;
                        arq.open("lb.txt", ios::out | ios::app);

                        arq <<" "<< to_string(pts) << " " << inputText;

                        quit = true;
                        inputText = "";

                        arq.close();
                    }
                }
                else if(e.type == SDL_TEXTINPUT)
                {
                    if( !( SDL_GetModState() & KMOD_CTRL && ( e.text.text[ 0 ] == 'c' || e.text.text[ 0 ] == 'C' || e.text.text[ 0 ] == 'v' || e.text.text[ 0 ] == 'V' ) ) )
                    {
                        inputText += e.text.text;
                        renderText = true;
                    }
                }
            }
            if(renderText)
            {
                SDL_RenderClear(GraphicManager::getInstance()->getRenderer());

                if(inputText != "")
                {
                    name.update(inputText);
                    render();
                }
                else
                {
                    name.update("");
                    render();
                }
                SDL_RenderPresent(GraphicManager::getInstance()->getRenderer());
            }
        }
        SDL_StopTextInput();
    }

    void GameOver::render()
    {
        sprite.render();
        mainMenu.render();
        playAgain.render();
        points.render();
        name.render();
    }
}
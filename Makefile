linker = -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf
cpps = main.cpp Ente.cpp Managers/GraphicManager.cpp Managers/EventManager.cpp Lists/EntityList.cpp Levels/Level.cpp Game/Game.cpp Entities/Obstacle/Plataform.cpp Entities/Character/Player.cpp Managers/CollisionManager.cpp Components/Sprite.cpp Menus/LevelMenu.cpp Menus/PauseMenu.cpp Entities/Character/Enemy.cpp Entities/Entity.cpp Menus/MainMenu.cpp Menus/GameOver.cpp Menus/Leaderboard.cpp Entities/Projectile.cpp Entities/Ground.cpp Levels/Level1.cpp Levels/Level2.cpp Components/Font.cpp Entities/Character/Maul.cpp Entities/Character/Trooper.cpp Entities/Character/Vader.cpp Entities/Obstacle/Barrel.cpp

includes = -IManagers -ILists -ILevels -IGame -IEntities -IEntities/Character -IEntities/Obstacle -IComponents -IMenus -I./

all:
	g++ -o main $(cpps) $(includes) $(linker)
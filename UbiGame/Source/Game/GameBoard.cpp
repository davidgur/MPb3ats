#include "GameBoard.h"
#include <array>
#include <chrono>

#include "GameEngine\GameEngineMain.h"
#include "Game\Components\PlayermovementComponent.h"
#include "GameEngine\EntitySystem\Components\SpriteRenderComponent.h"
#include "GameEngine\Util\SoundManager.h"
#include <GameEngine\EntitySystem\Components\SoundComponent.h>
#include <iostream>
#include <fstream>
#include <ctime>

#pragma warning(disable : 4996)

using namespace GameEngine;

using namespace Game;

static int point = 0;
static int nextIndex = 0;

std::time_t result = std::time(nullptr);
float timer;
static std::vector<int> data;
static std::vector<int> column;
static std::vector<float> prog;
static std::vector<GameEngine::Entity*> notes;
static bool a_pressed = true;
static bool s_pressed = true;
static bool d_pressed = true;
static std::vector<Entity> dots;
static GameEngine::SoundComponent* soundCompon;
static int soundId;
static std::string song = "deadmau5";
static bool isPlaying = false;

GameBoard::GameBoard()

	: m_player(nullptr)
{
	CreatePlayer(-1, -1);

	std::ifstream readFile("Resources/data/"+song+".txt");
	
	int a, b;
	float balance = 0.0;
	while (readFile >> a >> b)
	{
		data.push_back(a/(147+balance));
		balance += 0.1;
		column.push_back(b);
		prog.push_back(INT_MAX);
	}

	CreatePlayer(0, 0);
	timer = std::mktime(std::localtime(&result));
}


GameBoard::~GameBoard()
{

}

void GameBoard::Update()
{
	if (std::time(nullptr) - 37 >= result && !isPlaying) {
		soundCompon->PlaySound(soundId, false);
		isPlaying = true;
	}

	auto t1 = std::chrono::high_resolution_clock::now();
	if (nextIndex < data.size() && point >= data.at(nextIndex) && point <= data.at(nextIndex) + 1900) {

		CreatePlayer(115 * column.at(nextIndex) - 55, column.at(nextIndex));
		prog.at(nextIndex) = std::mktime(std::localtime(&result));
		nextIndex++;
		auto t2 = std::chrono::high_resolution_clock::now();

		auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
	}
	else {
		point++;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		a_pressed = true;
	}
	else if (a_pressed)
	{
		a_pressed = false;
	}

}

void GameBoard::CreatePlayer(float x, int a) {
	m_player = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(m_player);

	m_player->SetPos(sf::Vector2f(x, 10.f));
	m_player->SetSize(sf::Vector2f(60.f, 60.f));

	if (a != 0) {

		GameEngine::SpriteRenderComponent* spriteRender = static_cast<GameEngine::SpriteRenderComponent*>
			(m_player->AddComponent<GameEngine::SpriteRenderComponent>());

		spriteRender->SetFillColor(sf::Color::Transparent);

		if (a == 1) {
			spriteRender->SetTexture(GameEngine::eTexture::Player);
		}
		else if (a == 2) {
			spriteRender->SetTexture(GameEngine::eTexture::Player2);
		}
		else {
			spriteRender->SetTexture(GameEngine::eTexture::Player3);
		}

	}

	//move the box
	if (a == 0) {
		soundCompon = static_cast<GameEngine::SoundComponent*>
			(m_player->AddComponent<SoundComponent>());

		soundId = soundCompon->LoadSoundFromFile("Resources/audio/"+song+".wav");

		//create bg
		m_player = new GameEngine::Entity();
		GameEngine::GameEngineMain::GetInstance()->AddEntity(m_player);

		m_player->SetPos(sf::Vector2f(170.f, 260.f));
		m_player->SetSize(sf::Vector2f(340.f, 520.f));

		GameEngine::SpriteRenderComponent* spriteRender = static_cast<GameEngine::SpriteRenderComponent*>
			(m_player->AddComponent<GameEngine::SpriteRenderComponent>());

		spriteRender->SetFillColor(sf::Color::Transparent);
		spriteRender->SetTexture(GameEngine::eTexture::Background);
		//bg done
	}
	else if (a == -1) {
		//create bg
		m_player = new GameEngine::Entity();
		GameEngine::GameEngineMain::GetInstance()->AddEntity(m_player);

		m_player->SetPos(sf::Vector2f(170.f, 260.f));
		m_player->SetSize(sf::Vector2f(340.f, 520.f));

		GameEngine::SpriteRenderComponent* spriteRender = static_cast<GameEngine::SpriteRenderComponent*>
			(m_player->AddComponent<GameEngine::SpriteRenderComponent>());

		spriteRender->SetFillColor(sf::Color::Transparent);
		spriteRender->SetTexture(GameEngine::eTexture::Background);
		//bg done
	}
	else {
		m_player->AddComponent<PlayerMovementComponent>();
	}

	notes.push_back(m_player);

}

#include "PlayerMovementComponent.h"
#include "GameEngine\GameEngineMain.h"

#include "GameEngine\EntitySystem\Components\SpriteRenderComponent.h"

#include <SFML/Window/Keyboard.hpp>
#include <iostream>

using namespace Game;

bool a_pressed = false;
bool s_pressed = false;
bool d_pressed = false;
static int pointCount;

PlayerMovementComponent::PlayerMovementComponent()
	: m_lastFaceIndex(0)
	, m_wasFaceSwapButtonPressed(false)
{

}


PlayerMovementComponent::~PlayerMovementComponent()
{

}

void PlayerMovementComponent::OnAddToWorld()
{
	__super::OnAddToWorld();
}


void PlayerMovementComponent::Update()
{
	__super::Update();

	//Grabs how much time has passed since the last Update() call
	float dt = GameEngine::GameEngineMain::GetTimeDelta();

	//by default the wanted velocity is 0
	sf::Vector2f wantedVel = sf::Vector2f(0.f, 0.f);
	//player Velocity is applied when we have some input (for the time being let's make it 10pixels a second)
	float playerVel = 100.f;

	//desired pos
	wantedVel.y += playerVel * dt;

	//Update the entity position with new velocity
	GetEntity()->SetPos(GetEntity()->GetPos() + wantedVel);

	if (GetEntity()->GetPos().y > 350 && GetEntity()->GetSize().y != 100.f) {
		GetEntity()->SetSize(sf::Vector2f(100.f, 100.f));
	}
	else {
		if (GetEntity()->GetPos().y > 400 && GetEntity()->GetPos().y < 520) {
			//at bottom
			//left
			if (GetEntity()->GetPos().x < 113 ) {
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
				{
					a_pressed = true;
				}
				else if (a_pressed){
					a_pressed = false;
					//plus point
					pointCount++;
					std::cout << "Score: " << pointCount << "\n";
					//sf::Vector2f wantedVel = sf::Vector2f(10000.f, 10000.f);
					//GetEntity()->SetPos(GetEntity()->GetPos() + wantedVel);
					
				}
			}
			//center
			if (GetEntity()->GetPos().x > (113) && GetEntity()->GetPos().x < (226)) {
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
				{
					s_pressed = true;
				}
				else if (s_pressed)
				{
					s_pressed = false;
					//plus point
					pointCount++;
					std::cout << "Score: " << pointCount << "\n";
					//sf::Vector2f wantedVel = sf::Vector2f(10000.f, 10000.f);
					//GetEntity()->SetPos(GetEntity()->GetPos() + wantedVel);
				}
				
			}
			//right
			if (GetEntity()->GetPos().x > 226) {
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
				{
					d_pressed = true;
				}
				else if (d_pressed)
				{
					d_pressed = false;
					//plus point
					pointCount++;
					std::cout << "Score: " << pointCount << "\n";
					//sf::Vector2f wantedVel = sf::Vector2f(10000.f, 10000.f);
					//GetEntity()->SetPos(GetEntity()->GetPos() + wantedVel);
				}
				
			}
		}
	}
}

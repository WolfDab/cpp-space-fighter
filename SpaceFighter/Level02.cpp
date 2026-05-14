

#include "Level02.h"
#include "BioEnemyShip.h"
#include "HunterEnemyShip.h"


void Level02::LoadContent(ResourceManager& resourceManager)
{
	// Setup enemy ships
	Texture* pTexture = resourceManager.Load<Texture>("Textures\\BioEnemyShip.png");

	const int COUNT = 22;

	double xPositions[COUNT] =
	{
		0.25, 0.2, 0.3,
		0.75, 0.8, 0.7,
		0.3, 0.25, 0.35, 0.2, 0.4,
		0.7, 0.75, 0.65, 0.8, 0.6,
		0.5, 0.4, 0.6, 0.45, 0.55, .6
	};

	double delays[COUNT] =
	{
		0.0, 0.25, 0.25,
		3.0, 0.25, 0.25,
		3.25, 0.25, 0.25, 0.25, 0.25,
		3.25, 0.25, 0.25, 0.25, 0.25,
		3.5, 0.3, 0.3, 0.3, 0.3, 0.3
	};

	float delay = 3.0; // start delay
	Vector2 position;

		for (int i = 0; i < COUNT; i++)
		{
		delay += delays[i];
		position.Set(xPositions[i] * Game::GetScreenWidth(), -pTexture->GetCenter().Y);

			BioEnemyShip* pEnemy = new BioEnemyShip();
			pEnemy->SetTexture(pTexture);
			pEnemy->SetCurrentLevel(this);
		pEnemy->Initialize(position, (float)delay);
			AddGameObject(pEnemy);
		}

	Texture* pHunterTexture = resourceManager.Load<Texture>("Textures\\BioEnemyShip.png");
    
    float hunterDelay = 6.0f; // Start spawning them a bit later in the level
    
    // Spawn 3 Hunters
    for (int i = 0; i < 3; i++)
    {
        hunterDelay += 4.0f; // Stagger their spawns by 4 seconds
        
        // Spawn them roughly in the center
        Vector2 hunterPosition(Game::GetScreenWidth() * 0.5f, -pHunterTexture->GetCenter().Y);

        HunterEnemyShip* pHunter = new HunterEnemyShip();
        pHunter->SetTexture(pHunterTexture);
        pHunter->SetCurrentLevel(this);
        pHunter->Initialize(hunterPosition, hunterDelay);
        AddGameObject(pHunter);
    }

    // Setup background
    SetBackground(resourceManager.Load<Texture>("Textures\\SpaceBackground02.png"));

	Level::LoadContent(resourceManager);
}


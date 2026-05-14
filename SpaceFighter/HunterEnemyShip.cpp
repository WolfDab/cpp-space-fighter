
#include "HunterEnemyShip.h"
#include "Level.h"


HunterEnemyShip::HunterEnemyShip()
{
	SetSpeed(100);
	SetMaxHitPoints(3);
	SetCollisionRadius(20);
}


void HunterEnemyShip::Update(const GameTime& gameTime)
{
    if (IsActive())
    {
        float xMovement = 0.0f;
        PlayerShip* pPlayer = PlayerShip::GetInstance();

        // Check if the player exists and is active
        if (pPlayer != nullptr && pPlayer->IsActive())
        {
            float playerX = pPlayer->GetPosition().X;
            float hunterX = GetPosition().X;

            // Move left or right to track the player's X position
            // Added a small 5-pixel buffer to prevent jittering when aligned
            if (hunterX < playerX - 5.0f) {
                xMovement = GetSpeed() * gameTime.GetElapsedTime();
            }
            else if (hunterX > playerX + 5.0f) {
                xMovement = -GetSpeed() * gameTime.GetElapsedTime();
            }
        }

        // Apply X movement for tracking, and standard Y movement for forward progress
        TranslatePosition(xMovement, GetSpeed() * gameTime.GetElapsedTime());

        if (!IsOnScreen()) Deactivate();
    }

    EnemyShip::Update(gameTime);
}


void HunterEnemyShip::Draw(SpriteBatch& spriteBatch)
{
	if (IsActive())
	{
		const float alpha = GetCurrentLevel()->GetAlpha();
		spriteBatch.Draw(m_pTexture, GetPosition(), Color::WHITE * alpha, m_pTexture->GetCenter(), Vector2::ONE, Math::PI, 1);
	}
}

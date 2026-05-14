
#pragma once

#include "EnemyShip.h"

class HunterEnemyShip : public EnemyShip
{

public:

	HunterEnemyShip();
	virtual ~HunterEnemyShip() {}

	virtual void SetTexture(Texture* pTexture) { m_pTexture = pTexture; }

	virtual void Update(const GameTime& gameTime);

	virtual void Draw(SpriteBatch& spriteBatch);


private:

	Texture* m_pTexture = nullptr;

};
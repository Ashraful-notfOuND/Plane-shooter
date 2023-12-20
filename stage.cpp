#pragma once

#include"init.hpp"
#include"util.cpp"
SDL_Texture* bulletTexture;
SDL_Texture* playerTexture;
SDL_Texture* enemyTexture;

static void drawBullets(void)
{
	Entity *b;

	for (b = stage.bulletHead.next ; b != NULL ; b = b->next)
	{
		blit(b->texture, b->x, b->y);
	}
}

static void drawPlayer(void)
{
	blit(playerTexture, player.x, player.y);
}

static void drawFighters(void)
{
	Entity *e;

	for (e = stage.fighterHead.next ; e != NULL ; e = e->next)
	{
		blit(e->texture, e->x, e->y);
	}
}
static void draw(void)
{
	drawFighters();

	drawPlayer();

	drawBullets();
}
static void spawnEnemies(void)
{
	Entity *enemy;

	if (--enemySpawnTimer <= 0)
	{
		enemy = malloc(sizeof(Entity));
		memset(enemy, 0, sizeof(Entity));
		stage.fighterTail->next = enemy;
		stage.fighterTail = enemy;

		enemy->x = SCREEN_WIDTH;
		enemy->y = rand() % SCREEN_HEIGHT;
		enemy->side = SIDE_ENEMY;
		enemy->health = ENEMY_HEALTH;
		enemy->texture = enemyTexture;
		
		SDL_QueryTexture(enemy->texture, NULL, NULL, &enemy->w, &enemy->h);

		enemy->dx = ENEMY_SPEED;
		//enemy->dy = pow(-1,rand())*ENEMY_SPEED;
		enemy->dy = player.dy;
		if(enemy->y == player.y) enemy->dy=0;
		enemySpawnTimer = 30 + (rand() % 60);
	}
}

static int bulletHitFighter(Entity *b)
{
	Entity *e;

	for (e = stage.fighterHead.next ; e != NULL ; e = e->next)
	{
		if (e->side != b->side && collision(b->x, b->y, b->w, b->h, e->x, e->y, e->w, e->h))
		{
			b->health = 0;
			e->health--;

			return 1;
		}
	}

	return 0;
}

static void doBullets(void)
{
	Entity *b, *prev;

	prev = &stage.bulletHead;

	for (b = stage.bulletHead.next ; b != NULL ; b = b->next)
	{
		b->x += b->dx;
		b->y += b->dy;

		if (bulletHitFighter(b) || b->x > SCREEN_WIDTH)
		{
			if (b == stage.bulletTail)
			{
				stage.bulletTail = prev;
			}

			prev->next = b->next;
			free(b);
			b = prev;
		}

		prev = b;
	}
}

static void doFighters(void)
{
	Entity *e, *prev;

	prev = &stage.fighterHead;

	e = stage.fighterHead.next;
	for (; e != NULL ; e = e->next)
	{
		e->x += e->dx;
		e->y += e->dy;

		if (e != &player && (e->x < -e->w || e->health==0))
		{
			if (e == stage.fighterTail)
			{
				stage.fighterTail = prev;
			}

			prev->next = e->next;
			free(e);
			e = prev;
		}

		prev = e;
	}
}
static void fireBullet()
{
	Entity *bullet;

	bullet = (Entity*)malloc(sizeof(Entity));
	memset(bullet, 0, sizeof(Entity));
	stage.bulletTail->next = bullet;
	stage.bulletTail = bullet;

	bullet->x = player.x+20;
	bullet->y = player.y+20;
	bullet->dx = PLAYER_BULLET_SPEED;
	bullet->health = 1;
	bullet->side = SIDE_PLAYER;
	bullet->texture = bulletTexture;
	SDL_QueryTexture(bullet->texture, NULL, NULL, &bullet->w, &bullet->h);

	bullet->y += (player.h / 2) - (bullet->h / 2);

	player.reload = 8;
}
static void doPlayer(void)
{
	player.dx = player.dy = 0;

	if (player.reload > 0)
	{
		player.reload--;
	}

	if (app.keyboard[SDL_SCANCODE_UP])
	{
		player.dy = -PLAYER_SPEED;

		if (player.y == 0)
		{
			player.dy = 0;
		}
	}

	if (app.keyboard[SDL_SCANCODE_DOWN])
	{
		player.dy = PLAYER_SPEED;

		if (player.y == SCREEN_HEIGHT - 48)
		{
			player.dy = 0;
		}
	}

	if (app.keyboard[SDL_SCANCODE_LEFT])
	{
		player.dx = -PLAYER_SPEED;
		
		if (player.x == 0)
		{
			player.dx = 0;
		}
	}

	if (app.keyboard[SDL_SCANCODE_RIGHT])
	{
		player.dx = PLAYER_SPEED;

		if (player.x == SCREEN_WIDTH - 48)
		{
			player.dx = 0;
		}
	}

	if (app.keyboard[SDL_SCANCODE_LCTRL] && player.reload == 0)
	{
		fireBullet();
	}

	player.x += player.dx;
	player.y += player.dy;
}
static void initPlayer()
{
	Entity *player = (Entity*)malloc(sizeof(Entity));
	memset(player, 0, sizeof(Entity));
	stage.fighterTail->next = player;
	stage.fighterTail = player;

	player->x = 1000;
	player->y = 1000;
	player->side = SIDE_PLAYER;
	player->texture = playerTexture;
	SDL_QueryTexture(playerTexture, NULL, NULL, &player->w, &player->h);
}
static void logic(void)
{
	doPlayer();

	doFighters();

	doBullets();

	spawnEnemies();
}
static void capFrameRate(long *then, float *remainder)
{
	long wait, frameTime;

	wait = 16 + *remainder;

	*remainder -= (int)*remainder;

	frameTime = SDL_GetTicks() - *then;

	wait -= frameTime;

	if (wait < 1)
	{
		wait = 1;
	}

	SDL_Delay(wait);

	*remainder += 0.667;

	*then = SDL_GetTicks();
}
void initStage(void)
{
	app.delegate.logic = logic;
	app.delegate.draw = draw;

	memset(&stage, 0, sizeof(Stage));
	stage.fighterTail = &stage.fighterHead;
	stage.bulletTail = &stage.bulletHead;

	initPlayer();

	playerTexture = loadTexture("player.png");
	enemyTexture = loadTexture("enemy.png");
	bulletTexture = loadTexture("playerBullet.png");

	enemySpawnTimer = 0;
}

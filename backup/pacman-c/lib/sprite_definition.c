#include "../include/sprite_definition.h"

void InitVector(Vector *vector, float x, float y, int frameWidth, int frameHeight, float xSpeed, float ySpeed) {
	vector->x = x;
	vector->y = y;
	vector->frameWidth = frameWidth;
	vector->frameHeight = frameHeight;
	vector->xSpeed = xSpeed;
	vector->xSpeed = ySpeed;
	vector->len = sqrt(pow(x, 2) * pow(y, 2));
}

void InitSprite(Sprite *sprite, Attributes *attributes, Vector *vector, SDL_Surface *image, SDL_Texture *texture, SDL_Rect srcrect, SDL_Rect dstrect) {
	sprite->attributes = attributes;
	sprite->vector = vector;
	sprite->image = image;
	sprite->texture = texture;
	sprite->srcrect = srcrect;
	sprite->dstrect = dstrect;
}

void RenderSprite(Sprite *sprite) {
	if(sprite->attributes->isActive) {
		sprite->image = IMG_Load(sprite->attributes->url);
		sprite->texture = SDL_CreateTextureFromSurface(renderer, sprite->image);

		sprite->srcrect.x = sprite->attributes->instance * sprite->attributes->frames * sprite->vector->frameWidth;
		sprite->srcrect.y = 0;
		sprite->srcrect.w = sprite->vector->frameWidth;
		sprite->srcrect.h = sprite->vector->frameHeight;

		sprite->dstrect.x = sprite->vector->x;
		sprite->dstrect.y = sprite->vector->y;
		sprite->dstrect.w = sprite->vector->frameWidth * sprite->attributes->scale;
		sprite->dstrect.h = sprite->vector->frameHeight * sprite->attributes->scale;
	}
}

void UpdateSprite(Sprite *sprite, Uint32 ticks) {
	Uint32 time = ticks / (sprite->attributes->frequency);
	Uint32 count = time % (sprite->attributes->frames);
	sprite->srcrect.x = count * sprite->vector->frameWidth + (sprite->attributes->frames * sprite->attributes->instance * sprite->vector->frameWidth);

	SDL_RenderCopy(renderer, sprite->texture, &(sprite->srcrect), &(sprite->dstrect));
}

void SpriteInstance(Sprite *sprite, int instance) {
	sprite->attributes->instance = instance;
}

void DestroySprite(Sprite *sprite) {
	SDL_FreeSurface(sprite->image);
	SDL_DestroyTexture(sprite->texture);
}
